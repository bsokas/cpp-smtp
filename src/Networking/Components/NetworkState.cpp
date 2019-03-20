#include <stdio.h>
#include <stdlib.h>
#include <csignal>
#include <map>
#include <vector>

#define START_PORT 8100

class NetworkState {
  //Singleton instance for maintaining network state
  static NetworkState *netstate;
  static unsigned char created;
  int portavail;
  std::map<int, std::string> serviceMap;
  std::vector<int*> retiredPorts;

  NetworkState(){
    created = 1;
    portavail = START_PORT;
  };

  void fileService(int *newport, std::string serviceDescriptor){
    serviceMap[*newport] = serviceDescriptor;
  };

public:
  static NetworkState* getInstance(){
    if (created != 1) {
      netstate = new NetworkState();
    }
    return netstate;
  };

  int* obtainPort(std::string serviceDescriptor){
    int* newport = new int;
    if (!retiredPorts.empty()) {
      newport = retiredPorts.back();
      retiredPorts.pop_back();
    } else {
      *newport = portavail++;
    }

    fileService(newport, serviceDescriptor);
    return newport;
  };

  void retirePort(int *port) {
    // TODO use csignal to kill the process
    retiredPorts.push_back(port);
  }

  void print(){
    std::cout<<"*****PORTS IN USE*****\n";
    std::cout<<"PORT\t\tUSER\t\n";
    for(std::map<int, std::string>::iterator i=serviceMap.begin(); i!=serviceMap.end(); ++i) {
      std::cout<<i->first<<"\t\t"<<i->second<<"\n";
    }
  }

  ~NetworkState(){}

};
