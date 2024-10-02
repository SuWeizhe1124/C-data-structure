#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */


enum BoolAlgebra {Zero,One};  /*�C�|���A,Zero��0,One��1*/

enum BoolAlgebra SetOne()
{
 return One;
}

bool IsOne(enum BoolAlgebra x)
{
 if(x==One)
   return true;
 return false;
}


bool IsEqual(enum BoolAlgebra x,enum BoolAlgebra y)
{
 if(x==y) 
    return true;
 return false;
}

enum BoolAlgebra  NOT(enum BoolAlgebra x)
{
 if(x==One)
    return Zero;
 return One;
}

enum BoolAlgebra AND(enum BoolAlgebra x,enum BoolAlgebra y)
{
 if(x==One)
    if (y==One)
        return One;
 return Zero;
}

enum BoolAlgebra OR(enum BoolAlgebra x,enum BoolAlgebra y)
{
 if(x==Zero)
   if (y==Zero)
       return Zero;
 return One;
}

int main(void)
{
  enum BoolAlgebra a,b;

  a=SetOne();                         /*  a�]��1  */
  b=NOT(SetOne());                    /*  b�]��0  */

  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("(a AND b)=%d\n",AND(a,b));
  printf("(a OR  b)=%d\n",OR(a,b));

  switch(IsOne(b))
  {
    case true:
         printf("b�O�_��1 ==>True\n");
         break;
    case false:
         printf("b�O�_��1 ==>False\n");
         break;
  }

  /* system("pause"); */
  return 0;
}
