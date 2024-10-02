/*   Bubble Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int n)
{
  int data[5]={24,7,36,2,65};
  int i;
  for(i=0;i<n;i++)             
     x[i]=data[i];
}

void BubbleSort(int x[],int n)
{
  int i,k,flag,temp;
  
  k=n-1;
  while(k!=0)
  { 
    flag=0;          /*  記錄此回合掃描是否有資料進行互換  */
    for(i=0;i<=k-1;i++)
    {
     if(x[i] > x[i+1])
     {
       temp=x[i]; x[i]=x[i+1]; x[i+1]=temp;
       flag=i;
     }
    }
    k=flag;
  }
}

void PrintData(int x[],int n)
{
   int i;
   for(i=0;i<n;i++)             
     printf("%2d  ",x[i]);
   printf("\n");
} 

int main()
{
  int x[5]={0};

  SetData(x,5);
  printf("排序前  "); PrintData(x,5);
  BubbleSort(x,5);
  printf("排序後  "); PrintData(x,5);

  system("pause");
  return 0;
}
