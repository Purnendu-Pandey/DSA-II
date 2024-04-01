#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst *lc;
    struct bst *rc;
}*root,*temp,*t1,*new2,*new1;
int n,cnt=0,lcnt=0;
void init()
{
     root=NULL;
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
void inorder(struct bst *temp)
{
     if (temp!=NULL)
     {
         inorder(temp->lc);
         printf("%d  ",temp->data);
         inorder(temp->rc);
     }
} 
void preorder(struct bst *temp)
{
     if (temp!=NULL)
     {
         printf("%d  ",temp->data); 
         preorder(temp->lc);
         preorder(temp->rc);
     }
} 
void postorder(struct bst *temp)
{
     if (temp!=NULL)
     {
         postorder(temp->lc);
         postorder(temp->rc);
         printf("%d  ",temp->data);
     }
} 
void btreetraverse(struct bst *root)
{
     printf("\n Binary search tree in preorder : \t");
     preorder(root);                
     printf("\n Binary search tree in inorder : \t");
     inorder(root);
     printf("\n Binary search tree in postorder : \t");
     postorder(root);
     printf("\n");
}
int count(struct bst *temp)
{
    if (temp!=NULL)
    {
        cnt++;
        count(temp->lc);
        count(temp->rc);
    }
    return cnt;
}            
int countleaf(struct bst *temp)
{
    if (temp!=NULL)
    { 
        if (temp->lc==NULL && temp->rc==NULL )
            lcnt++;
        countleaf(temp->lc);
        countleaf(temp->rc); 
    }
    return lcnt;
}           
struct bst *search(struct bst *temp,int key)
{      
       struct bst *r;
       temp=r;
       while (temp!=NULL)
       {
             if (temp->data ==key)
                 return temp;
             else 
                 if (key < temp->data)
                     temp=temp->lc;
             else 
                 if (key > temp->data)
                    temp=temp->rc;
        }
        return NULL;
}
struct bst *succ(struct bst *node)
{
       t1=node;
       while (t1 && t1->lc!=NULL)
              t1=t1->lc;
       return t1;       
}
struct bst *delete(struct bst *root,int key) 
{
       if (root==NULL)
           return root;
       if (key < root->data)
           root->lc=delete(root->lc,key);
       else
          if (key > root->data)
              root->rc=delete(root->rc,key);
       else
       {
           if (root->lc==NULL)
           {
              temp=root->rc;
              return temp;
            }
            else 
                if (root->rc==NULL)
                {
                    temp=root->lc;
                    return temp;
                }
           temp=succ(root->rc);
           root->data=temp->data;
           root->rc=delete(root->rc,temp->data);
        }
        return root;
}     
void main()
{
     int op=1,i,key;
     init();
     printf("\n\n  Binary search tree Operations \n");
     while (op>=1 && op <=7)
     {
           cnt=0,lcnt=0;
           printf("\n 1 : Create a binary search tree ");
           printf("\n 2 : Traverse a binary search tree ");
           printf("\n 3 : Insert Node in a binary search tree ");
           printf("\n 4 : Search Node in  a binary search tree ");
           printf("\n 5 : Delete node in binary search tree ");
           printf("\n 6 : Count total no of nodes a binary search tree ");
           printf("\n 7 : Count leaf nodes a binary search tree ");
           printf("\n Enter the desired option :  ");
           scanf("%d",&op);
           switch (op)
           {
                  case 1:if (root!=NULL)
                             printf("\n Binary search tree already exist.");
                         else
                         {
                             printf("\n Enter the number of nodes : ");
                             scanf("%d",&n);
                             if (n<0)
                             {
                                 printf("\n Invalid no of nodes ");
                                 return;
                             }
                             else
                             {
                                 for (i=1;i<=n;i++)
                                 {
                                      new2=create();
                                      printf("\n Enter the data for node %d :",i); 
                                      scanf("%d",&new2->data);
                                      if (root==NULL)
                                         root=new2;
                                      else
                                          insert(root,new2);
                                  }
                              }
                          }
                          break;    
                  case 2: if (root==NULL)
                              printf("\n Binary search tree is empty.");
                          else
                              btreetraverse(root);
                          break;
                   case 3 : new2=create();
                           printf("\n Enter the data for node  :"); 
                           scanf("%d",&new2->data);
                           if (root==NULL)
                               root=new2;
                           else
                               insert(root,new2);
                           break;
                   case 4 : if (root==NULL)
                              printf("\n Binary search tree is empty.");
                           else
                           {
                              printf("\n Enter the data for node to be search  :  "); 
                              scanf("%d",&key);
                              t1=search(root,key);
                              if (t1==NULL)
                                  printf("\n %d data is not found in binary search tree \n",key); 
                              else
                                  printf("\n %d data is found  in binary search tree \n",key);
                           }
                           break;
                   case 5 : if (root==NULL)
                              printf("\n Binary search tree is empty.");
                          else
                          {
                              printf("\n Enter the data for node to be delete  :  "); 
                              scanf("%d",&key);
                              root=delete(root,key);
                          }
                          break;
                   case 6 : if (root==NULL)
                                printf("\n Binary search tree is empty.");
                            else
                            {
                               cnt=count(root);
                               printf("\n Total no of nodes in binary search tree : %d \n",cnt);
                            }                
                            break;
                   case 7:if (root==NULL)
                                printf("\n Binary search tree is empty.");
                            else
                            {
                               cnt=countleaf(root);
                               printf("\n Total no of leaf nodes in binary search tree :  %d \n",cnt);
                            }
                            break;
                   default:printf("\n Enter a valid option .");
           }
            if (op!=2)
               btreetraverse(root);
      }
}
/*
Output:

Binary search tree Operations 
1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  1

Enter the number of nodes : 7
Enter the data for node 1 :  55
Enter the data for node 2 :  65
Enter the data for node 3 :  45
Enter the data for node 4 :  70
Enter the data for node 5 :  40
Enter the data for node 6 :  60
Enter the data for node 7 :  50

Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  2

Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  2

Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  3

Enter the data for node  :  57

Binary search tree in preorder : 	55  45  40  50  65  60  57  70  
Binary search tree in inorder : 	40  45  50  55  57  60  65  70  
Binary search tree in postorder : 	40  50  45  57  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  6

Total no of nodes in binary search tree : 8 

Binary search tree in preorder : 	55  45  40  50  65  60  57  70  
Binary search tree in inorder : 	40  45  50  55  57  60  65  70  
Binary search tree in postorder : 	40  50  45  57  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  7

Total no of leaf nodes in binary search tree :  4 

Binary search tree in preorder : 	55  45  40  50  65  60  57  70  
Binary search tree in inorder : 	40  45  50  55  57  60  65  70  
Binary search tree in postorder : 	40  50  45  57  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  5

Enter the data for node to be delete  :  57

Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  6

Total no of nodes in binary search tree : 7 

Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  7

Total no of leaf nodes in binary search tree :  4 

Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  4

Enter the data for node to be search  :  55
55 data is found  in binary search tree 
 
Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  4

Enter the data for node to be search  :  10
10 data is not found in binary search tree 
 
Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

1 : Create a binary search tree 
2 : Traverse a binary search tree 
3 : Insert Node in a binary search tree 
4 : Search Node in  a binary search tree 
5 : Delete node in binary search tree 
6 : Count total no of nodes a binary search tree 
7 : Count leaf nodes a binary search tree 
Enter the desired option :  6

Total no of nodes in binary search tree : 7 

Binary search tree in preorder : 	55  45  40  50  65  60  70  
Binary search tree in inorder : 	40  45  50  55  60  65  70  
Binary search tree in postorder : 	40  50  45  60  70  65  55  

*/               
                   
                   
                   
                   
                   
                   
                   
                   
                     


