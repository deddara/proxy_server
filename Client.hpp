#ifndef CLIENT_H
# define CLIENT_H
# include "iostream"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
# include <strings.h>
# include <unistd.h>
# include <string.h>


enum Stage{
	rdy_send,
	rdy_recv,
	finish
};

class Client{

private:
	int			cl_socket;
	int 		host_socket;
	std::string const 		host_ip;
	std::string const 		host_port;
	enum Stage	stage;

public:
	Client(int &, std::string const &, std::string const &);
	~Client();

	int const & getSocket() const { return cl_socket; }
	Stage getStage() const { return stage; }

	void db_connect();
};


#endif