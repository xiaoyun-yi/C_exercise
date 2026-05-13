#include <stdio.h>

// int main()
// {
//     int num1=0;
//     int num2=0;
//     scanf("%d %d",&num1,&num2);//scanf 相当于输入函数
//     int sum=num1+num2;
//     printf("%d",sum);
//     return 0;
// }

//变量作用域，
//变量生命周期 变量作用的范围
// int main()
// {
//     {
//         int a=10;
//         printf("%d\n",a);
//     }

//     return 0;
// }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
// extern int a;//从另一个文件导入变量

// int main()
// {

//     return 0;
// }
// int main()
// {
//     int breakfast=0;
//     printf("吃早饭了吗？\n");
//     scanf("%d",&breakfast);
//     while(breakfast==1)
//     { 
//         printf("吃了啥\n");
//         break;
//     }
//     if(breakfast==0)
//     {
//         printf("快去吃早饭\n");
//     }
//     return 0;
// }

//定义函数
// int Chengfa(int a,int b)
// {
//     int c=0;
//     c=a*b*3;
//     return c;
// }
// int main()
// {
//     int n1=0;
//     int n2=0;
//     scanf("%d,%d",&n1,&n2);
//     int result=Chengfa(n1,n2);
//     printf("结果是%d\n",result);
//     return 0;
// }

//数组
// int main()
// {
//     int arr[10]={1,2,3,4,5,6,7,8,9,0};
//     printf("%d\n",arr[3]);
//     return 0;
// }
//打印小飞机

// #include <string.h>
// int main ()
// {
//     char arr[]={'q','w','w'};   
//     printf("%d\n",strlen(arr));
//     return 0;
// }


//求两个数的较大值
// int max(int a,int b)
// {
//     if (a>b)
//     return a;
//     else
//     return b;

// }
// int main ()
// {
//     int a=0;
//     int b=0;
//     scanf("%d %d",&a,&b);
//     int bigger=max(a,b);
//     printf("%d",bigger);
//     return 0;
// }


// int function(int x)
// {
//     if(x<0)
//     return 1;

//     else if(x==0)
//     return 0;

//     else if (x>0)
//     return -1;
// }

// int main()
// {
//    int a=0;
//    scanf("%d",&a);//表示可输入
//    printf("%d",function(a));
//     return 0;

// }


//a=a+3>>a+=3
// b=a++>>b=a;a=a+1
//c=++a>>a=a+1,c=a;--同理


// int main()
// {
//     int a=3.14;
//     printf("%d\n",a);
//     return 0;
// }

//三目操作符
//exp1?exp2:exp3   第一个表达式为真，则输出第二个表达式的结果，否则输出第三个表达式的结果
//逗号表达式，最后输出的是最后一个表达式的值


//常见关键字

//typedef 类型重命名 针对类型
// typedef unsigned int unit;//将unsigned int重命名为unit  将来使用unit代替unsigned int
// int main()
// {
//     unsigned int a=10;
//     unit b=20;

//     return 0;
// }

//ststic  修饰变量（局部和全局）和函数
//修饰局部变量时，局部变量不销毁，保持最后的值，改变了变量的存储位置，存储在静态区原来在栈区

// void test()  //void 没有返回值，不需要return 定义函数
// {
//     int a=1;//a一直初始化
//     a++;
//     printf("a=%d\n",a);
// }
// int main()
// {
//     int i=0;
//     while(i<10)
//     {
//         test();
//         i++;
//     }

//     return 0;
// }//输出十个2
// void test()//viod 没有返回值，不需要return
// {
//     static int a=1;//静态变量值初始化一次
//     a++;
//     printf("a=%d\n",a);
// }
// int main()
// {
//     int i=0;
//     while(i<10)
//     {
//         test();
//         i++;
//     }

//     return 0;
// }//2，3，4，5，6，7，8，9，10，11

//修饰全局变量时，改变了变量的链接属性，变成内部链接
// static int a=10;//只能在本文件使用，不能被其他文件使用 
//单纯的全局变量int a=10;可以通过extern在其他文件使用

//修饰函数时，改变了函数的链接属性，变成内部链接
//register  建议将变量存储在寄存器中，提高访问速度，一般不用，编译器优化会自动完成
//#define MAX 1000//定义常量，预处理指令
// #define add(x,y) ((x)+(y))//宏函数 add 宏名，x,y形式参数  相当于是替换里面的参数 
// int main()
// {
//     int a=0;
//     int b=0;
//     scanf("%d %d",&a,&b);
//     printf("%d\n",add(a,b));//宏函数调用
//     return 0;
// }


//指针
//一个内存单元的大小是一个字节，1比特=8字节
//int a=10;
// int* p=&a; //&取地址运算符，p存放地址（内存单位的编号），p称为指针，
//这里的int表示指针指向的数据类型 也就是a的类型  还有char* float* double*等
//*p就相当于a,*p=20;就相当于a=20;
//指针地址的大小与数据类型无关，在32位系统中指针大小是4字节，在64位系统中指针大小是8字节
//int *p1,*p2;俩个都是int指针
//int* p1,p2; p1是int指针，p2是int变量
//结构体
// struct stu//stu是一个类型  struct stu s1;结构体变量 创建结构体变量s1
// {
//     //结构体成员变量
//     char name[20];
//     int age;
//     float score;
// };
// int main()
// {
//     struct stu s={"zhangsan",20,99.5f};//定义结构体变量并初始化
//     printf("name=%s age=%d score=%.2f\n",s.name,s.age,s.score);//顺序对应
//     return 0;
// }
//结构体指针变量->成员名，->解引用+点运算符  