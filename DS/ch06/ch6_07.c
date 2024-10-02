#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#include "lib6_07.h"

void CreateQueues(void)
{
  int i;
  for(i=0;i<MaxQueues;i++)
  {
    front[i]=NULL;
    rear[i]=NULL;
  }
}

void PrintQueue(int i)
{
  Q_Node_P visitP;
  visitP=front[i];
  printf("��C�Y��|");
  while(visitP!=NULL)
  {
    printf("%d|",visitP->Item.ItemKey);
    visitP=visitP->link;
  }
  printf("��C����\n");
}

int main(void)
{
  element Item;
  int i;
  char ch='I';

  CreateQueues();

  while(ch!='E')
  {
    fflush(stdin);
    printf("[A]=addQ,[D]=deleteQ,[P]=print,[E]=Exit:");
    scanf("%c",&ch);
    switch(ch)
    {
     case 'A':
       printf("�naddQ����C�s��:");  scanf("%d",&i);
       while((i>=MaxQueues) || i<0)
       {
        printf("�naddQ����C�s��:"); scanf("%d",&i);
       }
       printf("addQ to Q%d:",i);
       scanf("%d",&Item.ItemKey);
       addQ(&front[i],&rear[i],Item);
       printf("addQ Q%d->%d\n",i,Item.ItemKey);
       break;
     case 'D':
       printf("�ndeleteQ����C�s��:");   scanf("%d",&i);
       while((i>=MaxQueues) || i<0)
       {
        printf("�ndeleteQ����C�s��:"); scanf("%d",&i);
       }
       printf("delQ Q%d->%d\n",i,deleteQ(&front[i]).ItemKey);
       break;
     case 'P':
       printf("�п�J�n�˵���C���s��:");   scanf("%d",&i);
       while((i>=MaxQueues) || i<0)
       {
        printf("�п�J�n�˵���C���s��:");   scanf("%d",&i);
       }
       PrintQueue(i);
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
