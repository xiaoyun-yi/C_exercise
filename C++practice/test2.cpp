#include <iostream>
using namespace std;

//数组
//数据类型 数组名[元素个数]
//数据类型 数组名[元素个数] = {元素1，元素2，元素3...}
//数据类型 数组名[] = {元素1，元素2，元素3...} //编译器根据初始化列表的元素个数自动推断数组的大小
// int main()
// {
//     int arr1[]={1,2,3,4};
//     cout << arr1 << endl;//访问的是数组的首地址
//     cout << &arr1[0] << endl;//访问的是数组的首地址
// }

//找一个数组里面的最大值
// int main()
// {
//     int arr[] = {1, 5, 3, 9, 2};
//     int max = arr[0]; //假设第一个元素是最大值
//     for(int i = 1; i < sizeof(arr)/sizeof(arr[0]); i++)
//     {
//         if(arr[i] > max)
//         {
//             max = arr[i]; //更新最大值
//         }
//     }
//     cout << "数组中的最大值是：" << max << endl;

//     system("pause");
//     return 0;
// }


// //数组元素逆序
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     for(int i = 0; i < size / 2; i++)
//     {
//         int temp = arr[i]; //交换arr[i]和arr[size - 1 - i]
//         arr[i] = arr[size - 1 - i];
//         arr[size - 1 - i] = temp;
//     }
//     cout << "数组元素逆序后是：";
//     for(int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     system("pause");
//     return 0;
// }


// //冒泡排序 升序
// int main()
// {
//     int arr[] = {5, 2, 9, 1, 5, 6};
//     int size = sizeof(arr) / sizeof(arr[0]);//排序的总趟数等于元素个数减一
//     for(int i = 0; i < size - 1; i++)
//     {
//         for(int j = 0; j < size - 1 - i; j++)//交换的次数等于元素个数减一减去已经排序好的趟数
//         {
//             if(arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     cout << "数组元素升序排列后是：";
//     for(int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     system("pause");
//     return 0;
// }


//二维数组  必须要有列数
//数据类型 数组名[行数][列数]
//数据类型 数组名[行数][列数] = {{元素11, 元素12, ...}, {元素21, 元素22, ...}, ...}
//数据类型 数组名[][列数] = {{元素11, 元素12, ...}, {元素21, 元素22, ...}, ...} 
//cout <<sizeof(arr[0]) << endl;//打印第一行的大小
// cout <<sizeof(arr[0][0]) << endl;//打印第一行第一个元素的大小

// int main()
// {
//     int arr[3][3]={
//         {10,10,10},{20,20,20},{30,10,20}
//     };
//     string name[3]={"a","b","c"};
//     for(int i=0;i<3;i++)
//     {
//         int sum=0;
//         for(int j=0;j<3;j++)
//         {
//             sum+=arr[i][j];
            
//         }
//         cout<<name[i]<<" 总分："<<sum<<endl;
//     }
            
//     system("pause");
//     return 0;
// }

//函数
//函数声明 在函数的前面声明函数的原型
//函数写在调用的后面，要在最前面加个声明  int max(int a, int b);
//声明可以写多次

//指针大小 根据操作系统分为4个字节或者8个字节

//空指针 给指针变量初始化
//空指针不可以进行访问

//野指针，指向非法的空间,避免出现
//int * p = (int*)0x1100;
//cout<<*p<<endl;

//const修饰指针
//const修饰常量
//const即修饰指针，又修饰常量

// int main()
// {
//     const int a = 10; //a是一个常量，值为10
//     const int *p1 = &a; //p1是一个指向常量的指针，常量指针，可以修改指针的指向，但不能通过指针修改所指向的值
//     int *const p2 = (int*)&a; //p2是一个指针常量，必须初始化，不能修改指针的指向，但可以通过指针修改所指向的值
//     const int *const p3 = &a; //p3是一个常量指针，必须初始化，不能修改指针的指向，也不能通过指针修改所指向的值

//     cout << "a: " << a << endl;
//     cout << "*p1: " << *p1 << endl;
//     cout << "*p2: " << *p2 << endl;
//     cout << "*p3: " << *p3 << endl;

//     // *p1 = 20; //错误，不能通过p1修改a的值
//     // p1 = &b; //正确，可以修改p1的指向

//     // *p2 = 20; //正确，可以通过p2修改a的值
//     // p2 = &b; //错误，不能修改p2的指向

//     // *p3 = 20; //错误，不能通过p3修改a的值
//     // p3 = &b; //错误，不能修改p3的指向

//     system("pause");
//     return 0;
// }

//int * const p = &a; 
//p是一个指针常量，必须初始化，不能修改指针的指向，但可以通过指针修改所指向的值
//const int *p = &a; //p是一个指向常量的指


//冒泡排序函数
// void maopao(int *arr,int len)
// {
//     for(int i = 0; i < len - 1; i++)
//     {
//         for(int j = 0; j < len - 1 - i; j++)
//         {
//             if(arr[j] > arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     cout << "数组元素升序排列后是：";
//     for(int i = 0; i < len; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }


// int main()
// {
//     int arr[10]={1,2,13,4,15,6,17,8,19,10};
//     int len = sizeof(arr)/sizeof(arr[0]);
//     maopao(arr,len);
//     system("pause");
//     return 0;
// }
