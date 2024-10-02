#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MaxCQueueSize 30

typedef struct node *bt_pointer;

typedef struct node
{
    char data;
    bt_pointer left_child,right_child;
}treenode;

typedef bt_pointer element;   /*  佇列元素為節點指標 */

typedef struct{
   element cqueue[MaxCQueueSize];
   int front;
   int rear;
}CQueueADT;

CQueueADT CreateCQueue()
{
  CQueueADT NewCQueue;
  NewCQueue.front=0;
  NewCQueue.rear=0;
  return NewCQueue;
}

bool isEmpty(CQueueADT CQ)
{
   if(CQ.front==CQ.rear) return true;
   else return false;
}

bool isFull(CQueueADT CQ)
{
   if(CQ.front==CQ.rear) return true;
   else return false;
}

void AddCQ(CQueueADT *CQ,element item)
{
  CQ->rear=(CQ->rear+1)%MaxCQueueSize;
  if(isFull(*CQ)==true)
  {
     printf("佇列已滿!");
     exit(1);
  }
  else
    CQ->cqueue[CQ->rear]=item;
}

element DeleteCQ(CQueueADT *CQ)
{
  if(isEmpty(*CQ)==true)
  {
     printf("佇列已空!");
     exit(1);
  }
  else
  {
    CQ->front=(CQ->front+1)%MaxCQueueSize;
    return  CQ->cqueue[CQ->front];
  }
}

bt_pointer MakeTree()
{
  bt_pointer B,C,E,A,D;

  /* node B*/
  B=(bt_pointer)malloc(sizeof(treenode));
  B->data='B';
  B->left_child =NULL;
  B->right_child=NULL;

  /* node C*/
  C=(bt_pointer)malloc(sizeof(treenode));
  C->data='C';
  C->left_child =B;
  C->right_child=NULL;

  /* node E*/
  E=(bt_pointer)malloc(sizeof(treenode));
  E->data='E';
  E->left_child =NULL;
  E->right_child=NULL;

  /* node A*/
  A=(bt_pointer)malloc(sizeof(treenode));
  A->data='A';
  A->left_child =NULL;
  A->right_child=E;

  /* D */
  D=(bt_pointer)malloc(sizeof(treenode));
  D->data='D';
  D->left_child =A;
  D->right_child=C;
  return D;
}

void level_order(bt_pointer ptr)
{
   CQueueADT queue;

   queue=CreateCQueue();
   if(ptr==NULL) return;
   AddCQ(&queue,ptr);
   while(isEmpty(queue)!=true)
   {
    ptr=DeleteCQ(&queue);
    printf("%c ",ptr->data);
    if (ptr->left_child != NULL)
        AddCQ(&queue,ptr->left_child);
    if (ptr->right_child != NULL)
        AddCQ(&queue,ptr->right_child);
   }
}

int main(void)
{
  bt_pointer root=NULL;

  root=MakeTree();
  level_order(root);

  system("pause");
  return 0;
}
