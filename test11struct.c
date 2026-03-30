//结构体
#include <stdio.h>
//结构体是一种用户自定义的数据类型，可以包含多个不同类型的成员变量
// struct human
// {
//     char name[20];  //结构体成员变量
//     int age;
//     float height;
// };   //分号前面可以放变量，一般不放
// struct st
// {
//     struct human h; //结构体成员变量是另一个结构体
//     int score;
//     char grade;
// };

// void print(struct st *ps1)
// {
//     printf("name=%s, age=%d, height=%.2f, score=%d, grade=%c\n", 
//         ps1->h.name, ps1->h.age, ps1->h.height, ps1->score, ps1->grade);//结构体指针->成员变量名 访问结构体成员变量
// }

// void print2(struct st s1)
// {
//     printf("name=%s, age=%d, height=%.2f, score=%d, grade=%c\n", 
//         s1.h.name, s1.h.age, s1.h.height, s1.score, s1.grade);//结构体变量.成员变量名 访问结构体成员变量
// }

// int main()
// {
//     struct human h1; //定义一个结构体变量h1
//     //访问结构体成员变量
//     //使用点运算符（.）访问结构体成员变量
//     //结构体变量.成员变量名
//     h1.age=18; //给结构体成员变量赋值
//     printf("age=%d\n",h1.age); //访问结构体成员变量

//     struct st s1={{"ss",12,3.23},85,'A'}; //定义一个结构体变量s1
//     s1.h.age=20; //访问嵌套结构体成员变量
//     printf("age=%d\n",s1.h.age); //访问嵌套结构体成员变量

//     print(&s1); //传递结构体变量的地址给函数
//     print2(s1); //传递结构体变量给函数
//     return 0;
// }

//结构体成员可以是其他结构体 嵌套结构体   python里面的类里面可以有属性是另一个类的实例

//统计 二进制中1的个数

// int count_bin(int n)
// {
//     int count = 0;
//     int i=0;
//     for(i=0;i<32;i++) //假设int类型是32位
//     {
//      if(((n>>i)&1)==1) //右移i位，判断最低位是否为1
//      {
//         count++; //统计1的个数
//      }
//       return count;
//      }
//}


// int count_bin(int n)//传入 unsigned int n 负数就可以
// {
//     int count = 0;
//     while (n)
//     {
//         if((n%2)==1) //如果n的二进制表示的最后一位是1
//         {
//             count++; //统计1的个数
//         }
//         n /= 2; //整除2，相当于右移一位

//     }
//     return count;
// }  //负数不行


// int count_bin(int n)
// {
//     int count = 0;
//     while (n)
//     {
//         n=n&(n-1); //每次将n和n-1进行按位与运算，都会将n的二进制表示的最后一个1变成0
//         count++; //统计1的个数

//     }
//     return count;
// }  //负数也可以




// int main()
// {
//     int n = 29; //二进制表示为11101
//     count_bin(n);
//     printf("二进制中1的个数是：%d\n", count_bin(n));
//     return 0;
// }

//求两个二进制位中不同的个数

// int differ(int n1, int n2)
// {
//     int count = 0;
//     int i=0;
//     for(i=0;i<32;i++) //假设int类型是32位
//     {
//         if(((n1>>i)&1) != ((n2>>i)&1)) //右移i位，判断最低位是否不同
//         {
//             count++; //统计不同的个数
//         }
//     }
//     return count;
// }

// int differ(int n1, int n2)
// {
//     int count = 0;
//     int n = n1 ^ n2; //异或运算，得到n1和n2二进制表示中不同的位
//     while (n)
//     {
//         n = n & (n - 1); //每次将n和n-1进行按位与运算，都会将n的二进制表示的最后一个1变成0
//         count++; //统计不同的个数
//     }
//     return count;
// }  //负数也可以



// int main()
// {
//     int n1=0;
//     int n2=0;
//     printf("请输入两个整数：");
//     scanf("%d %d",&n1,&n2);
//     differ(n1,n2);
//     printf("两个整数的二进制表示中不同的个数是：%d\n", differ(n1,n2));
//     return 0;
// }

//获取一个整数二进制序列中所有偶数位和奇数位，分别打印二进制序列

