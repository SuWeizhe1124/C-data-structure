#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */
#include "lib3_07.h"           /* 載入範例3-7之函式 */

/*********  輸入矩陣元素  **********/
double* SetAllElt(double *PTo_Matrix,int p,int q)
{
   float value;
   int i,j;
   for(i=1;i<=p;i++)
   {
     for(j=1;j<=q;j++)
     {
        printf("元素(%d%d)=",i,j);     scanf("%f",&value);
        PTo_Matrix=SetElt(PTo_Matrix,p,q,i,j,(double)value);
     }
   }
   return PTo_Matrix;
}
/***********  列印矩陣  ***********/
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
/***********  轉置運算  ***********/
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

  printf("請輸入A矩陣的大小(pxq)\n");
  printf("p=");    scanf("%d",&p);
  printf("q=");    scanf("%d",&q);

  A=Create(p,q);        /*  建立矩陣  */
  A=SetAllElt(A,p,q);   /*  輸入矩陣元素  */
  B=Transpose(A,p,q);   /*  轉置運算  */

  printf("原始矩陣如下:\n");
  PrintAllElt(A,p,q);
  printf("轉置矩陣如下:\n");
  PrintAllElt(B,q,p);

  FreeMaxtrix(A);
  FreeMaxtrix(B);
  system("pause");
  return 0;
}
