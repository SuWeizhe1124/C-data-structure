#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#include "lib6_04.h"

TokenType GetOneToken(char *symbol,int *c)
{
  *symbol=expr[*c];
  (*c)++;
  switch (*symbol)
  {
    case '(': return LPAREN;
    case ')': return RPAREN;
    case '+': return PLUS;
    case '-': return MINUS;
    case '*': return TIMES;
    case '/': return DIVIDE;
    case '@': return EOE;
    default: return OPERAND;
  }
}

void PrintTokenOperator(TokenType token_operator)
{
  switch (token_operator)
  {
    case PLUS:    printf("+");  break;
    case MINUS:   printf("-");  break;
    case TIMES:   printf("*");  break;
    case DIVIDE:  printf("/");  break;
    default: break;
  }
}

void push(int *top,TokenType token_operator)
{
   if(*top>=MaxStackSize-1)
   {
     printf("堆疊已滿!");
     exit(1);
   }
   stack[++(*top)]=token_operator;
}

TokenType pop(int *top)
{
  if(*top==-1)
  {
     printf("堆疊已空!");
     exit(1);
  }
  return stack[(*top)--];
}

int main(void)
{

  printf("請輸入中序表示法,結尾字元為@:");
  scanf("%s",expr);
  printf("後序表示法為:");
  TransToPostfix();

  system("pause");
  return 0;
}
