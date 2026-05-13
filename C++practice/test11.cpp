#include <iostream>
using namespace std;

//运算符重载
//对已有的运算符进行重新定义，赋予新的功能
//1.+号重载
class person
{
    public:

    // //1.成员函数重载  加号+
    // person operator+(person &p) //重载+号，返回值为person类型的对象
    // {
    //     person temp;
    //     temp.m_a=this->m_a+p.m_a; //this指针指向调用成员函数的对象
    //     temp.m_b=this->m_b+p.m_b;
    //     return temp; //返回temp对象
    // }
    //左移运算符重载不会利用成员函数重载，
//因为左移运算符的左边是cout对象，cout对象不是person类的对象，所以只能通过全局函数重载来实现左移运算符的重载





    int m_a;
    int m_b;
};

ostream & operator<<(ostream &out, person &p) //重载左移运算符，返回值为ostream类型的对象，参数为一个ostream类型的对象和一个person类型的对象
{
    out<<p.m_a<<" "<<p.m_b; //通过对象访问成员变量
    return out; //返回out对象
}


//2.全局函数重载
// person operator+(person &p1, person &p2) //重载+号，返回值为person类型的对象，参数为两个person类型的对象
// {
//     person temp;
//     temp.m_a=p1.m_a+p2.m_a; //通过对象访问成员变量
//     temp.m_b=p1.m_b+p2.m_b;
//     return temp; //返回temp对象
// }

// void test1()
// {
//     person p1;
//     p1.m_a=10;
//     p1.m_b=20;
//     person p2;
//     p2.m_a=30;
//     p2.m_b=40;
//     person p3=p1+p2;  //正确，通过重载+号实现两个person对象相加
//     cout<<"成员函数重载: "<<p3.m_a<<", "<<p3.m_b<<endl;
// }

// void test2()
// {
//     person p1;
//     p1.m_a=10;
//     p1.m_b=20;
//     person p2;
//     p2.m_a=30;
//     p2.m_b=40;
//     person p3=p1+p2;  //正确，通过重载+号实现两个person对象相加
//     cout<<"全局函数重载: "<<p3.m_a<<", "<<p3.m_b<<endl;
// }

void test3()
{
    person p1;
    p1.m_a=10;
    p1.m_b=20;
    cout<<"重载左移运算符: "<<p1<<endl; //正确，通过重载左移运算符实现输出person对象
}

int main()
{
    //test1();
    //test2();
    test3();
    return 0;
}



//++重载 前置 后置
//返回引用是为了一直对一个数据进行操作，链式操作；
//myinteger & operator++() //前置++重载，返回值为myinteger类型的引用
//myinteger operator++(int) //后置++重载，返回值为myinteger类型的对象，参数为int类型的占位参数
//int是占位参数是为了区分前置++和后置++，
//后置递增返回值，前置递增返回引用，
//前置递增先递增再返回，后置递增先返回再递增，

//赋值运算符重载

//函数调用运算符重载 （仿函数）
//void operator()(int a, int b) //重载函数调用运算符，返回值为void类型，参数为两个int类型的变量
//匿名函数对象
//cout<<person()(10,10)//正确，通过重载函数调用运算符实现匿名函数对象调用