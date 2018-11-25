#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _BSD_SOURCE
int main(int argc,char *argv[])
{
  char computer[256];
  struct utsname uts;
  if( 0 != gethostname(computer,255) || uname(&uts) < 0) {
    fprintf(stderr,"could not get host information\n");
    exit(1);
  }
  printf("Computer host name is %s\n",computer);
  printf("System is %s on %s hardware\n",uts.sysname,uts.machine);
  printf("Nodename is %s\n",uts.nodename);
  printf("Version is %s, %s \n",uts.release,uts.version);
  
  exit(0);
}
