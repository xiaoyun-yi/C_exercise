#include<stdio.h>

//内存分为栈区 堆区和静态区
//栈区内存使用习惯是先用高处地址，再用低处地址，堆区内存使用习惯是先用低处地址，再用高处地址，
//静态区内存使用习惯是先用低处地址，再用高处地址  

//数组随着下标增长，地址是由低到高变化的
//const  变量前面加上const修饰，表示该变量的值不能被修改，
//编译器会对其进行检查，如果尝试修改该变量的值，编译器会报错
//assert 断言 断言是一种调试工具，用于在程序中检查某个条件是否为真，如果条件不满足，程序会终止并输出错误信息
//assert宏定义在<cassert>头文件中，使用时需要包含该头文件
//assert(condition)  condition是一个表达式，如果condition为假，程序会终止并输出错误信息
//assert(condition)  condition是一个表达式，如果condition为假，程序会终止并输出错误信息

//错误分为 编译错误和链接错误 运行时错误
//编译错误是指在编译阶段发生的错误，通常是由于语法错误、类型错误、缺少头文件等引起的
//链接错误是指在链接阶段发生的错误，通常是由于函数未定义、变量未定义、库文件缺失等引起的
//链接错误
// int main()
// {
//     printf("hello world\n");
//     return 0;
// }  //链接错误，缺少printf函数的定义，应该包含<stdio.h>头文件

//想知道输入的三个数字能不能组成三角形，如果能组成三角形判断是等腰，等边还是普通三角形

// int main()
// {
//     int a=0;
//     int b=0;
//     int c=0;
//     printf("请输入三个整数：");
//     scanf("%d %d %d",&a,&b,&c);
//     if(a+b>c && a+c>b && b+c>a) //判断能否组成三角形
//     {
//         if(a==b && b==c) //判断是否是等边三角形
//         {
//             printf("等边三角形\n");
//         }
//         else if(a==b || a==c || b==c) //判断是否是等腰三角形
//         {
//             printf("等腰三角形\n");
//         }
//         else
//         {
//             printf("普通三角形\n");
//         }
//     }
//     else
//     {
//         printf("不能组成三角形\n");
//     }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
//     return 0;
// }

//short 类型指针 一次访问两个字节

//int 一次访问四个字节 00 00 00 01  存储的时候是 01 00 00 00  小端存储  内存存储是倒着存储的
//short 一次访问两个字节 00 01 存储的时候是 01 00 小端存储  
//int 需要short 访问两次

// 将字符串逆序

// int main()
// {
//     char arr[10000] = {0};
//     printf("请输入一个字符串：");
//     scanf("%s", arr);
//     int len = strlen(arr);
//     for(int i=0; i<len/2; i++)
//     {
//         char temp = arr[i];
//         arr[i] = arr[len-1-i];
//         arr[len-1-i] = temp;
//     }
//     printf("逆序后的字符串：%s\n", arr);
//     return 0;
// }


//scanf函数，读到空格就不读取了，所以如果输入的字符串中有空格，scanf函数只能读取到第一个空格之前的内容，后面的内容会被忽略
//如果想要读取包含空格的字符串，可以使用fgets函数，fgets函数可以读取一行输入，包括空格，直到遇到换行符或者达到指定的字符数为止
#include <string.h>

// int main()
// {
//     char arr[10001]={0};
//     printf("请输入一个字符串：");
//     fgets(arr, sizeof(arr), stdin); //使用fgets函数读取输入的字符串，fgets函数会读取一行输入，包括空格，直到遇到换行符为止
//     int left=0;
//     int right=strlen(arr)-1;
//     int *p = &right;
//         while(left<*p)
//         {
//             char temp = arr[left];
//             arr[left] = arr[*p];
//             arr[*p] = temp;
//             left++;
//             (*p)--;
//         }
//     // while(left<right)
//     // {
//     //     char temp = arr[left];
//     //     arr[left] = arr[right];
//     //     arr[right] = temp;
//     //     left++;
//     //     right--;
//     // }
//     printf("逆序后的字符串是：%s\n",arr);
//     return 0;
// }

//求 a+aa+aaa+aaaa+aaaaa的前五项之和

// int main()
// {
//     int a=0;
//     printf("请输入一个整数：");
//     scanf("%d",&a);
//     int sum=0;
//     int term=a; //第一项
//     for(int i=1; i<=5; i++)
//     {
//         sum += term; //将当前项加入到sum中
//         term = term*10 + a; //计算下一项，下一项是当前项乘以10再加上a，例如：如果a=2，第一项是2，第二项是2*10+2=22，第三项是22*10+2=222，以此类推
//     }
//     printf("前五项之和为：%d\n", sum);

//     return 0;
// }

//求0-10000之间的水仙花数 
//水仙花数是指一个n位数，其各位数字的n次幂之和等于它本身的数，
//例如：153是一个三位数，1^3 + 5^3 + 3^3 = 153，所以153是一个水仙花数

