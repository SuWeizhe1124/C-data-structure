#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#include "lib6_06.h"

void CreateStacks(void)
{
  int i;
  for(i=0;i<MaxStacks;i++)
    top[i]=NULL;
}

void PrintStack(int i)
{
  S_Node_P visitP;
  visitP=top[i];
  printf("堆疊頂端|");
  while(visitP!=NULL)
  {
    printf("%d|",visitP->Item.ItemKey);
    visitP=visitP->link;
  }
  printf("堆疊底端\n");
}

int main(void)
{
  element Item;
  int i;
  char ch='I';

  CreateStacks();

  while(ch!='E')
  {
    fflush(stdin);
    printf("[I]=push,[O]=pop,[P]=print,[E]and[Others]=Exit:");
    scanf("%c",&ch);
    switch(ch)
    {
      case 'I':
        printf("請輸入要push的堆疊編號:");  scanf("%d",&i);
        while((i>=MaxStacks) || i<0)
        {
         printf("請輸入要push的堆疊編號:"); scanf("%d",&i);
        }
        printf("push to S%d:",i);
        scanf("%d",&Item.ItemKey);
        push(&top[i],Item);
        printf("push S%d->%d\n",i,Item.ItemKey);
        break;
      case 'O':
        printf("請輸入要pop的堆疊編號:");   scanf("%d",&i);
        while((i>=MaxStacks) || i<0)
        {
         printf("請輸入要push的堆疊編號:"); scanf("%d",&i);
        }
        printf("pop S%d->%d\n",i,pop(&top[i]).ItemKey);
        break;
      case 'P':
        printf("請輸入要檢視堆疊的編號:");   scanf("%d",&i);
        while((i>=MaxStacks) || i<0)
        {
         printf("請輸入要檢視堆疊的編號:");   scanf("%d",&i);
        }
        PrintStack(i);
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
