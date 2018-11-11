#include<stdio.h>
//you must input "Hello 234"or something like this
int main(){
int num;
//scanf("Hello %d",&num);
//printf("num= %d\n",num);
 char s[256];
 int n;
 float f;
 char c;
 //input like this
 //Hello, 1234, 5.678, X, string to the end of the line
 //scanf("Hello,%d,%g, %c, %[^\n]",&n,&f,&c,s);
 // printf("n=%d f= %f c= %c ,s= %s \n",n,f,c,s);
 char *cptr;
 //scanf("Hello,%s",cptr);
 // printf(" %s\n",cptr);
 scanf("%[^]0-9-]",s);
 
 printf("s= %s\n",s);
return 0;
}
