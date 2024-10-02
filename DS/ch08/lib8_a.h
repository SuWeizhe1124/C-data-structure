#include <malloc.h>

#define FALSE 0
#define TRUE 1
#define MaxVertexSize 101  /* 最多100個頂點 */

typedef struct node *node_pointer;
typedef struct node{
    int vertex;      /* 若頂點編號為字元,則改為 char vertex; 依此類推 */
    struct node *next;
}graphnode;

node_pointer graph[MaxVertexSize];
int n=1;  /* 目前正在處理的頂點編號 */


short int visited[MaxVertexSize]; /* 全域陣列,用來記錄頂點是否被拜訪過 */

struct Queue_Node{
    int vertex;
    struct Queue_Node *link;
};

typedef struct Queue_Node Q_Node;
typedef Q_Node *Q_Node_P;

void addQ(Q_Node_P *front,Q_Node_P *rear,int vertex)
{
   Q_Node_P temp;
   temp=(Q_Node_P) malloc(sizeof(Q_Node));
   if(temp==NULL)
   {
     printf("記憶體不足!");
     exit(1);
   }

   temp->vertex=vertex;
   temp->link=NULL;
   if (*front==NULL)   /* 佇列為空 */
      *front=temp;
   else                /* 佇列非空 */
     (*rear)->link=temp;
   *rear=temp;  /*  rear永遠指向佇列的尾端,也就是新增的節點  */

}

int deleteQ(Q_Node_P *front)
{
   Q_Node_P temp=*front;
   int vertex;

   if(temp==NULL)
   {
     printf("佇列已空!");
     exit(1);
   }
   vertex=temp->vertex;
   *front=temp->link;     /*  front永遠指向佇列的頭端  */
   free(temp);
   return vertex;
}

void bfs(int v)
{
  node_pointer w;
  Q_Node_P front,rear;
  front=rear=NULL;
  printf("%d\n",v);
  visited[v]=TRUE;
  addQ(&front,&rear,v);

  while(front!=NULL)          /* 第一層迴圈判斷佇列是否為空 */
  {
    v=deleteQ(&front);        /* 取出佇列元素 */

    w=graph[v];
    while(w!=NULL)       /* 第二層迴圈陸續拜訪相鄰頂點並加入到佇列 */
    {
     if(visited[w->vertex]!=TRUE)
      {
        printf("%d\n",w->vertex);
        visited[w->vertex]=TRUE;
        addQ(&front,&rear,w->vertex);
      }
     w=w->next;
    }
  }
}

void dfs(int v)    /*  v為拜訪起點 */
{
  
   node_pointer w;
   printf("%d\n",v);     /* 印出頂點 */
   visited[v]=TRUE;      /* 設定為已拜訪 */
    
   w=graph[v];
   while(w!=NULL)
   {
     if(visited[w->vertex]!=TRUE)
        dfs(w->vertex);      /* 未拜訪時,用dfs搜尋 */
     w=w->next; 
   }   
}

void connected_components(int MaxVertexNo)
{
  int i;
  for(i=1;i<=MaxVertexNo;i++)
   if(visited[i]!=TRUE)
   {
     printf("\n連通元件:\n");
     bfs(i);
   }   
}