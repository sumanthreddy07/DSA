//Selection sort program

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,n,temp,*head;

	printf("Enter the number of elements: ");
	scanf("%d",&n);

	head=(int*)malloc(n*sizeof(int));

	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	scanf("%d",&*(head+i));

	for(i=0;i<n-1;i++)
	for(j=i;j<n;j++)
		if(*(head+i)>*(head+j))
		{
			temp=*(head+i);
			*(head+i)=*(head+j);
			*(head+j)=temp;
		}

	printf("The sorted array is: ");
	for(i=0;i<n;i++)
	printf("\t%d",*(head+i));

	printf("\n");
	return 0;
}
	
