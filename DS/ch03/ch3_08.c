#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */
#include "lib3_07.h"           /* ���J�d��3-7���禡 */

/*********  ��J�x�}����  **********/
double* SetAllElt(double *PTo_Matrix,int p,int q)
{
   float value;
   int i,j;
   for(i=1;i<=p;i++)
   {
     for(j=1;j<=q;j++)
     {
        printf("����(%d%d)=",i,j);     scanf("%f",&value);
        PTo_Matrix=SetElt(PTo_Matrix,p,q,i,j,(double)value);
     }
   }
   return PTo_Matrix;
}
/***********  �C�L�x�}  ***********/
void PrintAllElt(double *PTo_Matrix,int p,int q)
{
   int i,j;
   for(i=1;i<=p;i++)
   {
     printf("|");
     for(j=1;j<=q;j++)
        printf("%7.3f  ",RetrieveElt(PTo_Matrix,p,q,i,j));
     printf("|\n");
   }
}
/***********  ��m�B��  ***********/
double* Transpose(double *PTo_Matrix,int p,int q)
{
   double *T;
   int i,j;
   T=Create(q,p);
   for(i=1;i<=p;i++)
     for(j=1;j<=q;j++)
   	   T=SetElt(T,q,p,j,i,RetrieveElt(PTo_Matrix,p,q,i,j));
   return T;
}
int main(void)
{
  double *A,*B;
  int p,q;

  printf("�п�JA�x�}���j�p(pxq)\n");
  printf("p=");    scanf("%d",&p);
  printf("q=");    scanf("%d",&q);

  A=Create(p,q);        /*  �إ߯x�}  */
  A=SetAllElt(A,p,q);   /*  ��J�x�}����  */
  B=Transpose(A,p,q);   /*  ��m�B��  */

  printf("��l�x�}�p�U:\n");
  PrintAllElt(A,p,q);
  printf("��m�x�}�p�U:\n");
  PrintAllElt(B,q,p);

  FreeMaxtrix(A);
  FreeMaxtrix(B);
  system("pause");
  return 0;
}
