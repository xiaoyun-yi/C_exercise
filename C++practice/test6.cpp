//函数
//函数的默认参数
#include <iostream>
using namespace std;
#include <string>

//语法：返回值类型 函数名(参数列表 = 默认值)

// int fun(int a, int b, int c)
// {
//     return a + b + c;
// }

// void fun2(int a,int)//占位参数，也可以 int = 10 这个时候调用，可以不传参
// //函数的参数列表中有一个参数没有名字，这个参数叫占位参数，
// //占位参数不能在函数体内使用
// {
//     cout << "fun2函数的参数a的值为：" << a << endl;
// }


// int main()
// {
//     //函数的默认参数
//     //函数的默认参数必须从右向左依次设置，不能跳过某个参数
//     //函数的默认参数只能在函数声明时设置，不能在函数定义时设置
//     //如果函数声明和定义分开了，默认参数只能在声明时设置，定义时不能再设置
//     //函数默认参数 自己传入数据时，用自己的数据，没有就用默认值
//     cout << "fun(1, 2, 3)的值为：" << fun(1, 2, 3) << endl;//6
//     //函数的声明有默认参数，函数实现就不能有默认参数

//     //函数占位参数
//     //语法：返回值类型 函数名(数据类型){}
//     fun2(10,11);//fun2函数的参数a的值为：10


//     system("pause");
//     return 0;
// }

//函数重载
//函数重载是指在同一个作用域中，函数名相同，但参数列表不同的多个函数
//函数重载的满足条件：
//同一个作用域下，函数名相同，参数列表不同（参数个数不同，参数类型不同，参数顺序不同）


// void fun()
// {
//     cout << "fun函数被调用了" << endl;
// }

// int fun(int a)
// {
//     cout << "fun函数被调用了，参数a的值为：" << a << endl;
//     return a;
// }




//注意事项
// //引用作为重载条件
// void fun(int &a)
// {
//     cout << "fun函数被调用了，参数a的值为：" << a << endl;
// }

// void fun(const int &a)
// {
//     cout << "fun函数被调用了，参数a的值为：" << a << endl;
// }

// //函数重载碰到默认参数

// int main()
// {
//     int a = 10;
//     fun(a);//调用void fun(int &a)函数，输出fun函数被调用了，参数a的值为：10
//     fun(20);//调用void fun(const int &a)函数，
//     //因为20是一个常量，不能绑定到非常量引用int &a上，所以只能调用const int &a函数，输出fun函数被调用了，参数a的值为：20



//     system("pause");
//     return 0;
// }

//面向对象编程的特性：封装 继承 多态
//类和对象

//设计一个圆类，求圆的周长
// const double PI = 3.14;

// class circale
// {
//     //访问权限
//     public:
   
   
//     //属性
//     int r;//半径

//     //行为用函数
//     double getZC()//求周长
//     {
//         return 2 * PI * r;
//     }
// };

// int main()
// {
//     circale c1;//创建一个圆对象c1  实例化
//     c1.r = 10;//给圆对象c1的属性r赋值
//     cout << "圆的周长为：" << c1.getZC() << endl;//调用圆对象c1的行为getZC()求周长
//     return 0;
// }

// //学生类
// class student
// {
//     public:
//     string name;//姓名
//     string number;//学号
//     int age;//年龄

//     void show()//显示学生信息
//     {
//         cout << "学生姓名为：" << name << endl;
//         cout << "学生学号为：" << number << endl;
//         cout << "学生年龄为：" << age << endl;   
//     }

//     // void setname(string n)//设置学生姓名
//     // {
//     //     name = n;
//     // }



// };

// int main()
// {
//     student s1;//创建一个学生对象s1
//     s1.name = "张三";//给学生对象s1的属性name赋值
//     //s1.setname("李四");//调用学生对象s1的行为setname()设置学生姓名为李四
//     s1.number = "20210001";//给学生对象s1的属性number赋值
//     s1.age = 20;//给学生对象s1的属性age赋值

//     s1.show();//调用学生对象s1的行为show()显示学生信息
//     return 0;
// }

//访问权限
//公共 成员类内可以访问，类外也可以访问
//私有 成员类内可以访问，类外不可以访问
//保护 成员类内可以访问，类外不可以访问，子类可以访问

// class student
// {
//     //访问权限
//     public:
//     string name;//姓名
//     string number;//学号
//     int age;//年龄
//     protected:
//     string id;//身份证号
//     private:
//     string password;//密码
// };

//struct和class的区别
//struct默认的访问权限是public且不可以放函数，class默认的访问权限是private


//成员属性设置私有
//可以自己控制读写权限
//对于写可以检测数据有效性

class person 
{
public://设置公有方法访问私有属性
    void setname(string n)//设置姓名
    {
        name = n;
    }

    string getname()//获取姓名
    {
        return name;
    }

    int getage()//获取年龄
    {
        return age;
    }
    void setage(int a)//设置年龄
    {
        if (a >= 0 && a <= 150)
        {
            age = a;
        }
        else
        {
            cout << "年龄不合法" << endl;
        }
    }

    void sethobby(string h)//设置爱好
    {
        hobby = h;
    }

private:
    string name; //可读可写
    int age;//只读,  也可以写但是是在0-150之间
    string hobby;//只写
};

int main()
{
    person p1;//创建一个person对象p1
    p1.setname("张三");//调用person对象p1的行为setname()设置姓名为张三
    cout << "姓名为：" << p1.getname() << endl;//调用person对象p1的行为getname()获取姓名并输出
    
    p1.setage(20);//调用person对象p1的行为setage()设置年龄为20
    cout << "年龄为：" << p1.getage() << endl;//调用person对象p1的行为getage()获取年龄并输出，编译错误，因为age是私有属性，不能直接访问
    p1.sethobby("篮球");//调用person对象p1的行为sethobby()设置爱好为篮球

    return 0;
}