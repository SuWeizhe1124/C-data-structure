/*  Interpolation Search algorithm  */
#include <stdio.h>
#include <stdlib.h>
typedef struct{
      int key;
      char data;
      /*   ��L������ */
}record;

void SetData(record x[],int n)
{
  int key[10]={55,85,147,156,606,700,772,2715,2813,2873};
  int data[10]={'A','F','G','E','J','Q','W','X','U','P'};
  int i;

  for(i=0;i<n;i++)             
  {
    x[i].key=key[i];      x[i].data=data[i];
  }
}

int InterpolationSearch(record x[],int n,int k)
{
  int low,high,mid;

  low = 0;
  high = n-1;
  while ((x[low].key<k) && (x[high].key>= k))
  {
   mid=low+(((k-x[low].key)*(high-low))/(x[high].key-x[low].key));
   /*  �`�N�W�z�������۰ʸ�ƫ��A�վ�,���i�ϱo�U�����L���X�{ */
   if(x[mid].key == k)  return mid;
   if (x[mid].key < k)  low = mid + 1;    /* ���e�� */
   else                 high = mid - 1;   /* ���᭱ */
  }
  if (x[low].key == k)
    return low;
  else
    return -1;  /* �S���ŦX���O�� */
}

int main()
{
  int loc,n=10;
  record x[10];

  SetData(x,10);
  loc=InterpolationSearch(x,10,700); /*�j�Mkey=700���O�� */
  if (loc==-1)
    printf("�L�������\n");
  else
    printf("x[%d]=%d \t %c\n",loc,x[loc].key,x[loc].data);
  system("pause");
  return 0;
}