// int main()
// {
//     int i=0;
//     int n=0;
//     printf("请输入一个整数：");
//     scanf("%d",&n);
//     for(i=31;i>=0;i-=2)

//     {
       
//     printf("%d", (n>>i)&1); //右移i位，判断最低位是否为1
          
//     }
//     printf("\n");
//     for(i=30;i>=0;i-=2)

//     {
//         printf("%d", (n>>i)&1); //右移i位，判断最低位是否为1
//     }

   
//     return 0;
// }

//全局变量，静态变量放在静态区，不初始化的时候默认值为0，
//局部变量放在栈区，不初始化的时候默认值是随机的，可能是垃圾值
//sizeof返回的结果是size_t类型，是无符号整型
//sizeof(-1)返回结果
// int i;
// int main()
// {
//     i--;
//     if(i>sizeof(i))
//     {
//         printf("111\n");//i 的值是 -1，与 4 比较时，因类型不同（有符号 vs 无符号），
//         //-1 被转换为无符号大数（4294967295），因此 -1 > 4 成立，输出 111
//     }
//     if(i<sizeof(i))
//     {
//         printf("222");
//     }

//     int n=sizeof(-1); //sizeof(-1)返回结果是4，因为-1是一个int类型的常量，占4个字节
//     printf("sizeof(-1)=%d\n",n);
//     return 0 ;
// }
//有符号和无符号比较时，要转化成无符号，，也就是将有符号数转化成对应补码的无符号数进行比较，所以-1会被转化成一个很大的无符号数，因此-1 > 4成立，输出111
//sizeof(-1)返回结果是4，因为-1是一个int类型的常量，占4个字节

// 输入数字。生成用 * 表示的x形，字数表示有几行

// int main()
// {
//     int n=0;
//     printf("请输入一个整数："); 
    
//     while(scanf("%d",&n)==1) //当输入一个整数时，scanf返回1，继续循环；当输入非整数时，scanf返回0，退出循环
//     {
//         int i=0;
//         int j=0;
//         for(i=0;i<n;i++)
//         {
//             for(j=0;j<n;j++)
//             {
//                 if(i==j || i+j==n-1) //判断是否在对角线上
//                 {
//                     printf("*");
//                 }
//                 else
//                 {
//                     printf(" ");
//                 }
//             }
//             printf("\n");
//         }
//     }
//     return 0;
// }

//输入年份和月份，输出该月的天数

// int days(int month,int year)
// {
//     int day=0;
//     switch(month)
//     {
//         case 1:
//         case 3:
//         case 5:
//         case 7:
//         case 8:
//         case 10:
//         case 12:
//             day=31;
//             break;
//         case 4:
//         case 6:
//         case 9:
//         case 11:
//             day=30;
//             break;
//         case 2:
//             if((year%4==0 && year%100!=0) || year%400==0) //判断是否是闰年
//             {
//                 day=29;
//             }
//             else
//             {
//                 day=28;
//             }
//             break;
//         default:
//             printf("输入的月份不合法！\n");
//     }
//     return day;
// }

// int main()
// {
//     int year=0;
//     int month=0;
//     printf("请输入年份和月份：");
//     scanf("%d %d",&year,&month);
//     int day=days(month,year);
//     printf("%d年%d月有%d天\n",year,month,day);
//     return 0;
// }



// int main()
// {
//     int y=0;
//     int m=0;
//     int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //定义一个数组，存储每个月的天数，0号位置不使用
//     printf("请输入年份和月份：");

//     while(scanf("%d %d",&y,&m)==2) //当输入两个整数时，scanf返回2，继续循环；当输入非整数时，scanf返回0，退出循环
//     {
//         if(m<1 || m>12)
//         {
//             printf("输入的月份不合法！\n");
//             continue; //跳过本次循环，继续下一次循环
//         }
//         int day=days[m]; //获取该月的天数
//         if(m==2) //如果是2月，还要判断是否是闰年
//         {
//             if((y%4==0 && y%100!=0) || y%400==0) //判断是否是闰年
//             {
//                 day=29;
//             }
//         }
//         printf("%d年%d月有%d天\n",y,m,day);
//     }
//     return 0;
// }
// //F10不可以 F11可以进入函数