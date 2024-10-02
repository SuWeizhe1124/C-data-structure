#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MAX_SIZE 100

typedef enum {head,entry,array} nodetype;
typedef struct matrix_node MatrixNode;
typedef MatrixNode *MatrixNode_P;
struct entry_node
{
  int value;
  int row;
  int col;
};

struct matrix_node
{
    MatrixNode_P down;
    MatrixNode_P right;
    nodetype tag;
    union
    {
      MatrixNode_P Next;
      struct entry_node element;
    }u;
};

MatrixNode_P HeadNode[MAX_SIZE];
MatrixNode_P GetNode(void) /* 取得新的稀疏矩陣元素的節點 */
{
  MatrixNode_P NewNode_P;
  NewNode_P=(MatrixNode_P) malloc(sizeof(MatrixNode));
  if (NewNode_P==NULL)
  {
     printf("記憶體不足!");
     exit(1);
 }
 return  NewNode_P;
}

MatrixNode_P ReadMatrix(void)
{
  int RowNum,ColNum,NonZeroNum,HeadNum;
  int i,CurrentRow,row,col,value;
  MatrixNode_P ArrayNode_P,temp,LastNode_P;
  printf("請輸入矩陣的列數:");         scanf("%d",&RowNum);
  printf("請輸入矩陣的行數:");         scanf("%d",&ColNum);
  printf("請輸入矩陣的非零元素個數:"); scanf("%d",&NonZeroNum);
  if(RowNum>=ColNum) HeadNum=RowNum;
  else HeadNum=ColNum;

  /**********建立矩陣節點************/
  ArrayNode_P=GetNode();
  ArrayNode_P->tag=array;
  ArrayNode_P->u.element.row=RowNum;
  ArrayNode_P->u.element.col=ColNum;

  /********建立頭節點與元素節點******/
  if(HeadNum==0)
  {  /*空矩陣*/
     ArrayNode_P->right=ArrayNode_P;
     ArrayNode_P->down=ArrayNode_P;      /*非必要*/
     ArrayNode_P->u.Next=ArrayNode_P;    /*非必要*/
  }
  else
  {
     for(i=0;i<HeadNum;i++)    /*建立所有的頭節點*/
     {
        temp=GetNode();
        HeadNode[i]=temp;
        HeadNode[i]->tag=head;
        HeadNode[i]->right=temp;
        HeadNode[i]->u.Next=temp;
     }
  }
  CurrentRow=0;
  LastNode_P=HeadNode[0];
  printf("依序(以列為優先)輸入非零元素值\n");
  /***************處理元素節點*********************/
  for(i=0;i<NonZeroNum;i++)
  {
     printf("列 行 元素值:");
     scanf("%d%d%d",&row,&col,&value);
     if(row-1>CurrentRow)
     {
        /*該列最後一個節點的鏈結指回列頭節點*/
        LastNode_P->right=HeadNode[CurrentRow];
        CurrentRow=row-1;
        LastNode_P=HeadNode[row-1];  /* 調整為新的列*/
     }
     temp=GetNode();
     temp->tag=entry;
     temp->u.element.row=row;
     temp->u.element.col=col;
     temp->u.element.value=value;

     /*****************處理水平鏈結******************/
     LastNode_P->right=temp;
     LastNode_P=temp;
     /*****************處理垂直鏈結******************/
     HeadNode[col-1]->u.Next->down=temp;/*處理垂直鏈結*/
     HeadNode[col-1]->u.Next=temp; /* Next指向該行末節點 */
  }
  /*最後列最後一個節點的水平鏈結指回該列頭節點*/
  LastNode_P->right=HeadNode[CurrentRow];

  for(i=0;i<ColNum;i++)
  {   /*處理垂直環狀最後一個鏈結*/
      HeadNode[i]->u.Next->down=HeadNode[i];
  }
  /***************元素節點處理完畢***************/

  for(i=0;i<HeadNum-1;i++)
  {     /*處理頭節點之間的鏈結*/
      HeadNode[i]->u.Next=HeadNode[i+1];
  }
  /*最後一個頭節點鏈結回矩陣節點*/
  HeadNode[HeadNum-1]->u.Next=ArrayNode_P;

  /*********處理矩陣節點的相關鏈結************/
  ArrayNode_P->right=HeadNode[0];
  ArrayNode_P->down=HeadNode[0];      /*非必要*/
  ArrayNode_P->u.Next=HeadNode[0];    /*非必要*/

  return  ArrayNode_P;
}

void PrintMatrix(MatrixNode_P ArrayNode)
{
  int i,j;
  MatrixNode_P Head_P,temp;

  Head_P=ArrayNode->right;
  for(i=0;i<ArrayNode->u.element.row;i++)
  {
    printf("|");
    temp=Head_P->right;
    for(j=0;j<ArrayNode->u.element.col;)
    {
     if(j!=temp->u.element.col-1)
     {
       printf("%2d",0);       /* 0元素 */
       j++;
     }
     else
     while(temp!=Head_P)
     {
        printf("%2d",temp->u.element.value); /* 非0元素 */
        temp=temp->right;
        j++;
     }
    }
    printf("|\n");
    Head_P=Head_P->u.Next;   /*  到下一列  */
  }
}

void EraseMatrix(MatrixNode_P ArrayNode)
{
  MatrixNode_P Head_P,freeone,nextone;
  int i;

  Head_P=ArrayNode->right;   /* Head_P指向第一個頭節點 */
  /*  逐列釋放元素節點  */
  for(i=0;i < ArrayNode->u.element.row;i++)
  {
    /* 釋放該列所有元素節點 */
    nextone=Head_P->right;
    while(nextone!=Head_P)
    {
      freeone=nextone;
      nextone=nextone->right;
      free(freeone);
    }
    freeone=Head_P;
    Head_P=Head_P->u.Next;  /* Head_P指向下一個頭節點 */
    free(freeone); /* 釋放該列的頭節點 */
  }

  /*若矩陣的行多於列時,必須刪除剩餘行的頭節點*/
  nextone=Head_P;
  while(nextone!=ArrayNode)
  {
     freeone=nextone;
     nextone=nextone->u.Next;
     free(freeone);
  }

  free(ArrayNode);  /* 釋放矩陣節點 */
  ArrayNode=NULL;
}
int main(void)
{

  MatrixNode_P A;
  A=ReadMatrix();
  printf("===列印矩陣===\n");
  PrintMatrix(A);
  EraseMatrix(A);
  printf("===釋放矩陣完畢===\n");
  system("pause");
  return 0;
}
