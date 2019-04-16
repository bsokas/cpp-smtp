#include <iostream>
#include <string>
#include <sys/types.h>
#include <netinet/in.h>


//Sets required values for server startup
void prepPort(struct sockaddr_in &serverAddress, unsigned short int &port) {
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(port);
  serverAddress.sin_addr.s_addr = INADDR_ANY;
}

int bindSocket(int &socketfd, struct sockaddr_in *serverAddress, socklen_t &addrLen) {
  try {
    return bind(socketfd, (struct sockaddr *) serverAddress, addrLen);
  } catch (std::exception e) {
    return -1;
  }
}
