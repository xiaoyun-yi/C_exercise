//代码区
//代码区共享，只读



//全局区域  存放全局变量，静态变量和常量(字符串，const修饰的全局常量)，
//操作系统决定何时释放

//栈区 不要返回局部变量的地址
// 这部分的数据由编译器管理

//堆区
// 这部分的数据由程序员管理，使用new分配，使用delete释放

#include <iostream>
using namespace std;

// int g_a = 10;//全局变量
// const int c_a = 10;//全局常量

// int *func()
// {
//     // int a = 10;//局部变量
//     // return &a;//返回局部变量的地址，错误的做法

//     int *p = new int(10);//在堆区分配一个整数，正确的做法
//     return p;//返回堆区变量的地址
// }

// int main()
// {
//     //全局变量
//     int a = 10;//局部变量
//     int *p = func();
//     cout << "堆区变量的值为：" << *p << endl;

//     static int s_a = 10;//静态变量

//     //字符串常量
//     cout << "字符串常量地址为：" << (int)&"hello world" << endl;

//     //const 修饰的变量
//     const int c_b = 10;//局部常量
//     cout << "局部常量c_b地址为：" << (int)&c_b << endl;

//     system("pause");
//     return 0;
// }

// int main()
// {
//     //new的基本语法
//     //new返回的是该数据类型的指针
//     int *p = new int(10);//在堆区分配一个整数，并初始化为10
//     cout << "堆区变量的值为：" << *p << endl;
//     //利用delete释放堆区内存
//     delete p;//释放p指向的内存

//     //在堆区利用new开辟一个数组
//     int *arr = new int[5];//在堆区分配一个包含5个整数的数组
//     for(int i = 0; i < 5; i++)
//     {
//         arr[i] = i * 10;
//         cout << "数组元素" << i << "的值为：" << arr[i] << endl;
//     }
//     //利用delete[]释放堆区内存
//     delete[] arr;//释放arr指向的内存

//     system("pause");
//     return 0;
// }





//引用
//引用必须初始化，且一旦绑定到一个变量，就不能再绑定到其他变量
//引用本质上是一个别名，编译器会将对引用的操作转换为对其绑定变量的操作
//语法： 数据类型 &别名 = 原名
//int a = 10;
//int &b = a;//b是a的引用，b和a是同一个变量的两个名字
//cout << "a的值为：" << a << endl;
//cout << "b的值为：" << b << endl; 

// int main()
// {
//     int a = 10;
//     int &b = a;//b是a的引用，b和a是同一个变量的两个名字 
//     //引用必须初始化，必须有个值，且一旦绑定到一个变量，就不能再绑定到其他变量
//     cout << "a的值为：" << a << endl;
//     cout << "b的值为：" << b << endl;
//     system("pause");
//     return 0;
// }

//引用做函数的参数
//函数传参时，利用引用的技术让形参修饰实参  可以简化指针

// void swap1(int a, int b)//值传递，交换失败
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }
// void swap2(int &a, int &b)//引用传递，交换成功
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }
// void swap3(int *a, int *b)//指针传递，交换成功
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }


// int main()
// {
//     int a = 10;
//     int b = 20;
//     swap1(a, b);
//     cout << "swap1 a的值为：" << a << endl;
//     cout << "swap1 b的值为：" << b << endl;//依旧是a=10,b=20


//     swap2(a, b);
//     cout << "swap2 a的值为：" << a << endl;
//     cout << "swap2 b的值为：" << b << endl;//交换后a=20,b=10

//     swap3(&a, &b);
//     cout << "swap3 a的值为：" << a << endl;
//     cout << "swap3 b的值为：" << b << endl;//交换后a=10,b=20

//     system("pause");
//     return 0;
// }

//引用做函数的返回值
//不要返回局部变量的引用
// int & test1()
// {
//     int a = 10;//局部变量存放在栈区
//     return a;//返回局部变量的值，正确的做法
//     // return &a;//返回局部变量的地址，错误的做法
// }

// //函数返回的是a的引用


// int & test2()
// {
//     static int a = 10;//存放在全局区， 程序执行完才会释放
//     return a;//返回局部变量的值，正确的做法  
// }


// int main()
// {
//     // int & ref = test1();
//     // cout << "test1函数返回的值为：" << ref << endl;//这个没有结果，
//     // //因为a已经被释放了，ref是一个悬空引用，访问它会导致未定义行为
//     // cout << "test1函数返回的值为：" << ref << endl;

//     int & ref2 = test2();
//     cout << "test2函数返回的值为：" << ref2 << endl;
//     test2() = 20;//通过引用修改了test2函数中的静态变量a的值
//     //如果函数的返回值是引用，这个函数调用可以作为左值
//     cout << "test2函数返回的值为：" << ref2 << endl;//输出20


//     system("pause");
//     return 0;
// }



//引用的本质是一个别名，编译器会将对引用的操作转换为对其绑定变量的操作
//在C++内部实现是一个指针常量

// void fun(int &ref)
// {
//     ref = 20;//通过引用修改了实参的值
// }

// int main()
// {
//     int a = 10;
//     int& ref = a;//ref是a的引用，ref和a是同一个变量的两个名字
//     ref = 20;//通过引用修改了a的值
//     cout << "main函数中a的值为：" << a << endl;
//     //cout << "main函数中a的地址为：" << (int)&a << endl;
//     fun(a);
//     cout << "main函数中a的值为：" << a << endl;
//     system("pause");
//     return 0;

// }

//常量引用
//常量引用可以绑定到右值上，普通引用不行
//常量引用可以绑定到临时对象上，普通引用不行

int main()
{
    int a = 10;
    //int &ref = 10;//这是不可以的，普通引用不能绑定到右值上，引用必须指向合法的内存地址
    // const int &ref = 10;//这是可以的，常量引用可以绑定到右值上，
    // //编译器会在内存中创建一个临时对象来存储这个右值，并将ref绑定到这个临时对象上
    // ref = 20;//这是不可以的，常量引用不能修改其绑定的对象的值



    const int &ref1 = a;//常量引用可以绑定到左值上
    cout << "ref1的值为：" << ref1 << endl;

    const int &ref2 = 20;//常量引用可以绑定到右值上
    cout << "ref2的值为：" << ref2 << endl;

    const int &ref3 = a + 10;//常量引用可以绑定到临时对象上
    cout << "ref3的值为：" << ref3 << endl;

    system("pause");
    return 0;
}

    