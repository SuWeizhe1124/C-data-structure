/*   Quick Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int n)
{
  int data[10]={30,24,27,16,29,33,25,18,32,35};
  int i;
  for(i=0;i<n;i++)             
     x[i]=data[i];
}

void PrintData(int x[],int a,int b)
{
   int i;
   for(i=0;i<a;i++)
     printf("   ");
   for(i=a;i<=b;i++)
     printf("%3d",x[i]);
   printf("\n");
}

void QuickSort(int x[],int left,int right)
{
  int i,j,temp,K;

  printf("left=%2d,right=%2d  ",left,right);
  PrintData(x,left,right);

  if(left<right)
  {
   i = left+1;
   j = right;
   K=x[left];
   do
   {
     while(x[i]<K)
       i++;         /* 由左向右尋找正確位置 */
     while(x[j]>K)
       j--;        /*  由右向左尋找正確位置*/
     if(i<j)
     {
        temp=x[i]; x[i]=x[j]; x[j]=temp;
     }
   }while(i<j);
   temp=x[left]; x[left]=x[j]; x[j]=temp;
   QuickSort(x,left,j-1);    /* 左半部繼續排序 */
   QuickSort(x,j+1 ,right);  /* 右半部繼續排序 */
  }
}

int main()
{
  int x[10]={0};

  SetData(x,10);
  printf("排序前            "); PrintData(x,0,9);
  QuickSort(x,0,9);
  printf("排序後            "); PrintData(x,0,9);
  system("pause");
  return 0;
}
