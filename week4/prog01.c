#include<stdio.h>
#include<stdlib.h>
int top=-1;
void show(int a[],int n);
void push(int a[],int n);
void pop(int a[],int n);
void peek(int a[],int n);
void print(int a[],int n);
int main()
{
	int n;

	printf("Enter the size of the stack: ");
	scanf("%d",&n);
        int a[n];

	show(a,n);
	


	return 0;
}
void show(int a[],int n)
{
	int input;
	printf("\nEnter the function(Enter 0 to exit): ");
	printf("1.Push ");
	printf("2.pop ");
	printf("3.peek ");
	printf("4.print ");
	scanf("%d",&input);

	switch(input)
	{
		case 1: push(a,n);
			show(a,n);
			break;
		case 2: pop(a,n);
			show(a,n);
			break;
		case 3: peek(a,n);
			show(a,n);
			break;
		case 4: print(a,n);
			show(a,n);
			break;
		case 0: exit(0);
		default:printf("\nInvalid Input");
			show(a,n);
			break;
	}

	return;
}
void push(int a[],int n)
{
	int num;
	if(top==n-1)
	{
		printf("\nstack overflow");
		return;
	}

	printf("\nEnter the element to be pushed: ");
	scanf("%d",&num);

	a[top+1]=num;
	printf("\nElement pushed.");
	top=top+1;

	return;
}
void pop(int a[],int n)
{
	if(top==-1)
	{
		printf("\nUnderflow");
		return;
	}
	
	printf("\nElement popped.");
	top=top-1;

	return;
}
void peek(int a[],int n)
{
	if(top!=-1&&top!=n)
	{
		printf("\nThe value of the top element is: %d",a[top]);
	}
	else
		printf("\nPeek function cannot be performed.");

	return;
}
void print(int a[],int n)
{
	if(top==-1)
	{
		printf("\nStack is empty. Function not possible.");
		return;
	}
	
	for(int i=0;i<=top;i++)
		printf("%d\t",a[i]);

	return;
}

