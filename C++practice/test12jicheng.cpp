#include <iostream>
using namespace std;

//继承实现
//语法 class 子类（派生类）：继承方式 父类（基类）
//继承方式：public（公有继承）  protected（保护继承）  private（私有继承）
//公共继承：父类的公有成员和保护成员在子类中保持不变，父类的私有成员在子类中不可访问
//保护继承：父类的公有成员和保护成员在子类中变为保护成员，父类的私有成员在子类中不可访问
//保护继承，类外也不可以访问
//私有继承：父类的公有成员和保护成员在子类中变为私有成员，父类的私有成员在子类中不可访问
// class basepage
// {
//     public:
//     void header()
//     {
//         cout<<"guangye header"<<endl;
//     }

//     void footer()
//     {
//         cout<<"guangye footer"<<endl;
//     }

//     void left()
//     {
//         cout<<"guangye left"<<endl;
//     }


// };

// class osborn: public basepage //osborn类继承basepage类，public表示公有继承
// {
//     public:
//     void content()
//     {
//         cout<<"osborn content"<<endl;
//     }
// };

// class evan: public basepage //evan类继承basepage类，public表示公有继承
// {
//     public:
//     void content()
//     {
//         cout<<"evan content"<<endl;
//     }
// };

// void test1()
// {
//     osborn o;
//     o.header();
//     o.footer();
//     o.left();
//     o.content();

//     evan e;
//     e.header();
//     e.footer();
//     e.left();
//     e.content();
// }

// int main()
// {
//     test1();
//     return 0;
// }


//继承中的对象模型
//VS里面 利用开发人员命令提示工具查看对象模型
//跳转到对硬盘 D：
//cd D:\Desktop\practice\C\.vscode\ctest\C++practice
//cl /d1 reportSingleClassLayout类名 文件名.cpp

//继承中的构造和析构函数
//先构造父类 ，接着子类，然后析构子类，最后父类

//子类和父类有同名的参数，直接打印的是子类的参数，
//如果想打印父类的参数，可以通过作用域运算符访问父类的成员变量  son.father::m_a
//同名成员函数，直接调用的是子类的成员函数，
//如果想调用父类的成员函数，可以通过作用域运算符访问父类的成员函数  son.father::func()
//子类和父类有同名的成员变量和成员函数，子类会隐藏父类的成员变量和成员函数，
//如果想访问父类的成员变量和成员函数，可以通过作用域运算符


//同名静态成员变量的访问，静态成员变量要在类外初始化（加上作用域）
//son.father::s_a 访问父类的静态成员变量  通过对象访问
//son::father::s_a 访问父类的静态成员变量  第一个：：表示通过类名访问，第二个表示作用域

//同名静态成员函数的访问（加上作用域）
//son.father::func() 访问父类的静态成员函数  通过对象访问
//son::father::func() 访问父类的静态成员函数  第一个：：表示通过类名访问，第二个表示作用域

//可以继承多个类
//语法 class 子类（派生类）：继承方式 父类1（基类1），继承方式 父类2（基类2），继承方式 父类3（基类3）
//如果多个父类中有同名的成员变量和成员函数，子类会隐藏父类的成员变量和成员函数，
//如果想访问父类的成员变量和成员函数，可以通过作用域运算符

//菱形继承 
//两个子类继承同一个父类，第三个子类同时继承这两个子类，形成菱形继承
//解决菱形继承问题：虚继承
//语法 class 子类（派生类）：继承方式 virtual 父类（基类）
//虚继承后，父类的成员变量和成员函数在子类中只有一份，
//子类通过作用域运算符访问父类的成员变量和成员函数时，
//编译器会自动判断访问的是哪一个父类的成员变量和成员函数

class animal{};

class dog: virtual public animal{
    public:
    int m_a; //同名成员变量
    void func() //同名成员函数
    {
        cout<<"dog func"<<endl;
    }
};

class cat: virtual  public animal{
    public:
    int m_a; //同名成员变量
    void func() //同名成员函数
    {
        cout<<"cat func"<<endl;
    }
};

// class son: public dog, public cat //son类同时继承dog类和cat类，形成菱形继承
// {
//     public:
//     int m_a; //同名成员变量
//     void func() //同名成员函数
//     {
//         cout<<"son func"<<endl;
//     }
// };

class son: public dog, public cat //son类同时继承dog类和cat类，形成菱形继承
{
    public:
    int m_a; //同名成员变量
    void func() //同名成员函数
    {
        cout<<"dog func"<<endl;
    }
};

void test2()
{
    son s;
    s.m_a=10; //访问son类的成员变量
    s.func(); //访问son类的成员函数

    s.dog::m_a=20; //访问dog类的成员变量
    s.dog::func(); //访问dog类的成员函数

    s.cat::m_a=30; //访问cat类的成员变量
    s.cat::func(); //访问cat类的成员函数

    cout<<"son m_a: "<<s.m_a<<endl;
    cout<<"dog m_a: "<<s.dog::m_a<<endl;
    cout<<"cat m_a: "<<s.cat::m_a<<endl;
}

int main()
{
    test2();
    return 0;
}
