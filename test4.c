//函数 分类 库函数和自定义函数  库函数是编译器提供的函数  自定义函数是程序员自己编写的函数
#include <stdio.h>//这个是输入输出函数库，提供了printf scanf等函数
#include <string.h>//这个是字符串函数库，提供了strlen strcmp strcpy等函数
// int main()
// {
//     char arr1[20]={0};
//     char arr2[]="hello world";
//     strcpy(arr1,arr2);//把arr2的内容复制到arr1中，strcpy函数需要包含string.h头文件
//     printf("%s\n",arr1);
//     return 0;
// }

//自定义函数  包括函数名，参数列表，函数体，返回值类型
//得到较大的数

// int get_max(int x,int y)//这个int是返回值类型，表示这个函数会返回一个整数，void表示这个函数没有返回值
// {
//     return x>y?x:y;//三目运算符  条件？表达式1：表达式2  如果条件为真，返回表达式1的值，否则返回表达式2的值
// }


// int main()
// {
//   int a=0;
//   int b=0;
//     printf("请输入两个数：\n");
//     scanf("%d %d",&a,&b);
//     int m=get_max(a,b);
//     printf("较大的数是：%d\n",m);
//     return 0;
// }

//交换两个数的值

// void swap(int *px,int *py)  //px放的是a的地址，py放的是b的地址，*px表示取px所指向的地址的值，也就是a的值，
// {
//     int temp=*px;//temp是一个临时变量，用来存储*px的值，也就是a的值
//     *px=*py;//把*py的值赋给*px，也就是把b的值赋给a
//     *py=temp;//把temp的值赋给*py，也就是把a的值赋给b
    
//     return 0;
// }
// //实参传递给形参的时候，形参是实参的临时拷贝，形参的改变不会影响实参的值，这就是值传递 
// //不改变实参的值时，不用传递实参的地址，直接传递实参的值就可以了；如果要改变实参的值，就要传递实参的地址，
// //这就是指针传递，形参是一个指针变量，指向实参的地址，通过指针变量来修改实参的值
// int main()
// {
//     int a=0;
//     int b=0;
//     printf("请输入两个数：\n");
//     scanf("%d %d",&a,&b);

//     printf("交换前：a=%d,b=%d\n",a,b);
//     //这里的a,b是实参，swap函数中的x,y是形参，实参和形参是两个不同的变量，
//     //swap函数中的x,y只是swap函数内部的变量，对main函数中的a,b没有影响，所以交换后main函数中的a,b的值没有改变
//     swap(&a, &b);
//     printf("交换后：a=%d,b=%d\n",a,b);
//     return 0;
// }

// int main()
// {
//     int a=10;
//     int *b=&a;//指针变量b存储了变量a的地址，&a表示取变量a的地址
//     a=20;
//     printf("%d\n",*b);//*b表示取指针变量b所指向的地址的值，也就是变量a的值，所以输出20
//     *b=30;//*b表示取指针变量b所指向的地址的值，也就是变量a的值，所以把变量a的值修改为30
//     printf("%d\n",a);//输出30
   
//     return 0;
// }

//一个工程可以有多个.c文件，但是main函数只能有一个，
//其他.c文件中不能有main函数，否则会出现重定义错误，编译器不知道哪个main函数是程序的入口点，所以会报错

//函数参数
//实参 真实传递给函数的参数 可以是常量 变量，表达式，函数 调用时必须有确定的值
//形参  函数名后括号中的变量，函数调用时作为实参使用

//传值调用  形参是实参的临时拷贝，形参的改变不会影响实参的值
//传地址调用  形参是一个指针变量，指向实参的地址，通过指针变量来修改实参的值  实参和形参之间建立真正的联系


//写一个函数判断一个数是否是素数
//打印100-200之间的素数
//#include <math.h>
// int main()
// {
//     int i=0;
//     for(i=100;i<=200;i++)// 也可以从奇数开始循环，i=101;i<=200;i+=2  这样就不需要判断偶数了
//     {
//         int j=0;
//         int flag=1;//flag用来标记是否是素数，初始值为1，表示假设是素数
//         for(j=2;j<i;j++)//j<=sqrt(i)
//         {
//             if(i%j==0)//如果i能被j整除，说明i不是素数
//             {
//                 flag=0;//把flag的值改为0，表示i不是素数
//                 break;//跳出循环，不需要继续判断了
//             }
//         }
//         if(flag==1)//如果flag的值还是1，说明i是素数
//         {
//             printf("%d\n",i);
//         }
//     }
//     return 0;   
// }

