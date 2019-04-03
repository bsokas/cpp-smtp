#include <iostream>
#include <cstdlib>
#include <cstdio>
// TODO insert appropriate libraries

class NetworkNode {
	int socketfd;
	struct sockaddr_in serverAddr;

public:
	NetworkNode(){};

	~NetworkNode(){};
}