//Program to find the rotation number using the unit's digit(working)

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int i=1,j,carry=0,a[100],prod0,prod,num,n;
	long long int result=0,ans=-1,ans2=0;

	printf("Enter the unit digit: ");
	scanf("%d",&n);
	
	result=n;
	a[0]=n;

hi: 
	ans=n*result;
	ans2=n*pow(10,i-1)+result/10;

	if(ans==ans2)
	{
		printf("%lld",result);
		exit(0);
	}

	prod0=a[i-1]*n;
	prod=prod0+carry;
	num=prod%10;
	carry=prod/10;

	a[i]=num;
	result=0;

	for(j=i;j>-1;j--)
	{
		result=result*10+a[j];
	}
	i++;

	goto hi;

	return 0;
}
