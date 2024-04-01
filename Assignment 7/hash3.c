#include<stdio.h>
void main ()
{
     int i,j,n,key,cnt,sum,ind,rem;
     long p,num;
     printf ("\n Enter size of hash table : ");
     scanf ("%d",&n);
     printf ("\n Enter size of data set : ");
     scanf ("%d",&cnt);
     if (n<cnt)
     {
        printf("\n Size  overflow\n\n");
        return;
     }
     int hash[n];
     printf ("Initial hash table : \nHash index  Data");
     for (i=0;i<n;i++) //initializing all indexes with -1
     {
           hash[i]=-1;
           printf("\n  %6d   %6d",i,hash[i]);
     }
     for (i=0;i<cnt;i++)
     {
         printf ("\n Enter  data element : ");
         scanf ("%d",&num);
         sum=0;
         p=num;
         while (num !=0)
         {
               rem=num%1000;
               sum=sum+rem;
               num /=1000;
         }
         ind=sum%n;
         if (hash [ind] ==-1)
             hash[ind]=p; 
         else
         {
            printf("\n Collision for value %d at index %d",p,ind);
            cnt++;
         }           
         printf("\n Updated hash table \n Hash index  Data");
         for (j=0;j<n;j++)
              printf("\n  %6d   %6d",j,hash[j]);    
     }
     printf("\n\n");
}

/*

OUTPUT:
Enter size of hash table : 10
Enter size of data set : 10
Initial hash table : 
Hash index  Data
       0       -1
       1       -1
       2       -1
       3       -1
       4       -1
       5       -1
       6       -1
       7       -1
       8       -1
       9       -1
Enter  data element : 123456

Updated hash table 
Hash index  Data
       0       -1
       1       -1
       2       -1
       3       -1
       4       -1
       5       -1
       6       -1
       7       -1
       8       -1
       9   123456
Enter  data element : 1234567

Updated hash table  
Hash index  Data
       0       -1
       1       -1
       2   1234567
       3       -1
       4       -1
       5       -1
       6       -1
       7       -1
       8       -1
       9   123456
Enter  data element : 321

Updated hash table 
Hash index  Data
       0       -1
       1      321
       2   1234567
       3       -1
       4       -1
       5       -1
       6       -1
       7       -1
       8       -1
       9   123456
Enter  data element : 1237

Updated hash table 
Hash index  Data
       0       -1
       1      321
       2   1234567
       3       -1
       4       -1
       5       -1
       6       -1
       7       -1
       8     1237
       9   123456
Enter  data element : 123456789
Collision for value 123456789 at index 8
Updated hash table 
Hash index  Data
       0       -1
       1      321
       2   1234567
       3       -1
       4       -1
       5       -1
       6       -1
       7       -1
       8     1237
       9   123456
Enter  data element : 1236
Updated hash table 
Hash index  Data
       0       -1
       1      321
       2   1234567
       3       -1
       4       -1
       5       -1
       6       -1
       7     1236
       8     1237
       9   123456
Enter  data element : 5615
Updated hash table 
Hash index  Data
       0     5615
       1      321
       2   1234567
       3       -1
       4       -1
       5       -1
       6       -1
       7     1236
       8     1237
       9   123456
Enter  data element : 12345678

Updated hash table 
Hash index  Data
       0     5615
       1      321
       2   1234567
       3       -1
       4       -1
       5   12345678
       6       -1
       7     1236
       8     1237
       9   123456
Enter  data element : 1555

*/