#define MaxStackSize 100

typedef struct{
    int ItemKey;
    /*   堆疊元素的其它欄位  */
}element;

typedef struct{
   element stack[MaxStackSize];
   int top;
}StackADT;

StackADT CreateStack()
{
  StackADT NewStack;
  NewStack.top=-1;
  return NewStack;
}

bool isEmpty(StackADT S)
{
   if(S.top<0) return true;
   else return false;
}

bool isFull(StackADT S)
{
   if(S.top>=MaxStackSize-1) return true;
   else return false;
}

void push(StackADT *S,element item)
{
  if(isFull(*S)==true)
  {
     printf("堆疊已滿!");
     exit(1);
  }
  else
    S->stack[++S->top]=item;
}

element pop(StackADT *S)
{
  if(isEmpty(*S)==true)
  {
     printf("堆疊已空!");
     exit(1);
  }
  else
    return  S->stack[S->top--];
}

