#include <stdio.h>
#include <stdlib.h>

int counter;

int FACTORIAL(int n)
{
    counter++;   /* �N��if�ԭz */
    if(n<0)
    {    counter++;   /* �N��return�ԭz */ return -1;  }
    counter++;   /* �N��if�ԭz */
    if(n==0)
    {    counter++;   /* �N��return�ԭz */  return 1;  }
    counter++;  /* �N��return�ԭz */ return n * FACTORIAL(n-1);
}

int main(void)
{
 printf("10!=%d\n",FACTORIAL(10));
 printf("counter=%d\n",counter);
 system("pause");
 return 0;
}
