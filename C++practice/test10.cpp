#include<iostream>
using namespace std;
//c++对象模型和this指针
//在C++中，类内的成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上
//class里面没有对象时占用1个字节的空间，为了区分空对象占内存的位置
//非静态成员变量在对象上分配内存，
//静态成员变量在类上分配内存，不属于类的对象上
//静态函数，非静态函数也不属于类的对象上
//this指针是一个隐含的指针，指向调用成员函数的对象 
//this指针，哪个对象调用就指向那个对象
//this指针的用途(不需要定义)
//形参和成员变量同名时，this指针可以区分
//在类的非静态成员函数中返回对象本身，可以使用return *this
// class person
// {
// public:
//     person(int a)
//     {
//         this->a=a;
   
//     }
//     int a;
// //   void personage(person &p)
// //     {
// //         this->a+=p.a;
// //     }
//     person& personage(person &p) //person&表示返回值是person类型的引用，返回对象本身 
//     {
//         this->a+=p.a;
//         return *this;
//     }
    
// };

// void test()
// {
//     person p(10);
//     person p1(20);
//    // p1.personage(p);
//    p1.personage(p).personage(p).personage(p);
//     cout<<p1.a<<endl;
// }

// int main()
// {
    
//     test();
//     return 0;
// }


//空指针访问成员函数
//const 修饰成员函数  此时不可以修改成员属性，加上mutable 可以修改成员属性
//常对象只能调用const成员函数，不能调用非const成员函数
// class person
// {
//     public:
//     person()
//     {}
//     void show()
//     {
//         cout<<"show function"<<endl;
//     }

//     void showperson() const //const修饰成员函数，表示该函数不会修改成员变量的值
//     {
//         // this->m_hight=170; //const成员函数不能修改成员变量
//         cout<<"showperson function"<<endl;
//     }

//     void showage()
//     {
//         if(this==NULL) //空指针访问成员函数时，this指针为NULL
//         {
//             return; //直接返回，避免访问成员变量导致崩溃
//         }
//         cout<<"age="<<this->m_age<<endl;
//     }   
//     int m_age;
//     //int m_hight;
//     mutable int m_hight; //mutable修饰成员变量，可以在const成员函数中修改
// };
// void test01()
// {
//     const person p; //常对象
//     //p.m_age=18; //常对象不能修改成员变量，编译器会报错
//     p.m_hight=170; //常对象不能修改成员变量，编译器会报错
//     p.showperson(); //常对象只能调用const成员函数
//     //p.showage(); //常对象不能调用非const成员函数，编译器会报错
//     //p.show(); //常对象不能调用非const成员函数，编译器会报错
// }

// void test()
// {
//     person *p=NULL;
//     p->show(); //空指针访问成员函数，编译器不会报错，运行时会崩溃
//     p->showage(); //空指针访问成员变量，编译器不会报错，运行时会崩溃
// }

// int main()
// {
//     test();
//     return 0;
// }

//友元
//让一个函数或者类，访问另一个类中私有成员
//关键字为friend
//三种实现方式
//1.友元函数
//2.友元类
//3.友元成员函数

class Building
{
    public:
     Building();
     
    friend void goodfriend(Building *building); 
    //友元函数，声明在类内，可以访问类的私有成员
    friend class Buildinggoodfriend; 
    //友元类，声明在类内，可以访问类的私有成员
    friend void Buildinggoodfriend::goodfriend(Building *building); 
    //友元成员函数，声明在类内，可以访问类的私有成员
    string m_sittingroom;
    private:
        
        string m_bedroom;
};

//类外写成员函数
Building::Building()
{
    m_sittingroom="客厅";
    m_bedroom="卧室";
}


class Buildinggoodfriend
{
    public:
    void goodfriend(Building *building)
    {
        cout<<"Buildinggoodfriend class goodfriend function sittingroom: "<<building->m_sittingroom<<endl;
        cout<<"Buildinggoodfriend class goodfriend function bedroom: "<<building->m_bedroom<<endl;
    }
};

void goodfriend(Building *building)
{
    cout<<"goodfriend function sittingroom: "<<building->m_sittingroom<<endl;
    cout<<"goodfriend function bedroom: "<<building->m_bedroom<<endl;
}

void test1()
{
    Building building;
    goodfriend(&building);
}

int main()
{
    test1();
    return 0;
}