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

bool IsSquareMartix(int p,int q)
{
 if((p>0) && (q>0) && (p==q))
    return true;
 return false;
}
