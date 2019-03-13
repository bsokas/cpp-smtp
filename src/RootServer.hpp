#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>

class RootServer {
  std::string serverName;
  int port, socketfd, numWritten;
  bool isStream;
  char buffer[256]; //for reading content in
  struct sockaddr_in serverAddress;
  struct hostent *caller;

public:
  //RootServer constructor
  RootServer(int &port){
    this->port = port;
    isStream = true;
  };

  char listen(){
    socketfd = socket(AF_INET, SOCK_STREAM, 0); //(addr domain, stream type, protocol type TCP/UDP)
    if (socketfd < 0){
      std::cout<<"Error with socket connector. Closing program\n\n";
      return -1;
    }

    return 0;
  };
};
