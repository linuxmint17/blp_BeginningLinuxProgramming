#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define _XOPEN_SOURCE 600
#include <time.h>
int main(int argc,char *argv[])
{

  struct tm *tm_ptr, timestruct;
  time_t the_time;
  char buf[256];
  char *result;
  (void) time(&the_time);
  tm_ptr = localtime(&the_time);
  
  strftime(buf,256,"%A %d %B, %I:%S %p",tm_ptr);
  printf("strftime gives : %s\n",buf);

  strcpy(buf,"Thu 25 Nov 2017,17:53 will do fine");

  printf("calling strptime with:%s\n",buf);
  tm_ptr = &timestruct;
  
 result =  strptime(buf,"%a %d %b %Y %R",tm_ptr);
 if( NULL== result)
 {
	 printf("reuslt is null\n");
 }
 else
 {
  printf("strptime consumed up to: %s\n",result);
 }
						 
  printf("date:%02d/%02d/%02d\n",
	 tm_ptr->tm_year%100,tm_ptr->tm_mon+1,tm_ptr->tm_mday);
  printf("time:%02d:%02d\n",
	 tm_ptr->tm_hour,tm_ptr->tm_min);
  exit(0);
}
