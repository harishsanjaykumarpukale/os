#include<stdio.h>
#include<uni
void main()
{
int pid,R;

if (pid ==0)
{
 printf("\nI am child \n My process id is %d\nMy parent's process id is %d",getpid(),getppid());
 execlp("./hp.o",NULL,NULL);
 
}


else if(pid>0)
{
R=wait(NULL);
printf("\nI am parent ,my process id is %d\n ",getpid());

}

else
{
printf("\nError in creating Child process\n");

}

}

