#ifndef SERVER_H
# define SERVER_H

# include "Client.hpp"

# include <iostream>
# include <cstdlib>
# include <strings.h>
# include <unistd.h>
# include <vector>

# include <thread>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/select.h>
#include <zconf.h>

class Server{

private:
	std::string const	host_ip;
	std::string const	host_port;
	std::string const	serv_port;
	std::string const	flog_name;

	std::vector<Client *> clients;
	int 				server_socket;
	int 				max_fd;
	fd_set 				writeset;
	fd_set 				readset;


public:
	Server(std::string &, std::string &, std::string &, std::string &);
	~Server();

	[[noreturn]] void start();
	void create_socket();
	void set_prepare();
	void new_connection();
	void serve_connections();
};

#endif
