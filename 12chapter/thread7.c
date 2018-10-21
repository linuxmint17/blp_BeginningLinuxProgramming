#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "Hello World";
int thread_finished = 0;

int main() {
    int res;
    pthread_t a_thread;
    void *thread_result;

    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    sleep(3);
    printf("canceling thread ..\n");
    res=pthread_cancel(a_thread);
    if (res != 0) {
        perror("Thread cancelation failed");
        exit(EXIT_FAILURE);
    }
    
    printf("waiting for thread to finish..\n");
    res = pthread_join(a_thread,&thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
  int i, res;
  res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
  if(res != 0){
    perror("Thread pthread_setcancelstate failed");
    exit(EXIT_FAILURE);
  }
  res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
    if(res != 0){
    perror("Thread pthread_setcanceltype failed");
    exit(EXIT_FAILURE);
  }

    printf("thread_function is running. ");
    for(i = 0;i<10;i++){
      printf(" thread is still running %d\n",i);      
      sleep(1);
    }
   
    pthread_exit(NULL);
}