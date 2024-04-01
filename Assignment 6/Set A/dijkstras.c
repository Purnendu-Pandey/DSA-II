#include<stdio.h>
#define MAX 10
#define mx 999
int graph[MAX][MAX],key[MAX],mst[MAX],wt,v,s,i,j,n;
int minkey()
{
    int minimum=mx,min,i;
    for (i=0;i<v;i++)
    {
        if (mst[i]==0 && key[i] < minimum)
        {
           minimum=key[i];
           min=i;
        }
    }
    return min;
}
void dijkstra(int s)
{
     int i,j,u;
     for (i=0;i<v;i++)
     {
         //parent[i]=-1;
         key[i]=mx;
         mst[i]=0;
     }
     key[s-1]=0;
     for (i=0;i<v-1;i++)
     {
         u=minkey();
         mst[u]=1;
         for (j=0;j<v;j++)
             if (mst[j]==0 && graph[u][j] && key[u]!=mx && key[u]+graph[u][j] < key[j])
             {
                //parent[i]=u;
                key[j]=key[u]+graph[u][j];
             }
     }
}
void print()
{
     printf("Distance From Source to Vertex : \n");
     for (i=0;i<v;i++)
     {
         if (i!=s)
            printf("%d -> %d : %d\n",s,i+1,key[i]);
         else
            printf("%d -> %d : %d\n",s,i+1,key[i]);
     }
}
void main()
{
     int e,v1,v2;
     printf("\nEnter Number Of Vertices For Undirected Graph : ");
     scanf("%d",&v);
     for (i=0;i<v;i++)
         for (j=0;j<v;j++)
             if (i==j)
                graph[i][j]=0;
             else
                graph[i][j]=999;
     printf("\nEnter Number Of Edges For Undirected Graph : ");
     scanf("%d",&e);
     for (i=0;i<e;i++)
     {
         printf("\nEnter Edge %d And Its Weight : ",i+1);
         scanf("%d%d%d",&v1,&v2,&wt);
         graph[v1-1][v2-1]=graph[v2-1][v1-1]=wt;
         //key[i]=wt;      
     }
     printf("\nAdjacency Matrix For Graph With %d Vertices & %d Edges : \n",v,e);
     printf("  ");
     for (i=1;i<=v;i++)
         printf(" %d",i);
     printf("\n");
     for (i=0;i<v;i++)
     {
         printf("%d  ",i+1);
         for (j=0;j<v;j++)
             printf("%d ",graph[i][j]);
         printf("\n");
     }
     printf("\nEnter starting Vertex : ");
     scanf("%d",&s);
     dijkstra(s); 
     print();
}

/*
OUTPUT:
Enter Number Of Vertices For Undirected Graph : 5
Enter Number Of Edges For Undirected Graph : 6
Enter Edge 1 And Its Weight : 1 2 9
Enter Edge 2 And Its Weight : 1 4 4
Enter Edge 3 And Its Weight : 4 3 1
Enter Edge 4 And Its Weight : 4 2 2
Enter Edge 5 And Its Weight : 2 3 6
Enter Edge 6 And Its Weight : 2 5 3

Adjacency Matrix For Graph With 5 Vertices & 6 Edges : 
   1 2 3 4 5
1  0 9 0 4 0 
2  9 0 6 2 3 
3  0 6 0 1 0 
4  4 2 1 0 0 
5  0 3 0 0 0 

Enter starting Vertex : 2
Distance From Source to Vertex : 
2 -> 1 : 6
2 -> 2 : 0
2 -> 3 : 3
2 -> 4 : 2
2 -> 5 : 3

----------------X-------------------------

Enter Number Of Vertices For Undirected Graph : 4
Enter Number Of Edges For Undirected Graph : 4
Enter Edge 1 And Its Weight : 1 2 1
Enter Edge 2 And Its Weight : 1 3 2
Enter Edge 3 And Its Weight : 1 4 9
Enter Edge 4 And Its Weight : 3 4 3

Adjacency Matrix For Graph With 4 Vertices & 4 Edges : 
   1 2 3 4
1  0 1 2 9 
2  1 0 0 0 
3  2 0 0 3 
4  9 0 3 0 

Enter starting Vertex : 1
Distance From Source to Vertex : 
1 -> 1 : 0
1 -> 2 : 1
1 -> 3 : 2
1 -> 4 : 5
*/