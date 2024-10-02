#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

struct SingleLinkList_Node
{
    int data;
    struct SingleLinkList_Node *link;
};
typedef struct SingleLinkList_Node S_Node;
typedef S_Node *S_Node_P;


S_Node_P insertFirst(S_Node_P L,int d);
S_Node_P insertLast(S_Node_P L,int d);

/********* ���~���X ***************/
void ErrorExit()
{
  printf("error");
  exit(1);
}
/********** �n�D�t�m�s�`�I ***************/
S_Node_P GetNode()
{
 S_Node_P NewNode_P;
 NewNode_P=(S_Node_P) malloc(sizeof(S_Node));
 if(NewNode_P==NULL)
 {
     printf("�O���餣��!");
     exit(1);
 }
 return  NewNode_P;
}
/********* Create�B�� **********/
S_Node_P Create()
{
  S_Node_P L;
  L=NULL;
  return L;
}

/*********** isEmpty�B�� ***********/
bool isEmpty(S_Node_P L)
{
  if (L==NULL)
     return true;
  else
     return false;
}

/*********** size�B�� ***********/
int size(S_Node_P L)
{
  int counter=0; 
  S_Node_P Trace;
  Trace=L;
  while (Trace!=NULL)
  {
      Trace=Trace->link;
      counter=counter+1;
  }
  return counter;
}

/***********  isNode�B��  ***********/
bool isNode(S_Node_P L,S_Node_P m)
{
  S_Node_P Trace;
  if (isEmpty(L)==true)
  {
    return false;
  }
  Trace=L;
  while (Trace!=NULL)
  {
    if (Trace==m) 
       return true;
    Trace=Trace->link;
   }
   return false;
}
/***********  isFirst�B��  ***********/
bool isFirst(S_Node_P L,S_Node_P m)
{
   if (isNode(L,m)==false) ErrorExit();
   if (L==m)
     return true;
   else
     return false;
}

/***********  isLast�B��  ***********/
bool isLast(S_Node_P L,S_Node_P m)
{
  if (isNode(L,m)==false) ErrorExit();
  if (m->link==NULL)
      return true;  
   else
      return false;  
}
/***********  first�B��  ***********/
S_Node_P first(S_Node_P L)
{
   if (isEmpty(L)==true) ErrorExit();
   return L;
}

/*********** last�B��  ***********/
S_Node_P last(S_Node_P L)
{
   S_Node_P Trace;
   if (isEmpty(L)==true) ErrorExit();
   Trace=L;
   while (Trace->link!=NULL)
       Trace=Trace->link;
   return Trace;
}

/***********  before�B��  ***********/
S_Node_P before(S_Node_P L,S_Node_P m)   
{
   S_Node_P Trace;
   if (isNode(L,m)==false) ErrorExit();
   if (isFirst(L,m)==true) ErrorExit();
   Trace=L;
   while (Trace->link!=m)
      Trace=Trace->link;
   
   return Trace;
}

/***********  after�B��  ***********/
S_Node_P after(S_Node_P L,S_Node_P m)
{
  if (isNode(L,m)==false) ErrorExit();
  return m->link;
}

/***********  replacedata�B��  ***********/
S_Node_P replacedata(S_Node_P L,S_Node_P m,int d)
{
  if (isNode(L,m)==false) ErrorExit();
  m->data=d;
  return L;
}

/***********  insertBefore�B��  ***********/
S_Node_P insertBefore(S_Node_P L,S_Node_P m,int d)
{
  S_Node_P n,B;
  if (isNode(L,m)==false) ErrorExit();
  n=GetNode();
  n->data=d;  n->link=NULL;
  if (isFirst(L,m)==false)
  {
    B=before(L,m);
    n->link=B->link;      /* B->link�N�Om */
    B->link=n;
   }
   else  /* m���Ĥ@�Ӹ`�I */
   {
     L= insertFirst(L,d);
   }
   return L;
}
/***********  insertAfter�B��  ***********/
S_Node_P insertAfter(S_Node_P L,S_Node_P m,int d)
{
  S_Node_P n,A;
  if (isNode(L,m)==false) ErrorExit();
  n=GetNode();
  n->data=d;  n->link=NULL;
  A=after(L,m);
  if(A!=NULL)
  {
    n->link=m->link;
    m->link=n;      /* �`�N�G�o�@��P�W�@�椧���Ǥ��i��� */
  }
  else     /*  m���̫�@�Ӹ`�I */
  {
    L= insertLast(L,d);
  }
  return L;
}

/***********  insertFirst�B��  ***********/
S_Node_P insertFirst(S_Node_P L,int d)
{
  S_Node_P n;
  n=GetNode();
  n->data=d;
  n->link=L;
  L=n;
  return L;
}

/***********  insertLast�B��  ***********/
S_Node_P insertLast(S_Node_P L,int d)
{
   S_Node_P n,LastNP;
   if(isEmpty(L)==true)
   {
     L=insertFirst(L,d);
   }
   else
   {
    n=GetNode();
    LastNP=last(L);
    n->data=d;
    n->link=NULL;
    LastNP->link=n;
   }
   return L;
}

/***********  NodeRemove�B��  ***********/
S_Node_P NodeRemove(S_Node_P L,S_Node_P m)
{
   S_Node_P B;
   if (isNode(L,m)==false) ErrorExit();
   if (isFirst(L,m)==false)
   { 
     B=before(L,m);
     B->link=m->link;
   }
   else
   {
     L=m->link;
   }
   free(m);         /*  ����m���Щҫ��V���`�I */
   return L;
}

int main(void)
{
  S_Node_P Balls,visit;

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

  while(visit!=NULL) /*�i��g�� for(i=1;i<=size(Balls);i++) */
  {
     printf("%d  ",visit->data);
     visit=visit->link;     
  }
  printf("\n");
  while(Balls!=NULL)
  {
     Balls=NodeRemove(Balls,first(Balls));
  }

  system("pause");
  return 0;
}
