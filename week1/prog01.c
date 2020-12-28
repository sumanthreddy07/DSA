//Insertion Sorting Program

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int temp,i,j,n,a,*head;

	printf("Enter the number of the elements: ");
	scanf("%d",&n);

	head=(int *)malloc(n*sizeof(int));

	printf("Enter the elements: ");
	
	for(i=0;i<n;i++)
	{
	scanf("%d",&*(head+i));
	}
	for(i=1;i<n;i++)
	for(j=i;j>=1;j--)
	{
		if(*(head+j)<*(head+j-1))
		{
			temp=*(head+j-1);
			*(head+j-1)=*(head+j);
			*(head+j)=temp;
		}
	}
	
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
	{
	printf("\t%d",*(head+i));
	}
	printf("\n");

	return 0;
}
