#include <stdio.h>
#include <stdlib.h>

//Utility functions for the NetworkManager
int checkPort(char* strport) {
  try {
    int numPort = atoi(strport);
    if (numPort < 0 || numPort > 65535) return -1;

    return numPort;
  } catch (std::exception e) {
    // TODO return or print an error here of some sort
    return -2;
  }
};