// is_prime(int n)
// {
//     int i=0;
//     for(i=2;i<=sqrt(n);i++)
//     {
//         if(n%i==0)
//         {
//             return 0;//不是素数
//         }
//     }
//     return 1;//是素数
// }



// int main()
// {
//     int i=0;
//     int count=0;
//     for(i=101;i<=200;i+=2)
//     {
//         if (is_prime(i))
//         {
//             printf("%d\n",i);
//             count++;
//         }
//     }
//     printf("100-200之间共有%d个素数\n",count);
//     return 0;
// }

//写一个函数判断是不是闰年
//打印1000——20026之间的闰年


// int is_run(int year)
// {
//     if((year%4==0 && year%100!=0) || year%400==0)//能被四整除且不能被100整除，或者能被400整除的年份是闰年
//     {
//         return 1;//是闰年
//     }
//     else
//     {
//         return 0;//不是闰年
//     }
// }

// int main()
// {
//     int year=0;
//     int count=0;
//     for(year=1000;year<=2026;year++)
//     {
//         if(is_run(year))
//         {
//             count++;
//             printf("%d\n",year);
//         }
//     }
//      printf("1000-2026之间共有%d个闰年\n",count);
// }

//二分查找

// int binary_search(int arr[],int n,int sz)
// {
//     int left=0;
//     int right=sz-1;
//     while(left<=right)
//     {
//         int mid=(left+right)/2;//mid是中间元素的下标
//         if(arr[mid]==n)
//         {
//             return mid;//找到了，返回mid
//         }
//         else if(arr[mid]>n)
//         {
//             right=mid-1;//在左半部分继续查找
//         }
//         else
//         {
//             left=mid+1;//在右半部分继续查找
//         }
//     }
//     return -1;//没有找到，返回-1
// }



// int main()
// {
//     int arr[]={1,2,3,4,5,6,7,8,9,10};
//     int n=9;
//     int sz=sizeof(arr)/sizeof(arr[0]);//计算数组的元素个数，sizeof(arr)表示整个数组的大小，sizeof(arr[0])表示数组中一个元素的大小，两个相除就得到了数组的元素个数
//     //找到了返回下标，找不到返回-1
//     int res=binary_search(arr,n,sz);
//     if(res==-1)
//     {
//         printf("没有找到%d\n",n);
//     }
//     else
//     {
//         printf("找到了%d，位于下标%d\n",n,res);
//     }

//     return 0;
// }

//形参字母可以和实参一样 数组传递给函数时，传递的是数组的地址，
//所以形参是一个指针变量，指向数组的第一个元素，通过指针变量来访问数组的元素  所以在函数内部计算数组参数个数是不正确的

//写一个函数，调用一次，将num加1

// int add(int *num)
// {
//     (*num)++;//把num指向的值加1
//     return 0;
// }


// int main()
// {
//     int num=0;
//     printf("num=%d\n",num);
//     add(&num);
//     printf("num=%d\n",num);//num的值没有改变，因为add函数中的形参是实参的临时拷贝，形参的改变不会影响实参的值，所以num的值还是0
//     add(&num);
//     printf("num=%d\n",num);
    
//     return 0;
// }


//函数定义不可以嵌套

//链式访问

//函数不写返回类型时，默认返回int类型，函数体中没有return语句时，默认返回0

// int main()
// {
//     int len=strlen("hello world");//strlen函数返回字符串的长度，strlen函数需要包含string.h头文件
//     printf("字符串的长度是：%d\n",strlen("hello world"));
//     //把一个函数的返回值作为另一个函数的参数，或者把一个函数的返回值作为另一个函数的返回值，这就是链式访问
//     printf("%d",printf("%d",printf("%d",43))); //printf 返回的结果是字符数
// }

//main函数有三个参数，分别是argc argv envp
//argc表示命令行参数的个数，argv是一个字符串数组，存储了命令行参数，envp是一个字符串数组，存储了环境变量