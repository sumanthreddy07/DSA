//BELLFORD ALGO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
struct Edge
{
	int source;
	int destination;
	int weight;
};
 
struct Graph
{
    int V, E; 
    struct Edge* edge;
};

struct Graph* create(int V, int E)
{
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
 
    graph->V=V;
    graph->E=E;
    graph->edge=(struct Edge*)malloc(graph->E* sizeof(struct Edge));
    return graph;
}
 
void FinalSolution(int dist[],int n)
{
    printf("\nVertex\tDistance from Source Vertex\n");
    int i;
 
    for (i=0;i<n;++i)
	{
		printf("%d \t\t %d\n", i, dist[i]);
	}
}
 
void BellmanFord(struct Graph* graph, int source)
{
    int V=graph->V;
    int E=graph->E;
    int Distances[V];
    int i,j;
 
    for (i=0;i<V;i++)
        Distances[i]=INT_MAX;
 
    Distances[source]=0;
 
    for (i=1;i<=V-1;i++)
    {
        for (j=0;j<E;j++)
        {
            int u=graph->edge[j].source;
            int v=graph->edge[j].destination;
            int weight=graph->edge[j].weight;
 
            if (Distances[u] + weight < Distances[v])
                Distances[v] = Distances[u] + weight;
        }
    }
 
    for (i=0;i<E;i++)
    {
        int u=graph->edge[i].source;
        int v=graph->edge[i].destination;
        int weight=graph->edge[i].weight;

        if (Distances[u] + weight < Distances[v])
            printf("This graph contains negative edge cycle\n");
    }
 
    FinalSolution(Distances, V);
 
    return;
}
 
int main()
{
    int V,E,S;
 
	printf("Enter number of vertices in graph\n");
    scanf("%d",&V);
 
	printf("Enter number of edges in graph\n");
    scanf("%d",&E);
 
	printf("Enter your source vertex number\n");
	scanf("%d",&S);
 
    struct Graph* graph = create(V, E);
 
    int i;
    for(i=0;i<E;i++){
        printf("\nEnter edge %d properties from, to,and it's weight respectively:\n",i+1);
        scanf("%d",&graph->edge[i].source);
        scanf("%d",&graph->edge[i].destination);
        scanf("%d",&graph->edge[i].weight);
    }
 
    BellmanFord(graph, S);
 
    return 0;
}
