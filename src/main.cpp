#include <iostream>
#include <cstdio>
#include "Networking/NetworkState.cpp"

int main(int argc, char** argv) {
	std::cout<<"******Setting up cpp-smtp program*****\n\n";
	// NetworkState::getInstance();
	NetworkState *netstate = NetworkState::getInstance();
	unsigned short int firstPort = netstate->getNetworkPort();
  printf("Application provided port %d\n\n", firstPort);

	netstate->print();

	return 0;
}
