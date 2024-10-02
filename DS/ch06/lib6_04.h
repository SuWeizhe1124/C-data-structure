#define MaxStackSize 100
#define MaxExprSize 100

typedef enum {LPAREN,RPAREN,PLUS,MINUS,TIMES,DIVIDE,EOE,OPERAND} TokenType;
TokenType stack[MaxStackSize];
char expr[MaxExprSize];
int isp[]={0,19,12,12,13,13,0};
int icp[]={20,19,12,12,13,13,0};

TokenType GetOneToken(char *,int *);
void PrintTokenOperator(TokenType);
void push(int *,TokenType);
TokenType pop(int *);

void TransToPostfix(void)
{
  char symbol;
  TokenType token;
  int top=0;
  int c=0;

  stack[0]=EOE;

  token=GetOneToken(&symbol,&c);
  while(token!=EOE)
  {
    if(token==OPERAND)      /* 遇到一般變數符號  */
      printf("%c",symbol);
    else
      if(token==RPAREN)    /* 遇到 ) */
      {
        while(stack[top]!=LPAREN)
            PrintTokenOperator(pop(&top));
        pop(&top);  /* 將(pop出來,但不印出 */
      }
      else                /* 遇到非)的任何運算子 */
      {
        while(isp[stack[top]]>=icp[token])
            PrintTokenOperator(pop(&top));  /* 取出優先權較高的運算子並印出 */
        push(&top,token);                   /* 疊入運算子  */
      }
    token=GetOneToken(&symbol,&c);
  }

  while((token=pop(&top))!=EOE)
     PrintTokenOperator(token);
}
