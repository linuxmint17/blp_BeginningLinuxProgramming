#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<semaphore.h>

void *thread_function(void *arg);
pthread_mutex_t work_mutex;/*protects both work_area and time_to_exit*/

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main()
{
  int res;
  pthread_t a_thread;
  void *thread_result;
  
  res = pthread_mutex_init(&work_mutex,NULL);
  if(res != 0){
    perror("mutex initialization faiiled");
    exit(EXIT_FAILURE);
  }
  
  res = pthread_create(&a_thread,NULL,thread_function,NULL);
  if(res != 0){
    perror("Thread creation failed");
    exit(EXIT_FAILURE);
  }
  
  pthread_mutex_lock(&work_mutex);
  printf("Input some text. enter 'end' to finish \n");
  while(!time_to_exit){
    fgets(work_area,WORK_SIZE,stdin);
    pthread_mutex_unlock(&work_mutex);
    while(1){
      pthread_mutex_lock(&work_mutex);
      if(work_area[0] != '\0'){
	pthread_mutex_unlock(&work_mutex);
	sleep(1);
      }
      else{
	break;
      }
    }
    pthread_mutex_unlock(&work_mutex);
  }
  
  printf("\n waiting for thread to finish...\n");
  res = pthread_join(a_thread,&thread_result);
  if(0 != res){
    perror("Thread join failed");
    exit(EXIT_FAILURE);
  }
  printf("thread joined \n");
    pthread_mutex_destroy(&work_mutex);
  exit(EXIT_SUCCESS);

}
void *thread_function(void *arg){
  sleep(1);
  pthread_mutex_lock(&work_mutex);
  while(strncmp("end",work_area,3)!=0){
    
    printf("you input %d characters \n",strlen(work_area) -1);
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while(work_area[0] =='\0'){
      pthread_mutex_unlock(&work_mutex);
      sleep(1);
      pthread_mutex_lock(&work_mutex);
  }
    time_to_exit = 1;
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
  }    
  pthread_exit(0);
}
