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
    if(token==OPERAND)      /* �J��@���ܼƲŸ�  */
      printf("%c",symbol);
    else
      if(token==RPAREN)    /* �J�� ) */
      {
        while(stack[top]!=LPAREN)
            PrintTokenOperator(pop(&top));
        pop(&top);  /* �N(pop�X��,�����L�X */
      }
      else                /* �J��D)������B��l */
      {
        while(isp[stack[top]]>=icp[token])
            PrintTokenOperator(pop(&top));  /* ���X�u���v�������B��l�æL�X */
        push(&top,token);                   /* �|�J�B��l  */
      }
    token=GetOneToken(&symbol,&c);
  }

  while((token=pop(&top))!=EOE)
     PrintTokenOperator(token);
}
