/*   Heap Sort algorithm */
#include <stdio.h>
#include <stdlib.h>

void SetData(int x[],int i,int n)
{
  int data[]={24,17,36,55,63,72,12,65,89,54};
  int j;

  for(j=i;j<=n;j++)
     x[j]=data[j-i];
}

void PrintData(int x[],int i,int n)
{
   int j;
   for(j=i;j<=n;j++)
     printf("%2d  ",x[j]);
   printf("\n");
}
 
void AdjustToHeap(int x[],int root,int n)
{
 int temp,parent,child;
 temp=x[root];               /* ���X�ڸ`�I��ȩ�Jtemp */

 parent=root;                    /* ���`�I���s�� */
 child=2*root;                   /* ���l�`�I���s�� */
  
  while(child <= n)
  {
     if ((child < n) && (x[child] < x[child+1]))
       child=child+1;    /* �k�l�`�I���j,�ҥH���Ӥ�����O�k�l�`�I */
     
     if(temp >= x[child])  
        break;              /* �ץ��w�g���� */
     else
     {
        x[parent]=x[child];                  /* �P���j���l�`�I���� */
        parent=child;                                /* ����U�@�h */
        child=child*2; 
     }
  }
  x[parent]=temp;             /* �ڸ`�I��ȩ�J���T����m */
}

void HeapSort(int x[],int i,int n)
{
  int temp;
  /* �Ĥ@���q */
  for(i=n/2;i>=1;i--)
  {
    AdjustToHeap(x,i,n);    /* �n�D�Nx[i]~x[n]�l��վ㬰�̤j�ְ� */
  }
  printf("�̤j�ְ�:\t");  PrintData(x,1,10);
  /* x[i:n]=x[1:10]�w���̤j�ְ� */

  /* �ĤG���q */
  for(i=n-1;i>=1;i--)
  {
    temp=x[1]; x[1]=x[i+1]; x[i+1]=temp;/* �N�@���O���w���x[i+1] */
    AdjustToHeap(x,1,i);   /* �n�D�Nx[1]~x[i]�G����վ㬰�̤j�ְ� */
    printf("i=%d���̤j�ְ�:\t",i);  PrintData(x,1,i);
  }
}

int main()
{
  int x[11]={0};

  SetData(x,1,10);
  printf("�Ƨǫe  x[1:10]="); PrintData(x,1,10);
  HeapSort(x,1,10);
  printf("�Ƨǫ�  x[1:10]="); PrintData(x,1,10);
  system("pause");
  return 0;
}
