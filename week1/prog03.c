//Bubble Sort

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
        {
        scanf("%d",&*(head+i));
        }
	
	for(i=n-1;i>0;i--)
	for(j=0;j<i;j++)
	if(*(head+j)>*(head+j+1))
	{
		temp=*(head+j);
		*(head+j)=*(head+j+1);
		*(head+j+1)=temp;
	}

	printf("The sorted array is: ");
	for(i=0;i<n;i++)
	printf("\t%d",*(head+i));
	printf("\n");

	return 0;
}


