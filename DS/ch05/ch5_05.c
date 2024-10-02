#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#include "lib5_05.h"

void printPoly(P_Node_P p)
{
  p=p->link;
  while (p->expont!=-1)
  {
      if(p->expont!=0)
      {
        printf("%.0fx^%d",p->coef,p->expont);
        printf("+");
      }
      else
        printf("%.0f",p->coef);
      p=p->link;
  }
  printf("\n");
}

int main(void)
{
  P_Node_P F,F_last,G,G_last,H;

  avail=NULL;

  /***************建立F*************************/
  F=GetNode();
  F->expont=-1;
  F->link=F;
  F_last=F;

  CircularListPolyAttach(&F_last,5,1000);
  CircularListPolyAttach(&F_last,7,387);
  CircularListPolyAttach(&F_last,10,0);

  printf("F(x)=");  printPoly(F);  /*列印F(x)*/

  /***************建立G*************************/
  G=GetNode();
  G->expont=-1;
  G->link=G;
  G_last=G;
  CircularListPolyAttach(&G_last,10,400);
  CircularListPolyAttach(&G_last,6,387);
  CircularListPolyAttach(&G_last,3,2);
  CircularListPolyAttach(&G_last,1,0);

  printf("G(x)=");  printPoly(G); /*列印G(x)*/

  H=CircularListPolyAdd(F,G);   /* H(x)=F(x)+G(x) */
  printf("H(x)=");  printPoly(H); /*列印H*/

  NewCircularListErase(&F);
  NewCircularListErase(&G);
  NewCircularListErase(&H);

  system("pause");
  return 0;
}
