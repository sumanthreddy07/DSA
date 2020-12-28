//Linear Queue using LL

#include<stdio.h>
#include<stdlib.h>

void show(void);
void enqueue(void);
void dequeue(void);
void print(void);
struct linknode
{
	int n;
	struct linknode *next;
};
struct queue 
{
	struct linknode *front;
	struct linknode *rear;
};
struct queue *Q;
int main()
{
	printf("Creating a Queue: \n");
	Q=(struct queue*)malloc(sizeof(struct queue));
	Q->front=Q->rear=NULL;
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
	struct linknode *newnode;
	newnode=(struct linknode*)malloc(sizeof(struct linknode));
	
	printf("Enter the value: ");
	scanf("%d",&newnode->n);


	if(Q->rear==NULL)
	{
		Q->front=newnode;
		Q->rear=newnode;
	}
	else
	{
		Q->rear->next=newnode;
		newnode->next=NULL;
		Q->rear=newnode;
	}
	printf("Done\n");
	show();
	return;
}
void dequeue(void)
{
	if(Q->front==NULL)
	{
		Q->rear=NULL;
		printf("The Queue is Empty\n");
		show();
		return;
	}
	struct linknode *temp;
	temp=Q->front->next;
	free(Q->front);
	Q->front=temp;

	printf("dequeued\n");
	show();
	return;
}

void print(void)
{
	struct linknode *temp;
	temp=Q->front;

	if(temp==NULL)
	{
		printf("Queue is empty\n");
		show();
		return;
	}
	while(Q->rear!=temp)
	{
		printf("->%d",temp->n);
		temp=temp->next;
	}
	if(Q->rear!=NULL)
		printf("->%d\n",Q->rear->n);

	show();
	return;
}
	
