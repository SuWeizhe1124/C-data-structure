struct PolynomialNode
{
    double coef;
    int expont;
    struct PolynomialNode *link;
};
typedef struct PolynomialNode P_Node;
typedef P_Node *P_Node_P;

void Attach(P_Node_P *rear,double coef,int expont)
{
 /* *rear指向串列最後一個節點,必須使用傳指標呼叫以便共用 */
 P_Node_P NewNode_P;
 NewNode_P=(P_Node_P) malloc(sizeof(P_Node));
 if (NewNode_P==NULL)
  {
     printf("記憶體不足!");
     exit(1);
 }
 NewNode_P->coef=coef;
 NewNode_P->expont=expont;
 (*rear)->link=NewNode_P;
 (*rear)=NewNode_P;
 (*rear)->link=NULL;
}

P_Node_P PolyAdd(P_Node_P p1,P_Node_P p2)
{
  P_Node_P p3,front,rear;
  double sum;

  rear=(P_Node_P) malloc(sizeof(P_Node));
  if (rear==NULL)
  {
     printf("記憶體不足!");
     exit(1);
  }
  front=rear;

  while((p1!=NULL) && (p2!=NULL))
  {
    if(p1->expont > p2->expont)
    {
      Attach(&rear,p1->coef,p1->expont);
      p1=p1->link;
    }
    else if (p1->expont < p2->expont)
    {
      Attach(&rear,p2->coef,p2->expont);
      p2=p2->link;
    }
    else if (p1->expont == p2->expont)
    {
      sum=p1->coef+p2->coef;
      if(sum!=0)
         Attach(&rear,sum,p1->expont);
      p1=p1->link;
      p2=p2->link;
    }
  }
  while (p1!=NULL)   /* 加入p1剩餘項目 */
  {
      Attach(&rear,p1->coef,p1->expont);
      p1=p1->link;
  }
  while (p2!=NULL)   /* 加入p2剩餘項目 */
  {
      Attach(&rear,p2->coef,p2->expont);
      p2=p2->link;
  }
  p3=front->link;
  free(front);

  return p3;
}


