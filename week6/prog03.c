#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int top=-1,n;
void push(char stack[],char a);
char pop(char stack[]);
int main()
{
	int i;
	char string[100],stack[100];
	printf("Enter the string: ");
	gets(string);


	n=strlen(string);

	for(i=0;i<n;i++)
	{
		push(stack,string[i]);
	}

	for(i=0;i<n/2;i++)
	{
		if(pop(stack)!=string[i])
		{
			printf("it is not a palidrome.");
			exit(0);
		}
		else
		{
		}
	}
	printf("It is a palindrome");
	return 0;
}

void push(char stack[],char a)
{
        if(top==n-1)
        {
                printf("\nstack overflow");
                exit(0);
        }
        stack[top+1]=a;
        top=top+1;

        return;
}
char pop(char stack[])
{
        if(top==-1)
        {
                printf("\nUnderflow");
                exit(0);
        }

        top=top-1;

        return stack[top+1];
}

