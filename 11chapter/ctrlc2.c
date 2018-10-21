#include<unistd.h>
#include<stdio.h>
#include<signal.h>
/*using the *nix recommended interface*/
void ouch(int sig)
{
  fprintf(stdout,"OUCH! - I got signal %d\n",sig);

}
int main()
{
  struct sigaction act;
  
  act.sa_handler = ouch;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

  sigaction(SIGINT,&act,0);
  while(1){
    fprintf(stdout,"hello world!\n");
    sleep(1);
  }
  
}
