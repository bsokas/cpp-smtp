#include <cstdlib>
#include <cstdio>
#include <netinet/in.h>
#include <sys/socket.h>

// Local imports
#include "NetworkState.hpp"
#include "../Utilities/nodeUtils.hpp"

using namespace nodeUtils;
class NetworkNode {
  static NetworkState *netstate;
  int* port;
  int socketfd;
  std::string serviceDescriptor;
  struct sockaddr_in serverAddress, clientAddress;

protected:
  void resetServer(){
    bzero((char *)&serverAddress, sizeof(serverAddress)); //zero out the serverAddress
    serverAddress.sin_family = AF_INET;   //inet addr family
    serverAddress.sin_port = htons(*port); //server address port
    serverAddress.sin_addr.s_addr = INADDR_ANY; //stores IP address of the host
  }

public:
  // Non-arg constructor, ideal for system automation
  NetworkNode(std::string serviceDescriptor){
    netstate=NetworkState::getInstance();
    this->serviceDescriptor = serviceDescriptor;
    port=netstate->obtainPort(serviceDescriptor);
  };

  void openServer(){
    socketfd = socket(AF_INET, SOCK_STREAM, 0); //alt to SOCK_STREAM is SOCK_DGRAM
    if (socketfd < 0){
      perror("Encountered error attempting to open listener for service: ");
      printf("%s\n", serviceDescriptor.c_str());
    }
    resetServer();
    if (bindSocketToAddr(socketfd, &serverAddress, sizeof(serverAddress)) == -1){
      perror("Encountered error attempting to bind socket on service descriptor ");
      printf("%s\n", serviceDescriptor.c_str());
    }

    listen(socketfd, 5); //start listening, set maxinum number of connections allowed while processing other req
  };

  ~NetworkNode(){
    netstate->retirePort(port);
  };

};
