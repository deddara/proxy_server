#include "Client.hpp"


Client::Client(int & cl_socket, std::string const & host_ip, std::string const & host_port) : cl_socket(cl_socket), host_ip(host_ip), host_port(host_port) {
	db_connect();
	stage = rdy_send;
}

Client::~Client() {
	close(cl_socket);
	close(host_socket);
}

void Client::db_connect() {
	struct sockaddr_in	addr;
	int					conn_sock;

	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(std::stoi("222"));
	addr.sin_addr.s_addr = inet_addr(host_ip.c_str());

	if ((conn_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		throw("Failed to create server socket\n");

	if (connect(conn_sock, (struct sockaddr*)& addr, sizeof (addr)) < 0) {
		throw ("Failed to connect\n");
	}
	std::cout << "connected" << std::endl;
	host_socket = conn_sock;
}