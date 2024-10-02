#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

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
     printf("���|�w��!");
     exit(1);
   }
   stack[++(*top)]=token_operator;
}

TokenType pop(int *top)
{
  if(*top==-1)
  {
     printf("���|�w��!");
     exit(1);
  }
  return stack[(*top)--];
}

int main(void)
{

  printf("�п�J���Ǫ�ܪk,�����r����@:");
  scanf("%s",expr);
  printf("��Ǫ�ܪk��:");
  TransToPostfix();

  system("pause");
  return 0;
}
