#include "inetClient.hh"

#include <iostream>
#include <string.h>

int main(int argc, char* argv[]){
  inetClient cli(512000);
  char* buf = cli.GetBufferPointer();

  char host[256];
 
  std::cout << "Enter host name or ip address: ";
  std::cin >> host;

  cli.Connect(host, 80);

  //char comm[250];
  const char* comm = "GET / HTTP/1.1\r\n\r\n";
  cli.Send(comm, strlen(comm));
  std::cout << "Received " << cli.Receive() << " bytes" << std::endl;;
    
  //receive and echo reply
  std::cout << "----------------------------\n\n";
  std::cout << buf;
  std::cout << "\n\n----------------------------\n\n";
  
  return 0;
}
