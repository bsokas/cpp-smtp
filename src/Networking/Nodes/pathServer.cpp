#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//PathServer provides simple functionality
//at a handful of different paths
class PathServer: public NetworkNode {
  std::string serverName;

public:
  PathServer(std::string serverName){
    this->serverName = serverName;
  }

  void runServer(){
    startServer();
    pathListener();
  }

  void pathListener(){
    while (1) {
      struct sockaddr_in *clientAddr;
      int clientfd = recvmsg(socketfd, (struct sockaddr *) clientAddr, MSG_PEEK);
      if (clientfd > 0) {
        printf ("Incoming msg w/ length: %d", clientfd);
      }
    }
  }

}
