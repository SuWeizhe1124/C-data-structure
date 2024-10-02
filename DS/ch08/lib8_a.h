#include <malloc.h>

#define FALSE 0
#define TRUE 1
#define MaxVertexSize 101  /* �̦h100�ӳ��I */

typedef struct node *node_pointer;
typedef struct node{
    int vertex;      /* �Y���I�s�����r��,�h�אּ char vertex; �̦����� */
    struct node *next;
}graphnode;

node_pointer graph[MaxVertexSize];
int n=1;  /* �ثe���b�B�z�����I�s�� */


short int visited[MaxVertexSize]; /* ����}�C,�ΨӰO�����I�O�_�Q���X�L */

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
     printf("�O���餣��!");
     exit(1);
   }

   temp->vertex=vertex;
   temp->link=NULL;
   if (*front==NULL)   /* ��C���� */
      *front=temp;
   else                /* ��C�D�� */
     (*rear)->link=temp;
   *rear=temp;  /*  rear�û����V��C������,�]�N�O�s�W���`�I  */

}

int deleteQ(Q_Node_P *front)
{
   Q_Node_P temp=*front;
   int vertex;

   if(temp==NULL)
   {
     printf("��C�w��!");
     exit(1);
   }
   vertex=temp->vertex;
   *front=temp->link;     /*  front�û����V��C���Y��  */
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

  while(front!=NULL)          /* �Ĥ@�h�j��P�_��C�O�_���� */
  {
    v=deleteQ(&front);        /* ���X��C���� */

    w=graph[v];
    while(w!=NULL)       /* �ĤG�h�j�鳰����X�۾F���I�å[�J���C */
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

void dfs(int v)    /*  v�����X�_�I */
{
  
   node_pointer w;
   printf("%d\n",v);     /* �L�X���I */
   visited[v]=TRUE;      /* �]�w���w���X */
    
   w=graph[v];
   while(w!=NULL)
   {
     if(visited[w->vertex]!=TRUE)
        dfs(w->vertex);      /* �����X��,��dfs�j�M */
     w=w->next; 
   }   
}

void connected_components(int MaxVertexNo)
{
  int i;
  for(i=1;i<=MaxVertexNo;i++)
   if(visited[i]!=TRUE)
   {
     printf("\n�s�q����:\n");
     bfs(i);
   }   
}