//Program to find the number of bits used by a number

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int count=0,i;
	long long int n;
	printf("Enter the number: ");
	scanf("%lld",&n);
	
	if(n==0)
	{
		printf("count= 1");
		exit(0);
	}

	while(n!=0)
	{
		count++;
		n=n/2;
	}
	printf("count= %d\n",count);

return 0;
}
