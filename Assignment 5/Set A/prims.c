#include<stdio.h>
#define m 9999
#define N 10
int parent[N],mst[N],wt[N],g[N][N];
int n;
int min_key()
{
	int minimum=m,min,i;
	for(i=0;i<n;i++)	  
        if(mst[i]==0 && wt[i]<minimum)
        {
           minimum=wt[i];
           min=i;
        }
        return min;
}
void prim()
{
				int i,j,u,v;	
				for(i=0;i<n;i++)
				{
	  			 	parent[i]=-1;
	   				wt[i]=m;
	   				mst[i]=0;
				}
	   		wt[0]=0;
	   		parent[0]=-1;
	   		for(i=0;i<n;i++)
	      {
	       		u=min_key();
	       		mst[u]=1;
	       		for(j=0;j<n;j++)
	       		{
	          	  if (g[u][j]!=0 && mst[j]==0 && g[u][j]<wt[j])
	           	  {
	                parent[j]=u;
	                wt[j]=g[u][j];
	              }
	          }
	      }
}
void main()
{
				int i,j,wt,mw=0;
				printf("\n Enter no of vertices :");
				scanf("%d",&n);	
				for (i=0;i<n;i++)
	    			for(j=0;j<n;j++)
	         			g[i][j]=0;
				while(1)
	 			{
	     			printf("Enter the edges from vertex to vertex(v1,v2):");
            scanf("%d%d",&i,&j);
	          if (i==0 && j==0)
	              break;
	          printf("Enter the weight from vertex to vertex(v1,v2):");
	          scanf("%d",&wt);
	          g[i-1][j-1]=wt;
	          g[j-1][i-1]=wt;
        }
	       printf("\n Adjacency matrix :\n");
	       for (i=0;i<n;i++)
	       printf(" \t%d",i+1);
	       for (i=0;i<n;i++)
	       {
	           printf("\n  %3d  ",i+1);
	           for (j=0;j<n;j++)
	               printf("   %3d ",g[i][j]);
	       }
	       	printf("\n");
	       	prim();
	       	printf("\n Edge weight \n");
	       	for(i=0;i<n;i++)
	       	{
	        		printf("\n %d<--->%d  %d",(parent[i])+1,i+1,g[i][parent[i]]);
	        		mw+=g[i][parent[i]];
	    		}
	        printf("\n The weight of minimum spanning tree is :%d",mw);
	        printf("  ");
}
/*
Enter no of vertices :5
Enter the edges from vertex to vertex(v1,v2):1 2
Enter the weight from vertex to vertex(v1,v2):4
Enter the edges from vertex to vertex(v1,v2):1 3
Enter the weight from vertex to vertex(v1,v2):6 
Enter the edges from vertex to vertex(v1,v2):1 5
Enter the weight from vertex to vertex(v1,v2):8
Enter the edges from vertex to vertex(v1,v2):2 4
Enter the weight from vertex to vertex(v1,v2):8
Enter the edges from vertex to vertex(v1,v2):3 2
Enter the weight from vertex to vertex(v1,v2):4
Enter the edges from vertex to vertex(v1,v2):3 4
Enter the weight from vertex to vertex(v1,v2):8
Enter the edges from vertex to vertex(v1,v2):3 5
Enter the weight from vertex to vertex(v1,v2):2
Enter the edges from vertex to vertex(v1,v2):0 0

Adjacency matrix :
      1      2      3      4      5
1     0      4      6      0      8
2     4      0      4      8      0
3     6      4      0      8      2
4     0      8      8      0      0
5     8      0      2      0      0

Edge weight
0<--->1  0
1<--->2  4
2<--->3  4
2<--->4  8
3<--->5  2
The weight of minimum spanning tree is :18
*/