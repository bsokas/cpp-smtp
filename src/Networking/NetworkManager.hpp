#include <stdio.h>
#include <stdlib.h>
#include "RootServer.hpp"
#include "Utilities/networkManager.hpp"

#define DEFAULT_PORT 8080
/**
  * NetworkManager controls the setup and runningn of a network
**/
class NetworkManager {
  int port;
  RootServer *root;

public:
  NetworkManager(){
    port = DEFAULT_PORT;
    root = new RootServer(port);
  };

  void setPort(char* port) {
    int numPort = checkPort(port);
    if (numPort < 0){
      std::cout<<"Invalid port number entered, setting to default port 8080\n";
    } else {
      std::cout<<"Network Manager using port "<<port<<std::endl;
      this->port = numPort;
    }
  };

  void listen(){
    root->run();
  }

  // TODO fill destructor
  ~NetworkManager(){
    delete root;
  };

};
