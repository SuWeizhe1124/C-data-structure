#define MaxStacks 5             /* ���|�Ӽ� */

typedef struct{
    int ItemKey;
    /*   ���|�������䥦���  */
}element;

struct Stack_Node{
    element Item;
    struct Stack_Node *link;
};

typedef struct Stack_Node S_Node;
typedef S_Node *S_Node_P;

S_Node_P top[MaxStacks];

void push(S_Node_P *top,element Item)   /*  �I�s�y�k�� push(&top[���|�s��],Item);  */
{
   S_Node_P temp;
   temp=(S_Node_P) malloc(sizeof(S_Node));
   if(temp==NULL)
   {
     printf("�O���餣��!");
     exit(1);
   }
   temp->Item=Item;
   temp->link=*top;
   *top=temp;     /*  top�û����V���|������  */
}

element pop(S_Node_P *top)             /*  �I�s�y�k�� item=pop(&top[���|�s��]);  */
{
   S_Node_P temp=*top;
   element Item;

   if(temp==NULL)
   {
     printf("���|�w��!");
     exit(1);
   }
   Item=temp->Item;
   *top=temp->link;     /*  top�û����V���|������  */
   free(temp);
   return Item;
}