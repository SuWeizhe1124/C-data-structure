#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#include "lib5_04.h"


void printPoly(P_Node_P p)
{
  while (p!=NULL)
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

void ErasePoly(P_Node_P p)
{
  P_Node_P freeone;
  while(p!=NULL)
  {
    freeone=p;
    p=p->link;
    free(freeone);
  }
}

int main(void)
{
  P_Node_P F,F_front,F_rear,G,G_front,G_rear,H;

  /***************建立F*************************/
  F_rear=(P_Node_P) malloc(sizeof(P_Node));
  if (F_rear==NULL)  {  printf("記憶體不足!");  exit(1);  }
  F_front=F_rear;
  Attach(&F_rear,5,1000);
  Attach(&F_rear,7,387);
  Attach(&F_rear,10,0);
  F=F_front->link;
  free(F_front);
  printf("F(x)=");  printPoly(F);  /*列印F(x)*/

  /***************建立G*************************/
  G_rear=(P_Node_P) malloc(sizeof(P_Node));
  if (G_rear==NULL)  {  printf("記憶體不足!");  exit(1);  }
  G_front=G_rear;
  Attach(&G_rear,10,400);
  Attach(&G_rear,6,387);
  Attach(&G_rear,3,2);
  Attach(&G_rear,1,0);
  G=G_front->link;
  free(G_front);
  printf("G(x)=");  printPoly(G); /*列印G(x)*/

  H=PolyAdd(F,G);   /* H(x)=F(x)+G(x) */
  printf("H(x)=");  printPoly(H); /*列印H*/

  ErasePoly(F);
  ErasePoly(G);
  ErasePoly(H);
  system("pause");
  return 0;
}
