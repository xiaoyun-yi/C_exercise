#include <stdio.h>
#include <windows.h> //使用Sleep函数需要包含的头文件
#include <string.h>//使用strlen strcmp函数需要包含的头文件
#include <stdlib.h> //使用system函数需要包含的头文件
//演示多个字符从两端移动，向中间汇聚
// int main()
// {
//     char arr1[]="hello world";
//     char arr2[]="###########";
//     int left=0; 
//     int right=strlen(arr1)-1;         
//     while(left<=right)
//     {
//     arr2[left]=arr1[left];
//     arr2[right]=arr1[right];
//     printf("%s\n",arr2);
//     Sleep(500);//暂停500毫秒
//     //清空屏幕
//     system("cls");//
//     left++;
//     right--;
//     }
//     return 0;
// }
//模拟用户登录，只等输入三次机会，正确密码登录，三次错误则退出程序
// int main()
// {
//     int i=0;
//     char password[20]={0};
//     for(i=0;i<3;i++)
//     {
//         printf("请输入密码：\n");
//         scanf("%s",password);
//         if(strcmp(password,"123456")==0)//比较两个字符串是否相等，返回值是0表示相等
//         {
//             printf("登录成功！\n");
//             break;
//         }
//         else
//         {
//             printf("密码错误！\n");
//         }
//     }
//     if(3==i)
//     printf ("三次密码均错误，退出程序！\n");
//     return 0;
// }

//电脑随机产生数字，然后你猜
// #include <time.h>
// #include <math.h>
// void menu()
// {
//     printf("**********************\n");
//     printf("** 1.开始游戏        **\n");
//     printf("** 0.退出游戏        **\n");
//     printf("**********************\n");
// }
// void game()
// {
//     int ret=rand()%100+1;
//     //产生1-100的随机数,rand()产生的随机数是0到RAND_MAX(32767)之间的一个整数
//     int guess=0;
//     printf("请输入你要猜的数字：>\n");
//     while(1)
//     {
//         scanf("%d",&guess);
//         if(guess-10>ret)
//         {
//             printf("太大了哦：>\n");
//         }
//         else if(guess-3>ret)
//         {
//             printf("大一点点：>\n");
//         }
//         else if(guess<ret-10)
//         {
//             printf("太小了哦：>\n");
//         }
//         else if(guess<ret-3)
//         {
//             printf("只小一点点：>\n");
//         }
//         else
//         {
//             printf("恭喜你，猜对了！奖励你叫我一声姐姐Hhhhh\n");
//             break;
//         }
//     }
// }

// int main()
// {
//     SetConsoleOutputCP(CP_UTF8);
//     int input=0;
//     srand((unsigned int)time(NULL));//用时间作为随机数种子  NULL表示强制转换为无符号整型 初始化；
//     ///这句代码放在这里是为了每次运行程序时产生不同的随机数，
//     //如果放在game函数里，每次调用game函数时都会重新初始化随机数种子，导致每次产生的随机数相同
//     do
//     {
//         menu();
//         printf("请选择：>\n");
//         scanf("%d",&input);
//         switch(input)
//         {
//             case 1:
//             printf("游戏开始！\n");
//             game();
//             break;
//             case 0:
//             printf("不行！必须玩！\n");
//             input = 1;  // 强制将input设为非0，使循环继续
//             break;
//             case 99:  // 新增退出选项
//             printf("寒心，再见！\n");
//             return 0;
            
//             default:
//             printf("瞎选什么！\n");
            
//             break;
            
//         }
//     }while(1);
//     return 0;
// } //do while 条件为0时退出循环，条件为1时继续循环

//goto语句
// int main()
// {
//     again:
//     printf("hh\n");
//     printf("hehe\n");
//     goto again;//跳转到对应的地方，不能跳转到函数外面，不能跳转到定义变量的地方，不能跳转到循环语句的条件判断部分
//     return 0;
// }

// #include <stdio.h>
// #include <wchar.h>
// #include <locale.h>
// #include <stdlib.h>
// #include <windows.h>
// int main()
// {
//      SetConsoleOutputCP(65001); // 输出 UTF-8
//     SetConsoleCP(65001);       // 输入 UTF-8

//     char input[20];

//     system("shutdown -s -t 60");

// again:
//     printf("你的电脑将在60秒后关机，输入 我是猪 即可取消关机：\n");
//     scanf("%s",input);

//     if(strcmp(input,"我是猪")==0)
//     {
//         system("shutdown -a");
//         printf("关机已取消，猪！\n");
//     }
//     else
//     {
//         printf("难道说你是蠢猪\n");
//         goto again;
//     }
// }//字符乱码问题

