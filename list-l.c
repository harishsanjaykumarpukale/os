#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<unistd.h>

char p[10]="rwxrwxrwx";

void main(int argc,char *argv[])
{int i,j;
 struct stat statv;
 struct passwd *pw_p;
 struct group *gr_p;
 int st_mode;
 char amode[10];
 if(lstat(argv[1],&statv)==-1)
   {printf("error in opening\n");
   exit (0);
   }
 st_mode=statv.st_mode;
switch(st_mode&S_IFMT)
  {case S_IFDIR:printf("d");
                break;
   case S_IFREG:printf(".");
	        break;
   case S_IFLNK:printf("l");
		break;
  }
for(i=0,j=(i<<8);i<9;i++,j>>=1)
   amode[i]=(st_mode&j)?p[i]:'-';
   amode[10]='\0';
   printf("%s",amode);
   gr_p=getgrgid(statv.st_gid);
   pw_p=getpwuid(statv.st_uid);
   printf("%s",pw_p->pw_name);
   printf("%s",gr_p->gr_name);
   printf("%d",(int)statv.st_size);
   printf("%s\n\n\n",argv[1]);
}

