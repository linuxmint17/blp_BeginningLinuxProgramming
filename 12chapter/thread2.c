#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void *thread_function(void *arg);
char message[]="hello world";
int run_now =1;

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
  int print_count1 = 0;
  while(print_count1++ <20){
    if(run_now == 1){
      printf("1");
      run_now = 2;
    }
    else{
      sleep(1);
    }
  }
  printf("\nWaiting fo thread to finish .. \n");
  res = pthread_join(a_thread,&thread_result);
  if(0 != res){
    perror("Thread join failed");
    exit(EXIT_FAILURE);
  }
  printf("Thread joined it returned %s \n",(char *)thread_result);
  printf("Message is now %s \n",message);
  exit(EXIT_SUCCESS);

}
void *thread_function(void *arg){
  int print_count2 = 0;
  while(print_count2++ <20){
    if(2 == run_now ){
      printf("2");
      run_now = 1;
    }
    else {
      sleep(1);
    }
  }
  printf("thread_function is running.\n");
  sleep(3);
  strcpy(message,"Bye!");
  pthread_exit("Thank you for the CPU time");
  
}
