

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

#define ROW 3
#define COL 3


//初始化棋盘
void initboard(char board[ROW][COL],int row,int col);
//打印棋盘
void displayboard(char board[ROW][COL],int row,int col);

//玩家下棋
void playermove(char board[ROW][COL],int row,int col);
//电脑下棋
void computermove(char board[ROW][COL],int row,int col);
//判断输赢 玩家赢，电脑赢，平局，继续游戏 不同结局返回不同字符，所以是char类型的函数
char iswin(char board[ROW][COL],int row,int col);

int find_two_in_line(char board[ROW][COL], int row, int col, char ch, int *x, int *y);
