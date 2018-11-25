#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc,char *argv[])
{

  uid_t uid;
  gid_t gid;

  struct passwd *pw;
  uid = getuid();
  gid = getgid();
  
  printf("User is %s\n",getlogin());
  printf("user IDs:uid =%d,gid =%d\n",uid,gid);

  pw = getpwuid(uid);
  printf("UID passwd entry:\n name = %s,uid = %d,gid = %d, home =%s ,shell =%s \n",
	 pw->pw_name,pw->pw_uid,pw->pw_gid,pw->pw_dir,pw->pw_shell);

  pw = getpwnam("root");
  printf("name=%s, uid=%d, gid=%d, home=%s, shell=%s\n",
	 pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);
  
  exit(0);
}
