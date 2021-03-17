#include "Server.hpp"

Server::Server(std::string & host_ip, std::string & port, std::string & serv_port, std::string & flog_name)\
:host_ip(host_ip), host_port(port), serv_port(serv_port) ,flog_name(flog_name){}

Server::~Server() {}

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
	max_fd = server_socket;
	for (auto client : clients){
		FD_SET(client->getSocket(), &readset);
//		if ((*it)->getResponse() && strlen((*it)->getResponse()->getStr())){
//			FD_SET((*it)->getFd(), &writeset);
//		}
		if (client->getSocket() > max_fd)
			max_fd = client->getSocket();
	}
}

void Server::new_connection() {
	int						accept_sock;

	if ((accept_sock = accept(server_socket, nullptr, nullptr)) < 0)
		throw "Accept connection error";
	fcntl(accept_sock, F_SETFL, O_NONBLOCK);
	clients.push_back(new Client(accept_sock, host_ip, host_port));
}

void Server::serve_connections() {
	for (auto client : clients) {
		if (FD_ISSET(client->getSocket(), &readset)){
			switch (client->getStage()){
				case rdy_send:
					break;
				case rdy_recv:
					break;
				case finish:
					break;
			}
		}
	}
}

void Server::start() {
	create_socket();

	for (;;){
		set_prepare();
		if (select(max_fd + 1, &readset, &writeset, NULL, NULL) < 0)
			throw "Select error";

		if (FD_ISSET(server_socket, &readset))
			new_connection();
		serve_connections();
	}
}