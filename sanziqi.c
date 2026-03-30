
#include "game.h"

void menu()
{
    printf("****************************\n");
    printf("******1.start   0.exit******\n");
    printf("****************************\n");
}



void game()
{
    printf("游戏开始！\n");
    char ret=0;
    
    char board[ROW][COL]={0};
    //初始化棋盘
    initboard(board,ROW,COL);
    //打印棋盘
    displayboard(board,ROW,COL);
    //下棋
    while(1)
    {
    playermove(board,ROW,COL);
    //判断输赢
    ret=iswin(board,ROW,COL);
    if(ret!='c')
    {
        break;
    }

    displayboard(board,ROW,COL);
    
    computermove(board,ROW,COL);
    //判断输赢
    ret=iswin(board,ROW,COL);
    if(ret!='c')
    {
        break;
    }
    displayboard(board,ROW,COL);
    //判断输赢，修改电脑能不能赢的函数
     
    }
    if(ret=='X')
    {
        printf("你竟然赢了！哈基米不服，再来一局！！！\n");
    }
    else if(ret=='s')
    {
        printf("拜倒在哈基米的石榴裙下吧哈哈哈哈哈\n");
    }
    else 
    {
        printf("赢不了了吧哈哈哈哈\n");
    }
    displayboard(board,ROW,COL);
}




int main()
{
    srand((unsigned int)(time(NULL)));//设置随机数种子
    int input=0;
  
    do
    {
        menu();
        printf("请选择：");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
            printf("三子棋\n");
            game();
            break;
            case 0:
            printf("不可以不玩！\n");
            break;
            default:
            printf("不要瞎选！\n");
        }
    }while(1);//条件为0时退出循环，条件为1时继续循环
    return 0;
}