#include <cstdio>
#include <cstdlib>
#include "../Components/NetworkNode.cpp"

// SimpleServer opens up a simple server and just prints the responses
class SimpleServer: public NetworkNode {
	int bufferSize;

public:
	//TODO: define need for a constructor
	SimpleServer(std::string serviceDescriptor) {
		super(serviceDescriptor);
		bufferSize = 2048;
	};

	SimpleServer(std::string serviceDescriptor, unsigned int bufferSize){
		this->bufferSize = bufferSize;
		super(serviceDescriptor);
	};

	void processInput(int &clientfd){
		char readbuffer[bufferSize];
		int numRead = read(clientfd, readbuffer, bufferSize);
		if (numRead < 0) {
			perror("ERROR attempting to read incoming client message");
			return;	
		}

		printf("%s", readbuffer);
		printf("\n");
		return;
	};
};
