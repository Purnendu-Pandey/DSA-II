#include<stdio.h>
int main()
{
	int i,j,n,cnt=0;
	printf("\n Enter no of vertices for undirected graph :");
	scanf("%d",&n);
	int adj[n][n];
	
	for (i=0;i<n;i++)
	for (j=0;j<n;j++)
	adj[i][j]=0;
	printf("\n Enter the edges for undirected graph :\n");
	while(1)
	{
	  printf("Enter the vertices having edgs for undirected graph(v1,v2):");
	  scanf("%d%d",&i,&j);
	  if(i==0||j==0)
	  break;
	       adj[i-1][j-1]=1;
	       adj[j-1][i-1]=1;
	}
	    printf("\n Adjacency Matrix for undirected graph :\n");
	    for (i=0;i<n;i++)
	    printf("    %d",i+1);
	    for (i=0;i<n;i++)
	    {
	       cnt=0;
	       printf("\n %d",i+1);
	       for (j=0;j<n;j++)
	       {
	          printf(" %d ",adj[i][j]);
	          if(adj[i][j]==1)
	          cnt++;
	       }
	       printf(" Degree %d ",cnt);
	    }
	       return 0;
}   

/*
Enter no of vertices for undirected graph :4

Enter the edges for undirected graph :
Enter the vertices having edgs for undirected graph(v1,v2):1 2
Enter the vertices having edgs for undirected graph(v1,v2):1 3 
Enter the vertices having edgs for undirected graph(v1,v2):1 4
Enter the vertices having edgs for undirected graph(v1,v2):2 1
Enter the vertices having edgs for undirected graph(v1,v2):0 0

 Adjacency Matrix for undirected graph :
    1   2   3   4
 1  0   1   1   1  Degree 3 
 2  1   0   0   0  Degree 1 
 3  1   0   0   0  Degree 1 
 4  1   0   0   0  Degree 1
 */
