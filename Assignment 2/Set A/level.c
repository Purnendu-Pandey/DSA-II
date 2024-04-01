#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst *lc;
    struct bst *rc;
}*root=NULL,*temp,*t1,*new2,*new1;
struct queue
{
     struct bst *data;
     struct queue *next;
}*f=NULL,*r=NULL,*temp1;
struct bst *create();

void insert(struct bst*,struct bst*);
int empty();
void enqueue(struct bst *);
struct bst* dequeue();
void level(struct bst *);

int empty()
{
    if (f==NULL && r==NULL)
        return 1;
    else
        return 0;
}
void enqueue(struct bst *t)
{
     temp1=malloc(sizeof(struct queue));
     temp1->data=t;
     temp1->next=NULL;
     if (f==NULL && r==NULL)
         f=r=temp1;
     else
     {
         r->next=temp1;
         r=r->next;
     }
}

struct bst *dequeue()
{
        struct bst *tt;
        tt=f->data;
        f=f->next;
        if (f==NULL)
            r=NULL;
        return tt;
}
struct bst *create()
{
       temp=(struct bst *)malloc(sizeof(struct bst));
       temp->lc=NULL;
       temp->rc=NULL;
       return temp;
}
void insert(struct bst *r,struct bst *new2)
{
      if (new2->data < r->data)
      { 
         if (r->lc == NULL)
             r->lc=new2;
         else
            insert(r->lc,new2);
      }
      if (new2->data > r->data)
      { 
         if (r->rc == NULL)
             r->rc=new2;
         else
            insert(r->rc,new2);
      }
}

void level(struct bst *t)
{
     int lcnt=0,tcnt=0,level1=0,final;
     struct bst *tt;
     tt=t;
     enqueue(tt);
     enqueue(NULL);
     printf(" \n Level : %d\t ",level1);
     printf("  Node at root\t :  ");
     while (!empty())
     {
            tt=dequeue();
            if (tt!=NULL)
            {
                lcnt++;
                tcnt++;
                printf("%d \t",tt->data);
                if (tt->lc!=NULL)
                    enqueue(tt->lc);
                if (tt->rc!=NULL)
                    enqueue(tt->rc);
            }
            else if (!empty())
            {
                      printf(" Number of Nodes  :%d\t  ",lcnt);
                      printf(" Total number of Nodes :%d\t  ",tcnt);
                      lcnt=0;
                      level1++;
                      enqueue(NULL);
                      printf(" \n Level : %d\t ",level1);
                      printf("  Nodes :  ");
          
            }
      }
      printf(" Number of Nodes  :%d\t  ",lcnt);
      printf(" Total number of Nodes :%d\t\t\t  ",tcnt);
      final=level1+1;
      printf("\n Total levels : %d\n\n",final);
}
void main()
{
   int n,i;
   printf("\n Enter total number of Nodes: ");
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {   
        new2=create();
        printf("\n Enter the data for node %d :  ",i); 
        scanf("%d",&new2->data);
        if (root==NULL)
            root=new2;
        else
            insert(root,new2);
   }    
   printf("\n\n Nodes by level order \n ");
   level(root);
}
             
/*
OUTPUT:
Enter total number of Nodes: 5
Enter the data for node 1 :  10
Enter the data for node 2 :  9
Enter the data for node 3 :  7
Enter the data for node 4 :  12
Enter the data for node 5 :  13

Nodes by level order 
Level : 0	   Node at root	 :  10 	 Number of Nodes  :1   Total number of Nodes :1	   
Level : 1	   Nodes :  9 	12 	 Number of Nodes  :2	   Total number of Nodes :3	   
Level : 2	   Nodes :  7 	13 	 Number of Nodes  :2	   Total number of Nodes :5			  
Total levels : 3
*/          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
