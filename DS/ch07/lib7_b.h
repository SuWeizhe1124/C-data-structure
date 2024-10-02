#include <malloc.h>


#define MaxSize 201               /* 累堆可以最多有200個元素 */
#define HeapFull(n) (n==MaxSize-1)
#define HeapEmpty(n) (!n)         /* n為0時,!0=1->相當於回傳TRUE */

typedef struct
{
    int key;     /* 鍵值,例如優先權等級 */
    /* 其他欄位,例如存放實際資料欄位 */
}element;

element heap[MaxSize];       /* 屬於Create運算 */
int n=0;                     /* 一開始累堆是空的 */

void insert_maxheap(element item,int *n)  /* 插入新元素到累堆 */
{
  int i;
  if(HeapFull(*n)) { printf("Heap is Full!\n"); exit(1); }
  
  (*n)++;
  i=*n;
  while(i!=1)
  {
    if(!(item.key > heap[i/2].key))  break;
    heap[i]=heap[i/2];        /* 將父節點往下降 */
    i=i/2;                    /* 由於宣告為int,所以相當於取下高斯 */
  }
  heap[i]=item;               /* 最後將新元素插入累堆正確位置 */  
}

element delete_maxheap(int *n)  /* 刪除最大鍵值元素 */
{
  int parent,child;
  element item,temp;
  
  if(HeapEmpty(*n)) { printf("Heap is Empty!\n"); exit(1); }
  
  item=heap[1];                  /* item是要回傳的最大鍵值元素 */
  
  temp=heap[(*n)];               /* 取出編號最後的節點放入temp */
  (*n)--;                        /* 整棵樹的節點數量應該少一個 */
  
  parent=1;                      /* 由根節點開始比較 */
  child=2;                       /* 左子節點的編號 */    
  
  while(child <= *n)
  {
     if ((child <*n) && (heap[child].key < heap[child+1].key))
       child++;             /* 右子節點較大,所以應該比較的是右子節點 */ 
     
     if(temp.key >= heap[child].key)  
        break;              /* 修正已經完成 */
     else
     {
        heap[parent]=heap[child];        /* 與較大的子節點互換 */
        parent=child;   child=child*2;   /* 移到下一層 */
     }
  }
  heap[parent]=temp;             /* 將編號最後的節點放入正確的位置 */
  return item;
}