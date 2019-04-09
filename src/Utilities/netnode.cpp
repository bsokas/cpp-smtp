#include <iostream>
#include <string>

void printNodeInit(unsigned short int &port, std::string &serviceName){
  printf("Network node provisioned on port %u", port);
  if (serviceName.length() > 0){
    printf("Name: %s", serviceName);
  }
}
