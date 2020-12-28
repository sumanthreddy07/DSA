//Program to find the rank of the formed word

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int i,n,k=0,j=0,num=0;
	char ch, a[26],b[26],c[26];

	printf("Enter the N= ");
	gets(a);
	fflush(stdin);

	ch=a[0];
	n=ch-'0';

	for(i=2;i<=2*n;i++)
	{
		b[j]=a[i];
		j++;
	}
	b[j]='\0';

	for(i=2*n+2;a[i]!='\0';i++)
	{
		c[k]=a[i];
		k++;
	}
	c[k]='\0';

	for(i=1;i<k;i++)
		if(c[i]<c[i-1])
		{
			printf("Invalid String.\n");
			exit(0);
		}
	j=0;	
	for(i=0;i<strlen(b);i++)
	{
		if(c[j]='\0')
		continue;

		else
		{
		if(c[j]>b[i])
			num=num+pow(2,n-i-1);
		else
		{
			j++;
			num++;
		}
		}
	}

	printf("The rank of the word is:%d\n",num-1);

	return 0;
}
