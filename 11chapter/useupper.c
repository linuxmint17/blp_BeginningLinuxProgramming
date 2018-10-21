#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char ** argv)
{
  char *filename;
  if(2!=argc){
    fprintf(stderr,"usage: useupper file\n");
      exit(1);
    }
  filename = argv[1];
  if(!freopen(filename,"r",stdin)){
    fprintf(stderr,"could not redirect stdin from file %s\n",filename);
    exit(2);
  }
  execl("./upper.exe","uppser.exe",0);
  perror("could not exec ./upper.exe");
  exit(3);

}
