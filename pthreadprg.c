#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* display(void* p)
{
int (*ptr)[2][2][2]=(int*) p;
int i,j,k;

printf("\nThe first matrix is :\n");
for(i=0;i<1;i++)
for(j=0;j<2;j++)
{
for(k=0;k<2;k++)
printf("\t%d\t",*(*(*(*(ptr+i)+j)+k)));
printf("\n");
}

//((*(ptr+0)+j)+k)
printf("\nThe second matrix is :\n");

for(j=0;j<2;j++)
{
for(k=0;k<2;k++)
printf("\t%d\t",*(*(*(*(ptr+1)+j)+k)));
printf("\n");
}

}
void main()
{

pthread_t p,d;

int mat[2][2][2],i,j,k,*p1,p2;


printf("\nEnter the elements of first matrix of order 2x2: \n");


for(j=0;j<2;j++)
for(k=0;k<2;k++)
scanf("%d",&mat[0][j][k]);








printf("\nEnter the elements of second matrix: \n");


for(j=0;j<2;j++)
for(k=0;k<2;k++)
scanf("%d",&mat[1][j][k]);



p1=&mat[0][0][0];

pthread_create(&d,NULL,display,(void*) p1);

pthread_join(d,NULL);


pthread_exit(NULL);

}
