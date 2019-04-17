#include <iostream>
#include <cstdio>
#include "Networking/Interfaces/NetworkNode.cpp"

int main(int argc, char** argv) {
	std::cout<<"******Setting up cpp-smtp program*****\n\n";

  NetworkNode *node = new NetworkNode("Test-Service");
  node->startServer();

	return 0;
}
