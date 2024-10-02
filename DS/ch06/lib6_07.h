#define MaxQueues 5             /* ��C�Ӽ� */

typedef struct{
    int ItemKey;
    /*   ��C�������䥦���  */
}element;

struct Queue_Node{
    element Item;
    struct Queue_Node *link;
};

typedef struct Queue_Node Q_Node;
typedef Q_Node *Q_Node_P;

Q_Node_P front[MaxQueues];
Q_Node_P rear[MaxQueues];

void addQ(Q_Node_P *front,Q_Node_P *rear,element Item)   /*  �I�s�y�k�� addQ(&front[��C�s��],&rear[��C�s��],Item);  */
{
   Q_Node_P temp;
   temp=(Q_Node_P) malloc(sizeof(Q_Node));
   if(temp==NULL)
   {
     printf("�O���餣��!");
     exit(1);
   }
   temp->Item=Item;
   temp->link=NULL;
   if (*front==NULL)   /* ��C���� */
      *front=temp;
   else                /* ��C�D�� */
     (*rear)->link=temp;
   *rear=temp;     /*  rear�û����V��C������,�]�N�O�s�W���`�I  */
}

element deleteQ(Q_Node_P *front)             /*  �I�s�y�k�� item=deleteQ(&front[��C�s��]);  */
{
   Q_Node_P temp=*front;
   element Item;

   if(temp==NULL)
   {
     printf("��C�w��!");
     exit(1);
   }
   Item=temp->Item;
   *front=temp->link;     /*  front�û����V��C���Y��  */
   free(temp);
   return Item;
}