#include "game2.h"







void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i=0;
    int j=0;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            board[i][j] = set;
        }
    }
}

void displayboard(char board[ROWS][COLS], char flag[ROWS][COLS], int rows, int cols)
{
    int i=0;
    int j=0;
    printf("------------- game --------------\n");
    for(j=0;j<=cols;j++)
    {
        printf("%d ",j);
    }
    printf("\n");

    for(i=1;i<=rows;i++)
    {
        printf("%d ",i);
        for(j=1;j<=cols;j++)
        {
            if (flag[i][j] == 1)
                printf("F ");  // 标记显示为 F
            else
                printf("%c ", board[i][j]);
        }
        printf("\n");
    }
      printf("---------------------------------\n");
}

void set(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while(count)
    {
        int x = rand()%row+1;
        int y = rand()%col+1;
        if(board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}


int get_mine(char board[ROWS][COLS], int x, int y)
{
    return board[x-1][y-1] + board[x-1][y] + board[x-1][y+1]
         + board[x][y-1]                 + board[x][y+1]
         + board[x+1][y-1] + board[x+1][y] + board[x+1][y+1] - 8*'0';
}



// 递归展开函数，返回展开的格子数
int expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)
{
    // 坐标越界或格子已打开，返回0
    if (x < 1 || x > row || y < 1 || y > col || show[x][y] != '*')
        return 0;

    // 计算周围雷数
    int count = get_mine(mine, x, y);
    // 设置当前格子为数字字符
    show[x][y] = count + '0';
    int expanded = 1;  // 当前格子计数

    // 如果周围无雷，递归展开周围八个格子
    if (count == 0)
    {
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i == 0 && j == 0) continue; // 跳过自身
                expanded += expand(mine, show, x + i, y + j, row, col);
            }
        }
    }
    return expanded;
}


void find(char mine[ROWS][COLS], char show[ROWS][COLS], char flag[ROWS][COLS], int row, int col) {
    int x = 0, y = 0;
    char cmd;
    int win = 0;
    while (win < row * col - EASY_COUNT) {
        printf("选择操作：s 踩格子，f 切换标记。格式：s x y 或 f x y\n");
        scanf(" %c %d %d", &cmd, &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            if (cmd == 'f') {  // 标记/取消标记
                if (show[x][y] != '*') {
                    printf("该位置已打开，不能标记！\n");
                } else {
                    flag[x][y] = !flag[x][y];  // 切换标记
                    displayboard(show, flag, row, col);
                }
            } else if (cmd == 's') {  // 踩格子
                if (show[x][y] != '*') {
                    printf("这个坐标已经踩过了，换一个吧！\n");
                } else {
                    if (mine[x][y] == '1') {  // 踩到雷
                        Sleep(2000);
                        printf("你被炸鼠了！\n");
                        printf("雷的位置是：\n");
                        displayboard(mine, flag, row, col);  // 显示雷盘，此时 flag 可能干扰，可传 NULL 或不显示标记
                        break;
                    } else {
                        int expanded = expand(mine, show, x, y, row, col);
                        win += expanded;
                        displayboard(show, flag, row, col);
                    }
                }
            } else {
                printf("无效命令！\n");
            }
        } else {
            printf("坐标越界，重新输入！\n");
        }
    }
    if (win == row * col - EASY_COUNT) {
        printf("^_^！竟然成功躲过了所有的雷！\n");
        displayboard(mine, flag, row, col);
    }
}


