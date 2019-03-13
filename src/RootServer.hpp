#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>

class RootServer {
  std::string serverName;
  int port, socketfd, clientfd, numRead;
  socklen_t clientSize;
  bool isStream;
  char buffer[256]; //for reading content in
  struct sockaddr_in serverAddress, clientAddress;
  struct hostent *caller;

public:
  //RootServer constructor
  RootServer(int &port){
    this->port = port;
    isStream = true;
  };

  char startListener(){
    socketfd = socket(AF_INET, SOCK_STREAM, 0); //(addr domain, stream type, protocol type TCP/UDP)
    if (socketfd < 0){
      printf("Error with socket connector. Closing program\n\n");
      return -1;
    }

    resetServer();
    if (bindSocket() < 0) return -1;
    listen(socketfd, 5);      //begin listening on provided port
    acceptClient();
    readIn();

    return 0;
  };

  char bindSocket(){
    // bind ropes together the socket file descripto with the address for the server
    if (bind(socketfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0){
      printf("ERROR encountered attempting to bind socket. Closing program. \n\n");
      return -1;
    }

    return 0;
  }

  // Reset the internet socket addresses
  void resetServer(){
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    //use htons to convert from little-endian to big-endian
    //ex: 5001 == 0x1389, normally stored as 0x89 0x13 --> 0x13 0x89
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
  };

  void acceptClient(){
    clientSize = sizeof(clientAddress);
    clientfd = accept(socketfd, (struct sockaddr *) &clientAddress, &clientSize);
    if (clientfd < 0){
      printf("ERROR on accept\n\n");
    }
  };

  void readIn(){
    bzero(buffer, 256);
    std::string msg (buffer, 255);

    printf("Reveived connection!\n");
    printf("Here is the message: %s\n", msg.c_str());
  };
};
