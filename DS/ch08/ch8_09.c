/*   Shortest Path - Floyd's algorithm  */
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexSize 4 /* 最多頂點+1 */
#define INFINITE 99 /* 用以代表無限大 */

void Floyd_shortestpath(int edgeCost[][MaxVertexSize],int A[][MaxVertexSize],int n);

int main()
{
  int edgeCost[][MaxVertexSize]={{-1,-1,-1,-1},
                                 {-1, 0,10,15},
                                 {-1,12, 0, 4},
                                 {-1, 7,99, 0}};

  int A[MaxVertexSize][MaxVertexSize];
  int n=MaxVertexSize;
  int i,j;

  Floyd_shortestpath(edgeCost,A,n);  /* 計算最短路徑 */

  for(i=1;i<n;i++)
  {
   for(j=1;j<n;j++)
   {
    if(A[i][j]<INFINITE)
     printf("  %2d  ",A[i][j]);
    else
     printf("==");
   }
   printf("\n");
  }
  system("pause");
  return 0;
}

void Floyd_shortestpath(int edgeCost[][MaxVertexSize],int A[][MaxVertexSize],int n)
{
  int i,j,k;
  for(i=1;i<n;i++)                        /* 求A0 */
    for(j=1;j<n;j++)
      A[i][j]=edgeCost[i][j];

  for(k=1;k<n;k++)                        /* 求A1~A3 */
    for(i=1;i<n;i++)
      for(j=1;j<n;j++)
        if (A[i][j]>A[i][k]+A[k][j])
          A[i][j]=A[i][k]+A[k][j];
}


