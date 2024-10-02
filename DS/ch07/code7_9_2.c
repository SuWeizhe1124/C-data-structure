#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node *bt_pointer;

typedef struct node
{
    int data;                   /* 如為字元資料改為 char data; 依此類推 */
    bt_pointer left_child,right_child;
}treenode;

bt_pointer search(bt_pointer root,int k)
{                /* root指向子樹根節點,k為目標鍵值 */
  if(root == NULL) return NULL;            /* 已找到葉節點,仍未找到 */
  if(k == root->data) return root;         /* 找到了 */
  if(k < root->data)
    return search(root->left_child,k);   /* 往左子樹找 */
  else
    return search(root->right_child,k); /* 往右子樹找 */
}

bt_pointer iteration_search(bt_pointer BSTree,int k)
{                /* BSTree指向樹的根節點,k為目標鍵值 */
  while(BSTree!=NULL)
  {
    if(k == BSTree->data) return BSTree;  /* 找到了 */
    if(k < BSTree->data)
       BSTree=BSTree->left_child;   /* 往左子樹找 */
    else
       BSTree=BSTree->right_child;  /* 往右子樹找 */
  }
  return NULL;            /* 已找到葉節點,仍未找到 */
}

bt_pointer modify_search(bt_pointer BSTree,int k)
{                /* BSTree指向樹的根節點,k為目標鍵值 */
  while(BSTree!=NULL)
  {
    if(k == BSTree->data) return NULL;  /* 找到了 */
    if(k < BSTree->data)
    {
       if(BSTree->left_child==NULL) break;   /* 左子節點為空,跳出 */
       BSTree=BSTree->left_child;   /* 往左子樹找 */
    }
    else
    {
       if(BSTree->right_child==NULL) break;  /* 右子節點為空,跳出 */
       BSTree=BSTree->right_child;  /* 往右子樹找 */
    }
  }
  return BSTree;            /* 未找到資料,回傳應插入位置的父節點 */
}

void insert_node(bt_pointer *wnode,int num)
{
  bt_pointer ptr;
  bt_pointer temp=modify_search(*wnode,num);

  if(temp || ((*wnode)==NULL))             /* *wnode為NULL,代表空樹 */
  {                       /* 非空樹時,由temp是否為NULL決定是否要作 */
    ptr=(bt_pointer)malloc(sizeof(treenode)); /* 可增配置是否成功,略 */
    ptr->data=num;
    ptr->left_child =NULL;
    ptr->right_child=NULL;

    if((*wnode)!=NULL)           /* 非空樹時 */
    {
     if(num<temp->data)
       temp->left_child=ptr;
     else
       temp->right_child=ptr;
    }
    else
    {
      *wnode=ptr;               /* 空樹時新元素直接指定為根節點 */
    }
  }
}

void inorder(bt_pointer ptr) /* 中序走訪 */
{
 /* prt一開始應該指向樹的根節點 */
  if(ptr)     /* 若ptr非NULL */
  {
    inorder(ptr->left_child);
    printf("%d ",ptr->data);   /* 如為字元資料改為%c */
    inorder(ptr->right_child);
  }
}

void preorder(bt_pointer ptr) /* 前序走訪 */
{
 /* prt一開始應該指向樹的根節點 */
  if(ptr)     /* 若ptr非NULL */ 
  {
    printf("%d ",ptr->data);   /* 如為字元資料改為%c */
    preorder(ptr->left_child);    
    preorder(ptr->right_child);
  } 
}

int main(void)
{

  int i;
  int array[8]={25,15,30,12,17,12,16,27};
  bt_pointer head= NULL;
  for(i=0;i<=7;i++)
    insert_node(&head,array[i]);

  printf("preoder\n");
  preorder(head);
  printf("\ninoder\n");
  inorder(head);

  system("pause");
  return 0;
}
