#include "game.h"



void initboard(char board[ROW][COL],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            board[i][j]=' ';//初始化棋盘为全空格
        }
    }
}

void displayboard(char board[ROW][COL],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf(" %c ",board[i][j]);//打印棋盘的每一个格子
            if(j<col-1)//如果不是最后一列，打印竖线分隔符
            {
                printf("|");
            }
        }
        printf("\n");//换行
        if(i<row-1)//如果不是最后一行，打印横线分隔符
        {
            for(int j=0;j<col;j++)
            {
                printf("---");//打印横线分隔符
                if(j<col-1)//如果不是最后一列，打印加号分隔符
                {
                    printf("+");
                }
            }
            printf("\n");//换行
        }
    }
}


void playermove(char board[ROW][COL],int row,int col)
{
    int x=0,y=0;
    printf("请输入下棋的坐标（行 列）：");
    scanf("%d%d",&x,&y);
    //判断输入是否合法
    if(x>=1&&x<=row&&y>=1&&y<=col)
    {
        if(board[x-1][y-1]==' ')//判断该位置是否为空格
        {
            board[x-1][y-1]='X';//玩家下棋用X表示
        }
        else
        {
            printf("不要企图篡改棋子位置！\n");
            playermove(board,row,col);//递归调用，重新输入
        }
    }
    else
    {
        printf("不要瞎输入，臭狗屎！\n");
        playermove(board,row,col);//递归调用，重新输入
    }
}


// void computermove(char board[ROW][COL],int row,int col)
// {
//     int x=0,y=0;
//     printf("哈基咪正在思考...\n");

//     do
//     {
//         x=rand()%row;//生成0到row-1之间的随机数作为行坐标
//         y=rand()%col;//生成0到col-1之间的随机数作为列坐标
//     }while(board[x][y]!=' ');//如果该位置不是空格，继续生成随机数
//     board[x][y]='s';//电脑下棋用O表示
// }



// 检查玩家 ch（'s' 或 'X'）是否有两子一线且第三格为空，若有则通过指针返回该空位坐标，返回 1；否则返回 0
// int find_two_in_line(char board[ROW][COL], int row, int col, char ch, int *x, int *y)
// {
//     // 检查所有行
    
//     for (int i = 0; i < row; i++) {
//         int count = 0, empty_j = -1;
//         for (int j = 0; j < col; j++) {
//             if (board[i][j] == ch) count++;
//             else if (board[i][j] == ' ') empty_j = j;
//         }
//         if (count == 2 && empty_j != -1) {
//             *x = i;
//             *y = empty_j;
//             return 1;
//         }
//     }

//     // 检查所有列
//     for (int j = 0; j < col; j++) {
//         int count = 0, empty_i = -1;
//         for (int i = 0; i < row; i++) {
//             if (board[i][j] == ch) count++;
//             else if (board[i][j] == ' ') empty_i = i;
//         }
//         if (count == 2 && empty_i != -1) {
//             *x = empty_i;
//             *y = j;
//             return 1;
//         }
//     }

//     // 检查主对角线（左上到右下）
//     int count = 0, empty_i = -1, empty_j = -1;
//     for (int i = 0; i < row; i++) {
//         if (board[i][i] == ch) count++;
//         else if (board[i][i] == ' ') {
//             empty_i = i;
//             empty_j = i;
//         }
//     }
//     if (count == 2 && empty_i != -1) {
//         *x = empty_i;
//         *y = empty_j;
//         return 1;
//     }

//     // 检查副对角线（右上到左下）
//     count = 0;
//     empty_i = -1; empty_j = -1;
//     for (int i = 0; i < row; i++) {
//         if (board[i][row - 1 - i] == ch) count++;
//         else if (board[i][row - 1 - i] == ' ') {
//             empty_i = i;
//             empty_j = row - 1 - i;
//         }
//     }
//     if (count == 2 && empty_i != -1) {
//         *x = empty_i;
//         *y = empty_j;
//         return 1;
//     }

