
#include "game2.h"


void menu()
{
    printf("~~~~~~~~~~~~~~~~~~\n");
    printf("~~~~~ 1.play ~~~~~\n");
    printf("~~~~~ 0.exit ~~~~~\n");
    printf("~~~~~~~~~~~~~~~~~~\n");
}




void game2()
{
    char mine[ROWS][COLS] = {0};//雷盘 存放布置好的雷的信息  
    char show[ROWS][COLS] = {0};//显示盘  存放玩家看到的盘面信息
    char flag[ROWS][COLS] = {0};  // 0表示未标记，1表示标记
    //初始化数组内容为指定内容
    //mine 在没有雷的时候用0表示，在有雷的时候用1表示
    //show 在没有被玩家踩过的格子用*表示，在被玩家踩
    initboard(mine,ROWS,COLS,'0');
    initboard(show,ROWS,COLS,'*');

   
    //设置雷
    set(mine,ROW,COL);
    //displayboard(mine,ROW,COL);

    displayboard(show,flag,ROW,COL);
    //玩家踩雷
    find(mine,show,flag,ROW,COL);
    //标记雷
   

}








int main()
{
    int input = 0;
    char str[20] = {0};
    
    srand((unsigned int)time(NULL)); // 只需调用一次，放在main函数开头即可
    do
    {
        printf("新推出扫雷游戏，玩不玩捏^-^\n");
        menu();
        
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                printf("正在进入游戏界面...\n");
                Sleep(1000); //1秒后进入游戏界面
                game2();
                break;
            case 0:
                printf("不玩的话，让你的电脑关机吧，你有30s的时间考虑一下\n");
                printf("输入 我是猪 即可取消关机：\n");
                system("shutdown -s -t 30");
                while (1) 
                {
                    
                    scanf("%19s", str);
                    if (strcmp(str, "我是猪") == 0) 
                        {
                        system("shutdown -a");
                        printf("关机已取消，猪啸啸，哈哈哈！\n");
                        break; // 跳出循环，回到主菜单
                        } 
                        else
                        {
                            printf("输入错误，再试试吧（或者等30秒后关机）\n");
                    // 不清除缓冲区？scanf会跳过空白，但如果有多个单词只读第一个，这里简单处理
                        }
                }
                break;
            default:
            printf("不要乱输入，臭狗屎！\n");
            break;
        }
        
        
        /* code */
    } while (1);

    return 0;
    
}