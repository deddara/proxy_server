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
	recv_client_query, //read client request
	send_db_resp, //send what mysql response
	recv_db_resp, //recv mysql resp
	send_client_resp, //send to mysql client's query
	finish, //close connection
};

class Client{

private:
	int						cl_socket;
	int 					host_socket;
	std::string const 		host_ip;
	std::string const 		host_port;
	enum Stage				stage;
	char					*body;
	int 					body_len;
	int 					in_process;


public:
	Client(int &, std::string const &, std::string const &);
	~Client();

	int const & getSocket() const { return cl_socket; }
	Stage getStage() const { return stage; }
	char const * getBody() const { return  body; }
	int	const &	getDbSocket() const { return host_socket; }
	void	setStage(Stage const & stg) { stage = stg; }
	void	setProcess(int const &num) { in_process = num; }
	int const & getProcess() const { return in_process; }
	int const & getBodyLen() const { return body_len; }

	int		buff_dup(char const *buf, const int & len);
	void 	buff_clear();

	void	recv_db_response();
	void	send_client_response();
	void	db_connect();
};


#endif