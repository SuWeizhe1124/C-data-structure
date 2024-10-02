#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#define MAX_Row 4
#define MAX_Column 3
#define MAX_Item MAX_Row*MAX_Column  /* A�x�}�j�p��4*3 */

typedef struct
{
  int row;
  int column;
  double value;
}item;

/*********** �۷��Create�B�� ************/
void Create(item *A)
{
  int i;
  for(i=0;i<=MAX_Item;i++)         /*  �}�C��l��*/
  {
    A[i].row=0;A[i].column=0;A[i].value=0;
  }
}

void DeleteOldItem(item*,int);
void AddNewItem(item*,int,int,double);

/***********  SetElement�B��  ***********/
void SetElt(item *A,int i,int j,double newvalue)
{
 int k;
 if((i>A[0].row) || (j>A[0].column))
    exit(1);

 for(k=1;k<=A[0].value;k++)
 {
    if((i==A[k].row) && (j==A[k].column))
    {
       /*  ���ŦX������  */
       if(newvalue==0)
             DeleteOldItem(A,k);    /*   �R���@��  */
       else
             A[k].value=newvalue;   /*   �קﶵ��  */
       return;
    }
 }
 /*  �����ŦX������  */
 if(newvalue==0)
   return;              /* �����ŦX������,�����ݷs�W */
 else
   AddNewItem(A,i,j,newvalue); /* �����ŦX������,�B�ݷs�W */
}
/***********  DeleteOldItem  ***********/
void DeleteOldItem(item *A,int k)
{
  int p;
  /*  �Ӷ��ؤ��᪺�Ҧ����ئV�e�h��,�y���Ӷ��سQ�R��  */
  for(p=k;p<A[0].value;p++)
  {
    A[p].row=A[p+1].row;
    A[p].column=A[p+1].column;
    A[p].value=A[p+1].value;
  }
  /*  �R���@�Ӷ��ث�,�}�C�̫�@������0  */
  A[(int)A[0].value].row=0;
  A[(int)A[0].value].column=0;
  A[(int)A[0].value].value=0;

  A[0].value=A[0].value-1;    /*   ���ؤ�1  */
}
/***********  AddNewItem  ***********/
void AddNewItem(item *A,int i,int j,double newvalue)
{
  int p;

  /*  �Ӷ��ؤ��᪺�Ҧ����ئV��h��,
      �˥X�@�ӪŶ�,�ѳ̫�@���}�l�V�U�h��  */
  for(p=(int)A[0].value;p>=1;p--)
  {
    if((A[p].row>i) || ((A[p].row==i) && (A[p].column>j)))
    {
       A[p+1].row=A[p].row;
       A[p+1].column=A[p].column;
       A[p+1].value=A[p].value;
       
    }
    else
       break;    /*  �w�F�ؼж��ؤ��e�@��,�G����h�� */
  }
  /*  �b�˥X���Ŷ�,��J�s���ح� */
  A[p+1].row=i;
  A[p+1].column=j;
  A[p+1].value=newvalue;

  A[0].value=A[0].value+1;    /*   ���ئh1  */
}
/***********  RetrieveElement�B��  ***********/
double RetrieveElt(item *A,int i,int j)
{
 int k;
 if((i>A[0].row) || (j>A[0].column))
    exit(1);
 for(k=1;k<=A[0].value;k++)
 {
    if((i==A[k].row) && (j==A[k].column))
        return A[k].value;    /* ���ŦX������,�G�^�ǭ�  */
 }
 return 0; /* �䤣��ŦX������,�N��ӯx�}������0,�G�^��0  */
}


int main(void)
{
  int i,j;
  char choice;
  float newvalue;

  item A[MAX_Item+1];  /*  MAX_Item���@�ӱ`��  */
                       /* �۷��Create�B�⤧�Ĥ@�ӨB�J */
  Create(A);          /* �۷��Create�B�⤧�ĤG�ӨB�J */
  A[0].row=MAX_Row;          /*  �̦h�O��4�C  */
  A[0].column=MAX_Column;    /*  �̦h�O��3��  */

  SetElt(A,1,1,2);               /*�]�wa11=<1,1,2>*/
  SetElt(A,2,3,1);               /*�]�wa23=<2,3,1>*/
  SetElt(A,3,1,7);               /*�]�wa31=<3,1,7>*/

  while(1)
  {
    fflush(stdin);
    printf("s:����SetElement�B��,r:����RetrieveElement�B��");
    printf(",p:�C�L�x�},q:���}\n");
    printf("�п��:");
    scanf("%c",&choice);
    switch(choice)
    {
      case 's':
           printf("�п�J��������(aij)�Τ�����\n");
           printf("i=");    scanf("%d",&i);
           printf("j=");    scanf("%d",&j);
           printf("newvalue=");  scanf("%f",&newvalue);
           SetElt(A,i,j,(double)newvalue);
           break;
      case 'r':
           printf("�п�J��������(aij)\n");
           printf("i=");    scanf("%d",&i);
           printf("j=");    scanf("%d",&j);
           printf("(a%d%d)=%7.3f\n",i,j,RetrieveElt(A,i,j));
           break;
      case 'p':
           for(i=1;i<=A[0].row;i++)
           {
              printf("|");
              for(j=1;j<=A[0].column;j++)
              {
                 printf("%7.3f  ",RetrieveElt(A,i,j));
              }
              printf("|\n");
           }
           break;
      case 'q':
           return 0;
    }         
  }
  system("pause");
  return 0;
}
