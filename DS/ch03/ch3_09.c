#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MAX_Row 4
#define MAX_Column 3
#define MAX_Item MAX_Row*MAX_Column  /* A矩陣大小為4*3 */

typedef struct
{
  int row;
  int column;
  double value;
}item;

/*********** 相當於Create運算 ************/
void Create(item *A)
{
  int i;
  for(i=0;i<=MAX_Item;i++)         /*  陣列初始化*/
  {
    A[i].row=0;A[i].column=0;A[i].value=0;
  }
}

void DeleteOldItem(item*,int);
void AddNewItem(item*,int,int,double);

/***********  SetElement運算  ***********/
void SetElt(item *A,int i,int j,double newvalue)
{
 int k;
 if((i>A[0].row) || (j>A[0].column))
    exit(1);

 for(k=1;k<=A[0].value;k++)
 {
    if((i==A[k].row) && (j==A[k].column))
    {
       /*  找到符合的項目  */
       if(newvalue==0)
             DeleteOldItem(A,k);    /*   刪除一項  */
       else
             A[k].value=newvalue;   /*   修改項目  */
       return;
    }
 }
 /*  未找到符合的項目  */
 if(newvalue==0)
   return;              /* 未找到符合的項目,但不需新增 */
 else
   AddNewItem(A,i,j,newvalue); /* 未找到符合的項目,且需新增 */
}
/***********  DeleteOldItem  ***********/
void DeleteOldItem(item *A,int k)
{
  int p;
  /*  該項目之後的所有項目向前搬移,造成該項目被刪除  */
  for(p=k;p<A[0].value;p++)
  {
    A[p].row=A[p+1].row;
    A[p].column=A[p+1].column;
    A[p].value=A[p+1].value;
  }
  /*  刪除一個項目後,陣列最後一項必為0  */
  A[(int)A[0].value].row=0;
  A[(int)A[0].value].column=0;
  A[(int)A[0].value].value=0;

  A[0].value=A[0].value-1;    /*   項目少1  */
}
/***********  AddNewItem  ***********/
void AddNewItem(item *A,int i,int j,double newvalue)
{
  int p;

  /*  該項目之後的所有項目向後搬移,
      騰出一個空間,由最後一項開始向下搬移  */
  for(p=(int)A[0].value;p>=1;p--)
  {
    if((A[p].row>i) || ((A[p].row==i) && (A[p].column>j)))
    {
       A[p+1].row=A[p].row;
       A[p+1].column=A[p].column;
       A[p+1].value=A[p].value;
       
    }
    else
       break;    /*  已達目標項目之前一項,故停止搬移 */
  }
  /*  在騰出之空間,填入新項目值 */
  A[p+1].row=i;
  A[p+1].column=j;
  A[p+1].value=newvalue;

  A[0].value=A[0].value+1;    /*   項目多1  */
}
/***********  RetrieveElement運算  ***********/
double RetrieveElt(item *A,int i,int j)
{
 int k;
 if((i>A[0].row) || (j>A[0].column))
    exit(1);
 for(k=1;k<=A[0].value;k++)
 {
    if((i==A[k].row) && (j==A[k].column))
        return A[k].value;    /* 找到符合之條件,故回傳值  */
 }
 return 0; /* 找不到符合之條件,代表該矩陣元素為0,故回傳0  */
}


int main(void)
{
  int i,j;
  char choice;
  float newvalue;

  item A[MAX_Item+1];  /*  MAX_Item為一個常數  */
                       /* 相當於Create運算之第一個步驟 */
  Create(A);          /* 相當於Create運算之第二個步驟 */
  A[0].row=MAX_Row;          /*  最多記錄4列  */
  A[0].column=MAX_Column;    /*  最多記錄3行  */

  SetElt(A,1,1,2);               /*設定a11=<1,1,2>*/
  SetElt(A,2,3,1);               /*設定a23=<2,3,1>*/
  SetElt(A,3,1,7);               /*設定a31=<3,1,7>*/

  while(1)
  {
    fflush(stdin);
    printf("s:執行SetElement運算,r:執行RetrieveElement運算");
    printf(",p:列印矩陣,q:離開\n");
    printf("請選擇:");
    scanf("%c",&choice);
    switch(choice)
    {
      case 's':
           printf("請輸入元素索引(aij)及元素值\n");
           printf("i=");    scanf("%d",&i);
           printf("j=");    scanf("%d",&j);
           printf("newvalue=");  scanf("%f",&newvalue);
           SetElt(A,i,j,(double)newvalue);
           break;
      case 'r':
           printf("請輸入元素索引(aij)\n");
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
