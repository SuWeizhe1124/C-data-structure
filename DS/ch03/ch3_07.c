#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

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
     /*   �W�@��۷��  *(PTo_Matrix+((i-1)*q)+(j-1))=value;
          �]�N�O(PTo_Matrix[i-1][j-1]=value)   */
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

  printf("�п�JA�x�}���j�p(pxq)\n");
  printf("p=");    scanf("%d",&p);
  printf("q=");    scanf("%d",&q);

  printf("�п�JB�x�}���j�p(rxs)\n");
  printf("r=");    scanf("%d",&r);
  printf("s=");    scanf("%d",&s);

 /****************�إ߯x�}***********************/
  A=Create(p,q);
  B=Create(r,s);

 /***********�]�w�x�}�����P���X�x�}����**********/
  B=SetElt(B,r,s,1,1,15.6);   /* �]�wb11=15.6 */
  printf("b11=%f\n",RetrieveElt(B,r,s,1,1));
 /**************�P�_�x�}�O�_����}**************/
  if(IsSquareMatrix(p,q))
     printf("�x�}A(%dx%d)�O��}\n",p,q);
  else
     printf("�x�}A(%dx%d)���O��}\n",p,q);
 /*********����x�}���Ϊ��O����Ŷ�*************/
  FreeMaxtrix(A);
  FreeMaxtrix(B);
  system("pause"); 
  return 0;
}
