#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void ouch(int sig)
{
  fprintf(stdout,"OUCH! - I got signal %d\n",sig);
  /* if you uncomment the line below it will behavior differently*/
  /*  (void) signal(SIGINT,SIG_DFL);*/
}
int main()
{
  (void)signal(SIGINT,ouch);
  while(1){
    fprintf(stdout,"hello world!\n");
    sleep(1);
  }
  
  exit(0);
}
