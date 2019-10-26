#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
 int isprime(int a)
{int i,flag=0;
 for(i=2;i<a;i++)
     if(a%i==0)
	{flag=1;
	 break;
	}
  if(flag==1)
	return -1;
  else 
	return 1;
}
int main(int argc,char *argv[])
{int i=1,num=2;
 int x=atoi(argv[1]);
 while(i<=x)
 {if(isprime(num)==1)
     {printf("%d\t",num);
      num++;
      i++;
     }
  else
    num++;
 }
 return 0;
}
