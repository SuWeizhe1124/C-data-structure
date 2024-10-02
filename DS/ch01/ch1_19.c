#include <stdio.h>
#include <stdlib.h>

int FACTORIAL(int n)
{
    if(n<0)
        return -1;
    if(n==0)
        return 1;
    return n * FACTORIAL(n-1);
}

int main(void)
{
 printf("10!=%d\n",FACTORIAL(10));
 system("pause");
 return 0;
}
