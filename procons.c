#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack
{
	int data[SIZE];
	int top;
};
typedef struct stack STACK;


int i,empty=SIZE,mutex=1,full=0;



void insert(int item,STACK *s)
{
	if (s->top==SIZE-1){
		printf("\nStack is FULL \n");
		}
	else
		s->data[++(s->top)]=item;

}


void delete(STACK *s)
{
	if(s->top==-1){
		printf("\n Stack is empty\n");
		exit(0);
	}
	else
		printf("\n The element deleted is %d ",s->data[s->top--]);
}
int produce_item()
{
	int item;
	printf("\nEnter the next item:\n");
	scanf("%d",&item);
	return item;
}

int wait(int s)
{

	while(s<=0);
	return s-1;
}


int signal(int s)
{
	return s+1;
}



void* producer(void* arg)
{
	STACK *s =(STACK*) arg;
		i=produce_item();
		empty=wait(empty);


		mutex=wait(mutex);

		insert(i,s);

		mutex=signal(mutex);

		full=signal(full);


	pthread_exit(0);
}

void* consumer(void* arg)
{
	STACK *s =(STACK*) arg;
		full=wait(full);

		mutex=wait(mutex);

		delete(s);

		mutex=signal(mutex);

		empty=signal(empty);


	pthread_exit(0);

}

void main()
{
int ch;
pthread_t p,c;


STACK s;
s.top=-1;
for(;;){
printf("\n1.PRODUCE\n2.CONSUME\n3.EXIT\n");
scanf("%d",&ch);
switch(ch)
 {
case 1:
pthread_create(&p,NULL,producer,(void*) &s);
pthread_join(p,NULL);
break;

case 2:
pthread_create(&c,NULL,consumer,(void*) &s);
pthread_join(c,NULL);
break;

default:
exit(0);

 }
}


}
