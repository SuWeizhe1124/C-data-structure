#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#include "lib6_03.h"

void PrintCQueue(CQueueADT *CQ)
{
  int i;
  printf("front值目前=%d,rear值目前=%d,環狀佇列如下:\n",
          CQ->front,CQ->rear);

  if(isEmpty(*CQ)==true)
  {
    printf("佇列已空!\n");
    return;
  }

  for(i=0;i<5;i++)
     printf("  CQ[%d] ",i);
  printf("\n");

  for(i=0;i<5;i++)
  {
      if(i==CQ->front)
        printf("|   N\t");
      else
        printf("|%4d\t",CQ->cqueue[i]);
  }
  printf("|\n");
}

int main(void)
{
  element Item;
  int i;
  CQueueADT CQ1;
  char ch='I';

  CQ1=CreateCQueue();
  for(i=0;i<MaxCQueueSize;i++)
    CQ1.cqueue[i].ItemKey=0;
  while(ch!='E')
  {
    fflush(stdin);
    printf("[A]=AddQ,[D]=DeleteQ,[E] and [Others]=Exit:");
    scanf("%c",&ch);
    switch(ch)
    {
      case 'A':
        printf("AddCQ :");
        scanf("%d",&Item.ItemKey);
        AddCQ(&CQ1,Item);
        printf("AddCQ入%d\n",Item.ItemKey);
        break;
      case 'D':
        printf("DeleteCQ出%d\n",DeleteCQ(&CQ1).ItemKey);
        break;
      default:
        ch='E';
        PrintCQueue(&CQ1);
        printf("byebye!!\n");
        break;
    }
  }

  system("pause");
  return 0;
}
