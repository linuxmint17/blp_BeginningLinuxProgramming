#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int opt;
	while(-1 != (opt=getopt(argc,argv,":if:lr"))) {
		switch(opt) {
			case 'i':
			case 'l':
			case 'r':
				printf("option: %c\n",opt);
				break;
			case 'f':
			  printf("filename:%s \n",optarg);
			  break;
         		case ':':
	        	  printf("option needs a value \n");
		          break;
         		case '?':
	        	  printf("unkonwn option: %c \n",optopt);
		          break;
         		}
	}
		for(;optind<argc;optind++)
		  printf("argument :%s \n",argv[optind]);
		  exit(0);
}
