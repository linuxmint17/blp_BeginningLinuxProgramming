#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<stdlib.h>
void printdir(char *dir,int depth)
{
  DIR *dp;
  struct dirent *entry;
  struct stat statbuf;
  if((dp = opendir(dir)) ==NULL){
    fprintf(stderr,"cannot open directory\n");
    return ;
  }
  chdir(dir);
  while((entry = readdir(dp))!=NULL){
    lstat(entry->d_name,&statbuf);
    if(S_ISDIR(statbuf.st_mode)){
      /* Found a directory ,but ignore . and .. */
      if(strcmp(".",entry->d_name) == 0 ||
	 strcmp("..",entry->d_name)==0)
	continue;
      printf("%*s%s/\n",depth,"",entry->d_name);
      continue;
      /*Recurse at a new indent level */
	     printdir(entry->d_name,depth+4);
    }
    else printf("%*s%s\n",depth,"",entry->d_name);
  }
  chdir("..");
  closedir(dp);
}
int main(int argc,char **argv)
{
  if(2!=argc)
    {
      printf("%s need a parameter like %s /home \n ",argv[0],argv[0]);
      exit(0);
    }
  else
    {
      printdir(argv[1],0);
      exit(0);
    }
}
      
