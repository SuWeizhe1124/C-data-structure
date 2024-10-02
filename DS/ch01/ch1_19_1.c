#include <stdio.h>
#include <stdlib.h>

int counter;

int FACTORIAL(int n)
{
    counter++;   /* 代表if敘述 */
    if(n<0)
    {    counter++;   /* 代表return敘述 */ return -1;  }
    counter++;   /* 代表if敘述 */
    if(n==0)
    {    counter++;   /* 代表return敘述 */  return 1;  }
    counter++;  /* 代表return敘述 */ return n * FACTORIAL(n-1);
}

int main(void)
{
 printf("10!=%d\n",FACTORIAL(10));
 printf("counter=%d\n",counter);
 system("pause");
 return 0;
}
