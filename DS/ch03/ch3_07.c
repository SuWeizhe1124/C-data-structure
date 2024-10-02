#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

double* Create(int p,int q)
{
  double *PTo_Matrix;

  if((p>0) && (q>0))
  {
    PTo_Matrix=(double *)malloc(sizeof(double)*p*q);
    return PTo_Matrix;
  }
  else
    exit(1);
}

void FreeMaxtrix(double *PTo_Matrix)
{
  free(PTo_Matrix);
}

double* SetElt(double *PTo_Matrix,int p,int q,int i,int j,double value)
{
 if((i<=p) && (j<=q))
 {
   PTo_Matrix[(i-1)*q+(j-1)]=value;
     /*   上一行相當於  *(PTo_Matrix+((i-1)*q)+(j-1))=value;
          也就是(PTo_Matrix[i-1][j-1]=value)   */
    return PTo_Matrix;
 }
 else
    exit(1);
}
double RetrieveElt(double *PTo_Matrix,int p,int q,int i,int j)
{
 if((i<=p) && (j<=q))
    return PTo_Matrix[(i-1)*q+(j-1)];
 else
    exit(1);
}

bool IsSquareMatrix(int p,int q)
{
 if((p>0) && (q>0) && (p==q))
    return true;
 return false;
}

int main(void)
{
  double *A,*B;
  int p,q,r,s;

  printf("請輸入A矩陣的大小(pxq)\n");
  printf("p=");    scanf("%d",&p);
  printf("q=");    scanf("%d",&q);

  printf("請輸入B矩陣的大小(rxs)\n");
  printf("r=");    scanf("%d",&r);
  printf("s=");    scanf("%d",&s);

 /****************建立矩陣***********************/
  A=Create(p,q);
  B=Create(r,s);

 /***********設定矩陣元素與取出矩陣元素**********/
  B=SetElt(B,r,s,1,1,15.6);   /* 設定b11=15.6 */
  printf("b11=%f\n",RetrieveElt(B,r,s,1,1));
 /**************判斷矩陣是否為方陣**************/
  if(IsSquareMatrix(p,q))
     printf("矩陣A(%dx%d)是方陣\n",p,q);
  else
     printf("矩陣A(%dx%d)不是方陣\n",p,q);
 /*********釋放矩陣佔用的記憶體空間*************/
  FreeMaxtrix(A);
  FreeMaxtrix(B);
  system("pause"); 
  return 0;
}
