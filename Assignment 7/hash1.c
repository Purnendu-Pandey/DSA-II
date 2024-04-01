#include<stdio.h>
void main()
{
     int i,j,n,key,ind,k,cnt=0;
     printf("Enter Size Of Hash Table : ");
     scanf("%d",&n);
     int hash[n];
     printf("\nEnter Key Of Hash Table : ");
     scanf("%d",&k);
     printf("\nInitial Hash Table :\nIndex  Data\n");
     for (i=0;i<n;i++)
     {
         hash[i]=-1;
         printf("%d        %d\n",i,hash[i]);
     }
     printf("Enter %d Elements : ",n);
     for (i=0;i<n;i++)
     {
         printf("\nEnter Element : ");
         scanf("%d",&key);
         ind=key%k;
         if (hash[ind]!=-1)
         {
            printf("\nCollision Occured At Index %d for %d Element...\n",ind,key);
            i--;
            continue;
         }
         else
            hash[ind]=key;
         printf("Updated Hash Table :\nIndex  Data\n");
         for (j=0;j<n;j++)
             printf("  %d     %d\n",j,hash[j]);
     }
}  

/*
OUTPUT:-
Enter Size Of Hash Table : 10
Enter Key Of Hash Table : 10

Initial Hash Table :
Index  Data
0        -1
1        -1
2        -1
3        -1
4        -1
5        -1
6        -1
7        -1
8        -1
9        -1
Enter 10 Elements : 
Enter Element : 10
Updated Hash Table :
Index  Data
  0     10
  1     -1
  2     -1
  3     -1
  4     -1
  5     -1
  6     -1
  7     -1
  8     -1
  9     -1

Enter Element : 11
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     -1
  3     -1
  4     -1
  5     -1
  6     -1
  7     -1
  8     -1
  9     -1

Enter Element : 16
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     -1
  3     -1
  4     -1
  5     -1
  6     16
  7     -1
  8     -1
  9     -1

Enter Element : 24
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     -1
  3     -1
  4     24
  5     -1
  6     16
  7     -1
  8     -1
  9     -1

Enter Element : 16

Collision Occured At Index 6 for 16 Element...

Enter Element : 15
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     -1
  3     -1
  4     24
  5     15
  6     16
  7     -1
  8     -1
  9     -1

Enter Element : 13
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     -1
  3     13
  4     24
  5     15
  6     16
  7     -1
  8     -1
  9     -1

Enter Element : 19
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     -1
  3     13
  4     24
  5     15
  6     16
  7     -1
  8     -1
  9     19

Enter Element : 5 

Collision Occured At Index 5 for 5 Element...

Enter Element : 12
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     12
  3     13
  4     24
  5     15
  6     16
  7     -1
  8     -1
  9     19

Enter Element : 17
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     12
  3     13
  4     24
  5     15
  6     16
  7     17
  8     -1
  9     19

Enter Element : 18
Updated Hash Table :
Index  Data
  0     10
  1     11
  2     12
  3     13
  4     24
  5     15
  6     16
  7     17
  8     18
  9     19



*/
