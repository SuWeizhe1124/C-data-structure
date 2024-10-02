#include <malloc.h>


#define MaxSize 201               /* �ְ�i�H�̦h��200�Ӥ��� */
#define HeapFull(n) (n==MaxSize-1)
#define HeapEmpty(n) (!n)         /* n��0��,!0=1->�۷��^��TRUE */

typedef struct
{
    int key;     /* ���,�Ҧp�u���v���� */
    /* ��L���,�Ҧp�s���ڸ����� */
}element;

element heap[MaxSize];       /* �ݩ�Create�B�� */
int n=0;                     /* �@�}�l�ְ�O�Ū� */

void insert_maxheap(element item,int *n)  /* ���J�s������ְ� */
{
  int i;
  if(HeapFull(*n)) { printf("Heap is Full!\n"); exit(1); }
  
  (*n)++;
  i=*n;
  while(i!=1)
  {
    if(!(item.key > heap[i/2].key))  break;
    heap[i]=heap[i/2];        /* �N���`�I���U�� */
    i=i/2;                    /* �ѩ�ŧi��int,�ҥH�۷����U���� */
  }
  heap[i]=item;               /* �̫�N�s�������J�ְ勵�T��m */  
}

element delete_maxheap(int *n)  /* �R���̤j��Ȥ��� */
{
  int parent,child;
  element item,temp;
  
  if(HeapEmpty(*n)) { printf("Heap is Empty!\n"); exit(1); }
  
  item=heap[1];                  /* item�O�n�^�Ǫ��̤j��Ȥ��� */
  
  temp=heap[(*n)];               /* ���X�s���̫᪺�`�I��Jtemp */
  (*n)--;                        /* ��ʾ𪺸`�I�ƶq���Ӥ֤@�� */
  
  parent=1;                      /* �Ѯڸ`�I�}�l��� */
  child=2;                       /* ���l�`�I���s�� */    
  
  while(child <= *n)
  {
     if ((child <*n) && (heap[child].key < heap[child+1].key))
       child++;             /* �k�l�`�I���j,�ҥH���Ӥ�����O�k�l�`�I */ 
     
     if(temp.key >= heap[child].key)  
        break;              /* �ץ��w�g���� */
     else
     {
        heap[parent]=heap[child];        /* �P���j���l�`�I���� */
        parent=child;   child=child*2;   /* ����U�@�h */
     }
  }
  heap[parent]=temp;             /* �N�s���̫᪺�`�I��J���T����m */
  return item;
}