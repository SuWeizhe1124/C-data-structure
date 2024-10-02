#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MaxVertexSize 101  /* 最多100個頂點 */

typedef struct node *node_pointer;
typedef struct node{
    int vertex;  /* 若頂點編號為字元,則改為 char vertex; 依此類推 */
    struct node *next;
}graphnode;


typedef struct{
    int count;      /* 記錄此頂點的先行者數量 */
    struct node *next;
}headnode;

headnode graph[MaxVertexSize];

void inc_count(int i)
{
  graph[i].count++;
}

void dec_count(int i)
{
  graph[i].count--;
}


void makeAOV()
{
   int edge[][8]={{-1,-1,-1,-1,-1,-1,-1,-1},
                  {-1, 0, 1, 1, 0, 0, 0 ,0},
                  {-1, 0, 0, 0, 1, 1, 0, 0},
                  {-1, 0, 0, 0, 0, 0, 1, 0},
                  {-1, 0, 0, 0, 0, 0, 0, 1},
                  {-1, 0, 0, 0, 0, 0, 0, 1},
                  {-1, 0, 0, 0, 0, 0, 0, 1},
                  {-1, 0, 0, 0, 0, 0, 0, 0}};
   node_pointer ptr,successor;
   int i,j;

   for(i=1;i<=7;i++)
   {
     successor=NULL;
     for(j=7;j>=1;j--)
     {
       if(edge[i][j]==1)
       {
         ptr=(node_pointer) malloc(sizeof(graphnode));
         ptr->vertex=j;
         ptr->next=successor;
         inc_count(j);
         successor=ptr;
       }
     }
     graph[i].next= successor;
   }

}

void topological_sort(int n)
{

   int i,j,k,top=0;
   node_pointer ptr;


   for(i=1;i<=n;i++)
   {
     if(graph[i].count==0)
     {
       graph[i].count=top;
       top=i; /* 設定堆疊top指向最後進入堆疊且count為0頂點串列頭 */
     }
   }
   for(i=1;i<=n;i++)
   {
     if(top==0)
     {
      printf("網路包含環路,無法進行拓樸排序");
      exit(1);
     }
     j=top;
     top=graph[top].count;
     printf("V%d ",j);

     /*  無先行者之頂點已輸出,所以相鄰串列內各頂點count-1 */
     ptr=graph[j].next;
     while(ptr!=NULL)
     {
       k=ptr->vertex;
       dec_count(k);               /* count 遞減 */
       if(graph[k].count==0)
       {
         graph[k].count=top;
         top=k;
       }
       ptr=ptr->next;
     }
   }
}

int main()
{

  makeAOV();
  topological_sort(7);
  system("pause");
  return 0;
}
