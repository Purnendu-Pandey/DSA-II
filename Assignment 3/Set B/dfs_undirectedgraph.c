/*DFS for undirected graph */
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int adj[MAX][MAX];
void add_edge(int u,int v)	
{
	adj[u][v]=1;
	adj[v][u]=1;
	}
void dfs(int start,int visited[],int n)
{
	int i;
	visited[start]=1;
	printf("%d  ",start+1);
	for (i=0;i<n;i++)
	{
	  if (adj[start][i]==1 && visited[i]==0)
	  {
	     dfs(i,visited,n);
	  }
	}
}
void main()
{
	int n,e,start,u,v,i,j;
	int visited[MAX]={0};
	printf("\n Depth First Search Traversal for Undirected graph \n ");
	printf("Enter no of vertices for Undirected graph : ");
	scanf("%d",&n);
	printf("Enter no of edges for Undirected graph : ");
	scanf("%d",&e);	
	for (i=0;i<n;i++)
	{
	    for (j=0;j<n;j++)
	    {
	         adj[i][j]=0;
	    }
	}
       	   for (i=0;i<e;i++)
           {
       	      printf("Enter the edges %d (u v) : ",i+1);
       	      scanf("%d%d",&u,&v);
       	      add_edge(u-1,v-1);
           }
       	      printf("Enter the starting vertex of DFS :");
       	      scanf("%d",&start);
       	      printf("Adjacency Matrix for Undirected graph  : \n");
       	      for (i=0;i<n;i++)
	           printf("    %d",i+1);
	           printf("\n");
	      for (i=0;i<n;i++)
	      {
	         printf("\n  %d",i+1);
	         for (j=0;j<n;j++)
	             printf("   %d",adj[i][j]);
	      }
	        printf("\n DFS traversal starting from vertex %d :",start);
	        dfs(start-1,visited,n);
}
/*
Depth First Search Traversal for Undirected graph 
Enter no of vertices for Undirected graph : 4
Enter no of edges for Undirected graph : 5
Enter the edges 1 (u v) : 1 2
Enter the edges 2 (u v) : 1 3
Enter the edges 3 (u v) : 3 2
Enter the edges 4 (u v) : 4 2
Enter the edges 5 (u v) : 3 4
Enter the starting vertex of DFS :2
Adjacency Matrix for Undirected graph  : 
      1   2   3   4
  1   0   1   1   0
  2   1   0   1   1
  3   1   1   0   1
  4   0   1   1   0
 DFS traversal starting from vertex 2 : 2  1  3  4
 */