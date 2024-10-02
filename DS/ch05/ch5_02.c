#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

struct DoubleLinkList_Node
{
    int data;
    struct DoubleLinkList_Node *llink;
    struct DoubleLinkList_Node *rlink;
};
typedef struct DoubleLinkList_Node D_Node;
typedef D_Node *D_Node_P;


/********* 錯誤跳出 ***************/
void ErrorExit()
{
  printf("error");
  exit(1);
}
/********** 要求配置新節點 ***************/
D_Node_P GetNode()
{
 D_Node_P NewNode_P;
 NewNode_P=(D_Node_P) malloc(sizeof(D_Node));
 if(NewNode_P==NULL)
 {
     printf("記憶體不足!");
     exit(1);
 }
 return  NewNode_P;
}
/********* Create運算 **********/
D_Node_P Create()
{
  D_Node_P L;
  L=NULL;
  return L;
}

/*********** isEmpty運算 ***********/
bool isEmpty(D_Node_P L)
{
  if (L==NULL)  return true;
  else  return false;
}

/***********  isNode運算  ***********/
bool isNode(D_Node_P L,D_Node_P m)
{
  D_Node_P Trace;
  if (isEmpty(L)==true)
  {
    return false;
  }
  Trace=L;
  do{
     if (Trace==m)
         return true;
     Trace=Trace->rlink;
  }while(Trace!=L);
      
  return false;
}
/***********  isFirst運算  ***********/
bool isFirst(D_Node_P L,D_Node_P m)
{
   if (isNode(L,m)==false) ErrorExit();
   if (L==m)
     return true;
   else
     return false;
}

/***********  isLast運算  ***********/
bool isLast(D_Node_P L,D_Node_P m)
{
  if (isNode(L,m)==false) ErrorExit();
  if (m->rlink==L)
      return true;  
  else
      return false;  
}
/***********  first運算  ***********/
D_Node_P first(D_Node_P L)
{
   if (isEmpty(L)==true) ErrorExit();
   return L;
}

/*********** last運算  ***********/
D_Node_P last(D_Node_P L)
{
   return L->llink;
}

/***********  insertBefore運算  ***********/
D_Node_P insertBefore(D_Node_P L,D_Node_P m,int d)
{
  D_Node_P n;
  if (isNode(L,m)==false) ErrorExit();
  n=GetNode();
  n->data=d;  n->rlink=NULL;  n->llink=NULL;
  n->rlink=m;
  n->llink=m->llink;
  m->llink->rlink=n;
  m->llink=n;
  if (isFirst(L,m)==true) 
     L=n;
  return L;
}
/***********  insertAfter運算  ***********/
D_Node_P insertAfter(D_Node_P L,D_Node_P m,int d)
{
  D_Node_P n;
  if (isNode(L,m)==false) ErrorExit();
  n=GetNode();
  n->data=d;  n->rlink=NULL;  n->llink=NULL;
  n->llink=m;
  n->rlink=m->rlink;
  m->rlink->llink=n;
  m->rlink=n;
  return L;
}

/***********  insertFirst運算  ***********/
D_Node_P insertFirst(D_Node_P L,int d)
{
  D_Node_P n;
  if(isEmpty(L)==true)
   {
     n=GetNode();
     n->data=d;
     n->rlink=n;
     n->llink=n;
     L=n;
   }
   else
   {
     L=insertBefore(L,first(L),d);  
   }
   return L;
}

/***********  insertLast運算  ***********/
D_Node_P insertLast(D_Node_P L,int d)
{
   D_Node_P n;
   if(isEmpty(L)==true)
      L=insertFirst(L,d);
   else
      L=insertAfter(L,last(L),d);
   return L;

}

/***********  NodeRemove運算  ***********/
D_Node_P NodeRemove(D_Node_P L,D_Node_P m)
{
   if (isNode(L,m)==false) ErrorExit();
   if ((isFirst(L,m)==true) && (isLast(L,m)==true))
      L=NULL;
   else if ((isFirst(L,m)==true) && (isLast(L,m)==false))
   {
      m->llink->rlink=m->rlink;
      m->rlink->llink=m->llink;
      L=m->rlink;
   }
   else
   {
      m->llink->rlink=m->rlink;
      m->rlink->llink=m->llink;
   } 
   free(m);
   return L;
}

int main(void)
{
  D_Node_P Balls,visit;

  Balls=Create();
  Balls=insertFirst(Balls,27);
  Balls=insertAfter(Balls,last(Balls),13);
  Balls=insertAfter(Balls,last(Balls),16);
  Balls=insertAfter(Balls,last(Balls),32);
  Balls=insertAfter(Balls,last(Balls),18);
  Balls=insertAfter(Balls,last(Balls),25);
  Balls=insertLast(Balls,22);
  
  printf("開獎球如下(最後一球為特別號):\n");
  visit=Balls;

  do
  {
     printf("%d  ",visit->data);
     visit=visit->rlink;     
  }while(visit!=Balls);
  printf("\n");
  while(Balls!=NULL)
  {
     Balls=NodeRemove(Balls,first(Balls));
  }
  system("pause");
  return 0;
}
