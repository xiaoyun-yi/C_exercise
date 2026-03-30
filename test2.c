//分支 if swich和循环语句while for do while 转向语句 break continue return goto 这些都是控制语句
//分支 if
//if, else ;if ,else if ,else
#include <stdio.h>
// int main() {
//     int age = 10;
//     if (age <10) //一条语句可以不用大括号，多条必须要有大括号
//     {
//         printf("青少年\n");
//     } else if (age>=10 && age<18) {
//         printf("依旧未成年\n");
//     } else if(age>18 && age<30){
//         printf("青年\n");}
//       else if(age>=30 && age<70){
//             printf("中年\n");}
    
//     return 0;
// }//else 是和最近的if匹配，和缩进无关
// int main()
// {
//     for(int i=1;i<=100;i++)
//     {
//         if(i%2==1)
//         {
//             printf("%d\n",i);
//         }
//     }
    
//     return 0;
// }

//swiTch 语句

// int main()
// {
//     int day=0;
//     printf("请输入一个1-7的数字\n");
//     scanf("%d",&day);
//     switch(day)//表达式必须是整数或字符型    根据逻辑需要，可以考虑不加break
//     {
//         case 1:
//         printf("星期一\n");
//         break;
//         case 2:
//         printf("星期二\n");
//         break;
//         case 3:
//         printf("星期三\n");
//         break;
//         case 4:
//         printf("星期四\n");
//         break;
//         case 5:
//         printf("星期五\n");
//         break;
//         case 6:
//         printf("星期六\n");
//         break;
//         case 7:
//         printf("星期天\n");
//         break;
//         default://case不能满足
//         printf("输入错误\n");
//         break;
//     }
//     return 0;
// }

//while 语句
//while(条件表达式){语句体;}
// int main()
// {
//    int i=1;
//     while(i<=10)
//     {
//         if(5==i)
//         continue;
//         //break;  break 直接跳出循环，遇到continue是跳过本次循环，判断要不要进行下一次循环
//         printf("%d\n",i);
//         i++;
//     }
//     //printf("%d\n",i);
//     return 0;

// }
//getchar 获取一个字符，从键盘获取（输入）出错时返回EOF；
//putchar 输出一个字符到屏幕  两个参数类型都是int
// int main()
// {
//     int ch=0;
//     while ((ch = getchar()) != EOF) {
//         putchar(ch);
//     }
//     return 0;
// }//输入一个字符后有个回车才会输出；输入a的时候，按回车，缓冲区有一个a和/n  再按回车，输出一个空行
//EOF 在windows系统下是ctrl+z  在linux系统下是ctrl+d

//数组名本身是地址，不需要取地址
// int main()
// {
// char password[20]={0};//初始化
// printf("请输入密码：\n");
// scanf("%s",password);//&password[0]  password scanf遇到空格，回车，制表符就停止

// //getchar();//吸收回车,只吸收一个字符
// int ch=0;
// while((ch=getchar())!='\n' && ch!=EOF);
// {;}//吸收多余字符，直到遇到换行或者文件结束符EOF
// printf("确认密码：%s\n",password);
// int ret=getchar();
// if('Y'==ret)
// {
//     printf("yes\n");
// }
// else
// {
//     printf("no\n");
// }
// return 0;
// }

//作业  1转化ASCII码，并输出  c%是打印数字对应的ASCII码
// int main ()
// {
//     int arr[]={73,24,99,97,109,101,115,33};
//     int i=0;
//     int size=sizeof(arr)/sizeof(arr[0]);
//     while(i<size)
//     {
//         printf("%c",arr[i]);
//         i++;
//     }
//     return 0;
// }

//2 输入一个人的出生日期，分别输出生日中的年月日，年份范围1900-2023，月份范围1-12，日期范围1-31
//输入只有一行，年月日，中间没有分隔符，输出时第一行为年份，第二行为月份，第三行为日期，
//月份和日期只有一位数时，前面补0
// int main()
// {
//     int year,month,day;
//     scanf("%4d%2d%2d",&year,&month,&day);
    
//     printf("year=%4d\n",year);
//     printf("month=%02d\n",month);//2位，不足补0
//     printf("day=%02d\n",day);
//     return 0;
// }
// int main()
// {
//     int id=0;
//     float C=0.0f;
//     float M=0.0f;
//     float E=0.0f;
//     scanf("%d;%f,%f,%f",&id,&C,&M,&E);
//     printf("The each subject score of number %d is %.2f %.2f %.2f",id,C,M,E);//保留两位小数
//     return 0;
// }

