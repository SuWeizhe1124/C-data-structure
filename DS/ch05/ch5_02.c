#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

struct DoubleLinkList_Node
{
    int data;
    struct DoubleLinkList_Node *llink;
    struct DoubleLinkList_Node *rlink;
};
typedef struct DoubleLinkList_Node D_Node;
typedef D_Node *D_Node_P;


/********* ���~���X ***************/
void ErrorExit()
{
  printf("error");
  exit(1);
}
/********** �n�D�t�m�s�`�I ***************/
D_Node_P GetNode()
{
 D_Node_P NewNode_P;
 NewNode_P=(D_Node_P) malloc(sizeof(D_Node));
 if(NewNode_P==NULL)
 {
     printf("�O���餣��!");
     exit(1);
 }
 return  NewNode_P;
}
/********* Create�B�� **********/
D_Node_P Create()
{
  D_Node_P L;
  L=NULL;
  return L;
}

/*********** isEmpty�B�� ***********/
bool isEmpty(D_Node_P L)
{
  if (L==NULL)  return true;
  else  return false;
}

/***********  isNode�B��  ***********/
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
/***********  isFirst�B��  ***********/
bool isFirst(D_Node_P L,D_Node_P m)
{
   if (isNode(L,m)==false) ErrorExit();
   if (L==m)
     return true;
   else
     return false;
}

/***********  isLast�B��  ***********/
bool isLast(D_Node_P L,D_Node_P m)
{
  if (isNode(L,m)==false) ErrorExit();
  if (m->rlink==L)
      return true;  
  else
      return false;  
}
/***********  first�B��  ***********/
D_Node_P first(D_Node_P L)
{
   if (isEmpty(L)==true) ErrorExit();
   return L;
}

/*********** last�B��  ***********/
D_Node_P last(D_Node_P L)
{
   return L->llink;
}

/***********  insertBefore�B��  ***********/
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
/***********  insertAfter�B��  ***********/
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

/***********  insertFirst�B��  ***********/
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

/***********  insertLast�B��  ***********/
D_Node_P insertLast(D_Node_P L,int d)
{
   D_Node_P n;
   if(isEmpty(L)==true)
      L=insertFirst(L,d);
   else
      L=insertAfter(L,last(L),d);
   return L;

}

/***********  NodeRemove�B��  ***********/
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
  
  printf("�}���y�p�U(�̫�@�y���S�O��):\n");
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
