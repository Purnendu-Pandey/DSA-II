#include<stdio.h>
#include<stdlib.h>
#define max 10
int n,i,j;
int adj[max][max];
int indegree[max]={0},vis[max];
int queue[max],f=-1,r=-1;
void topo();
void insert(int v);
int delete();
int main()
{
					printf("\n Enter the no of vertices of directed graph  :");
					scanf("%d",&n);
					for (i=0;i<n;i++)
					{
	   					indegree[i]=0;
	   					vis[i]=0;
	   					for (j=0;j<n;j++)
	       			adj[i][j]=0;
					}
					while(1)
					{
	  					printf("Enter the edges from vertex to vertex(v1,v2):");
             	scanf("%d%d",&i,&j);
	      			if (i==0 && j==0)
	         		break;
	      			else
	         				adj[i-1][j-1]=1;	 
					}
	  			printf("\n Adjacency matrix :\n\n");
	  			printf(" ");
	  			for (i=0;i<n;i++)
	      	printf(" %d ",i+1);
	  			printf("indegree");
	  			for (i=0;i<n;i++)
	  			{
	     					printf("\n  %d ",i+1);
	     					for (j=0;j<n;j++)
	     					{
	        					printf(" %d ",adj[i][j]);
	        					if (adj[j][i]==1)
	           				indegree[i]++;	
	      				}        
	          		printf(" %d ",indegree[i]);
	        }
	        for(i=0;i<n;i++)
	        {
	            if(indegree[i]==0)
	            {
	                insert(i);
	                vis[i]=1;
	            }
	        }
	        printf("\n Topological sort is :");
	        topo();
}
int delete()
{
    		int item;
    		r++;
    		item=queue[r];
    		return item;
}	
void insert(int vertex)
{
   			f++;
   			queue[f]=vertex;
}        
void topo()
{
 	 		  int k;
   			while(f!=r)
   			{
      			int k;
      			k=delete();
      			printf(" %d ",k+1);
      			for(i=0;i<n;i++)
      			{
        					if(adj[k][i]==1)
        					{
          						indegree[i]=indegree[i]-1;
          						if(indegree[i]==0)
            					insert(i);
        					}
       			}
   			}
}      
/*  
Enter the no of vertices of directed graph  :5
Enter the edges from vertex to vertex(v1,v2):1 2
Enter the edges from vertex to vertex(v1,v2):1 3
Enter the edges from vertex to vertex(v1,v2):3 5
Enter the edges from vertex to vertex(v1,v2):3 4
Enter the edges from vertex to vertex(v1,v2):2 4
Enter the edges from vertex to vertex(v1,v2):5 2
Enter the edges from vertex to vertex(v1,v2):0 0 

Adjacency matrix :
     1  2  3  4  5  indegree
  1  0  1  1  0  0     0 
  2  0  0  0  1  0     2 
  3  0  0  0  1  1     1 
  4  0  0  0  0  0     2 
  5  0  1  0  0  0     1 
 Topological sort is : 1  3  5  2  4 	        
*/        
