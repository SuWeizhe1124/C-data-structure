#include <stdio.h>
#include <stdlib.h>

int counter;

int FACTORIAL(int n)
{
    int i;
    int FACT=1;      counter++;  /* �N��=���w�ԭz */
    counter++;   /* �N��if�ԭz */  
    if(n<0)
    {   counter++;   /* �N��return�ԭz */  return -1;  }
    counter++;   /* �N��if�ԭz */  
    if(n==0)
    {   counter++;   /* �N��return�ԭz */  return 1;  }
    for(i=1;i<=n;i++)
    {
        counter++;   /* �N��for�ԭz */ 
        FACT=i*FACT;   counter++;   /* �N��=���w�ԭz */ 
    }
    counter++;   /* �N��for�ԭz�̫�@������,�]�N�Oi=n�� */ 
    counter++;   /* �N��return�ԭz */  return FACT;
}



int main(void)
{
 printf("10!=%d\n",FACTORIAL(10));
 printf("counter=%d\n",counter);
 system("pause");
 return 0;
}
