#include "iostream"
#include "Server.hpp"

typedef struct	Server_info{
	std::string ip = "127.0.0.1";
	std::string port = "3306";
	std::string serv_port = "3030";
	std::string fname = "mysql.log";
	int 		threads_num = 5;
}				Server_info;

void	check_argument(int i, int argc){
	//if next argument doesn't exist
	if (i == argc - 1){
		std::cerr << "Invalid argument" << std::endl;
		exit(1);
	}
}

void		validate_params(int argc, char **argv, Server_info & server_info){
	for (int i = 0; i < argc; i++){
		if (std::string(argv[i]) == "-help"){
			std::cout << "Usage:\n"
				"\t'-ip': ip address to connect. Default value: 127.0.0.1\n"
				"\t'-p': port to connect. Default value: 3306\n"
				"\t'-sp': server port to run. Default value: 3030\n"
				"\t'-f': file name for log. Default name: 'mysql.log'\n"
				"\t'-t': thread numbers. Default value: 5\n";
				exit(0);
		}
		if (std::string(argv[i]) == "-ip"){
			check_argument(i, argc);
			server_info.ip = std::string(argv[i + 1]);
		}
		if (std::string(argv[i]) == "-p"){
			check_argument(i, argc);
			server_info.port = std::string(argv[i + 1]);
		}
		if (std::string(argv[i]) == "-sp"){
			check_argument(i, argc);
			server_info.serv_port = std::stoi(argv[i + 1]);
		}
		if (std::string(argv[i]) == "-f"){
			check_argument(i, argc);
			server_info.fname = std::string(argv[i + 1]);
		}
		if (std::string(argv[i]) == "-t"){
			check_argument(i, argc);
			server_info.threads_num = std::stoi(argv[i + 1]); //better to check if not a num
		}
	}
}

int		main(int argc, char **argv){
	Server_info server_info;
	validate_params(argc, argv, server_info);

	try {
		Server server = Server(server_info.ip, server_info.port, server_info.serv_port, server_info.fname, server_info.threads_num);
		server.start();
	}
	catch (const char* msg){
		std::cerr << msg;
		return (1);
	}
	return (0);
}