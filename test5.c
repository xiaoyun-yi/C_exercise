
#include <stdio.h>
#include <string.h>

//函数的声明和定义

// //函数的声明
// int add(int x,int y);//函数的声明，告诉编译器这个函数的名字是add，参数列表是int x,int y，返回值类型是int，
// //这样编译器就知道这个函数的存在了，可以在main函数中调用这个函数了  有这个声明之后，函数的定义就可以在使用之后
// int main()
// {
//     int a=0;
//     int b=0;    
//     scanf("%d %d",&a,&b);
//     int sum=add(a,b);
//     printf("sum=%d\n",sum);
//     return 0;
// }

// //函数的定义
// int add(int x,int y)
// {
//     return x+y;
// }

//新建两个文件  add.h  add.c  .h里面放声明  .c里面放定义  main.c里面调用add函数  这样就实现了函数的分文件编写
//test5.c调用时需要包含add.h头文件，编译时需要把add.c和test5.c一起编译，生成可执行文件  #include "add.h"
//使用静态库  要导入#pragma comment(lib,"add.lib")  这样就不需要在编译时把add.c和test5.c一起编译了，
//直接编译test5.c就可以了，链接器会自动链接add.lib库文件  


//函数的递归
//程序调用自身的编程技巧，递归函数必须有一个明确的结束条件，否则会导致死循环，最终导致栈溢出错误


//%d打印有符号的整数（会有负数） %u 打印无符号的整数（不会有负数）
// %f 打印浮点数 %lf 打印双精度浮点数 %c 打印字符 %s 打印字符串

//接受一个整型数，按照顺序打印它的每一位
// int main ()
// {
//     unsigned int num=0;
//     scanf("%u",&num);
//     printf("num=%u\n",num);
//     return 0;
// }//这个不对，%u只能打印无符号整数，不能打印每一位数字，应该使用循环来打印每一位数字

// void print(unsigned int num)
// {
//     if(num>9)//如果num大于9，说明还有下一位数字
//     {
//         print(num/10);//递归调用print函数，打印num的前面几位数字，num/10表示把num的最后一位数字去掉
//     }
//     printf("%u ",num%10);//打印num的最后一位数字，num%10表示取num的最后一位数字
// }


// int main ()
// {
//     unsigned int num=0;
//     scanf("%u",&num);
//     print(num);//打印数字的函数
//     return 0;
// }

//递归要有终止条件，递归之后要逐渐接近终止条件
//递归函数的调用会占用栈空间，如果递归层数过多，会导致栈溢出错误，
//所以在使用递归时要注意递归的层数，避免出现栈溢出错误
//存储区 分为代码区、数据区、堆区、栈区
//代码区 存储程序的机器代码，程序运行时不允许修改   数据区 存储全局变量和静态变量，程序运行时允许修改  
//堆区 由程序员分配和释放，存储动态分配的内存，程序运行时允许修改  
//栈区 由编译器自动分配和释放，存储函数的参数、局部变量和返回地址，程序运行时允许修改


//编写函数，不允许创建临时变量，求字符串长度
//模拟实现strlen函数

// int my_strlen(char *str)
// {
//     if(*str == '\0')
//     {
//         return 0;
//     }
//     return 1 + my_strlen(str + 1);//不能换成str++，因为str++先传str在自增，可以用++str
// }


// int my_strlen(char *str)
// {
//     int count=0;
//     while(*str != '\0')
//     {
//         count++;//临时变量
//         str++;//由于char类型的大小固定为1字节，因此str++会使指针的地址值增加1，从而指向内存中的下一个字符。
//         //把str指向下一个字符，继续判断下一个字符是否是'\0'，如果不是，就继续递归调用my_strlen函数，直到遇到'\0'为止，这样就得到了字符串的长度
//     }
//     return count ;
// }


// int main()
// {
//     int len=my_strlen("asd");//  [a s d \0]   字符串传参和数组传参一样，都是首字符地址
//     printf("len=%d\n",len);
//     return 0;
// }


//迭代
//计算n的阶乘  n! = n * (n-1)!  0! = 1

// int jiecheng(int n)
// {
//     if(n>=1)
//     {
//         return n*jiecheng(n-1);
//     }
//     else
//     {
//         return 1;
//     }
// }


// int main()
// {
//     int n=0;
//     scanf("%d",&n);
//     int ret=jiecheng(n);
//     printf("%d的阶乘是%d\n",n,ret);
//     return 0;
// }

//求第n个斐波那契数列
//斐波那契数列  1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765... 前两项的和等于第三项

// int feibo(int n)
// {
//     if(n==1 || n==2)
//     {
//         return 1;
//     }
//     else
//     {
//         return feibo(n-1)+feibo(n-2);
//     }
// }

//这样子计算 的n很大的话，会导致计算很多斐波那契数列，
//比如feibo(50)会计算很多次feibo(25)，feibo(25)又会计算很多次feibo(12)，
//所以当n很大的时候，这个递归函数的效率非常低，甚至可能导致栈溢出错误，

