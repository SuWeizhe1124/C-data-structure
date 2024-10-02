#define TRUE 1
#define FALSE 0

typedef struct node *bt_pointer;

typedef struct node
{
    int data;                   /* �p���r����Ƨאּ char data; �̦����� */
    bt_pointer left_child,right_child;
}treenode;

typedef struct thread_T_node *thread_bt_pointer;

typedef struct thread_T_node
{
    short int left_thread,right_thread;
    char data;
    thread_bt_pointer left_child,right_child;
}threadTreenode;

thread_bt_pointer thread_inoder_successor(thread_bt_pointer temp)
{
   thread_bt_pointer ptr;
   ptr=temp->right_child;
   if(temp->right_thread!=TRUE)
   {
     /* �k�l�쵲�D�޽u */
     while(temp->left_thread !=TRUE) /* ���l�쵲�D�޽u�A���򩹥���*/
     {        
        ptr=ptr->left_child;
     }
   }
   return ptr;
}

void thread_inorder(thread_bt_pointer tree)
{
  thread_bt_pointer temp = tree;
  while(1)
  {
    temp=thread_inoder_successor(temp);
    if(temp==tree) break;
    printf("%c ",temp->data);
  }  
}

void insert_right(thread_bt_pointer parent,thread_bt_pointer child)
{
  thread_bt_pointer temp;

  /* (1) */
  child->right_child = parent->right_child;
  child->right_thread=parent->right_thread;
  
  /* (2) */
  child->left_child=parent;
  child->left_thread=TRUE;
  
  /* (3) */
  parent->right_child=child;
  parent->right_thread=FALSE;
  
  /* (4) */
  if(child->right_thread==FALSE)
  {
     temp=thread_inoder_successor(child);
     temp->left_child=child;
  }
}

int equal2t (bt_pointer t1,bt_pointer t2) /* t1,t2�۵��P�w�t��k */
{
 /* t1�@�}�l���ӫ��V�Ĥ@�ʾ𪺮ڸ`�I */
 /* t2�@�}�l���ӫ��V�ĤG�ʾ𪺮ڸ`�I */

  return ((!t1 && !t2) ||                       /* t1,t2�����D�ž� */
   (t1 && t2 && t1->data == t2->data) &&        /* ����ڸ`�I */
    equal2t(t1->left_child,t2->left_child) &&   /* ������l�� */
    equal2t(t1->right_child,t2->right_child));   /* ����k�l�� */
}

bt_pointer copybt(bt_pointer t1) /* �ƻst1�G���� */
{
  bt_pointer temp;
  if(t1)
  {
    temp = (bt_pointer) malloc(sizeof(treenode));
    if (temp==NULL) exit(1);     /* �O����t�m���� */
    temp->left_child = copybt(t1->left_child);     /* �ƻs���l�� */
    temp->right_child = copybt(t1->right_child);   /* �ƻs�k�l�� */
    temp->data=t1->data;                           /* �ƻs������ */
  return temp;
  }
  return NULL;
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

void postorder(bt_pointer ptr) /* ��Ǩ��X */
{
 /* prt�@�}�l���ӫ��V�𪺮ڸ`�I */
  if(ptr)     /* �Yptr�DNULL */
  {    
    postorder(ptr->left_child);    
    postorder(ptr->right_child);
    printf("%d ",ptr->data);   /* �p���r����Ƨאּ%c */
  }    
}