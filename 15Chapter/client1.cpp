#include<sys/types.h>
#include<sys/un.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
  int sockfd;
  int len;
  struct sockaddr_un address;
  int result;
  char  ch = 'A';

  //create a socket for the client
  sockfd = socket(AF_UNIX,SOCK_STREAM,0);
  //name the socket as agreed with the server
  address.sun_family = AF_UNIX;
  strcpy(address.sun_path,"server_socket");
  len = sizeof(address);
  //connect your socket to the server's socket
  result = connect(sockfd,(struct sockaddr*)&address,len);
  if(result == -1){
    perror("oops, client1");
    exit(1);
  }
  //you can now read and write via sockfd;
  write(sockfd,&ch,1);
  read(sockfd,&ch,1);
  printf("char from server =%c\n",ch);
  close(sockfd);
  exit(0);
}
