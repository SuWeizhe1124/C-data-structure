#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

struct SingleLinkList_Node
{
    int data;
    struct SingleLinkList_Node *link;
};
typedef struct SingleLinkList_Node S_Node;
typedef S_Node *S_Node_P;


S_Node_P insertFirst(S_Node_P L,int d);
S_Node_P insertLast(S_Node_P L,int d);

/********* 錯誤跳出 ***************/
void ErrorExit()
{
  printf("error");
  exit(1);
}
/********** 要求配置新節點 ***************/
S_Node_P GetNode()
{
 S_Node_P NewNode_P;
 NewNode_P=(S_Node_P) malloc(sizeof(S_Node));
 if(NewNode_P==NULL)
 {
     printf("記憶體不足!");
     exit(1);
 }
 return  NewNode_P;
}
/********* Create運算 **********/
S_Node_P Create()
{
  S_Node_P L;
  L=NULL;
  return L;
}

/*********** isEmpty運算 ***********/
bool isEmpty(S_Node_P L)
{
  if (L==NULL)
     return true;
  else
     return false;
}

/*********** size運算 ***********/
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

/***********  isNode運算  ***********/
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
/***********  isFirst運算  ***********/
bool isFirst(S_Node_P L,S_Node_P m)
{
   if (isNode(L,m)==false) ErrorExit();
   if (L==m)
     return true;
   else
     return false;
}

/***********  isLast運算  ***********/
bool isLast(S_Node_P L,S_Node_P m)
{
  if (isNode(L,m)==false) ErrorExit();
  if (m->link==NULL)
      return true;  
   else
      return false;  
}
/***********  first運算  ***********/
S_Node_P first(S_Node_P L)
{
   if (isEmpty(L)==true) ErrorExit();
   return L;
}

/*********** last運算  ***********/
S_Node_P last(S_Node_P L)
{
   S_Node_P Trace;
   if (isEmpty(L)==true) ErrorExit();
   Trace=L;
   while (Trace->link!=NULL)
       Trace=Trace->link;
   return Trace;
}

/***********  before運算  ***********/
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

/***********  after運算  ***********/
S_Node_P after(S_Node_P L,S_Node_P m)
{
  if (isNode(L,m)==false) ErrorExit();
  return m->link;
}

/***********  replacedata運算  ***********/
S_Node_P replacedata(S_Node_P L,S_Node_P m,int d)
{
  if (isNode(L,m)==false) ErrorExit();
  m->data=d;
  return L;
}

/***********  insertBefore運算  ***********/
S_Node_P insertBefore(S_Node_P L,S_Node_P m,int d)
{
  S_Node_P n,B;
  if (isNode(L,m)==false) ErrorExit();
  n=GetNode();
  n->data=d;  n->link=NULL;
  if (isFirst(L,m)==false)
  {
    B=before(L,m);
    n->link=B->link;      /* B->link就是m */
    B->link=n;
   }
   else  /* m為第一個節點 */
   {
     L= insertFirst(L,d);
   }
   return L;
}
/***********  insertAfter運算  ***********/
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
    m->link=n;      /* 注意：這一行與上一行之順序不可對調 */
  }
  else     /*  m為最後一個節點 */
  {
    L= insertLast(L,d);
  }
  return L;
}

/***********  insertFirst運算  ***********/
S_Node_P insertFirst(S_Node_P L,int d)
{
  S_Node_P n;
  n=GetNode();
  n->data=d;
  n->link=L;
  L=n;
  return L;
}

/***********  insertLast運算  ***********/
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

/***********  NodeRemove運算  ***********/
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
   free(m);         /*  釋放m指標所指向的節點 */
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
  
  printf("開獎球如下(最後一球為特別號):\n");
  visit=Balls;

  while(visit!=NULL) /*可改寫為 for(i=1;i<=size(Balls);i++) */
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
