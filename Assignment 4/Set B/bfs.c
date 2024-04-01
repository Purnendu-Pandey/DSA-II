//set B-1st
#include<stdio.h>
#include<stdlib.h>
#define N 10

struct node
{
       int data;
       struct node *next;
}*v[N],*temp,*t;
 
int ind[N],outd[N],q[N],f,r;

void init();
void insert(int);
int  delete();

void init()
{
     f=r=-1;
}
void insert( int n)
{
     r++;
     q[r]=n;  
}
int delete()
{    
    f++;
    int val=q[f];
    return val;    
}     
void bfs()
{
        int i,k;
        int vis[N]={0};
        printf("\n Enter the start vertex : ");
        scanf("%d",&k);
        printf("\n BFS Traversal is : ");
       
        insert(k);
        vis[k-1]=1;
       
        while (f!=r)
        {
            k=delete();
            printf(" %d ",k);
             
            struct node *ptr;
            for(ptr=v[k-1];ptr!=NULL;ptr=ptr->next)
            {
                if (vis[(ptr->data)]==0)
                {
                    vis[(ptr->data)]=1;
                    insert((ptr->data)+1);
                }
            }    
        }
}
void main ()
{
            int i,j,n,k;
            init();
            printf("\n Enter the number of vertices for adjacency list for directed graph: ");
            scanf("%d",&n);
            for (i=0;i<n;i++)
            {
                v[i]=NULL;
                ind[i]=outd[i]=0;
            }
            while (1)
            {
            printf("\n Enter the edge from vertex and to vertex  : ");
            scanf("%d%d",&i,&j);
            if (i==0 && j==0)
               break;
            else
            {
                temp=malloc(sizeof(struct node));
                temp->data=j-1;
                temp->next=NULL;
                if (v[i-1]==NULL)
                    v[i-1]=t=temp;
                else
                {
                    for (t=v[i-1];t->next!=NULL;t=t->next);
                    t->next=temp;
                }
            }    
      }
      printf("\n Adjacency list :");
      printf("\n");
      
      for (i=0;i<n;i++)
      {
          printf("\n Vertex %d : ",i+1);
          for (t=v[i];t!=NULL;t=t->next)
              printf("%d --> ",(t->data)+1);
          printf(" NULL\n ");
      }
        printf("\n  Vertex   Indegree  Outdegree  Total degree ");
        for (i=0;i<n;i++)
        {
          for (t=v[i];t!=NULL;t=t->next)
              {
                  
                  ind[t->data]++;
                  outd[i]++;
              }       
        }
        for (i=0;i<n;i++)
        printf("\n      %d          %d        %d         %d ",i+1,ind[i],outd[i],(ind[i]+outd[i]));
        printf("\n");
        bfs();
        printf(" ");
            
}
/*

Enter the number of vertices for adjacency list for directed graph: 4
Enter the edge from vertex and to vertex  : 1 2
Enter the edge from vertex and to vertex  : 1 3
Enter the edge from vertex and to vertex  : 1 4 
Enter the edge from vertex and to vertex  : 2 3
Enter the edge from vertex and to vertex  : 2 4
Enter the edge from vertex and to vertex  : 0 0

Adjacency list :
Vertex 1 : 2 --> 3 --> 4 -->  NULL
Vertex 2 : 3 --> 4 -->  NULL
Vertex 3 :  NULL
Vertex 4 :  NULL

Vertex  Indegree  Outdegree  Total degree
  1        0        3         3
  2        1        2         3
  3        2        0         2
  4        2        0         2

Enter the start vertex : 1
BFS Traversal is :  1  2  3  4

*/