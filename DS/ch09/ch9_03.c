/*   Insertion Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int n)
{
  int data[5]={24,21,16,42,25};
  int i;
  for(i=0;i<n;i++)             
     x[i]=data[i];
}

void PrintData(int x[],int n)
{
   int i;
   for(i=0;i<n;i++)             
     printf("%2d  ",x[i]);
   printf("\n");
} 

void InsertionSort(int x[],int n)
{
	
  int i,j,temp;
  for(j=1;j<n;j++)
  {

   temp=x[j];
   i=j-1;
   while(temp < x[i] && i>=0)   /* 往後搬移資料，以騰出空間插入新資料 */
   {
     x[i+1]=x[i];
     i--;
   }
   x[i+1]=temp;  /* 騰出的空間存入新資料 */
   printf("Step %d  ",j);  PrintData(x,j+1);
  }
}

int main()
{
  int x[5]={0};

  SetData(x,5);
  printf("排序前  "); PrintData(x,5);
  InsertionSort(x,5);
  printf("排序後  "); PrintData(x,5);

  system("pause");
  return 0;
}
