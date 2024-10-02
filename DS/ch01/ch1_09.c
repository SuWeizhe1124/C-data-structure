#include <stdio.h>
#include <stdlib.h>

int FACTORIAL(int n)
{
    int i;
    int FACT=1;
    if(n<0)
        return -1;
    if(n==0)
        return 1;
    for(i=1;i<=n;i++)
        FACT=i*FACT;
    return FACT;
}

int main(void)
{
 printf("10!=%d\n",FACTORIAL(10));
 system("pause");
 return 0;
}
