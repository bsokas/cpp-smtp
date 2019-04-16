#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>

#include "../NetworkState.cpp"
#include "../../Utilities/netnode.cpp"

#define PORT_LIMIT 65535

class NetworkNode {
	std::string name;
	int socketfd;
	struct sockaddr_in serverAddr;
	unsigned short int port;
	NetworkState* netstate;

public:
	NetworkNode(std::string name = ""){
		netstate = NetworkState::getInstance();
		this->name = name;
		port = netstate -> getNetworkPort(name);
	};

	void startServer(){
			if (port < 0 || port > PORT_LIMIT) {
				perror("Invalid port number: ");
				printf("%hu", port);
			}

			socketfd = socket(AF_INET, SOCK_STREAM, 0);
			if (socketfd < 0) {
				printf("Socket failed to connect for %s", name.c_str());
				return;
			}
			prepPort(serverAddr, port);

			socklen_t addrLength = sizeof(serverAddr);
			if (bindSocket(socketfd, &serverAddr, addrLength) < 0) {
				perror("Error attempting to bind to socket");
				return;
			}
			listen(socketfd, 5);	//setting backlog queue to max size of 5
	};

	void print(){
		printf("Node name: %s\n", name.c_str());
		printf("Node setup on port: %hu\n", port);
	}

	~NetworkNode(){};
};
