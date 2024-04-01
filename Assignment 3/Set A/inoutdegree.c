#include<stdio.h>
int main()
{
	int i,j,n,v1,v2,G[10][10],max_edges,in[10],out[10];
	printf("\n Enter no of vertices for Directed graph : ");
	scanf("%d",&n);	
	for (i=0;i<n;i++)
	{
	     in[i]=0;
	     out[i]=0;
	}
	for (i=0;i<n;i++)
	    for (j=0;j<n;j++)
	         G[i][j]=0;
	max_edges=n*(n-1);
	for (i=0;i<=max_edges;i++)
	{
	    printf("Enter Edge from vertex to vertex for directed:");
	    scanf("%d%d",&v1,&v2);
	    if((v1==0)&&(v2==0))
	      break;
	    if(v1>n||v2>n||v1<1||v2<1)
	     {
	        printf("\n Invalid Edge ");
	        i--;
	     }
	  else
	      G[v1-1][v2-1]=1;
	 }
	    printf("Adjacency Matrix for directed graph  : \n");
	    for (i=0;i<n;i++)
	         printf("    %d ",i+1);
	    printf("\n");
	    for (i=0;i<n;i++)
	    {
	       printf(" %d",i+1);
	       for (j=0;j<n;j++)
	          printf("  %d   ",G[i][j]);
	       printf("\n");
	    }
	    for (i=0;i<n;i++)
	        for (j=0;j<n;j++)
	        {
	          if(G[i][j]==1)
	            out[i]++;
	          if(G[j][i]==1)
	            in[i]++;
	        } 
   	 	printf("Vertex Indegree   Outdegree  Total Degree ");
   	 	for (i=0;i<n;i++)
   	 	{
   	 	   printf("\n%d",i+1);
		   printf("        %d",in[i]);
		   printf("             %d",out[i]);
		   printf("               %d",in[i]+out[i]);
		}
}
/*
Enter no of vertices for Directed graph : 4
Enter Edge from vertex to vertex for directed:1 2
Enter Edge from vertex to vertex for directed:1 3
Enter Edge from vertex to vertex for directed:1 4
Enter Edge from vertex to vertex for directed:2 3
Enter Edge from vertex to vertex for directed:0 0
Adjacency Matrix for directed graph  : 
    1     2     3     4 
 1  0     1     1     1   
 2  0     0     1     0   
 3  0     0     0     0   
 4  0     0     0     0
Vertex Indegree   Outdegree  Total Degree
1        0             3               3
2        1             1               2
3        2             0               2
4        1             0               1
*/

