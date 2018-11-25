#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
  char *var, *value;
  if(argc == 1 ||argc >3){
    fprintf(stderr,"usage: %s var [value]\n",argv[0]);
    exit(1);
  }
  var = argv[1];
  value = getenv(var);
  if(value)
    printf("Variable %s has avlue %s\n", var, value);
  else
    printf("Variable %s has no value\n", var);


  if(3 == argc) {
    char *string;
    value = argv[2];
    string = (char *)malloc(strlen(var)+strlen(value)+2);
    if(!string){
      fprintf(stderr,"out of memory\n");
      exit(1);
    }
    strcpy(string,var);
    strcat(string,"=");
    strcat(string,value);
    printf("Calling put enve with : %s \n",string);
    if(0 != putenv(string) ) {
      fprintf(stderr,"putenv failed\n");
      free(string);
      exit(1);
    }
    value = getenv(var);
    if(value)
      printf("New value of %s is %s \n",var ,value);
    else
      printf("New value of %s is null?? \n",var );
  }
  exit(0);
}
