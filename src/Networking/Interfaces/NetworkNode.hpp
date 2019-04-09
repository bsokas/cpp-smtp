#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../NetworkState";

#include <string>
// TODO insert appropriate libraries

#define PORT_LIMIT 65535

class NetworkNode {
	std::string name;
	int socketfd;
	struct sockaddr_in serverAddr;
	unsigned short int port;
	NetworkState* netstate;

public:
	NetworkNode(std::name = ""){
		netstate = NetworkState::getInstance();
		this->name = name;
		port = netstate.getNetworkPort(name);
		printNodeInit(this->port, this->name);
	};

	~NetworkNode(){};
}
