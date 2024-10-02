#include <stdio.h>
#include <stdlib.h>

int counter;

int FACTORIAL(int n)
{
    int i;
    counter+=2;
    if(n<0)
    {   counter++;  return -1;  }
    counter++;
    if(n==0)
    {   counter++;  return 1;  }
    for(i=1;i<=n;i++)
        counter+=2;
    counter+=2;    return 0;
}



int main(void)
{
 FACTORIAL(10);
 printf("counter=%d\n",counter);
 system("pause");
 return 0;
}
