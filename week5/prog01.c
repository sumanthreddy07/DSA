//Infix to postfix

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;

char expr[100];
int n;

void postfix(int n);
int peek(char b[]);
int Prec(char c);
char pop(char b[]);
void push(char ch,char b[]);
int main()
{
        printf("Enter the expression in infix: ");
        gets(expr);
        fflush(stdin);
        n=strlen(expr);
        postfix(strlen(expr));

        return 0;
}

void postfix(int n)
{
	int j=0,i;
	char a[n],b[n];

	for(i=0;i<n;i++)
	{
		if((expr[i]>='A'&&expr[i]<='Z')||(expr[i]>='a'&&expr[i]<='z'))
		{
			a[j]=expr[i];
			j=j+1;
		}
		else if(expr[i]=='(')
		{
			push(expr[i],b);
		}
		else if(expr[i]==')')
		{
			while(top!=-1&&peek(b)!='(')
				{
					a[j]=pop(b);
					if(a[j]=='(')
                                        j=j-1;

					j=j+1;
				}
		}
		else
		{
			 while (top!=-1 && Prec(expr[i]) <= Prec(peek(b))) 
                		{
					a[j] = pop(b);
					if(a[j]=='(')
					j=j-1;
					j=j+1;
				}
            			push(expr[i],b); 
		}
        } 
	
	while (top!=-1) 
        {
		a[j] = pop(b);
		j++;
	}
  
    	if(a[j-1]=='(')
		a[j-1]='\0';
	else
		a[j] = '\0';
 
    	printf( "%s",a); 
	
	return;
}
int Prec(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 
int peek(char b[])
{
        if(top!=-1&&top!=n)
        {
                return b[top+1];
        }
        else
                printf("\nPeek function cannot be performed.");

        return 0;
}

void push(char ch,char b[])
{
        if(top==n-1)
        {
                printf("\nstack overflow");
                exit(0);
        }

        b[top+1]=ch;
        top=top+1;

        return;
}
char pop(char b[])
{
        if(top==-1)
        {
                printf("\nUnderflow");
                exit(0);
        }

        top=top-1;

        return b[top+1];
}
