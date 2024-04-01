//Set B
#include<stdio.h>
#define N 10
int g[N][N],n,sol[N][N];
void print();
void fw()
{
					int i,j,k;
					for(i=0;i<n;i++)
	    				for(j=0;j<n;j++)
	    				sol[i][j]=g[i][j];
	    
					for(k=0;k<n;k++)
					{
	   				 	for(i=0;i<n;i++)
	    				{
	       				for(j=0;j<n;j++)
	       				{
	          			if(i=j)
	            		sol[i][j]=0;
	          			if(sol[i][j]+sol[k][j]<sol[i][j])
	             		sol[i][j]=sol[i][k]+sol[k][j];
	       				}
	    				}
					}       
}
void print()
{
					int i,j;	
					printf("  ");
					for(i=0;i<n;i++)

	    		printf("  %d",i+1);
					printf("\n");
	      	for(i=0;i<n;i++)
	      	{
	        	 	printf("\n  %d",i+1);
	          	for(j=0;j<n;j++)
	          	{
	             		printf("  %d",sol[i][j]);
	          	}
	     	  }
	     	 	printf("\n\n");
}
void main()
{
				int i,j,wt,mw=0;
				printf("\n Enter no of vertices :");
				scanf("%d",&n);	
				for (i=0;i<n;i++)
	    	for(j=0;j<n;j++)
	    	{
	       		if(i==j)
	        			g[i][j]=0;
	       		else
	         		g[i][j]=999;
	    	}  
				while(1)
	 			{
	     			printf("Enter the edges from vertex to vertex(v1,v2):");
            scanf("%d%d",&i,&j);
	      		if (i==0 && j==0)
	         	break;
	         	printf("Enter the weight from vertex to vertex(v1,v2):");
	         	scanf("%d",&wt);
	         	g[i-1][j-1]=wt;
        }
				printf("\n Adjacency matrix :\n");
				printf(" ");
				for (i=0;i<n;i++)
	    	printf("  %d    ",i+1);
	    	for (i=0;i<n;i++)
	    	{
	      		printf("\n %d",i+1);
	          for (j=0;j<n;j++)
	          printf("%4d ",g[i][j]);
	    	}
	    	printf("\n\n");
	    	fw();
	    	printf("\n The shortest paths matrix is");
	    	print();
	    	printf("The shortest paths vertex to all vertex : \n");
	    	printf("Edges weight ");
	    	for(i=0;i<n;i++)
	      for(j=0;j<n;j++)
	      {
	        if(i!=j)
	            printf("\n %d<--->%d  %d",i+1,j+1,sol[i][j]);
	        else
	            printf("\n %d<---.%d  %d",i+1,j+1,sol[i][j]);
	      }
}	  
/*
Enter no of vertices :5
Enter the edges from vertex to vertex(v1,v2):1 2
Enter the weight from vertex to vertex(v1,v2):10
Enter the edges from vertex to vertex(v1,v2):2 3
Enter the weight from vertex to vertex(v1,v2):1
Enter the edges from vertex to vertex(v1,v2):4 1
Enter the weight from vertex to vertex(v1,v2):7
Enter the edges from vertex to vertex(v1,v2):5 4
Enter the weight from vertex to vertex(v1,v2):2
Enter the edges from vertex to vertex(v1,v2):5 3
Enter the weight from vertex to vertex(v1,v2):9
Enter the edges from vertex to vertex(v1,v2):0 0

 Adjacency matrix :
     1    2    3    4    5    
 1   0   10  999  999  999 
 2 999    0    1  999  999 
 3 999  999    0  999  999 
 4   7  999  999    0  999 
 5 999  999    9    2    0 

The shortest paths matrix is    
     1    2   3    4    5
  1  0    10  999  999  999
  2  999   0  1    999  999
  3  999 999  0    999  999
  4  7   999  999   0   999
  5  999 999  9     2    0

The shortest paths vertex to all vertex : 
Edges weight 
 1<---.1  0
 1<--->2  10
 1<--->3  999
 1<--->4  999
 1<--->5  999
 2<--->1  999
 2<---.2  0
 2<--->3  1
 2<--->4  999
 2<--->5  999
 3<--->1  999
 3<--->2  999
 3<---.3  0
 3<--->4  999
 3<--->5  999
 4<--->1  7
 4<--->2  999
 4<--->3  999
 4<---.4  0
 4<--->5  999
 5<--->1  999
 5<--->2  999
 5<--->3  9
 5<--->4  2
 5<---.5  0
*/
	    
