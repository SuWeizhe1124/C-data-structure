#define MaxStacks 5             /* 堆疊個數 */

typedef struct{
    int ItemKey;
    /*   堆疊元素的其它欄位  */
}element;

struct Stack_Node{
    element Item;
    struct Stack_Node *link;
};

typedef struct Stack_Node S_Node;
typedef S_Node *S_Node_P;

S_Node_P top[MaxStacks];

void push(S_Node_P *top,element Item)   /*  呼叫語法為 push(&top[堆疊編號],Item);  */
{
   S_Node_P temp;
   temp=(S_Node_P) malloc(sizeof(S_Node));
   if(temp==NULL)
   {
     printf("記憶體不足!");
     exit(1);
   }
   temp->Item=Item;
   temp->link=*top;
   *top=temp;     /*  top永遠指向堆疊的頂端  */
}

element pop(S_Node_P *top)             /*  呼叫語法為 item=pop(&top[堆疊編號]);  */
{
   S_Node_P temp=*top;
   element Item;

   if(temp==NULL)
   {
     printf("堆疊已空!");
     exit(1);
   }
   Item=temp->Item;
   *top=temp->link;     /*  top永遠指向堆疊的頂端  */
   free(temp);
   return Item;
}