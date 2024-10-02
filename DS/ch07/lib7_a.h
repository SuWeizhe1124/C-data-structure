#define TRUE 1
#define FALSE 0

typedef struct node *bt_pointer;

typedef struct node
{
    int data;                   /* 如為字元資料改為 char data; 依此類推 */
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
     /* 右子鏈結非引線 */
     while(temp->left_thread !=TRUE) /* 左子鏈結非引線，持續往左探*/
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

int equal2t (bt_pointer t1,bt_pointer t2) /* t1,t2相等判定演算法 */
{
 /* t1一開始應該指向第一棵樹的根節點 */
 /* t2一開始應該指向第二棵樹的根節點 */

  return ((!t1 && !t2) ||                       /* t1,t2必須非空樹 */
   (t1 && t2 && t1->data == t2->data) &&        /* 比較根節點 */
    equal2t(t1->left_child,t2->left_child) &&   /* 比較左子樹 */
    equal2t(t1->right_child,t2->right_child));   /* 比較右子樹 */
}

bt_pointer copybt(bt_pointer t1) /* 複製t1二元樹 */
{
  bt_pointer temp;
  if(t1)
  {
    temp = (bt_pointer) malloc(sizeof(treenode));
    if (temp==NULL) exit(1);     /* 記憶體配置失敗 */
    temp->left_child = copybt(t1->left_child);     /* 複製左子樹 */
    temp->right_child = copybt(t1->right_child);   /* 複製右子樹 */
    temp->data=t1->data;                           /* 複製資料欄位 */
  return temp;
  }
  return NULL;
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

void postorder(bt_pointer ptr) /* 後序走訪 */
{
 /* prt一開始應該指向樹的根節點 */
  if(ptr)     /* 若ptr非NULL */
  {    
    postorder(ptr->left_child);    
    postorder(ptr->right_child);
    printf("%d ",ptr->data);   /* 如為字元資料改為%c */
  }    
}