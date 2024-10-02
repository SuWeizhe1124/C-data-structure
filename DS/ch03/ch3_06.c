#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

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

 /****************建立矩陣***********************/
  double A[p][q];   /*   相當於Create運算      */
  double B[r][s];   /*   相當於Create運算      */
 /***********設定矩陣元素與取出矩陣元素**********/
   B[i-1][j-1]=15.6;   /*  SetElement運算,設定b11=15.6  */
   printf("b11=%f\n",B[i-1][j-1]); /* RetrieveElement運算  */
 /**************判斷矩陣是否為方陣**************/
  if(IsSquareMatrix(p,q))
     printf("矩陣A(%dx%d)是方陣\n",p,q);
  else
     printf("矩陣A(%dx%d)不是方陣\n",p,q);
  system("pause");
  return 0;
}
