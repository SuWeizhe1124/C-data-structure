#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */


struct PolynomialNode_Of_CircularList
{
    double coef;
    int expont;
    struct PolynomialNode_Of_CircularList *link;
};
typedef struct PolynomialNode_Of_CircularList P_Node;
typedef P_Node *P_Node_P;
P_Node_P avail;


P_Node_P GetNode(void)
{
 P_Node_P NewNode_P;
 if(avail!=NULL)
 {
   NewNode_P=avail;
   avail=avail->link;
 }
 else
 {
   NewNode_P=(P_Node_P) malloc(sizeof(P_Node));
   if (NewNode_P==NULL)  { printf("記憶體不足!");  exit(1);  }
 }
 return NewNode_P;
}

void RetNode(P_Node_P ReleaseNode_P)
{
  ReleaseNode_P->link=avail;
  avail=ReleaseNode_P;
}


void NewCircularListErase(P_Node_P *p)
{
  P_Node_P Node;

  Node=(*p)->link;
  (*p)->link=avail;
  avail=Node;
  (*p)=NULL;
}

void CircularListPolyAttach(P_Node_P *last,double coef,int expont)
{
  P_Node_P NewNode_P;
  NewNode_P=GetNode();
  NewNode_P->coef=coef;
  NewNode_P->expont=expont;
  NewNode_P->link=(*last)->link;
  (*last)->link=NewNode_P;
  (*last)=NewNode_P;
}

P_Node_P CircularListPolyAdd(P_Node_P p1,P_Node_P p2)
{
  P_Node_P p3,p1_start,p3_last;
  int OK=0;
  /*  P_Node_P p3,front,rear; */
  double sum;

  p1_start=p1;
  p1=p1->link;  /*  指到第一個項目 */
  p2=p2->link;  /*  指到第一個項目 */
  p3=GetNode();    /*  取得標頭節點  */
  p3->expont=-1;   /*  設定為標頭節點  */
  p3_last=p3;

  do
  {
    if(p1->expont > p2->expont)
    {
      CircularListPolyAttach(&p3_last,p1->coef,p1->expont);
      p1=p1->link;
    }
    else if (p1->expont < p2->expont)
    {
      CircularListPolyAttach(&p3_last,p2->coef,p2->expont);
      p2=p2->link;
    }
    else if (p1->expont == p2->expont)
    {
      if(p1_start==p1)
         OK=1;     /*  當p1->expont=p2->expont=-1時,會執行此行  */
      sum=p1->coef+p2->coef;
      if(sum!=0)
         CircularListPolyAttach(&p3_last,sum,p1->expont);
      p1=p1->link;
      p2=p2->link;
    }
  }while(OK!=1);
  p3_last->link=p3;  /* 環狀最後一個鏈結 */

  return p3;
}


