#ifndef SERVER_H
# define SERVER_H

# include "Client.hpp"

# include <iostream>
# include <cstdlib>
# include <unistd.h>
# include <vector>
# include <queue>

# include <thread>
# include <mutex>

# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <sys/select.h>
# include <zconf.h>

class Server{

private:
	std::string const	host_ip;
	std::string const	host_port;
	std::string const	serv_port;
	std::string const	flog_name;
	int 		const	th_num;

	std::vector<Client *> clients;
	std::queue<Client *> clients_que;
	int 				server_socket;
	int 				max_fd;
	fd_set 				writeset;
	fd_set 				readset;
	int 				lfile;
	int 				skip_select[2];

public:
	Server(std::string &, std::string &, std::string &, std::string &, int &);
	~Server();

	[[noreturn]] void start();
	std::queue<Client*> & getClientsQue()  { return clients_que;};
	void create_socket();
	void set_prepare();
	void new_connection();
	void serve_connections(std::mutex & que_mutex);
	void recv_msg(Client *client);
	void send_db_response(Client *client);
	void log_query(const char *, const int &);
	void start_threads(std::mutex & que_mutex);
	int * getSelectSkipFile() { return skip_select; }

};

#endif
