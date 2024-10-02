#include <stdio.h>
#include <stdlib.h>

int hanoi(int n,char T1,char T2,char T3)
{
  if (n<1)
      return 1;
  if (n==1)
     printf("%c木樁最上層盤子移動到%c木樁\n",T1,T3);
  else
  {
    hanoi(n-1,T1,T3,T2);
    printf("%c木樁最上層盤子移動到%c木樁\n",T1,T3);
    hanoi(n-1,T2,T1,T3);
  }
  return 0;
}

int main(void)

{
  int n;
  printf("請輸入河內塔的盤子數:");
  scanf("%d",&n);
  if(hanoi(n,'a','b','c'))
  {
    printf("錯誤的盤子數,請輸入最小為1的正整數!\n");
    /* system("pause"); */
    return 1;
  }
 /* system("pause"); */
  return 0;
}

