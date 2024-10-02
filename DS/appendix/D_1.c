#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* �O�� bool�C�|�� */

#define MaxStackSize 64
#define ExitX 6
#define ExitY 6                /* �X�f�y�� */

typedef struct{
   int x;          /* x.y���ثe�y�� */
   int y;
   int direction; /*�N��ثe�¦V���@��,0�W 1 �k 2�U 3��*/
}Position;
Position stack[MaxStackSize];

typedef struct{
   int Horizontal;  /* �������ʶq */
   int Vertical;    /* �������ʶq */
}Offset;
Offset move[4];  /* �C�Ӥ�V���������ʻP�������ʶq */

int maze[8][8]={{1,1,1,1,1,1,1,1},
                {1,0,1,0,0,0,1,1},
                {1,0,1,0,1,0,1,1},
                {1,0,0,0,1,0,1,1},
                {1,0,1,1,0,0,0,1},
                {1,1,1,1,0,1,0,1},
                {1,0,1,0,0,1,0,1},
                {1,1,1,1,1,1,1,1}};

int Mark[8][8]={0};  /* �C�Ӯy�ЬO�_���L,��l���������L */

void push(int *top, Position NewPos)
{
  if(*top>=MaxStackSize-1)
   {
     printf("���|�w��!");
     exit(1);
   }
   stack[++(*top)]=NewPos;
}

Position pop(int *top)
{
  if(*top==-1)
  {
     printf("���|�w��!");
     exit(1);
  }
  return stack[(*top)--];
}

void PrintPath(int top)
{
  int i;
  printf("�J�f-");
  for(i=0;i<=top;i++)
    printf("(%d,%d)-",stack[i].x,stack[i].y);
  printf("�w�F�X�f!\n");
}

bool pathpoint(int i,int j,int top)
{
  int k;
  for(k=0;k<=top;k++)
   if(stack[k].x==i && stack[k].y==j)
     return true;
  return false;

}

void PrintPathGraph(int top)
{
  int i,j;
  for(i=0;i<=7;i++)
  {
    for(j=0;j<=7;j++)
    {
      if(pathpoint(i,j,top)==true)   printf("��");
      else
        if(maze[i][j]==1)   printf("��");
        else                printf("  ");
    }
    printf("\n");
  }
}

void FindPath(void)
{
 bool goal;    /* �ΨӤ���O�_�w�F�X�f  */
 int top=0,x,y,direction,nextX,nextY;
 Position NowPos;

 stack[0].x=1;  stack[0].y=1;  /* ��l�y�� */
 stack[0].direction=1;
 Mark[1][1]=1;  /* �]�w�����L */
 goal=false;

 while(top >-1 && goal!=true)
 {
    NowPos=pop(&top);
    x=NowPos.x;  y=NowPos.y;  direction=NowPos.direction;

    while(direction < 4)     /* �̦h���ե|�Ӥ�V */
    {
      nextX=x+move[direction].Horizontal;
      nextY=y+move[direction].Vertical;
      if (nextX==ExitX && nextY==ExitY)
      {
        goal=true;
        NowPos.x=x; NowPos.y=y;
        NowPos.direction=direction;
        push(&top,NowPos);     /* push �X�f�e�@�Ӫ���m */
        NowPos.x=nextX; NowPos.y=nextY;
        push(&top,NowPos);     /* push �X�f */
        break;
      }
      else
      if (maze[nextX][nextY]!=1 && Mark[nextX][nextY]!=1)
      { /* �Y�D����B�����L */
        /* ���ʥB��V */
        NowPos.x=x; NowPos.y=y;
        direction++;
        NowPos.direction=direction;
        push(&top,NowPos);
        x=nextX; y=nextY; direction=0;
        Mark[nextX][nextY]=1;
      }
      else
        direction++;    /* ����V */
    }
 }
 /**************************************************/
 if(goal == true)
 {
   PrintPath(top);
   PrintPathGraph(top);
 }
 else
   printf("���g�c�L����q���i�F�X�f!\n");
}

int main(void)
{
  move[0].Horizontal=0;  move[0].Vertical=-1;  /* �V�W */
  move[1].Horizontal=1;  move[1].Vertical=0;   /* �V�k */
  move[2].Horizontal=0;  move[2].Vertical=1;   /* �V�U */
  move[3].Horizontal=-1; move[3].Vertical=0;   /* �V�� */

  FindPath();
  system("pause");
  return 0;
}
