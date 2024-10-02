#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>           /* 記錄 bool列舉值 */

#define MaxStackSize 64
#define ExitX 6
#define ExitY 6                /* 出口座標 */

typedef struct{
   int x;          /* x.y為目前座標 */
   int y;
   int direction; /*代表目前朝向哪一方,0上 1 右 2下 3左*/
}Position;
Position stack[MaxStackSize];

typedef struct{
   int Horizontal;  /* 水平移動量 */
   int Vertical;    /* 垂直移動量 */
}Offset;
Offset move[4];  /* 每個方向的水平移動與垂直移動量 */

int maze[8][8]={{1,1,1,1,1,1,1,1},
                {1,0,1,0,0,0,1,1},
                {1,0,1,0,1,0,1,1},
                {1,0,0,0,1,0,1,1},
                {1,0,1,1,0,0,0,1},
                {1,1,1,1,0,1,0,1},
                {1,0,1,0,0,1,0,1},
                {1,1,1,1,1,1,1,1}};

int Mark[8][8]={0};  /* 每個座標是否走過,初始為全未走過 */

void push(int *top, Position NewPos)
{
  if(*top>=MaxStackSize-1)
   {
     printf("堆疊已滿!");
     exit(1);
   }
   stack[++(*top)]=NewPos;
}

Position pop(int *top)
{
  if(*top==-1)
  {
     printf("堆疊已空!");
     exit(1);
  }
  return stack[(*top)--];
}

void PrintPath(int top)
{
  int i;
  printf("入口-");
  for(i=0;i<=top;i++)
    printf("(%d,%d)-",stack[i].x,stack[i].y);
  printf("已達出口!\n");
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
      if(pathpoint(i,j,top)==true)   printf("★");
      else
        if(maze[i][j]==1)   printf("■");
        else                printf("  ");
    }
    printf("\n");
  }
}

void FindPath(void)
{
 bool goal;    /* 用來分辨是否已達出口  */
 int top=0,x,y,direction,nextX,nextY;
 Position NowPos;

 stack[0].x=1;  stack[0].y=1;  /* 初始座標 */
 stack[0].direction=1;
 Mark[1][1]=1;  /* 設定為走過 */
 goal=false;

 while(top >-1 && goal!=true)
 {
    NowPos=pop(&top);
    x=NowPos.x;  y=NowPos.y;  direction=NowPos.direction;

    while(direction < 4)     /* 最多測試四個方向 */
    {
      nextX=x+move[direction].Horizontal;
      nextY=y+move[direction].Vertical;
      if (nextX==ExitX && nextY==ExitY)
      {
        goal=true;
        NowPos.x=x; NowPos.y=y;
        NowPos.direction=direction;
        push(&top,NowPos);     /* push 出口前一個的位置 */
        NowPos.x=nextX; NowPos.y=nextY;
        push(&top,NowPos);     /* push 出口 */
        break;
      }
      else
      if (maze[nextX][nextY]!=1 && Mark[nextX][nextY]!=1)
      { /* 若非圍牆且未走過 */
        /* 移動且轉向 */
        NowPos.x=x; NowPos.y=y;
        direction++;
        NowPos.direction=direction;
        push(&top,NowPos);
        x=nextX; y=nextY; direction=0;
        Mark[nextX][nextY]=1;
      }
      else
        direction++;    /* 僅轉向 */
    }
 }
 /**************************************************/
 if(goal == true)
 {
   PrintPath(top);
   PrintPathGraph(top);
 }
 else
   printf("本迷宮無任何通路可達出口!\n");
}

int main(void)
{
  move[0].Horizontal=0;  move[0].Vertical=-1;  /* 向上 */
  move[1].Horizontal=1;  move[1].Vertical=0;   /* 向右 */
  move[2].Horizontal=0;  move[2].Vertical=1;   /* 向下 */
  move[3].Horizontal=-1; move[3].Vertical=0;   /* 向左 */

  FindPath();
  system("pause");
  return 0;
}
