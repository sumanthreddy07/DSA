//Value of the expression in prefix

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void evaluate(int n);
void push(int stack[],int a);
int pop(int stack[]);

char expr[100];
int stack[100],n,top=-1;

int main()
{

        printf("Enter the Expression in prefix: ");
        gets(expr);
        fflush(stdin);
        n=strlen(expr);
        evaluate(n);

        return 0;
}

void evaluate(int n)
{
        int i,bignum=0,c[100];

        for(i=0;i<n;i++)
                c[n-i-1]=expr[i];

        for(i=0;i<n;i++)
                expr[i]=c[i];

        for(i=0;i<n;i++)
        {
                char b;
                b=expr[i];
                if(b>=48&&b<=57)
                {
                        push(stack,b-48);
                }
                else if(b=='(')
                {
                        i=i+1;
                        while(expr[i]!=')')
                        {
                                bignum=bignum*10+(expr[i]-48);
                                i++;
                        }
                        push(stack,bignum);
                }
                else
                {
                        int val1=pop(stack);
                        int val2=pop(stack);
                        switch(b)
                        {
                                case '+': push(stack,val2+val1);
                                        break;
                                case '-': push(stack,val1-val2);
                                        break;
                                case '*': push(stack,val2*val1);
                                        break;
                                case '/': push(stack,val1/val2);
                                        break;
                                case '^': push(stack,pow(val1,val2));
                                        break;
                        }
                }
        }

        printf("The value of the expression is: %d.\n",stack[0]);
        return;


}

void push(int stack[],int a)
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
int pop(int stack[])
{
        if(top==-1)
        {
                printf("\nUnderflow");
                exit(0);
        }

        top=top-1;

        return stack[top+1];
}


