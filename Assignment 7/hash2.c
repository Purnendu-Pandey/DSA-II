#include<stdio.h>
int index1(int num1)
{
      long sqr;
      int ind;
      sqr=num1*num1;
      //printf("\n Square of number %d",sqr);
      if (sqr < 99)
          ind=sqr%10;
      else
      if (sqr < 999)
      {
           sqr /= 10; 
           ind=sqr%10;
      }
      else
      if (sqr < 9999)
      {
          sqr /= 10; 
          ind=sqr%100;
      }
      else
      if (sqr < 999999)
      {
          sqr /= 100; 
          ind=sqr%100;
          printf("\n %d %d ",sqr,ind);
      }
      else
      {
          sqr /= 100; 
          ind=sqr%100;
          printf("\n %d %d ",sqr,ind);
      }
      return ind;   
}
void main ()
{
     int i,j,n,key,num,cnt,sqr,ind1;
     printf ("\n Enter size of hash table : ");
     scanf ("%d",&n);
     printf ("\n Enter size of data set : ");
     scanf ("%d",&cnt);
     /*
     if (n<cnt)
     {
        printf("\n Size  overflow\n\n");
        return;
     }
     */
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
         ind1=index1(num);
         printf("\n Square of number %d",num*num);
         if (hash[ind1]!=-1)
         {
             printf("\n Collision occurs at index %d for data %d",ind1,num);
             cnt++;
             printf("\n\n Updated hash table \n Hash index  Data");
             for (j=0;j<n;j++)
                 //if (hash[j]!=-1)
                     printf("\n  %6d   %6d",j,hash[j]);
             continue;
         }
         else
         {
             ind1=index1(num);
             hash[ind1]=num;
         }
         printf("\n\n Updated hash table \n Hash index  Data");
         for (j=0;j<n;j++)
             printf("\n  %6d   %6d",j,hash[j]);
         printf("\n");           
     }
     printf("\n\n");
}

/*
OUTPUT:
y57@pc21:~/DS_SEM_4_SYBSC_57/ASSIGNMENT 7$ ./a.out

 Enter size of hash table : 100

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
      10       -1
      11       -1
      12       -1
      13       -1
      14       -1
      15       -1
      16       -1
      17       -1
      18       -1
      19       -1
      20       -1
      21       -1
      22       -1
      23       -1
      24       -1
      25       -1
      26       -1
      27       -1
      28       -1
      29       -1
      30       -1
      31       -1
      32       -1
      33       -1
      34       -1
      35       -1
      36       -1
      37       -1
      38       -1
      39       -1
      40       -1
      41       -1
      42       -1
      43       -1
      44       -1
      45       -1
      46       -1
      47       -1
      48       -1
      49       -1
      50       -1
      51       -1
      52       -1
      53       -1
      54       -1
      55       -1
      56       -1
      57       -1
      58       -1
      59       -1
      60       -1
      61       -1
      62       -1
      63       -1
      64       -1
      65       -1
      66       -1
      67       -1
      68       -1
      69       -1
      70       -1
      71       -1
      72       -1
      73       -1
      74       -1
      75       -1
      76       -1
      77       -1
      78       -1
      79       -1
      80       -1
      81       -1
      82       -1
      83       -1
      84       -1
      85       -1
      86       -1
      87       -1
      88       -1
      89       -1
      90       -1
      91       -1
      92       -1
      93       -1
      94       -1
      95       -1
      96       -1
      97       -1
      98       -1
      99       -1
Enter  data element : 12
Square of number 144
Updated hash table 
Hash index  Data
       4       12

Enter  data element : 2
Square of number 4
Collision occurs at index 4 for data 2
Updated hash table 
Hash index  Data
       4       12

Enter  data element : 13
Square of number 169
Updated hash table 
Hash index  Data
       4       12
       6       13

Enter  data element : 16
Square of number 256
Updated hash table 
Hash index  Data
       4       12
       5       16
       6       13

Enter  data element : 15
Square of number 225
Updated hash table 
Hash index  Data
       2       15
       4       12
       5       16
       6       13

Enter  data element : 8
Square of number 64
Collision occurs at index 4 for data 8
Updated hash table 
Hash index  Data
       2       15
       4       12
       5       16
       6       13
Enter  data element : 9
Square of number 81
Updated hash table 
Hash index  Data
       1        9
       2       15
       4       12
       5       16
       6       13

Enter  data element : 10
Square of number 100
Updated hash table 
Hash index  Data
       0       10
       1        9
       2       15
       4       12
       5       16
       6       13

Enter  data element : 17
Square of number 289
Updated hash table 
Hash index  Data
       0       10
       1        9
       2       15
       4       12
       5       16
       6       13
       8       17

Enter  data element : 25
Square of number 625
Collision occurs at index 2 for data 25
Updated hash table 
Hash index  Data
       0       10
       1        9
       2       15
       4       12
       5       16
       6       13
       8       17
Enter  data element : 14
Square of number 196
Updated hash table 
Hash index  Data
       0       10
       1        9
       2       15
       4       12
       5       16
       6       13
       8       17
       9       14

Enter data element : 11 
Square of number 121
Collision occurs at index 2 for data 11
Updated hash table 
Hash index  Data
       0       10
       1        9
       2       15
       4       12
       5       16
       6       13
       8       17
       9       14
Enter  data element :  65
Square of number 4225
Updated hash table 
Hash index  Data
       0       10
       1        9
       2       15
       4       12
       5       16
       6       13
       8       17
       9       14
      22       65
*/
