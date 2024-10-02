#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MemSize 23             /* 陣列大小 */

typedef struct{
    int ItemKey;
    /*   堆疊元素的其它欄位  */
}element;

element Mem[MemSize];
int top[MemSize];
int boundary[MemSize+1];
int MaxStacks;    /* 記錄堆疊數量 */

void CreateStack(void)
{
 int i;

 printf("輸入堆疊量,勿超過%d:",MemSize);
 scanf("%d",&MaxStacks);

 top[0] = boundary[0] = -1;
 for(i=1;i<MaxStacks;i++)
 {
   top[i]=boundary[i]=((int)(MemSize/MaxStacks))*i;
 }
 boundary[MaxStacks]= MemSize-1;
}

void push(int i,element Item)
{
  if(top[i] == boundary [i+1])
  {
     printf("堆疊S%d已滿!",i);
     exit(1);
  }
  Mem[++top[i]] = Item;
}
element pop(int i)
{
  if (top[i] == boundary[i])
  {
     printf("堆疊S%d已空!",i);
     exit(1);
  }
  return Mem[top[i]--];
}

void PrintMemStack(void)
{
  int i;
  for(i=0;i<MemSize;i++)
     printf("|%2d",Mem[i]);
  printf("|\n");

  for(i=0;i<MaxStacks;i++)
     printf("top[%d]=%d \t",i,top[i]);
  printf("\n");
  for(i=0;i<=MaxStacks;i++)
     printf("boundary[%d]=%d \t",i,boundary[i]);
  printf("\n");
}

int main(void)
{
  element Item;
  int i;
  char ch='I';

  CreateStack();

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
        push(i,Item);
        printf("push S%d->%d\n",i,Item.ItemKey);
        break;
      case 'O':
        printf("請輸入要pop的堆疊編號:");   scanf("%d",&i);
        while((i>=MaxStacks) || i<0)
        {
         printf("請輸入要push的堆疊編號:"); scanf("%d",&i);
        }
        printf("pop S%d->%d\n",i,pop(i).ItemKey);
        break;
      case 'P':
        PrintMemStack();
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

