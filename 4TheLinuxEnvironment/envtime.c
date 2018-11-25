#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc,char *argv[])
{
  int i;
  time_t the_time;
  for(i = 1;i <= 10; i++) {
    the_time = time((time_t *)0);
    sleep(1);
  }
  time_t new_time=time((time_t *)0);
  printf("total used time is %d seconds\n",difftime(new_time,the_time));

  exit(0);
}
