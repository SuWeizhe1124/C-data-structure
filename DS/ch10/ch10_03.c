/*  Interpolation Search algorithm  */
#include <stdio.h>
#include <stdlib.h>
typedef struct{
      int key;
      char data;
      /*   其他資料欄位 */
}record;

void SetData(record x[],int n)
{
  int key[10]={55,85,147,156,606,700,772,2715,2813,2873};
  int data[10]={'A','F','G','E','J','Q','W','X','U','P'};
  int i;

  for(i=0;i<n;i++)             
  {
    x[i].key=key[i];      x[i].data=data[i];
  }
}

int InterpolationSearch(record x[],int n,int k)
{
  int low,high,mid;

  low = 0;
  high = n-1;
  while ((x[low].key<k) && (x[high].key>= k))
  {
   mid=low+(((k-x[low].key)*(high-low))/(x[high].key-x[low].key));
   /*  注意上述公式的自動資料型態調整,不可使得下高斯過早出現 */
   if(x[mid].key == k)  return mid;
   if (x[mid].key < k)  low = mid + 1;    /* 放棄前面 */
   else                 high = mid - 1;   /* 放棄後面 */
  }
  if (x[low].key == k)
    return low;
  else
    return -1;  /* 沒有符合的記錄 */
}

int main()
{
  int loc,n=10;
  record x[10];

  SetData(x,10);
  loc=InterpolationSearch(x,10,700); /*搜尋key=700的記錄 */
  if (loc==-1)
    printf("無此筆資料\n");
  else
    printf("x[%d]=%d \t %c\n",loc,x[loc].key,x[loc].data);
  system("pause");
  return 0;
}
