//postfix to prefix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
int top1=-1;
char expr[100],x[100];
void posttoin(int n);
char pop1(char y[]);
void push1(char ch,char y[]);

int top=-1;
void intopre(int n);
int peek(char b[]);
int Prec(char c);
char pop(char b[]);
void push(char ch,char b[]);


int main()
{
	printf("Enter the expression in postfix: ");
	gets(expr);
	fflush(stdin);
	n=strlen(expr);
	posttoin(n);
	intopre(n);

	return 0;
}

void posttoin(int n)
{
	int j=0,i;
	char y[n],c[n];

        for(i=0;i<n;i++)
                c[n-i-1]=expr[i];

        for(i=0;i<n;i++)
                expr[i]=c[i];


	for(int i=0;i<n;i++)
        {
                if((expr[i]>='A'&&expr[i]<='Z')||(expr[i]>='a'&&expr[i]<='z'))
                {
                        x[j]=expr[i];
                        j=j+1;
			
			if(top1!=-1)
			{
				x[j]=pop1(y);
				j=j+1;
			}
                }
                else
                {
                        push1(expr[i],y);
                }
        }


        x[n] = '\0';


        for(i=0;i<n;i++)
                c[n-i-1]=x[i];

        for(i=0;i<n;i++)
                x[i]=c[i];

	return;
}



void push1(char ch,char y[])
{
        if(top1==n-1)
        {
                printf("\nstack overflow");
                exit(0);
        }

        y[top1+1]=ch;
        top1=top1+1;

        return;
}
char pop1(char y[])
{
        if(top1==-1)
        {
                printf("\nUnderflow");
                exit(0);
        }

        top1=top1-1;

        return y[top1+1];
}





void intopre(int n)
{
        int j=0,i;
        char d[n],b[n],c[n];

        for(i=0;i<n;i++)
                c[n-i-1]=x[i];

        for(i=0;i<n;i++)
                x[i]=c[i];

        for(i=0;i<n;i++)
        {
                if((x[i]>='A'&&x[i]<='Z')||(x[i]>='a'&&x[i]<='z'))
                {
                        d[j]=x[i];
                        j=j+1;
                }
                else
                {
                         while (top!=-1 && Prec(x[i]) <= Prec(peek(b)))
                                {
                                        d[j] = pop(b);
                                        if(d[j]==')')
                                        j=j-1;
                                        j=j+1;
                                }
                                push(x[i],b);
                }
        }

        while (top!=-1)
        {
                d[j] = pop(b);
                j++;
        }

        for(i=0;i<n;i++)
                c[n-i-1]=d[i];

        for(i=0;i<n;i++)
                d[i]=c[i];


        printf( "%s",d);

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
                return b[top];
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

	
