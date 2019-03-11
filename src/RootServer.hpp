#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>

#define DEFAULT_PORT 8080

class RootServer {
  std::string serverName;
  int port, socketfd;
  bool isStream;

public:
  //RootServer constructor
  RootServer(){
    port = DEFAULT_PORT;
    isStream = true;
  };

  //RootServer constructor w/ port and streamtype
  RootServer(unsigned int port, bool &isStream){
    this->port = port;
    this->isStream = isStream;
  };

};
