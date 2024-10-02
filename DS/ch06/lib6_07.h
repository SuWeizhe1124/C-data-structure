#define MaxQueues 5             /* 佇列個數 */

typedef struct{
    int ItemKey;
    /*   佇列元素的其它欄位  */
}element;

struct Queue_Node{
    element Item;
    struct Queue_Node *link;
};

typedef struct Queue_Node Q_Node;
typedef Q_Node *Q_Node_P;

Q_Node_P front[MaxQueues];
Q_Node_P rear[MaxQueues];

void addQ(Q_Node_P *front,Q_Node_P *rear,element Item)   /*  呼叫語法為 addQ(&front[佇列編號],&rear[佇列編號],Item);  */
{
   Q_Node_P temp;
   temp=(Q_Node_P) malloc(sizeof(Q_Node));
   if(temp==NULL)
   {
     printf("記憶體不足!");
     exit(1);
   }
   temp->Item=Item;
   temp->link=NULL;
   if (*front==NULL)   /* 佇列為空 */
      *front=temp;
   else                /* 佇列非空 */
     (*rear)->link=temp;
   *rear=temp;     /*  rear永遠指向佇列的尾端,也就是新增的節點  */
}

element deleteQ(Q_Node_P *front)             /*  呼叫語法為 item=deleteQ(&front[佇列編號]);  */
{
   Q_Node_P temp=*front;
   element Item;

   if(temp==NULL)
   {
     printf("佇列已空!");
     exit(1);
   }
   Item=temp->Item;
   *front=temp->link;     /*  front永遠指向佇列的頭端  */
   free(temp);
   return Item;
}