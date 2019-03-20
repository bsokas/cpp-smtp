#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define DEFAULT_RESP "You've connected with the server!"


void sendDefaultResponse(int &clientfd){
  send(clientfd, DEFAULT_RESP, sizeof(DEFAULT_RESP), 0);
};

void parseRequest(int &clientfd){
  int readNum = 2048;
  char buffer[readNum];
  int numRead = read(clientfd, buffer, readNum);
  if (numRead > 0){
    printf("%s\n", buffer);
  }

  sendDefaultResponse(clientfd);
};
