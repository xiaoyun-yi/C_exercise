//字符串逆序

#include <stdio.h>
#include <string.h>

// void nixu(char str[]) {
//     int len = strlen(str);
//     for (int i = 0; i < len / 2; i++) 
//     {
//         char temp = str[i];
//         str[i] = str[len - 1 - i];
//         str[len - 1 - i] = temp;
//     }
// }

// int main() {
//     char arr[] = {0};      // 预留足够空间
//     printf("输入一个字符串：\n");
//     scanf("%s", arr);          // 读取一个单词（不含空格）

//     nixu(arr);                 // 原地逆序
//     printf("逆序之后的字符串为：%s\n", arr);
//     return 0;
// }

//将字符串逆序

// void reverse(char *str)
// {
//     char temp=*str;
//     int len=strlen(str);
//     *str=*(str+len-1);
//     *(str+len-1)='\0';
//     if (strlen(str+1)>=2) 
//     {
//         reverse(str+1);
//     }
//     *(str+len-1)=temp;

// }


// int main()
// {
//     char str[]={0};
//     printf("输入一个字符串：\n");
//     scanf("%s", str);
//     reverse(str);
//     printf("逆序之后的字符串为：%s\n",str);
    
//     return 0;
// }

// int digitsum(unsigned int n)
// {
//     if (n == 0) 
//     {
//         return 0;
//     }
//     return (n % 10) + digitsum(n / 10);//c语言中，整数除法会自动向下取整，所以n/10会去掉最后一位数字
// }





// int main()
// {
//     unsigned int n=0;//无符号整数  用于存储非负整数
//     printf("输入一个正整数：\n");
//     scanf("%u", &n);
//     int sum = digitsum(n);
//     printf("数字和为：%d\n", sum);
//     return 0;
// }

//编写一个函数实现n的k次方


// double cifang(int n, int k)
// {
//     if (k == 0)
//     {
//         return 1;
//     }
//     else if(k<0)
//     {
//         return 1.0/cifang(n, -k);
//     }
//     else
//     {
//     return n * cifang(n, k - 1);
//     }
    
// }

// int main()
// {
//     int n=0;
//     printf("输入一个整数n：\n");
//     scanf("%d", &n);
//     int k=0;
//     printf("输入一个整数k：\n");
//     scanf("%d", &k);
//     double m=cifang(n,k);
//     printf("n的k次方为：%lf\n", m);
    
//     return 0;
// }

//逗号表达式 （1，2） 最后输出的是2，字节大小为4  sizeof() 是算字节的长度
//int arr[10] = {0};  // arr的数据类型是 int [10]


//sizeof 是一个操作符，用来计算变量或者数据类型所占的字节数。它在编译时进行计算，
//返回一个 size_t 类型的值，表示对象或类型的大小（以字节为单位）。
//sizeof 可以用于基本数据类型、数组、结构体、指针等。
//strlen 是一个库函数，只能计算字符串长度，不包括\0

// int main()
// {
//     char arr[10] = {0};  // arr的数据类型是 char [10]
//     printf("sizeof(arr) = %zu\n", sizeof(arr));  // 输出数组占用的字节数  10
//     printf("strlen(arr) = %zu\n", strlen(arr));  // 输出字符串的长度（不包括\0）  0
    
//     return 0;
// }

// char acx[]="hello"; //acx的数据类型是 char [6] 包含了\0  存放的字符串
// char acy[]={'h','e','l','l','o'}; //acy的数据类型是 char [5] 不包含\0 存放的是字符

//数组 列不可以省略！！！

// //交换两个数组
// void swap(int arr1[], int arr2[], int size) {
//     for (int i = 0; i < size; i++) {
//         int temp = arr1[i];
//         arr1[i] = arr2[i];
//         arr2[i] = temp;
//     }
// }

// int main()
// {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int arr2[] = {6, 7, 8, 9, 10};
//     int size = sizeof(arr1) / sizeof(arr1[0]); // 计算数组元素的数量
//     swap(arr1, arr2, size);
//     printf("交换后的数组1：");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr1[i]);
//     }
//     printf("\n");
//     printf("交换后的数组2：");
//     for (int i = 0; i < size; i++) {    
//         printf("%d ", arr2[i]);
//     }   
//     return 0;
// }


//创建一个数组，实现函数init print reverse

// void init(int arr[], int size) 
// {
//     for (int i = 0; i < size; i++) 
//     {
//         arr[i] = 0;
//     }
// }

// void print(int arr[], int size) 
// {
//     for (int i = 0; i < size; i++) 
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void reverse(int arr[], int size) 
// {
//     for (int i = 0; i < size / 2; i++) 
//     {
//         int temp = arr[i];
//         arr[i] = arr[size - 1 - i];
//         arr[size - 1 - i] = temp;
//     }
// }


// int main()
// {
//     int arr[5]={1,2,3,4,5};
//     int size = sizeof(arr) / sizeof(arr[0]);
    
//     printf("原来的数组：");
//     print(arr, size);
//     printf("逆序后的数组：");
//     reverse(arr, size); // 逆序数组元素
//     print(arr, size); // 打印逆序后的数组元素
//     init(arr, size); // 初始化数组，所有元素设置为10
//     printf("初始化后的数组：");
//     print(arr, size);
//     printf("\n");       
//     return 0;
// }