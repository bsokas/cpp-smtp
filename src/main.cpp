#include <iostream>
#include <cstdio>
#include "Networking/Nodes/simpleServer.cpp"

int main(int argc, char** argv) {
	std::cout<<"******Setting up cpp-smtp program*****\n\n";

  SimpleServer *simpserv = new SimpleServer("Test-Server");

  simpserv->print();
  simpserv->runServer();

	return 0;
}
