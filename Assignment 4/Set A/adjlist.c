#include<stdio.h>
#include<stdlib.h>
#define N 10

struct node
{
       int data;
       struct node *next;
}*v[N],*temp,*t;

void main ()
{
      int i,j,n;
      printf("\n Enter the number of vertices for adjacency list : ");
      scanf("%d",&n);
      for (i=0;i<n;i++)
           v[i]=NULL;
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
}
/*
output:
Enter the number of vertices for adjacency list : 6
Enter the edge from vertex and to vertex  : 1 2
Enter the edge from vertex and to vertex  : 1 4
Enter the edge from vertex and to vertex  : 4 2
Enter the edge from vertex and to vertex  : 2 5
Enter the edge from vertex and to vertex  : 5 4
Enter the edge from vertex and to vertex  : 3 5
Enter the edge from vertex and to vertex  : 6 6
Enter the edge from vertex and to vertex  : 0 0

Adjacency list :
Vertex 1 : 2 --> 4 -->  NULL
Vertex 2 : 5 -->  NULL
Vertex 3 : 5 -->  NULL
Vertex 4 : 2 -->  NULL
Vertex 5 : 4 -->  NULL
Vertex 6 : 6 -->  NULL
*/