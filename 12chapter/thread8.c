#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define NUM_TRHEADS 6


void *thread_function(void *arg);

char message[] = "Hello world";
int thread_finished = 0;

int main()
{
  int res;
  pthread_t a_thread[NUM_TRHEADS];
  void * thread_result;
  int losts_of_threads;
  for(losts_of_threads = 0; losts_of_threads <NUM_TRHEADS;losts_of_threads++){
    res = pthread_create(a_thread+losts_of_threads,NULL,
			 thread_function,(void *)&losts_of_threads);
  if(res!=0){
    perror("Attribute creation failed");
    exit(EXIT_FAILURE);
  }
      sleep(1);
  }
  for(losts_of_threads=NUM_TRHEADS -1;losts_of_threads >=0;
      losts_of_threads--){
    res = pthread_join(*(a_thread+losts_of_threads),&thread_result);
    if(res  == 0){
      printf("Picked up a thread\n");
    }
     else{
	perror("pthread_join failed");
      }
  }
  
    printf("All done\n");
    exit(EXIT_SUCCESS);
}
void * thread_function(void *arg){
  int my_number = *(int *)arg;
  int rand_num;
    printf("thread_function is running .Arugment was %d\n",my_number);
    rand_num = 1+ (int)(9.0*rand()/RAND_MAX +1.0);
    sleep(rand_num);
    printf("bye from %d \n",my_number);

    pthread_exit(NULL);
}
