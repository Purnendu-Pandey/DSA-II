#include<stdio.h>
#define max 10
#define m 999
int parent[max],min,mw=0,adj[max][max];
int i,j,k,a,b,u,v,n,edge;

int find(int i)
{
    while (parent[i]>0)
          i=parent[i];
    return i; 
}
void uni (int i,int j)
{
     parent[j]=i;
}
void kruskal()
{
     printf("\n The edges are :\n");
     printf("\nEdge No : Edge : Weight\n");
     for (edge=1;edge<=n-1;)
     {
        for (i=0,min=999;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if ( adj[i][j] < min )
                {
                    min=adj[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        u=find(a);
        v=find(b);
        if (u != v)
        {
            uni(v,u);
            printf("\n%d : %d->%d : %d\n",edge++,a+1,b+1,min);
            mw+=min; 
        }  
        adj[a][b]=adj[b][a]=999;
    }
    printf("\nMinimum Weight : %d",mw);   
} 
void main()
{
    int w;
    printf("\n Enter no of vertices : ");
    scanf("%d",&n);
      
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            if(i==j)
                adj[i][j]=0;
            else
                adj[i][j]=999;
        }
        printf("\nEnter edges for Undirected Graph \n");
        while (1) 
        {
            printf ("Enter the edge  from vertex and To vertex : ");
            scanf ("%d%d",&i,&j);
            if (i==0 || j==0)
                break;       
            printf ("Enter weight for edge between v1 and v2 : ");
            scanf ("%d",&w);  
            adj[i-1][j-1]=w;
            adj[j-1][i-1]=w;
        }
        printf("\n Adjacency matrix of Undirected  Graph  : \n");
        for(i=0;i<n;i++)
           printf("  %2d  ",i+1);    
        for (i=0;i<n;i++)
        {
           printf("\n  %d ",i+1);
           for(j=0;j<n;j++)
               printf ("  %4d ",adj[i][j]);
         }
        printf("\n Minimum cost spanning tree for given undirected graph with  vertices  %d",n);
        kruskal();
        printf("\n");
}
/*
Enter no of vertices : 5

Enter edges for Undirected Graph 
Enter the edge  from vertex and To vertex : 1 3
Enter weight for edge between v1 and v2 : 4
Enter the edge  from vertex and To vertex : 2 1
Enter weight for edge between v1 and v2 : 2
Enter the edge  from vertex and To vertex : 4 1
Enter weight for edge between v1 and v2 : 8
Enter the edge  from vertex and To vertex : 5 4
Enter weight for edge between v1 and v2 : 3
Enter the edge  from vertex and To vertex : 2 3
Enter weight for edge between v1 and v2 : 8
Enter the edge  from vertex and To vertex : 4 3
Enter weight for edge between v1 and v2 : 2
Enter the edge  from vertex and To vertex : 0 0

 Adjacency matrix of Undirected  Graph  :
         1      2      3      4      5
  1      0      2      4      8    999
  2      2      0      8    999    999
  3      4      8      0      2    999
  4      8    999      2      0      3
  5    999    999    999      3      0
 
Minimum cost spanning tree for given undirected graph with  vertices 5
The edges are :
Edge No : Edge : Weight

1 : 1->2 : 2
2 : 3->4 : 2
3 : 4->5 : 3
4 : 1->3 : 4

Minimum Weight : 11
*/