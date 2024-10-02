#include <stdio.h>
#include <stdlib.h>

int MAGIC_SQUARE(int *square,int n)
{
  int x,y,i,j,s,number;
  if((n%2)==0)
    return 1;
  x=0;
  y=(n-1)/2;
  for(s=0;s<n*n-1;s++)
     *(square+s)=0;              /*�N�}�C���������]�w��0*/
  *(square+(x*n)+y)=1;
  for(number=2;number<=(n*n);number++)
  {
    i=((x-1)+n)%n; j=((y-1)+n)%n;  /* ���w���l�Ƭ��t��,�G+n */
    if (*(square+(i*n)+j)!=0)
        x = (x+1) % n;
    else
    {   x=i; y=j;    }
    *(square+(x*n)+y)=number;
  }
  /*********** �C�L��}��� ************/
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf("%3d",*(square+(i*n)+j));
    printf("\n");
  }
  return 0;
}

int main(void)
{
  int n;
  int *workarray;             /* ���лP�}�C�O�@��⭱ */
  printf("�п�J����(�_��):");
  scanf("%d",&n);

  workarray=(int*)malloc(sizeof(int)*n*n); /* �ʺA�t�m�O���� */
  if(MAGIC_SQUARE(workarray,n))
  {
    printf("���~������,�п�J�_��!\n");
    /* system("pause"); */
    return 1;
  }
  free(workarray);
  /* system("pause"); */
  return 0;
}

