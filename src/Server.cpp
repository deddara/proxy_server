#include "Server.hpp"

# define COM_QUERY 0x03

Server::Server(std::string & host_ip, std::string & port, std::string & serv_port, std::string & flog_name, int & th_num)\
:host_ip(host_ip), host_port(port), serv_port(serv_port) ,flog_name(flog_name), th_num(th_num){
	lfile = open(flog_name.c_str(), O_CREAT | O_TRUNC | O_WRONLY , 0644);
	pipe(skip_select);
}

Server::~Server() {
	for (auto client : clients)
		delete client;
	close(server_socket);
	close(lfile);
	close(skip_select[0]);
	close(skip_select[1]);
	unlink("./temp_file");
}

void Server::create_socket() {
	struct sockaddr_in	addr;
	int					listen_sock;

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(std::stoi(serv_port));
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if ((listen_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		throw("Failed to create server socket");
	fcntl(listen_sock, F_SETFL, O_NONBLOCK);
	int opt = 1;
	setsockopt(listen_sock, SOL_SOCKET,  SO_REUSEADDR, &opt, sizeof(opt));

	if ((bind(listen_sock, (struct sockaddr*)& addr, sizeof(addr))) < 0)
		throw("Failed to bind port");

	if ((listen(listen_sock, 25)) < 0)
		throw("Server listen error");

	server_socket = listen_sock;
	std::cout << "Server listens for port " << serv_port <<  "..." << std::endl;
	std::cout << "Serving connection for " << host_ip << ":" << host_port << std::endl;
	std::cout << "All logs can be found in " << flog_name << std::endl;

}

void Server::set_prepare() {
	FD_ZERO(&readset);
	FD_ZERO(&writeset);
	FD_SET(server_socket, &readset);
	FD_SET(skip_select[0], &readset);
	max_fd = server_socket;
	for (auto client : clients){
		FD_SET(client->getSocket(), &readset);
		if (client->getStage() == recv_db_resp) {
			FD_SET(client->getDbSocket(), &readset);
			max_fd = client->getDbSocket() > max_fd ? client->getDbSocket() : max_fd;
		}
		if (client->getStage() == send_client_resp){
			FD_SET(client->getDbSocket(), &writeset);
			max_fd = client->getDbSocket() > max_fd ? client->getDbSocket() : max_fd;
		}
		if (client->getStage() == send_db_resp) {
			FD_SET(client->getSocket(), &writeset);
		}
		if (client->getSocket() > max_fd)
			max_fd = client->getSocket();
	}
}

void Server::new_connection() {
	int						accept_sock;

	if ((accept_sock = accept(server_socket, nullptr, nullptr)) < 0)
		throw "Accept connection error";
	clients.push_back(new Client(accept_sock, host_ip, host_port));
}

void Server::log_query(const char *buf, const int &buf_len) {
	std::time_t now = std::time(NULL);
	std::tm * ptm = std::localtime(&now);
	char buffer[32];
	std::strftime(buffer, 32, "[%d.%m.%Y %H:%M:%S] ", ptm);
	write(lfile, buffer, strlen(buffer));
	write(lfile, buf + 5, buf_len - 5);
	write(lfile, "\n", 1);
}

void Server::recv_msg(Client * client) {
	int buf_size = 2048;
	int n;
	char buff[buf_size];
	bzero(&buff, buf_size);

	n = recv(client->getSocket(), buff, buf_size, 0);

	if (n <= 0)
	{
		client->setStage(finish);
		return;
	}

	buff[n] = '\0';

	if(client->buff_dup(buff, n))
		throw "Buff append malloc failed";
	if (buff[4] == COM_QUERY) {
		log_query(buff, buf_size);
	}
	client->setStage(send_client_resp);
}

void Server::send_db_response(Client * client) {
	send(client->getSocket(), client->getBody(), client->getBodyLen(), 0);
	client->setStage(recv_client_query);
	client->buff_clear();
}

void Server::serve_connections(std::mutex & que_mutex) {
	for (auto client = clients.begin(); client != clients.end(); ++client) {
		if ((*client)->getStage() == finish){
			delete *client;
			client = clients.erase(client);
			if (client == clients.end())
				break;
		}

		if ((FD_ISSET((*client)->getSocket(), &readset) || FD_ISSET((*client)->getDbSocket(), &readset)\
		|| FD_ISSET((*client)->getSocket(), &writeset) || FD_ISSET((*client)->getDbSocket(), &writeset)) && !(*client)->getProcess()) {
			que_mutex.lock();
			clients_que.push((*client));
			que_mutex.unlock();
		}
	}
}

[[noreturn]] void worker(Server * server, std::mutex * mu) {
	for(;;){
		mu->lock();
		if (!server->getClientsQue().empty()){
			Client *client = server->getClientsQue().front();
			server->getClientsQue().pop();
			client->setProcess(1);
			switch (client->getStage()){
				case recv_client_query:
					server->recv_msg(client);
					break;
				case send_db_resp:
					server->send_db_response(client);
					break;
				case recv_db_resp:
					client->recv_db_response();
					break;
				case send_client_resp:
					client->send_client_response();
					break;
			}
			client->setProcess(0);
			write(server->getSelectSkipFile()[1], "1", 1);
		}
		mu->unlock();
	}
}

void Server::start_threads(std::mutex & que_mutex) {
	for (int i = 0; i < th_num; ++i){
		std::thread wrk (worker, this, & que_mutex);
		wrk.detach();
	}
}

void Server::start() {
	char		c;
	std::mutex	que_mutex;

	create_socket();
	start_threads(que_mutex);
	for (;;){
		set_prepare();
		if (select(max_fd + 1, &readset, &writeset, NULL, NULL) < 0)
			throw "Select error";

		if (FD_ISSET(server_socket, &readset))
			new_connection();
		if (FD_ISSET(skip_select[0], &readset))
			read(skip_select[0], &c, 1);
		serve_connections(que_mutex);
	}
}