// int feibo(int n)
// {
//     int a=1;
//     int b=1;
//     int c=0;
//     if(n==1 || n==2)
//     {
//         return 1;
//     }
//     else
//     {
//         for(int i=3;i<=n;i++)
//         {
//             c=a+b;//c是第i个斐波那契数列的值，a是第i-2个斐波那契数列的值，b是第i-1个斐波那契数列的值
//             a=b;//把b的值赋给a，a就变成了第i-1个斐波那契数列的值
//             b=c;//把c的值赋给b，b就变成了第i个斐波那契数列的值
//         }
//         return c;
//     }
// }

// int main()
// {
//     int n=0;
//     scanf("%d",&n);
//     feibo(n);
//     printf("%d的斐波那契数是%d\n",n,feibo(n));
//     return 0;
// }

//全选 按tab 可以整体后移，按shift+tab可以整体前移，
//swich 语句中参数是一个整数表达式，字符，数字等，不可以是浮点数


//从大到小输出
// int main()
// {
//     int a=0;
//     int b=0;
//     int c=0;
//     scanf("%d %d %d",&a,&b,&c);
//     int ret=paixu(a,b,c);
//     printf("从大到小输出: %d %d %d\n",ret,a+b+c-ret-a-b-c,a+b+c-ret-a-b-c);

// }

//求两个数的最大公约数
// int main()
// {
//     int a=0;
//     int b=0;    
//     scanf("%d %d",&a,&b);
//     int min=a<b?a:b;//min是a和b中的较小值
//     while(1)
//     {
//         if(a%min==0 && b%min==0)//如果min能同时整除a和b，说明min就是a和b的最大公约数
//         {
//             printf("最大公约数是%d\n",min);
//             break;//跳出循环，不需要继续判断了
//         }
//         min--;//如果min不能同时整除a和b，就把min的值减1，继续判断下一个较小的值是否能同时整除a和b，直到找到最大公约数为止
//     }
//     return 0;

// }//暴力求解

// //辗转相除法
// int main()
// {
//     int a=0;
//     int b=0; 
//     int c=0;   
//     scanf("%d %d",&a,&b);
//     int min=a<b?a:b;//min是a和b中的较小值
//     while(c=a%b)
//     {
//         a=b;//把b的值赋给a，a就变成了b的值
//         b=c;//把c的值赋给b，b就变成了a除以b的余数的值
//     }
//     printf("最大公约数是%d\n",b);
//     return 0;

// }


//编程数一下1-100的所有整数中有多少个数字9

// int main()
// {
//     int count=0;
//     for(int i=1;i<=100;i++)
//     {
//         if(i%10==9)//如果i的个位数是9，说明i中有一个数字9
//         {
//             count++;
//         }
//         if(i/10==9)//如果i的十位数是9，说明i中有一个数字9
//         {
//             count++;
//         }
//     }
//     printf("1-100之间有%d个数字9\n",count);
//     return 0;
// }

//计算1/1-1/2+1/3-1/4+...+1/99-1/100的值
// int main()
// {
//     int i=0;
//     double sum=0.0;
//     for(i=1;i<=100;i++)
//     {
//         if(i%2==1)//如果i是奇数，说明这一项是正数
//         {
//             sum+=1.0/i;//把这一项的值加到sum中
//         }
//         else//如果i是偶数，说明这一项是负数
//         {
//             sum-=1.0/i;//把这一项的值减去sum中
//         }
//     }
//     printf("1/1-1/2+1/3-1/4+...+1/99-1/100的值是%lf\n",sum);
//     return 0;
// }


// int main()
// {
//     int i=0;
//     double sum=0.0;
//     int flag=1;//flag用来标记这一项是正数还是负数，初始值为1，表示第一项是正数
//     for(i=1;i<=100;i++)
//     {
//         sum=sum+flag*1.0/i;//把这一项的值加到sum中，flag*1.0/i表示这一项的值，如果flag是1，说明这一项是正数，如果flag是-1，说明这一项是负数
//         flag=-flag;//把flag的值取反，这样下一项的值就会变成负数了，如果flag是1，说明下一项是负数，如果flag是-1，说明下一项是正数
//     }
//     printf("1/1-1/2+1/3-1/4+...+1/99-1/100的值是%lf\n",sum);
//     return 0;
// }

//打印乘法口诀表

// int main()
// {
//     int i=0;
//     for(i=1;i<=9;i++)
//     {
//         int j=0;
//         for(j=1;j<=i;j++)
//         {
//             printf("%d*%d=%-2d ",j,i,i*j);//%-2d表示左对齐，占2个字符宽度  %2d表示右对齐，占2个字符宽度 这样可以保证输出的格式整齐
//         }
//         printf("\n");
//     }
// }


//全局变量不用传参

