#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#define p 3   /* size of row of A */
#define q 3   /* size of column of A */
#define r 4   /* size of row of B */
#define s 6   /* size of column of B */

bool IsSquareMatrix(int m,int n)
{
 if((m>0) && (n>0) && (m==n))
    return true;
 return false;
}

int main(void)
{
  int i=1,j=1;

 /****************�إ߯x�}***********************/
  double A[p][q];   /*   �۷��Create�B��      */
  double B[r][s];   /*   �۷��Create�B��      */
 /***********�]�w�x�}�����P���X�x�}����**********/
   B[i-1][j-1]=15.6;   /*  SetElement�B��,�]�wb11=15.6  */
   printf("b11=%f\n",B[i-1][j-1]); /* RetrieveElement�B��  */
 /**************�P�_�x�}�O�_����}**************/
  if(IsSquareMatrix(p,q))
     printf("�x�}A(%dx%d)�O��}\n",p,q);
  else
     printf("�x�}A(%dx%d)���O��}\n",p,q);
  system("pause");
  return 0;
}
