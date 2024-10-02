/*   Selection Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int n)
{
  int data[5]={24,21,36,42,25};
  int i;
  for(i=0;i<n;i++)             
     x[i]=data[i];
}

void SelectionSort(int x[],int n)
{
	
   int i,j,minIndex,minValue,temp;
   for(i=0;i<n;i++)
   {
    minIndex=i;		       /* minIndexゼ逼场だ程ま */
    minValue=x[minIndex];  /* minValueゼ逼场だ程*/
 
    /* тゼ逼场だ程 */
    for(j=i+1;j<n; j++ )
    {
      if(x[j] < minValue)
      {
        minIndex = j;
        minValue = x[minIndex];
      }
    }
    temp=x[minIndex];    x[minIndex] = x[i];    x[i]=temp;
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
  printf("逼玡  "); PrintData(x,5);
  SelectionSort(x,5);
  printf("逼  "); PrintData(x,5);

  system("pause");
  return 0;
}