// int main()
// {
//     for(int i=0; i<=10000; i++)
//     {
//         int sum=0;
//         int temp=i;
//         int n=0; //n表示i的位数
//         while(temp>0)
//         {
//             n++;
//             temp /= 10; //temp除以10，去掉最后一位数字，直到temp为0，n就表示i的位数
//         }
//         temp=i; //将i赋值给temp，重新计算每位数字的n次幂之和
//         while(temp>0)
//         {
//             int digit = temp % 10; //获取最后一位数字
//             sum += pow(digit, n); //将该数字的n次幂加入到sum中
//             temp /= 10; //去掉最后一位数字
//         }
//         if(sum == i) //如果sum等于i，说明i是一个水仙花数
//         {
//             printf("%d\n", i);
//         }
//     }
//     return 0;
// }


// //打印菱形
// int main()
// {
//     int line=0;
//     printf("请输入菱形的行数：");
//     scanf("%d",&line);
//     for(int i=1; i<=line; i++) //打印上半部分
//     {
//         for(int j=1; j<=line-i; j++) //打印空格
//         {
//             printf(" ");
//         }
//         for(int k=1; k<=2*i-1; k++) //打印星号
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     for(int i=line-1; i>=1; i--) //打印下半部分
//     {
//         for(int j=1; j<=line-i; j++) //打印空格
//         {
//             printf(" ");
//         }
//         for(int k=1; k<=2*i-1; k++) //打印星号
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     return 0;
// }

// //int *arr[10] 是指针数组  int(*arr)[10] 是数组指针
// struct S
// {
//     int a;
//     intb;

// };

// int main()
// {
//     struct S a, *p=&a;//这个表示创建了一个结构体变量a和一个指向结构体变量a的指针p，结构体变量a里面有两个成员a和b，

//     a.a=99;
//     printf("%d\n",a.a);//a.a;(*p).a; p->a; 这三种方式都可以访问结构体变量a的成员a

//     return 0;
// }

//喝汽水，一瓶汽水一元，2个空瓶可以换一瓶汽水，20元可以喝多少汽水
// int main()
// {
//     int money=20;
//     int total=money; //总共喝的汽水数量
//     int empty=money; //空瓶数量
//     while(empty>=2)
//     {
//         total+=empty/2;
//         empty=empty%2 + empty/2; //换完汽水后剩下的空瓶数量，等于换完汽水后剩下的空瓶数量加上换到的汽水喝完后产生的空瓶数量
        
//     }
//     printf("总共可以喝：%d瓶汽水\n", total);

//     return 0;
// }

//k*=i+j  k=k*(i+j)  i+j的结果是一个整数，k的值会被更新为k乘以i+j的结果
//*p++  先使用*p的值，再将p的值加1

//求两个数的最小公倍数

// int main()
// {
//     int a=0;
//     int b=0;    
//     printf("请输入两个整数：");
//     scanf("%d %d",&a,&b);
//         int max = (a > b) ? a : b; //最大值
//         while(1)
//         {
//             if(max % a == 0 && max % b == 0) //如果max同时是a和b的倍数，说明max就是a和b的最小公倍数
//             {
//                 printf("最小公倍数是：%d\n", max);
//                 break; //找到最小公倍数后，退出循环
//             }
//             max++; //如果max不是a和b的倍数，继续增加max的值，直到找到最小公倍数为止
//         }
//     return 0;
// }


// int main()
// {
//     int a=0;
//     int b=0;    
//     printf("请输入两个整数：");
//     scanf("%d %d",&a,&b);
//     int max = (a > b) ? a : b; //最大值
//     int min = (a < b) ? a : b; //最小值
//     int i=1;
//     while(max*i%min!=0) //当max*i不是min的倍数时，继续增加i的值，直到找到max*i是min的倍数为止
//     {
//         i++;
//     }
//     printf("最小公倍数是：%d\n", max * i);

//     return 0;
// }

//逆置字符串，标点不动 i like beijing.  beijing. like i
#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse(char *left, char *right)
{
    assert(left != NULL && right != NULL); //断言，检查left和right是否为NULL，如果为NULL，程序会终止并输出错误信息
    while(left<right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

void reverse2(char *left, char *right)
{
    assert(left != NULL && right != NULL); //断言，检查left和right是否为NULL，如果为NULL，程序会终止并输出错误信息
    char *start = left; //记录每个单词的起始位置
    while(left<=right)
    {
        if(*left == ' '| *left == '\0' ) //当遇到空格或者字符串结束符时，说明一个单词结束了
        {
            reverse(start, left - 1); //逆置当前单词，left-1是当前单词的结束位置
            start = left + 1; //更新下一个单词的起始位置
        }
        left++;
    }
    reverse(start, left - 1); //逆置最后一个单词，left-1是最后一个单词的结束位置
}

int main()
{
    char arr[10001]={0};
    printf("请输入一个字符串：");
    fgets(arr, sizeof(arr), stdin); //使用fgets函数读取输入的字符串，fgets函数会读取一行输入，包括空格，直到遇到换行符为止
    reverse(arr, arr + strlen(arr) - 2); //逆置整个字符串

    reverse2(arr, arr + strlen(arr) - 2); //逆序每个单词
    printf("逆序后的字符串是：%s\n",arr);
    return 0;
}