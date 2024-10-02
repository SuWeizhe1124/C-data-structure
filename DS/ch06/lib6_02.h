#define MaxQueueSize 100

typedef struct{
    int ItemKey;
    /*   ��C�������䥦���  */
}element;

typedef struct{
   element queue[MaxQueueSize];
   int front;
   int rear;
}QueueADT;

QueueADT CreateQueue()
{
  QueueADT NewQueue;
  NewQueue.front=-1;
  NewQueue.rear=-1;
  return NewQueue;
}

bool isEmpty(QueueADT Q)
{
   if(Q.front>=Q.rear) return true;
   else return false;
}

bool isFull(QueueADT Q)
{
   if(Q.rear>=MaxQueueSize-1) return true;
   else return false;
}

void AddQ(QueueADT *Q,element item)
{
  if(isFull(*Q)==true)
  {
     printf("��C�w��!");
     exit(1);
  }
  else
    Q->queue[++Q->rear]=item;
}

element DeleteQ(QueueADT *Q)
{
  if(isEmpty(*Q)==true)
  {
     printf("��C�w��!");
     exit(1);
  }
  else
    return  Q->queue[++Q->front];
}

