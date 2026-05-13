#include<iostream>
using namespace std;
#include<string>

//多态：同一事物的多种形态
//静态多态：函数重载，运算符重载，复用函数名 编译阶段确定函数调用 地址
//动态多态：派生类和虚函数运行时多态  执行阶段确定函数调用地址
//实现动态多态的条件：1.必须有继承关系 2.父类中至少有一个虚函数 
//3.通过父类指针或引用指向子类对象 子类重写父类的虚函数 返回值类型 函数名，参数列表都相同
//虚函数：在父类中使用virtual关键字修饰的成员函数，
//public：
//virtual void func(){}; //虚函数

//父类指针指向子类对象时，发生多态

//用多态实现计算器
//1 常规写法
// class calculator
// {
//     public:

//     int result(string oper)
//     {
//         if(oper=="+")
//         {
//             return num1+num2;
//         }
//         else if(oper=="-")
//         {
//             return num1-num2;
//         }
//         else if(oper=="*")
//         {
//             return num1*num2;
//         }
//         else if(oper=="/")
//         {
//             return num1/num2;
//         }
//         else
//         {
//             cout<<"oper error"<<endl;
//             return 0;
//         }
//     }

//     int num1;
//     int num2;
//     string oper;
// };

// void test1()
// {
//     calculator c;
//     c.num1=10;
//     c.num2=20;
//     c.oper="+";
//     cout<<c.result(c.oper)<<endl;

//     c.oper="-";
//     cout<<c.result(c.oper)<<endl;

//     c.oper="*";
//     cout<<c.result(c.oper)<<endl;

//     c.oper="/";
//     cout<<c.result(c.oper)<<endl;

//     c.oper="%";
//     cout<<c.result(c.oper)<<endl;
// }

// int main()
// {
//     test1();
//     return 0;
// }
//这种想要修改源代码 不方便扩展 维护性差 违反开闭原则（对修改关闭，对扩展开放）


//2 用多态实现计算器

class calculator
{
public:
    virtual int result()=0; //纯虚函数 计算结果的接口 由子类实现
    int num1;
    int num2;
};

class add: public calculator
{
public:
    int result() override
    {
        return num1 + num2;
    }
};

class sub: public calculator
{
public:
    int result() override
    {
        return num1 - num2;
    }
};

void test1()
{
    calculator * c1=new add; //父类指针指向子类对象
    c1->num1=10;
    c1->num2=20;
    cout<<c1->result()<<endl;
    //用完后销毁
    delete c1;
    c1= new sub; //父类指针指向子类对象
    c1->num1=10;
    c1->num2=20;
    cout<<c1->result()<<endl;
    //用完后销毁
    delete c1;

}

int main()
{
    test1();
    return 0;
}


//纯虚函数语法：virtual 返回值类型 函数名(参数列表)=0; 
//=0表示纯虚函数 没有函数体 由子类实现
//纯虚函数所在的类叫抽象类 抽象类不能实例化对象 只能用来被继承 
//由子类实现纯虚函数后才能实例化对象

//类里面有纯虚函数 这个类就是抽象类，不能实例化对象 只能用于继承
//子类必须重写父类的纯虚函数才能实例化对象
//如果子类没有重写父类的纯虚函数 那么子类也是抽象类 不能实例化对象 只能用于继承

//相当于不可以建立对象

//虚析构 纯虚析构
//多态使用时，如果子类中有属性开辟到堆区，父类指针在释放时无法调用到子类的析构代码
//将父类的析构函数改为虚析构或者纯虚析构
//虚析构和纯虚析构的共性：解决父类指针释放子类对象无法调用析构函数  都需要具体的函数实现
//区别：纯虚析构 属于抽象类，无法实例化对象
//虚析构语法 
//virtual ~calculator()
//{cout<<"xxxxx"<<endl;}

//纯虚析构
//virtual ~calculator () = 0; 有声明 也要有实现
//calculator::~calculator() //纯虚析构的实现
//{ cout<<"calculator pure virtual destructor"<<endl;}


