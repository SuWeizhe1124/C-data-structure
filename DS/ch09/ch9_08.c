/*   Shell Sort algorithm  */
#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int n)
{
  int data[9]={24,15,33,61,16,62,39,41,25};
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

void ShellSort(int x[],int n)
{
  int i,j,increment,temp;

  increment = n / 2;  /* �㰣,�۰ʫ��A�ഫ�|�N�p�Ƴ����h�� */
  while(increment>0)
  {
   for(i=increment;i<n;i++)   /* ���� */
   {
      j=i-increment;         /* �U���նi�洡�J�Ƨ� */
      while(j>=0)
      {
       if(x[j] > x[j+increment])
       {
        temp=x[j]; x[j]=x[j+increment]; x[j+increment]=temp;
       }
       else
        j=j-increment;
      }
   }
   printf("        "); PrintData(x,9);
   increment=increment / 2;
  }
}

int main()
{
  int x[9]={0};

  SetData(x,9);
  printf("�Ƨǫe  "); PrintData(x,9);
  ShellSort(x,9);
  printf("�Ƨǫ�  "); PrintData(x,9);

  system("pause");
  return 0;
}
