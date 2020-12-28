//Program to find the length of the largest monotonically
//increasing subsequence(working)

#include<stdio.h>

int main()
{
        int i,j,n,max=0,a[100],len[100];
        printf("Enter the number n: ");
        scanf("%d",&n);
        printf("Enter the numbers: ");

        for(i=0;i<n;i++)
        scanf("%d",&a[i]);

        for(i=0;i<n;i++)
        len[i]=1;

        for(i=0;i<n;i++)
{
        for(j=0;j<i;j++)
{
        if(a[i]>a[j] && len[i]<=len[j])
        len[i]++;
}
}
        for(i=0;i<n;i++)
        if(max<len[i])
        max=len[i];

        printf("\nThe length of largest subsequence is: %d\n", max);
        return 0;
}
