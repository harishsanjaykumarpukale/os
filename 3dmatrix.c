#include<stdio.h>
#include<stdlib.h>

void main()
{
int mat[2][2][2],i,j,k;

printf("\nEnter the elements :\n");


for(i=0;i<2;i++)
	for(j=0;j<2;j++)
		for(k=0;k<2;k++)
			scanf("%d",&mat[i][j][k]);



for(i=0;i<2;i++)
        for(j=0;j<2;j++)
                for(k=0;k<2;k++)
                        printf("%d\n",mat[i][j][k]);

}