//     return 0;
// }

// void computermove(char board[ROW][COL], int row, int col)
// {
//     int x = 0, y = 0;
//     printf("哈基咪正在思考...\n");

//     // 1. 进攻：电脑能否直接获胜
//     if (find_two_in_line(board, row, col, 's', &x, &y)) {
//         board[x][y] = 's';
//         return;
//     }

//     // 2. 防守：堵住玩家即将获胜的位置
//     if (find_two_in_line(board, row, col, 'X', &x, &y)) {
//         board[x][y] = 's';
//         return;
//     }

//     // 3. 优先中心
//     if (board[1][1] == ' ') {
//         board[1][1] = 's';
//         return;
//     }

//     // 4. 优先角落
//     int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
//     for (int k = 0; k < 4; k++) {
//         int i = corners[k][0], j = corners[k][1];
//         if (board[i][j] == ' ') {
//             board[i][j] = 's';
//             return;
//         }
//     }

//     // 5. 再选边
//     int edges[4][2] = {{0,1}, {1,0}, {1,2}, {2,1}};
//     for (int k = 0; k < 4; k++) {
//         int i = edges[k][0], j = edges[k][1];
//         if (board[i][j] == ' ') {
//             board[i][j] = 's';
//             return;
//         }
//     }

//     // 6. 保底随机（理论上不会执行到这里，因为棋盘满时会先判平局）
//     do {
//         x = rand() % row;
//         y = rand() % col;
//     } while (board[x][y] != ' ');
//     board[x][y] = 's';
// }




//棋盘满了返回1，不满返回0
int isfull(char board[ROW][COL],int row,int col)
{
    int i=0;
    int j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if (board[i][j]==' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

//o玩家 miao哈基米 c继续  ！平局
char iswin(char board[ROW][COL],int row,int col)
{
//行
    int i=0;
    for(i=0;i<row;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' ')
        {
            return board[i][0];
        }
    }
//列
int j=0;
    for(j=0;j<col;j++)
    {
        if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[1][j]!=' ')
        {
            return board[1][j];
        }
    }
//对角线
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
    {
        return board[1][1];
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[1][1]!=' ')
    {
        return board[1][1];
    }
    //平局
    if(isfull(board,row,col))
    {
        return '!';
    }
    return 'c';
}


int evaluate(char board[ROW][COL]) {
    char result = iswin(board, ROW, COL);
    if (result == 's') return 10;   // 电脑赢
    if (result == 'X') return -10;  // 玩家赢
    return 0;                       // 平局或未结束（未结束会在递归中继续）
}


// isMax: true 表示当前是电脑回合（最大化），false 表示玩家回合（最小化）
int minimax(char board[ROW][COL], int depth, int isMax) {
    int score = evaluate(board);
    
    // 如果游戏已经结束，直接返回分数（depth 用于区分胜负早晚，但此处暂不考虑深度）
    if (score == 10 || score == -10) return score;
    // 如果棋盘满了且没有赢家，平局
    if (isfull(board, ROW, COL)) return 0;

    if (isMax) {
        // 电脑回合：选择最大值
        int best = -1000;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == ' ') 
                {
                    board[i][j] = 's';
                    best = max(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        // 玩家回合：选择最小值
        int best = 1000;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    best = min(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}


void computermove(char board[ROW][COL], int row, int col) {
    printf("哈基咪正在思考...\n");
    int bestX = -1, bestY = -1;
    int bestScore = -1000;  // 电脑要最大化分数

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] == ' ') {
                // 尝试在此落子
                board[i][j] = 's';
                int moveScore = minimax(board, 0, 0); // 下一步是玩家回合（isMax=0）
                board[i][j] = ' ';

                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestX = i;
                    bestY = j;
                }
            }
        }
    }
    // 下子在最佳位置
    board[bestX][bestY] = 's';
}