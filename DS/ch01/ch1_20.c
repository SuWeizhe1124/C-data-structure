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
     *(square+s)=0;              /*將陣列元素全部設定為0*/
  *(square+(x*n)+y)=1;
  for(number=2;number<=(n*n);number++)
  {
    i=((x-1)+n)%n; j=((y-1)+n)%n;  /* 為預防餘數為負數,故+n */
    if (*(square+(i*n)+j)!=0)
        x = (x+1) % n;
    else
    {   x=i; y=j;    }
    *(square+(x*n)+y)=number;
  }
  /*********** 列印方陣資料 ************/
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
  int *workarray;             /* 指標與陣列是一體兩面 */
  printf("請輸入階數(奇數):");
  scanf("%d",&n);

  workarray=(int*)malloc(sizeof(int)*n*n); /* 動態配置記憶體 */
  if(MAGIC_SQUARE(workarray,n))
  {
    printf("錯誤的階數,請輸入奇數!\n");
    /* system("pause"); */
    return 1;
  }
  free(workarray);
  /* system("pause"); */
  return 0;
}

