//Queue using Array

#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int front;
	int rear;
	int capacity;
	int size;
	int* array;
};
struct queue *Q;
void show(void);
void enqueue(void);
void dequeue(void);
void print(void);

int main()
{
	printf("Creating a Queue:\n");
	Q=(struct queue*)malloc(sizeof(struct queue));

	Q->front=-1;
	Q->rear=-1;
	Q->capacity=30;
	Q->size=0;
	Q->array=(int*)malloc(Q->capacity*sizeof(int));

	show();
}
void show(void)
{
        int num;
        printf("Enter the choice(0 to exit)");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Print  ");

        scanf("%d",&num);

        switch(num)
        {
                case 1: enqueue();
                        break;
                case 2: dequeue();
                        break;
                case 3: print();
                        break;
                case 0: exit(0);
        }
}
void enqueue(void)
{
	int item;
	printf("Enter the value: ");
	scanf("%d",&item);

	if(Q->size==30)
	 {
                        printf("Queue is full\n");
                        show();
                        return;
        }

	if(Q->rear==-1)
	{
		Q->front=0;
		Q->rear=0;
		Q->array[Q->rear]=item;
		Q->size=(Q->size)+1;
		show();
		return;
	}
	
	Q->rear = (Q->rear + 1)%Q->capacity; 
    	Q->array[Q->rear] = item; 
	Q->size=(Q->size)+1;
    	printf("Done\n"); 

	show();
	return;

} 
void dequeue(void) 
{ 
	if(Q->size==0)
	{
			printf("Queue is empty\n");
			show();
			return;
	}

	if(Q-size==1)
	{
		Q->front=-1;
		Q->rear=-1;
		Q->size=0;
		show();
		return;
	}
	else
{
    	int item = Q->array[Q->front]; 
    	Q->front = (Q->front + 1)%Q->capacity;
    	printf("%d is dequeued",item);
	Q->size=(Q->size)-1;
}
	
	show();
	return;
}
void print(void)
{
	int temp=Q->front;
	int x=0;
        if(Q->size==0)
        {
		{
                printf("Queue is empty\n");
                show();
                return;
		}
        }

	for(int i=0;i<Q->size;i++)
	{
		printf("->%d",Q->array[temp]);
		temp=(temp+1);
	}
	printf("\n");	
	show();
	return;
}
