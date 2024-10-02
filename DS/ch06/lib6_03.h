#define MaxCQueueSize 5

typedef struct{
    int ItemKey;
    /*   環狀佇列元素的其它欄位  */
}element;
typedef struct{
   element cqueue[MaxCQueueSize];
   int front;
   int rear;
}CQueueADT;

CQueueADT CreateCQueue()
{
  CQueueADT NewCQueue;
  NewCQueue.front=0;
  NewCQueue.rear=0;
  return NewCQueue;
}

bool isEmpty(CQueueADT CQ)
{
   if(CQ.front==CQ.rear) return true;
   else return false;
}

bool isFull(CQueueADT CQ)
{
   if(CQ.front==CQ.rear) return true;
   else return false;
}

void AddCQ(CQueueADT *CQ,element item)
{
  CQ->rear=(CQ->rear+1)%MaxCQueueSize;
  if(isFull(*CQ)==true)
  {
     printf("佇列已滿!");
     exit(1);
  }
  else
    CQ->cqueue[CQ->rear]=item;
}

element DeleteCQ(CQueueADT *CQ)
{
  if(isEmpty(*CQ)==true)
  {
     printf("佇列已空!");
     exit(1);
  }
  else
  {
    CQ->front=(CQ->front+1)%MaxCQueueSize;
    return  CQ->cqueue[CQ->front];
  }
}