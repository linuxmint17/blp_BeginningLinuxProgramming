#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char **argv)
{
  if(argc!=2)
    {
      puts(" this program neeed a number as parameter");
    }
  else{
    puts(strerror(atoi(argv[1])));
  }
  return 0;
}