// int main()
// {
    
//     int n=printf("Hello,world!");//printf 的返回值是实际输出的字符数
//     printf("\n%d\n",n);
//     return 0;
// }

//在四个数中找最大值
// int main()
// {
//    int arr[4]={0};//存数据
//    int i=0;
//    while (i<4)//赋予下标
//    {
//     scanf("%d",&arr[i]);
//     i++;
//    }
//    int max=arr[0];//假设第一个数是最大值
//    for (i = 1; i < 4; i++)//从第二个数开始比较
//    {
//     if(arr[i]>max)//如果当前数比假设的最大值还大
//     {
//         max=arr[i];//就把当前数赋值给max
//     }
    
//    }
//    printf("max=%d\n",max);
//    return 0;
// }
// int main()
// {
//     int i=1;//比较的次数
//     int n=0;
//     int max=0;
//     scanf("%d",&max);//先输入第一个数，假设为最大值
//     while(i<4)
//     {
//         scanf("%d",&n);
//         if(n>max)
//         {
//             max=n;
//         }
//         i++;
//     }
//     printf("max=%d\n",max);
//     return 0;
// }

//计算球的体积
// int main ()
// {
//     float r=0.0f;
//     printf("请输入球的半径：\n");   
//     scanf("%f",&r);
//     float V= (4.0f/3.0f)*3.14f*r*r*r;
//     printf("球的体积是：%.2f\n",V); 
//     return 0;
// }

//static 保留上一次的值

//for 循环
//for(初始化表达式;条件表达式（这个是判断表达式==）;迭代表达式)  break 只能结束一个循环
//{语句体;}  初始化在循环外面进行

//do while
//do
   //循环语句
// while(条件表达式);   至少循环一次
// int main()
// {
//     int i=1;
//     do
//     {
//         printf("%d\n",i);
//         i++;
//     } while (i<=10);
    
//     return 0;
// }  

//计算n的阶乘
// int main()
// {
//     int i=1;
//     int n=0; //初始化，要输入的数
//     int ret=1;
//     scanf("%d",&n);
//     for(i=1;i<=n;i++)
//     {
//         ret=ret*i;
//     }
//     {
//         printf("%d\n",ret);
//     }
//     return 0;
// }
//计算1！+2!+3!+4!
// int main()
// {
//   int n=1;
//   int i=1;
//   int sum=0;
//   int ret=1;
//  // scanf("%d",&n);
//   for(i=1;i<=4;i++)
//   {
//     for(n=1;n<=i;n++)
//     {
//         ret=ret*n;
//     }
//     sum=sum+ret;
//     ret=1;//每次计算完一个阶乘后要重置ret的值
//   }
//   printf("%d\n",sum);
//     return 0;
// }


int main()
{
     int n=1;
     int i=1;
     int sum=0;
     int ret=1;
    for( n=1;n<=3;n++)
    {
        ret=ret*n;
        sum=sum+ret;
    }
    printf("%d\n",sum);
    return 0;
}

//在有序数组里面找数字n
// int main()
// {
//     int arr[]={1,3,5,7,9,11,13,15,17,19};
//     int n=0;
//     int i=0;
//     int size=sizeof(arr)/sizeof(arr[0]);
//     printf("请输入要查找的数字：\n");
//     scanf("%d",&n);
//     for(i=0;i<size;i++)
//     {
//         if(arr[i]==n)
//         {
//             printf("找到了，下标是%d\n",i);
//             break;
//         }
//     }
//     if(i==size)
//     {
//         printf("没找到\n");
//     }
//     return 0;
// }

// //二分查找
// int main()
// {
// int arr[]={1,3,5,7,9,11,13,15,17,19};
//      int n=7;//查找数字7
//      int i=0;
//      int size=sizeof(arr)/sizeof(arr[0]);
//      int left=0;
//      int right=size-1;
//      while(left<=right)
//      {
//      int mid=(left+right)/2;// left right数太大时可能会溢出；left + (right-left)/2 防止溢出
//      if(arr[mid]<n)
//         {
//             left=mid+1;
//         }
//         else if(arr[mid]>n)
//         {
//             right=mid-1;
//         }
//         else
//         {
//             printf("找到了，下标是%d\n",mid);
//             break;
//         }
//       }
//     if(left>right)
//     {
//         printf("没找到\n");
//     }
//     return 0;
// } 