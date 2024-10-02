#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#define MaxVertexSize 101  /* �̦h100�ӳ��I */

typedef struct node *node_pointer;
typedef struct node{
    int vertex;  /* �Y���I�s�����r��,�h�אּ char vertex; �̦����� */
    struct node *next;
}graphnode;


typedef struct{
    int count;      /* �O�������I������̼ƶq */
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
       top=i; /* �]�w���|top���V�̫�i�J���|�Bcount��0���I��C�Y */
     }
   }
   for(i=1;i<=n;i++)
   {
     if(top==0)
     {
      printf("�����]�t����,�L�k�i��ݾ�Ƨ�");
      exit(1);
     }
     j=top;
     top=graph[top].count;
     printf("V%d ",j);

     /*  �L����̤����I�w��X,�ҥH�۾F��C���U���Icount-1 */
     ptr=graph[j].next;
     while(ptr!=NULL)
     {
       k=ptr->vertex;
       dec_count(k);               /* count ���� */
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
