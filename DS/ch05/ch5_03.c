#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

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
MatrixNode_P GetNode(void) /* ���o�s���}���x�}�������`�I */
{
  MatrixNode_P NewNode_P;
  NewNode_P=(MatrixNode_P) malloc(sizeof(MatrixNode));
  if (NewNode_P==NULL)
  {
     printf("�O���餣��!");
     exit(1);
 }
 return  NewNode_P;
}

MatrixNode_P ReadMatrix(void)
{
  int RowNum,ColNum,NonZeroNum,HeadNum;
  int i,CurrentRow,row,col,value;
  MatrixNode_P ArrayNode_P,temp,LastNode_P;
  printf("�п�J�x�}���C��:");         scanf("%d",&RowNum);
  printf("�п�J�x�}�����:");         scanf("%d",&ColNum);
  printf("�п�J�x�}���D�s�����Ӽ�:"); scanf("%d",&NonZeroNum);
  if(RowNum>=ColNum) HeadNum=RowNum;
  else HeadNum=ColNum;

  /**********�إ߯x�}�`�I************/
  ArrayNode_P=GetNode();
  ArrayNode_P->tag=array;
  ArrayNode_P->u.element.row=RowNum;
  ArrayNode_P->u.element.col=ColNum;

  /********�إ��Y�`�I�P�����`�I******/
  if(HeadNum==0)
  {  /*�ůx�}*/
     ArrayNode_P->right=ArrayNode_P;
     ArrayNode_P->down=ArrayNode_P;      /*�D���n*/
     ArrayNode_P->u.Next=ArrayNode_P;    /*�D���n*/
  }
  else
  {
     for(i=0;i<HeadNum;i++)    /*�إߩҦ����Y�`�I*/
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
  printf("�̧�(�H�C���u��)��J�D�s������\n");
  /***************�B�z�����`�I*********************/
  for(i=0;i<NonZeroNum;i++)
  {
     printf("�C �� ������:");
     scanf("%d%d%d",&row,&col,&value);
     if(row-1>CurrentRow)
     {
        /*�ӦC�̫�@�Ӹ`�I���쵲���^�C�Y�`�I*/
        LastNode_P->right=HeadNode[CurrentRow];
        CurrentRow=row-1;
        LastNode_P=HeadNode[row-1];  /* �վ㬰�s���C*/
     }
     temp=GetNode();
     temp->tag=entry;
     temp->u.element.row=row;
     temp->u.element.col=col;
     temp->u.element.value=value;

     /*****************�B�z�����쵲******************/
     LastNode_P->right=temp;
     LastNode_P=temp;
     /*****************�B�z�����쵲******************/
     HeadNode[col-1]->u.Next->down=temp;/*�B�z�����쵲*/
     HeadNode[col-1]->u.Next=temp; /* Next���V�Ӧ楽�`�I */
  }
  /*�̫�C�̫�@�Ӹ`�I�������쵲���^�ӦC�Y�`�I*/
  LastNode_P->right=HeadNode[CurrentRow];

  for(i=0;i<ColNum;i++)
  {   /*�B�z���������̫�@���쵲*/
      HeadNode[i]->u.Next->down=HeadNode[i];
  }
  /***************�����`�I�B�z����***************/

  for(i=0;i<HeadNum-1;i++)
  {     /*�B�z�Y�`�I�������쵲*/
      HeadNode[i]->u.Next=HeadNode[i+1];
  }
  /*�̫�@���Y�`�I�쵲�^�x�}�`�I*/
  HeadNode[HeadNum-1]->u.Next=ArrayNode_P;

  /*********�B�z�x�}�`�I�������쵲************/
  ArrayNode_P->right=HeadNode[0];
  ArrayNode_P->down=HeadNode[0];      /*�D���n*/
  ArrayNode_P->u.Next=HeadNode[0];    /*�D���n*/

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
       printf("%2d",0);       /* 0���� */
       j++;
     }
     else
     while(temp!=Head_P)
     {
        printf("%2d",temp->u.element.value); /* �D0���� */
        temp=temp->right;
        j++;
     }
    }
    printf("|\n");
    Head_P=Head_P->u.Next;   /*  ��U�@�C  */
  }
}

void EraseMatrix(MatrixNode_P ArrayNode)
{
  MatrixNode_P Head_P,freeone,nextone;
  int i;

  Head_P=ArrayNode->right;   /* Head_P���V�Ĥ@���Y�`�I */
  /*  �v�C���񤸯��`�I  */
  for(i=0;i < ArrayNode->u.element.row;i++)
  {
    /* ����ӦC�Ҧ������`�I */
    nextone=Head_P->right;
    while(nextone!=Head_P)
    {
      freeone=nextone;
      nextone=nextone->right;
      free(freeone);
    }
    freeone=Head_P;
    Head_P=Head_P->u.Next;  /* Head_P���V�U�@���Y�`�I */
    free(freeone); /* ����ӦC���Y�`�I */
  }

  /*�Y�x�}����h��C��,�����R���Ѿl�檺�Y�`�I*/
  nextone=Head_P;
  while(nextone!=ArrayNode)
  {
     freeone=nextone;
     nextone=nextone->u.Next;
     free(freeone);
  }

  free(ArrayNode);  /* ����x�}�`�I */
  ArrayNode=NULL;
}
int main(void)
{

  MatrixNode_P A;
  A=ReadMatrix();
  printf("===�C�L�x�}===\n");
  PrintMatrix(A);
  EraseMatrix(A);
  printf("===����x�}����===\n");
  system("pause");
  return 0;
}
