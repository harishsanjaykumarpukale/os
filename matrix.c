#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char* argv[])
{
int i,j,r,c,a[10][10],b[10][10],res[10][10];

r=atoi(argv[1]);

c=atoi(argv[2]);

printf("\n Enter the first matrix:\n");

for(i=0;i<r;i++)
	for(j=0;j<c;j++)
		scanf("%d",&a[i][j]);
printf("\n Enter the second matrix:\n");

for(i=0;i<r;i++)
        for(j=0;j<c;j++)
                scanf("%d",&b[i][j]);



for(i=0;i<r;i++)
        for(j=0;j<c;j++)
                res[i][j]=a[i][j]+b[i][j];

printf("\n MATRIX SUM IS :\n");

for(i=0;i<r;i++){
        for(j=0;j<c;j++)
                printf("%d\t",res[i][j]);
printf("\n");}

}




