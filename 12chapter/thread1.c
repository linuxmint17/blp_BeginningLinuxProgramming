#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void *thread_function(void *arg);
char message[]="hello world";

int main()
{
  int res;
  pthread_t a_thread;
  void *thread_result;
  res = pthread_create(&a_thread,NULL,thread_function,(void*)message);
  if(res != 0){
    perror("Thread creation failed");
    exit(EXIT_FAILURE);
  }
  printf("Waiting fo thread to finish .. \n");
  res = pthread_join(a_thread,&thread_result);
  if(0 != res){
    perror("Thread join failed");
    exit(EXIT_FAILURE);
  }
  printf("THread joined it returned %s \n",(char *)thread_result);
  printf("Message is now %s \n",message);
  exit(EXIT_SUCCESS);

}
void *thread_function(void *arg){
  
  printf("thread_function is running.Argument was %s \n",(char *)arg);
  sleep(3);
  strcpy(message,"Bye!");
  pthread_exit("Thank you for the CPU time");
  
}
