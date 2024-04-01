#include<stdio.h>
#include<stdlib.h>
#define max 10

struct node
{
       int data;
       struct node* next;
}*a[max],*temp,*t;
int adj[max][max],ind[max],out[max];

void main ()
{
     int i,j,n,cnt=0,td=0;
     printf ("\n Enter no of vertices to create adjacency list  : ");
     scanf ("%d",&n);
     
     for (i=0;i<n;i++)
     {
          a[i]=NULL;
          ind[i]=out[i]=0;      
     }                       
     printf ("\n Enter edges : \n ");
     while (1) 
     {
           printf ("\n Enter the edge from vertex and To vertex   :  ");
           scanf ("%d%d",&i,&j);
           if (i==0 && j==0)
               break;
           else
           {
               temp=malloc(sizeof(struct node));
               temp->data=j-1;
               temp->next=NULL;
               if (a[i-1]==NULL)
                   a[i-1]=temp;
               else
               {
                  for (t=a[i-1];t->next!=NULL;t=t->next);
                  t->next=temp;
               } 
          }
      } 
      printf ("\n Adjacency list : \n");
      for (i=0;i<n;i++)
      {
          printf("Vertex %d : ",i+1);
          for (t=a[i];t!=NULL;t=t->next)
              printf(" %d->",(t->data)+1);
          printf(" NULL\n");
      }
      printf("\n Vertex   Indegree   Outdegreee Totaldegree");
      for (i=0;i<n;i++)
      { 
           for (t=a[i];t!=NULL;t=t->next)
           {
                ind[t->data]++;
                out[i]++;   
           }
      }
      for (i=0;i<n;i++)
          printf (" \n    %d       %d        %d          %d ",i+1,ind[i],out[i],ind[i]+out[i]);
}
/*
Enter no of vertices to create adjacency list  : 5
Enter edges : 

Enter the edge from vertex and To vertex   :  1 2
Enter the edge from vertex and To vertex   :  1 4
Enter the edge from vertex and To vertex   :  4 2
Enter the edge from vertex and To vertex   :  4 3
Enter the edge from vertex and To vertex   :  2 3
Enter the edge from vertex and To vertex   :  2 5
Enter the edge from vertex and To vertex   :  3 5 
Enter the edge from vertex and To vertex   :  0 0

Adjacency list :
Vertex 1 :  2-> 4-> NULL
Vertex 2 :  3-> 5-> NULL
Vertex 3 :  5-> NULL
Vertex 4 :  2-> 3-> NULL
Vertex 5 :  NULL

Vertex   Indegree   Outdegreee Totaldegree
    1       0        2          2
    2       2        2          4
    3       2        1          3
    4       1        2          3
    5       2        0          2
*/