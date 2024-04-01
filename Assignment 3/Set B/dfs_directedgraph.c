#include<stdio.h>
#define max 10

int i,n,top;
int stack[max],adj[max][max];

void push(int n);
void display();
int pop();
int isempty();
void init();

void init()
{
     top=-1;
}
void push (int n)
{
     top++;
     stack[top]=n;
}
void display()
{
    printf ("\n Stack TOP-->");
    for (i=top;i>=0;i--)
        printf (" : %d ",stack[i]);
}
int pop()
{
     int val;
     val=stack[top];
     top--;
     return (val);    
}

int isempty()
{
    if (top==-1)
       return 1;
    else
        return 0;
    
}
void dfs()
{
    int k;
    int vis[20]={0};
    printf("\n Enter vertex to start DFS : ");
    scanf("%d",&k);
    printf("\n DFS traversal is : ");
    push(k);
    vis[k-1]=1;
    while (top!=-1)
    {
           k=pop();
           printf(" %d ",k);
           for  (i=0;i<n;i++)
           {
                if (((adj[k-1][i]==1)) && vis[i]==0)
                {
                    vis[i]=1;
                    push(i+1);
                }
          }
     }
     printf("\n");
}

 void main ()
{
     int j,curr,cnt=0,k;
     init();
     printf ("\n Enter no of vertices  : ");
     scanf ("%d",&n);
    printf ("\n Enter edges : \n ");
    while (1) 
    {
           printf ("\n Enter vertices having edge between them   :  ");
           scanf ("%d%d",&i,&j);
           if (i==0 || j==0)
               break;       
           adj[i-1][j-1]=1;
    } 
    printf ("\n Adjacency matrix  for directed graph : \n    ");
    for (i=0;i<n;i++)
    {
        printf (" %d ",i+1);
    }
    for (i=0;i<n;i++)
    {
        printf ("\n  %d ",i+1);
        cnt=0;
        for (j=0;j<n;j++)
        {
             printf (" %d ",adj[i][j]);
             if (adj[i][j]==1)
                 cnt++;
        }
        printf ("\n ");
    }
    dfs();
   
}
/*
Enter no of vertices  : 4
Enter edges :  
Enter vertices having edge between them   :  1 2
Enter vertices having edge between them   :  4 3
Enter vertices having edge between them   :  1 3
Enter vertices having edge between them   :  2 3
Enter vertices having edge between them   :  1 4
Enter vertices having edge between them   :  0 0
Adjacency matrix  for directed graph :
     1  2  3  4
  1  0  1  1  1

  2  0  0  1  0

  3  0  0  0  0

  4  0  0  1  0
Enter vertex to start DFS : 1
DFS traversal is :  1  4  3  2
*/