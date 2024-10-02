#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node *bt_pointer;

typedef struct node
{
    int data;                   /* �p���r����Ƨאּ char data; �̦����� */
    bt_pointer left_child,right_child;
}treenode;

bt_pointer search(bt_pointer root,int k)
{                /* root���V�l��ڸ`�I,k���ؼ���� */
  if(root == NULL) return NULL;            /* �w��츭�`�I,������� */
  if(k == root->data) return root;         /* ���F */
  if(k < root->data)
    return search(root->left_child,k);   /* �����l��� */
  else
    return search(root->right_child,k); /* ���k�l��� */
}

bt_pointer iteration_search(bt_pointer BSTree,int k)
{                /* BSTree���V�𪺮ڸ`�I,k���ؼ���� */
  while(BSTree!=NULL)
  {
    if(k == BSTree->data) return BSTree;  /* ���F */
    if(k < BSTree->data)
       BSTree=BSTree->left_child;   /* �����l��� */
    else
       BSTree=BSTree->right_child;  /* ���k�l��� */
  }
  return NULL;            /* �w��츭�`�I,������� */
}

bt_pointer modify_search(bt_pointer BSTree,int k)
{                /* BSTree���V�𪺮ڸ`�I,k���ؼ���� */
  while(BSTree!=NULL)
  {
    if(k == BSTree->data) return NULL;  /* ���F */
    if(k < BSTree->data)
    {
       if(BSTree->left_child==NULL) break;   /* ���l�`�I����,���X */
       BSTree=BSTree->left_child;   /* �����l��� */
    }
    else
    {
       if(BSTree->right_child==NULL) break;  /* �k�l�`�I����,���X */
       BSTree=BSTree->right_child;  /* ���k�l��� */
    }
  }
  return BSTree;            /* �������,�^�������J��m�����`�I */
}

void insert_node(bt_pointer *wnode,int num)
{
  bt_pointer ptr;
  bt_pointer temp=modify_search(*wnode,num);

  if(temp || ((*wnode)==NULL))             /* *wnode��NULL,�N��ž� */
  {                       /* �D�ž��,��temp�O�_��NULL�M�w�O�_�n�@ */
    ptr=(bt_pointer)malloc(sizeof(treenode)); /* �i�W�t�m�O�_���\,�� */
    ptr->data=num;
    ptr->left_child =NULL;
    ptr->right_child=NULL;

    if((*wnode)!=NULL)           /* �D�ž�� */
    {
     if(num<temp->data)
       temp->left_child=ptr;
     else
       temp->right_child=ptr;
    }
    else
    {
      *wnode=ptr;               /* �ž�ɷs�����������w���ڸ`�I */
    }
  }
}

void inorder(bt_pointer ptr) /* ���Ǩ��X */
{
 /* prt�@�}�l���ӫ��V�𪺮ڸ`�I */
  if(ptr)     /* �Yptr�DNULL */
  {
    inorder(ptr->left_child);
    printf("%d ",ptr->data);   /* �p���r����Ƨאּ%c */
    inorder(ptr->right_child);
  }
}

void preorder(bt_pointer ptr) /* �e�Ǩ��X */
{
 /* prt�@�}�l���ӫ��V�𪺮ڸ`�I */
  if(ptr)     /* �Yptr�DNULL */ 
  {
    printf("%d ",ptr->data);   /* �p���r����Ƨאּ%c */
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
