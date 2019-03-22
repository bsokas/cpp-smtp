#include <sys/socket.h>

namespace nodeUtils
{
  char bindSocketToAddr(int &socketfd, struct sockaddr_in* socketAddress, socklen_t socketSize){
  if (bind(socketfd, (struct sockaddr*) socketAddress, socketSize) < 0) {
    return -1;
  }

  return 0;
};

}
