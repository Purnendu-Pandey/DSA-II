#include<stdio.h>
void heapsort(int b[],int n);
void heapify(int b[],int n,int i);
int i,n;

void heapify (int b[],int n,int i)
{
     int largest,l,r,temp;
     largest=i;
     l=2*i;
     r=(2*i)+1;
     
     if (l<n && b[l]>b[largest])
         largest=l;
     if (r<n && b[r]>b[largest])
         largest =r;
     if (largest != i)
     {
         temp=b[largest];
         b[largest]=b[i];
         b[i]=temp;
         heapify(b,n,largest);
     }
}
void heapsort(int b[],int n)
{
     int i,temp;
     for (i=n/2-1;i>=0;i--)
          heapify(b,n,i);
     printf ("\n The  Max  heap : \n\t\t");
     for (i=0;i<n;i++)
         printf ("%d ",b[i]);
     printf("\n\n");
     for (i=n-1;i>=0;i--)
     {
         temp=b[0];
         b[0]=b[i];
         b[i]=temp;
         heapify(b,i,0);
     }
}

void main()
{
     int  b[15];
     printf ("\n Enter the dataset size : ");
     scanf ("%d",&n);
     printf ("\n Enter the dataset elements : ");
     for (i=0;i<n;i++)
         scanf ("%d",&b[i]);  
     printf ("\n The Input dataset elements are : \n\t\t");
     for (i=0;i<n;i++)
         printf ("%d ",b[i]);
     heapsort(b,n);
     printf ("\n The dataset  elements in ascending sorted order : \n\t\t");
     for (i=0;i<n;i++)
         printf ("%d\t ",b[i]);
     printf("\n ");
}

/*
OUTPUT:
Enter the dataset size : 5
Enter the dataset elements:
10 
5
22
7
54

The Input data elements are : 
10 5 22 7 54 
The heap data elements are : 
54 22 10 7 5 
The data elements in ascending sorted order : 
5	7	10	 22	 54	 
*/










      
