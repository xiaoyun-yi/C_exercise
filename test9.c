#include <stdio.h>

//z走n节台阶，每次可以走1节或者2节，求有多少种走法
//递归解法  f(n)=f(n-1)+f(n-2)
// int fib(int n)
// {
//     if(n==1)
//     {
//         return 1;
//     }
//     else if(n==2)
//     {
//         return 2;
//     }
//     else
//     {
//         return fib(n-1)+fib(n-2);
//     }
// }
// int main()
// {
//     int n=0;
//     printf("请输入台阶的节数：");
//     scanf("%d",&n);
//     int a=fib(n);
//     printf("共有 %d 种走法\n", a);
//     return 0;
// }

//整数序列，又重复的数字，要删除指定的数字，输出序列，原来的顺序不变

// int main()
// {
//     int n=0;
//     printf("请输入数字的个数：");
//     scanf("%d",&n);
//     int arr[10]={0};
//     int i=0;
//     for(i=0;i<n;i++)
//     {
//         printf("请输入第%d个数字：",i+1);
//         scanf("%d",&arr[i]);
//     }
//     int del = 0;
//     printf("请输入要删除的数字：");
//     scanf("%d",&del);
//     int j=0;
//     for(i=0;i<n;i++)
//     {
//         if(arr[i]!=del)
//         {
//             arr[j]=arr[i];
//             j++;
//         }
//     }   

//     for (i=0;i<j;i++)
//     {
//         printf("%d ",arr[i]);
//     }


//     return 0;
// }

//输入n个整数，输出其中的最大值和最小值
//输入两行，第一行输入整数的个数n，第二行输入n个整数，输出最大值和最小值的差
// int main()
// {
//     int n=0;
//     printf("请输入整数的个数：");
//     scanf("%d",&n);
//     int arr[10]={0};
//     int i=0;
//     for(i=0;i<n;i++)
//     {
//         printf("请输入第%d个整数：",i+1);
//         scanf("%d",&arr[i]);
//     }
//     int max=arr[0];
//     int min=arr[0];
//     for(i=1;i<n;i++)
//     {
//         if(arr[i]>max)
//         {
//             max=arr[i];
//         }
//         if(arr[i]<min)
//         {
//             min=arr[i];
//         }
//     }
//     int diff=max-min;
//     printf("最大值为%d，最小值为%d，差值为%d\n",max,min,diff);
//     return 0;
// }


// int main()
// {
//     int n=0;
//     printf("请输入整数的个数：");
//     scanf("%d",&n);
//     int arr[10]={0};
//     int i=0;
//     int max=0;
//     int min=100;
//     for(i=0;i<n;i++)
//     {
//         printf("请输入第%d个整数：",i+1);
//         scanf("%d",&arr[i]);
//         if(arr[i]>max)
//         {
//             max=arr[i];
//         }
//         if(arr[i]<min)
//         {
//             min=arr[i];
//         }
//     }
//     int diff=max-min;
//     printf("最大值为%d，最小值为%d，差值为%d\n",max,min,diff);
//     return 0;
// }

//字符大小写转换
// 大写转化成小写，小写转化成大写
// int main() {
//     char ch;
//     printf("请输入一个字符：");
//     while(scanf("%c", &ch)==1) 
//     {
//     if (ch >= 'a' && ch <= 'z')
//         printf("转换后的字符是：%c\n", ch - 32);
//     else if (ch >= 'A' && ch <= 'Z')
//         printf("转换后的字符是：%c\n", ch + 32);
    
    
//     }
//     getchar(); // 读取换行符，准备下一次输入
//     return 0;
// }

// #include <ctype.h> // 包含字符处理函数的头文件
// int main()
// {
//     char ch = 0;
//     while(scanf("%c", &ch)!=EOF) //读取成功时，返回读取的数据个数，失败则返回 EOF
//     {
//         if (islower(ch))
//             printf("转换后的字符是：%c\n", toupper(ch));
//         else if (isupper(ch))
//             printf("转换后的字符是：%c\n", tolower(ch));
//     }
//     return 0;
// }

//判断是不是字母
// #include <ctype.h>
// int main()
// {
//     char ch = 0;
//     while(scanf("%c", &ch)!=EOF) 
//     {
//         if (isalpha(ch)) //if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
//             printf("%c 是一个字母\n", ch);
//         else
//             printf("%c 不是一个字母\n", ch);
//     getchar(); // 读取换行符，准备下一次输入
//         }
//     return 0;
// }

//找三个数中最大的那个
// int main()
// {
//     int i = 0;
//     int max = 0;
//     int score = 0;
//     for(i=0;i<3;i++)
//     {
//         scanf("%d", &score);
//         if(score>max)
//         {
//             max=score;
//         }   

//     }
//     printf("最大的数是：%d\n", max);

//     return 0;
// }

//变种水仙花
//把任意的数字从中间拆分成两个数字，1234，1和234，12和34，123和4，拆分后乘积之和等于本身，则是变种水仙花数
//求出五位数中所有的水仙花数
// int main()
// {


//         int i = 10000;
//         for(i=10000;i<=99999;i++)
//         {
//             int a=i/10000;  //12345/10000=1
//             int b=(i%10000)/1000;  //12345%10000=2345  2345/1000=2
//             int c=(i%1000)/100;  //12345%1000=345  345/100=3
//             int d=(i%100)/10;  //12345%100=45  45/10=4
//             int e=i%10;  //12345%10=5
//             if(a*(b*1000+c*100+d*10+e)+ (a*10+b)*(c*100+d*10+e) + (a*100+b*10+c)*(d*10+e) + (a*1000+b*100+c*10+d)*e == i)
//             {
//                 printf("%d\n", i);
//             }
//         }
//     return 0 ;
// }

// int main()
// {
//     int i = 0;
//     for(i=10000;i<=99999;i++)
//     {
//         int j = 0;
//         int sum = 0;
//         for(j=0;j<5;j++)
//         {
//             int a =(int)pow(10,j);  //10的0次方=1  10的1次方=10  10的2次方=100  10的3次方=1000  10的4次方=10000
           
//             sum += (i%a)*(i/a);  //1*10000 + 2*1000 + 3*100 + 4*10 + 5*1
//         }
//         if(sum == i)
//         {
//             printf("%d\n", i);
//         }
//     }
//     return 0;
// }