#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//#define _GNU_SOURCE
int main(int argc,char *argv[])
{
	char tmpname[]="testXXXXXX";

	int tmp_fd=mkstemp(tmpname);

	if(tmp_fd>=0)
	{
		printf("create tmp file successfully\n");
		printf("Temporary file name is :%s\n",tmpname);
	}
	else
	{

		perror("failed\n");
 	}
	int ret =write(tmp_fd,"hahaha i'm inside tmpfile",strlen("hahaha i'm inside tmpfile"));
       	
	if(ret<0)
	{
		perror("error when write file\n");
	}
	else
	{
		printf("write %d into tmpfile %s\n",ret,tmpname);
	}
	ret= lseek(tmp_fd,0,SEEK_SET);
	if(ret<0)
	{
		perror("error when seek file\n");
	}
	else
	{
		printf("seek file offset to 0 %s\n",tmpname);
	}
	
	char tmpbuf[512]={0};
	ret = read(tmp_fd,tmpbuf,10);
	if(ret<=0)
	{
		perror("error when read file\n");
	}
	else
	{
		printf("read %d from tmpfile %s\n",ret,tmpname);
		printf("the content is %s\n",tmpbuf);
	}
	ret =close(tmp_fd);
	if(ret<0)
	{

		perror("error when closing  file\n");
		
	}
	else
	{
		printf("close tmpfile  %s successfully\n",tmpname);
	}
	memset(tmpbuf,0,sizeof(tmpbuf));
	//	ret = getwd(tmpbuf);
       char *currentpath=get_current_dir_name();

	sprintf(tmpbuf,"%s/%s",currentpath,tmpname);
	free(currentpath);
	puts(tmpbuf);
	ret=remove(tmpbuf);
        if(ret<0)
	{

		perror("error when remove  file\n");
		
	}
	else
	{
		printf("rm tmpfile  %s successfully\n",tmpfile);
	}
	
		
  exit(0);
}
