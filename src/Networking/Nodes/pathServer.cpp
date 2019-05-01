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
  };

  void runServer(){
    startServer();
    pathListener();
  };

  void pathListener(){
    while (1) {
      // struct sockaddr_in *clientAddr;
      struct msghdr header;
      int msglen = recvmsg(socketfd, &header, MSG_PEEK);
      if (msglen > 0) {
        printf ("Incoming msg w/ length: %d", msglen);
      } else {
        printf("Incoming msg registered as %d\n", msglen);
        return;
      }
    }
  };

  void print(){
    printf("Path Server %s has port %hu reserved\n", serverName.c_str(), port);
  }

};
