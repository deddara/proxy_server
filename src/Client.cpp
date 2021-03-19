#include "Client.hpp"


Client::Client(int & cl_socket, std::string const & host_ip, std::string const & host_port) : cl_socket(cl_socket), host_ip(host_ip),\
host_port(host_port), body(nullptr), body_len(0), in_process(0) {
	db_connect();
	stage = recv_db_resp;
}

Client::~Client() {
	if (body)
		free(body);
	close(cl_socket);
	close(host_socket);
}

int Client::buff_dup(char const * buff, const int & len) {
	if (!(body = (char*)malloc(len + 1))) {
		return 1;
	}
	body[len] = '\0';
	memcpy(body, buff, len);
	body_len = len;
	return 0;
}

void Client::buff_clear() {
	free(body);
	body = nullptr;
	body_len = 0;
}

void Client::recv_db_response() {
	int n;
	int buf_size = 2048;
	char buf[buf_size];

	bzero(&buf, buf_size);

	n = recv(host_socket, buf, buf_size, 0);
	if (n == 6) {
		std::cout << buf[0];
		write(1, buf, n);
		write(1, "\n", 1);
	}
	buf[n] = '\0';
	buff_dup(buf, n);
	stage = send_db_resp;
}

void Client::send_client_response() {
	send(host_socket, body, body_len, 0);
	stage = recv_db_resp;
	buff_clear();
}

void Client::db_connect() {
	struct sockaddr_in	addr;
	int					conn_sock;

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(std::stoi(host_port));
	addr.sin_addr.s_addr = inet_addr(host_ip.c_str());

	if ((conn_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		throw("Failed to create server socket\n");

	if (connect(conn_sock, (struct sockaddr*)& addr, sizeof (addr)) < 0) {
		throw ("Failed to connect\n");
	}
	host_socket = conn_sock;
}