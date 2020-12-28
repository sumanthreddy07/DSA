//DIG ALGO


#include<stdio.h>
#include<stdlib.h>
#define INFINITY 99
#define MAX 10
 
void DIJ(int G[MAX][MAX],int n,int start);
 
int main()
{
	int G[MAX][MAX],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the weighted adjacency matrix:\n");
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d",&G[i][j]);
	
	printf("\nEnter the starting node: ");
	scanf("%d",&u);
	DIJ(G,n,u);
	
	return 0;
}
 
void DIJ(int G[MAX][MAX],int n,int a)
{
 
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int v[MAX],count,mindis,nextnode,i,j;
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		if(G[i][j]==0)
			cost[i][j]=INFINITY;
		else
			cost[i][j]=G[i][j];
	
	for(i=0;i<n;i++)
	{
		distance[i]=cost[a][i];
		pred[i]=a;
		v[i]=0;
	}
	
	distance[a]=0;
	v[a]=1;
	count=1;
	
	while(count<n-1)
	{
		mindis=INFINITY;
		
		for(i=0;i<n;i++)
		if(distance[i]<mindis&&!v[i])
		{
			mindis=distance[i];
			nextnode=i;
		}
	
		v[nextnode]=1;
		for(i=0;i<n;i++)
			if(!v[i])
			if(mindis+cost[nextnode][i]<distance[i])
			{
				distance[i]=mindis+cost[nextnode][i];
				pred[i]=nextnode;
			}
		count++;
	}
 
	for(i=0;i<n;i++)
	if(i!=a)
	{
		printf("\nDistance of node%d=%d",i,distance[i]);
	}
}
