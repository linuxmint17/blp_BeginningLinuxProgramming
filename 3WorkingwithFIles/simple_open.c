#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#define  LEN  50
int main(int argc,char **argv)
{
  (void)argc;  (void)argv;
  char filename[LEN] ="/dev/testdev";
 int fd= open(filename,O_CREAT,S_IRUSR|S_IXOTH);
 if(fd>=0){
   fprintf(stdout,"create file successfully!\n");
   }
 else
   {
     fprintf(stderr,"failed to create file %s, errno is %d \n",filename,errno);
   }
   int ret = close(fd);
   if(ret>= 0 ){
     fprintf(stdout,"close file %s successfully\n",filename);
   }
   else{
     fprintf(stderr,"error when close file %s ,errno is %d  ",filename,errno);
   }
  

  return 0;
}
