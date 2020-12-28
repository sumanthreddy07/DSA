//Program to add two numbers

#include<stdio.h>
#include<string.h>
int main()
{
	int j,z[101],y[101],x[101],i,length,num,carry=0;
	char a[201],b[101],c[101];

	printf("Enter the two numbers with a space in between: ");
	gets(a);
	fflush(stdin);

	for(i=0;;i++)
	{
		if(a[i]<48||a[i]>57)
			break;
		else
			b[i]=a[i];
	}

	b[i]='\0';


	for(j=i+1;a[j]!='\0';j++)
		c[j-i-1]=a[j];
		c[j-i-1]='\0';

	for(i=0;i<strlen(b);i++)
		z[strlen(b)-i-1]=b[i]-'0';

        for(i=0;i<strlen(c);i++)
		y[strlen(c)-i-1]=c[i]-'0';

	if(strlen(b)>strlen(c))
	{
		length=strlen(b);
		for(i=strlen(c);i<=strlen(b);i++)
			y[i]=0;
			z[length]=0;
	}
	else
	{
                length=strlen(c);
                for(i=strlen(b);i<=strlen(c);i++)
                        z[i]=0;
                        y[length]=0;
	}

	for(i=0;i<length;i++)
	{
		num=y[i]+z[i]+carry;
		carry=num/10;
		x[i]=num%10;
	}

	x[i]=carry;

	if(x[i]==0)
	length=length-1;

	for(j=length;j>=0;j--)
		printf("%d",x[j]);

	return 0;
}

