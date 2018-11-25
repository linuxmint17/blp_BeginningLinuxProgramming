#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[])
{

  time_t timeval;

  (void) time(&timeval);
  printf("The date is :%s",ctime(&timeval));
  exit(0);
}
