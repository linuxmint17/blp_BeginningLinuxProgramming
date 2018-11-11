#include<unistd.h>
#include<stdlib.h>
int main(int argc,char **argv)
{

  if(argc!=2)
    {
      exit(0);
    }
  if((write(1,"Here is some data\n",18))!=atoi(argv[1]))
    {
      write(2,"A write error has occurred on file descriptor 1\n",46);
    }
    exit(0);
}
