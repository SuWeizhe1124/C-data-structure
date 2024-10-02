#include <stdio.h>
#include <stdlib.h>

int counter;

int FACTORIAL(int n)
{
    int i;
    int FACT=1;      counter++;  /* 代表=指定敘述 */
    counter++;   /* 代表if敘述 */  
    if(n<0)
    {   counter++;   /* 代表return敘述 */  return -1;  }
    counter++;   /* 代表if敘述 */  
    if(n==0)
    {   counter++;   /* 代表return敘述 */  return 1;  }
    for(i=1;i<=n;i++)
    {
        counter++;   /* 代表for敘述 */ 
        FACT=i*FACT;   counter++;   /* 代表=指定敘述 */ 
    }
    counter++;   /* 代表for敘述最後一次執行,也就是i=n時 */ 
    counter++;   /* 代表return敘述 */  return FACT;
}



int main(void)
{
 printf("10!=%d\n",FACTORIAL(10));
 printf("counter=%d\n",counter);
 system("pause");
 return 0;
}
