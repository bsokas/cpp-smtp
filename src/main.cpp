#include <iostream>
#include <cstdio>
#include "Networking/Nodes/simpleServer.cpp"
#include "Networking/Nodes/pathServer.cpp"

int main(int argc, char** argv) {
	std::cout<<"******Setting up cpp-smtp program*****\n\n";

  SimpleServer *simpserv = new SimpleServer("Test-Simple-Server");
  simpserv->print();

  PathServer *pathserv = new PathServer("Test-Path-Server");
  pathserv->print();
  pathserv->runServer();

	return 0;
}
