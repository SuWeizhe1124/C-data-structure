#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#include "lib6_03.h"

void PrintCQueue(CQueueADT *CQ)
{
  int i;
  printf("front�ȥثe=%d,rear�ȥثe=%d,������C�p�U:\n",
          CQ->front,CQ->rear);

  if(isEmpty(*CQ)==true)
  {
    printf("��C�w��!\n");
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
        printf("AddCQ�J%d\n",Item.ItemKey);
        break;
      case 'D':
        printf("DeleteCQ�X%d\n",DeleteCQ(&CQ1).ItemKey);
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
