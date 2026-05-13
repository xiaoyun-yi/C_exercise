#include <iostream>
using namespace std;


#define PI 3.14159//#define 宏常量： 不可以在main内部随意修改
//const double X = 7;//const 常量： 也不可以修改， 但是可以在main内部定义
// int main()
// {
//     cout << "Hello World!" << endl;
//     int a = 10;
//     cout << " a = " << a << endl;
//     cout << "一周共有： " << X <<"天"<< endl;
// /*多行注释

//  */

//     system("pause");
//     return 0;
// }


//关键字
//标识符 字母、数字、下划线组成，
//不能以数字开头，不能使用关键字，不能使用空格
//区分大小写
//数据类型：整型：short 2个字节 ,int四个字节, long4个字节, long long八个字节
//取值范围不同：short -32768~32767, int -2^31~2^31-1, long -2^31~2^31-1, long long -2^63~2^63-1
//字符型：char 1个字节
//浮点型：float 4个字节, double 8个字节
//有效数字范围：float 6~7位， double 15~16位 一般显示6位
//float f1 = 3.14f; //float类型的常量需要加f
//float f2 = 3e2; //科学计数法，3*10^2,3e-2 3*10^-2
//sizeof()函数：返回数据类型的字节数
//sizeof(数据类型或者变量)
//
//字符型：char c1 = 'a'; //单引号，字符常量
//创建字符型变量，要用单引号，单引号内只能有一个字符
//char c2 = 97; //字符型变量可以存储一个整数，
//存储的整数会被当做ASCII码值，97对应字符'a'

// 转义字符  \n 换行 \t 水平制表符占用位置取决于前面有几个字符，反正总共占用八个字符 
//\r 回车  \b 退格  \f 换页  \\输出一个反斜杠
// int main()
// {
//     cout << "aaa\tbbb" << endl;
//     cout << "aa\tbbb" << endl;
//     cout << "a\tbbb" << endl;
//     // \t 整齐地输出数据
//     system("pause");
//     return 0;
// }

//字符串类型
//两种风格 第一 C语言  char str1[] = "hello world"; //字符串常量，自动在末尾添加一个'\0'字符，表示字符串结束
//第二 C++风格 string str2 = "hello world"; //string是C++
//用C++风格的字符串需要包含头文件#include <string>

//布尔类型 bool 1字节 只能存储true和false
//布尔类型的值在内存中是以整数形式存储的，true
//在内存中存储为1，false在内存中存储为0
//布尔类型的变量可以参与逻辑运算，结果也是布尔类型 

//数据的输入
//使用cin对象和>>运算符
// int main()
// {
//     int a;
//     cout << "请输入一个整数：" << endl;
//     cin >> a;
//     cout << "您输入的整数是：" << a << endl;
//     system("pause");
//     return 0;
// }

//加减乘除，
//取余只能适用于整数，结果是整数
//除法：整数除以整数结果是整数，浮点数除以浮点数结果是浮点数，整数除以浮点数结果是浮点数
//自增自减：++a 先加1再使用，a++ 先使用再加1，--a 先减1再使用，a-- 先使用再减1
//关系运算符：> < >= <= == != 结果是布尔类型

//int a =10;
//int b = a++*10
//int c = ++a*10
//a++ 先使用a的值10乘以10得到100，然后a自增1变成11
//++a 先自增1变成12，然后使用a的值12乘以10得到120
//cout<<a==b<<endl; //输出false 因为a的值是12，b的值是100
//cout<<!a<<endl; //输出false 因为a的值是12，非0的整数在布尔上下文中被视为true，!true等于false
//cout<<!0<<endl; //输出true 因为0在布尔上下文中被视为false，!false等于true

//if语句
// if(条件表达式)
// {}
// int main()
// {
//     int score;
//     cout << "请输入一个成绩：" << endl;
//     cin >> score;
//     cout << "您输入的成绩是：" << score << endl;
//     if(score >= 90)
//     {
//         cout << "成绩优秀！" << endl;
//     }
//     else if(score >= 60)
//     {
//         cout << "成绩及格！" << endl;
//     }
//     else
//     {
//         cout << "成绩不及格！" << endl;
//     }
//     system("pause");
//     return 0;
// }

