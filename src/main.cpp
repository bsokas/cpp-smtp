#include <iostream>
// #include "Networking/NetworkManager.hpp"
#include "Networking/Components/NetworkNode.cpp"
#include "Networking/Nodes/SimpleServer.hpp"

int main(int argc, char** argv){
  std::cout<<"******Starting cpp-smtp server*****\n\n";

  if (argc < 2) {
    std::cout<<"Input improper number of arguments. Please include a port number\n\n";
    return -1;
  } else if (argc > 2) {
    std::cout<<"Excessive number of arguments. Please include a single port number.\n\n";
    return -1;
  }

  std::string sd = "Simple Server";
  SimpleServer *server = new SimpleServer(sd);
  server->openServer();

  return 0;
}
