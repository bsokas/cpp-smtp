#include <string>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "../Interfaces/NetworkNode.cpp"
#define DEFAULT_MSG "Simple Server message"

class SimpleServer: public NetworkNode {
  std::string serverName;
  std::string indexPath;
  unsigned short int defaultBufferSize;

public:
  SimpleServer(std::string serverName){
    defaultBufferSize = 300;
    indexPath = "UI/index.html";
    this->serverName = serverName;
    this->port = this->netstate->getNetworkPort(serverName);
  };

  void runServer(){
    startServer();
    threadlessListener();
  };

  //listens for and processes incoming connections w/o threads
  void threadlessListener(){
    char buffer[defaultBufferSize];
    bzero(buffer, defaultBufferSize);

    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientfd;

    while(1) {
      clientfd = accept(socketfd, (struct sockaddr *) &clientAddr, &clientAddrSize);
      if (clientfd < 0) {
        perror("Simple server encountered error attempting to accept connection\n");
      }

      respond(clientfd);
    }
  };

  char simpleReader(int &fd, char* bufferStart, int bufferSize = 0){
      if (bufferSize <= 0) bufferSize = defaultBufferSize;

      int numRead = read(fd, bufferStart, bufferSize);
      if (numRead < 0) {
        perror("Simple server input reader unable to parse input\n");
        return numRead;
      } else if (numRead == 0) {
        printf("Simple server read 0 bytes. Either at end of input or empty message\n");
        return numRead;
      }

      printf("Incoming Message: \n%s\n", bufferStart);
      return 0;
  };

  void respond(int &clientfd){
    try {
      std::fstream indexFile;
      indexFile.open(indexPath, std::ios::in);
      char buffer[defaultBufferSize];
      indexFile.read(buffer, defaultBufferSize);

      int written = write(clientfd, buffer, defaultBufferSize);
      if (written <= 0) throw "Unable to write to client\n";
      printf("Simple Server wrote default message\n");
    } catch (std::exception e) {
        printf("Error writing to socket: %s\n", e.what());
        return;
    }
  }

  void print(){
    printf("Simple server %s setup on port %hu\n", serverName.c_str(), port);
    printf("If running on a local deployment, access server at localhost:%hu\n", port);
  };

  ~SimpleServer(){};
};