// int main()
// {
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     cout <<"请输入三个整数：" << endl;
//     cin >> a >> b >> c;
//     cout << "您输入的三个整数是：" << a << " " << b << " " << c << endl;
//         if(a >= b && a >= c)
//         {
//             cout << "最大的数是：" << a << endl;
//         }
//         else if(b >= a && b >= c)
//         {
//             cout << "最大的数是：" << b << endl;
//         }
//         else
//         {
//             cout << "最大的数是：" << c << endl;
//         }

//     system("pause");
//     return 0;
// }

//三目运算符
//条件表达式 ? 表达式1 : 表达式2
//c=a>b?a:b; //如果a>b条件成立，c的值是a，否则c的值是b
//(a>b?a:b)=100  
// int main()
// {
//     int a = 10;
//     int b = 20;
//     int c = a > b ? a : b; //如果a>b条件成立，c的值是a，否则c的值是b
//     (a > b ? a : b) = 100; //将较大的数赋值为100 三木操作符返回的是变量，可以接着赋值
//     cout << "较大的数是：" << c << endl;
//     cout << b << endl; //输出100
//     system("pause");
//     return 0;
// }

//switch语句
//switch(表达式)
//{
//case 常量1:   
//    break;
//case 常量2:
//    break;
//default:
//    break;
//}

//while循环
//while(条件表达式)
//{
//循环体
//}

#include<ctime>
//又又又又猜数字
// int main()
// {
//     srand((unsigned int)time(NULL)); //设置随机数种子，保证每次运行程序生成的随机数不同
//     int num = rand()%100+1; //生成1~100的随机数
     

//     int guess = 0;
//     while(guess != num)
//     {
//         cout << "请输入一个1~100的整数：" << endl;
//         cin >> guess;
//         if(guess > num)
//         {
//             cout << "猜大了！" << endl;
//         }
//         else if(guess < num)
//         {
//             cout << "猜小了！" << endl;
//         }
//         else
//         {
//             cout << "恭喜你，猜对了！" << endl;
//             break;
//         }
//     }
//     system("pause");
//     return 0;
// }


//do while循环
//do
//{
//循环体
//}while(条件表达式); 至少执行一次循环体

//找出三位数中的水仙花数

// int main()
// {
//     for(int i = 100; i <= 999; i++)
//     {
//         int a = i / 100; //百位
//         int b = (i / 10) % 10; //十位
//         int c = i % 10; //个位
//         if(i == a*a*a + b*b*b + c*c*c)
//         {
//             cout << i << "是一个水仙花数！" << endl;
//         }
//     }


//     system("pause");
//     return 0;
// }

//用do while循环查找水仙花数

// int main()
// {
//     int i = 100;

//     do
//     {
//         int a = i / 100; //百位
//         int b = (i / 10) % 10; //十位
//         int c = i % 10; //个位
//         if(i == a*a*a + b*b*b + c*c*c)
//         {
//             cout << i << "是一个水仙花数！" << endl;
//         }
//         ++i;
//     } while (i < 1000);
    



//     system("pause");
//     return 0;
// }

//for 循环
//for(初始化表达式; 条件表达式; 更新表达式)
//{循环体}

//从1开始，如果数字个位或者十位含有7，或者数字能被7整除，就输出这个数字
// int main()
// {
//     for(int i = 1; i <= 100; i++)
//     {
//         if(i % 7 == 0 || i % 10 == 7 || (i / 10) % 10 == 7)
//         {
//             cout << "o" <<endl;
//         }
//         else
//         {
//             cout << 1<< endl;
//         }
//     }
//     cout << endl;

//     system("pause");
//     return 0;
// }

//输出九九乘法表
// int main()
// {
//     for(int i = 1; i <= 9; i++)
//     {
//         for(int j = 1; j <= i; j++)
//         {
//             cout << j << " * " << i << " = " << i*j << "\t";//  /t 用于对齐
//         }
//         cout << endl;//endl 是换行的意思
//     }

//     system("pause");
//     return 0;
// }


//continue 语句：跳过本次循环剩余的代码，直接进入下一次循环
//break 语句：跳出整个循环