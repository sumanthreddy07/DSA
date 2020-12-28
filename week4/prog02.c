#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int num;
	struct stack *next;
};
typedef struct stack node;
node *head;
int n,top=-1;
void show(void);
void push(void);
void pop(void);
void peek(void);
void print(void);

int main()
{
	printf("Enter the size of the stack: ");
	scanf("%d",&n);
	show();
}
void show(void)
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
                case 1: push();
                        show();
                        break;
                case 2: pop();
                        show();
                        break;
                case 3: peek();
                        show();
                        break;
                case 4: print();
                        show();
                        break;
                case 0: exit(0);
                default:printf("\nInvalid Input");
                        show();
                        break;
        }

        return;
}

void push(void)
{

	if(top==n-1)
	{
                printf("Stack overflow.");
		return;
	}

    	node *new;
    	new=(node *)malloc(sizeof(node));

    	printf("\nEnter the value: ");
    	scanf("%d",&new->num);
        	new->next=head;
        	head=new;
		top=top+1;
	return;
}
void pop(void)
{
	if(top==-1)
	{
		printf("Stack underflow");
		return;
	}

	node *new;
	new=head->next;
	free(head);
	head=new;
	top=top-1;

	return;
}
void peek(void)
{
	if(top==-1)
	{
		printf("The stack is empty");
		return;
	}

	printf("The value of the top most element is: %d",head->num);
	return;
}
void print(void)
{	
	if(top==-1)
        {
                printf("Stack is empty");
                return;
        }

	node *new;
	new=head;

	for(int i=0;i<=top;i++)
	{
		printf("%d\t",new->num);
		new=new->next;
	}

	return;
}
