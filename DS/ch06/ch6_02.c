#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#include "lib6_02.h"

void PrintQueue(QueueADT *Q)
{
  int i;
  printf("front值目前=%d,rear值目前=%d,佇列如下:\n",
          Q->front,Q->rear);

  if(Q->front>=Q->rear)
  {
    printf("佇列已空!\n");
    return;
  }

  for(i=0;i<=5;i++)
     printf("  Q[%d]  ",i);
  printf(".....\n");


  for(i=0;i<=5;i++)
  {
    if(i<=Q->front || i>Q->rear)
       printf("|  ==\t");
    else
       printf("|  %2d\t",Q->queue[i]);
  }
  printf("|.....\n");
}

int main(void)
{
  element Item;
  int i;
  QueueADT Q1;
  char ch='I';

  Q1=CreateQueue();

  while(ch!='E')
  {
    fflush(stdin);
    printf("[A]=AddQ,[D]=DeleteQ,[E] and [Others]=Exit:");
    scanf("%c",&ch);
    switch(ch)
    {
      case 'A':
        printf("AddQ :");
        scanf("%d",&Item.ItemKey);
        AddQ(&Q1,Item);
        printf("AddQ入%d,",Item.ItemKey);
        PrintQueue(&Q1);
        break;
      case 'D':
        printf("DeleteQ出%d,",DeleteQ(&Q1).ItemKey);
        PrintQueue(&Q1);
        break;
      default:
        ch='E';
        printf("byebye!!\n");
        break;
    }
  }
  system("pause");
  return 0;
}
