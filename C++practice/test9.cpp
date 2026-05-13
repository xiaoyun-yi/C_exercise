#include<iostream>
using namespace std;
//深拷贝和浅拷贝
//浅拷贝：默认的拷贝构造函数，直接复制对象的成员变量，
//如果成员变量是指针，那么就会复制指针的地址，导致多个对象指向同一块内存，
//可能会出现问题
//深拷贝：自己定义的拷贝构造函数，复制对象的成员变量，
//如果成员变量是指针，那么就会复制指针指向的内容，保证每个对象都有自己的内存空间

// class person
// {

//     public:
//     int s_age;  
//     int *m_height; //指针成员变量
//     person()
//     {
//         cout << "默认构造函数调用" << endl;
//     }
//     person(int age,int height)
//     {
//         s_age=age;
//         m_height=new int(height); //为指针成员变量分配内存  这个内存在堆区需要手动释放
//         //new int(height)表示分配一个int类型的内存，并初始化为height
//         cout << "有参构造函数调用" << endl;
//     }

// //浅拷贝会导致内存再次释放，从而产生问题
// //自己实现拷贝函数，解决浅拷贝问题，进行深拷贝
//     person(const person &p)//释放堆区的内存，重新分配内存，并复制内容
//     {
//         s_age = p.s_age;
//         m_height = new int(*p.m_height); //为指针成员变量分配内存，并复制内容
//         cout << "拷贝构造函数调用" << endl;
//     }
//     ~person()
//     {
//         cout << "析构函数调用" << endl;
//         if(m_height!=nullptr)
//         {
//             delete m_height; //手动释放堆区内存
//             m_height=nullptr;
//         }
//     }
// };

// void test01()
// {
//     person p1(10,180);
//     person p2(p1); //调用默认的拷贝构造函数，浅拷贝
//     cout << "p1的年龄为：" << p1.s_age << endl;
//     cout << "p1的身高为：" << *p1.m_height << endl;
//     cout << "p2的年龄为：" << p2.s_age << endl;
//     cout << "p2的身高为：" << *p2.m_height << endl;
// }

// int main()
// {
//     test01();

//     return 0;
// }

//初始化列表
//语法：构造函数（）：成员变量（参数），成员变量（参数）...{}
// class person
// {
//     public:
//     int s_age;
//     person()
//     {
//         cout << "默认构造函数调用" << endl;
//     }

//     person(int age):s_age(age) //初始化列表，直接在冒号后面初始化成员变量
//     {
//         cout << "有参构造函数调用" << endl;
//     }

//      person(const person &p):s_age(p.s_age) //拷贝构造函数，使用初始化列表
//      {
//          cout << "拷贝构造函数调用" << endl;
//      }

//      ~person()
//      {
//          cout << "析构函数调用" << endl;
//      }
// };


//类对象作为类成员
// class A{};

// class B{
//     A a; //类对象作为类成员，调用构造函数和析构函数
// };
//其他类作为本类对象时，先构造对象成员，再构造本类对象，析构时先析构本类对象，再析构对象成员
// class phone
// {
//     public:
//     string brand;
//     int price;
//     phone()
//     {
//         cout << "1默认构造函数调用" << endl;
//     }
//     phone(string brand,int price):brand(brand),price(price) //初始化列表
//     {
//         cout << "1有参构造函数调用" << endl;
//     }
//      phone(const phone &p):brand(p.brand),price(p.price) //拷贝构造函数，使用初始化列表
//      {
//          cout << "拷贝构造函数调用" << endl;
//      }
//         ~phone()
//         {
//             cout << "1析构函数调用" << endl;
//         }
// };

// class person
// {
//     public:
//     person(string name,string brand,int price):name(name),phone1(brand,price) //初始化列表，直接在冒号后面初始化成员变量
//     {
//         cout << "2有参构造函数调用" << endl;
//     }
//      person(const person &p):name(p.name),phone1(p.phone1) //拷贝构造函数，使用初始化列表
//      {
//          cout << "拷贝构造函数调用" << endl;
//      }
//     ~person()
//     {
//         cout << "2析构函数调用" << endl;
//     }
//     string name;
//     int age;
//     phone phone1; //类对象作为类成员

// };

// void test01()
// {
//     person p1("张三","华为",2000);
//     person p2(p1); //调用拷贝构造函数
// }

// int main()
// {
//     test01();

//     return 0;
// }

//静态成员
//在成员变量和成员函数前加上关键字static，
//静态成员属于类，不属于对象，所有对象共享同一份数据
//静态成员变量在类内声明，在类外初始化，必须加上类名
//静态成员变量：所有对象共享同一份数据，在编译阶段分配内存，类内声明，类外初始化
//静态成员函数，所有对象共享同一个函数，静态成员函数只能访问静态成员变量

// class person
// {
//     public:
//     static int s_age;
//     int s_weight;
//     private:
//     static int m_height;
//  public:
//     static void func()
//     {
//         s_age=20; //静态成员函数可以访问静态成员变量
//         //s_weight=150; //静态成员函数不能访问非静态成员变量
//         //m_height=180; //静态成员函数不能访问私有的静态成员变量
//         cout << "成员函数调用" << endl;
//     }

// };

// int person:: s_age=10;
// int person:: m_height=180; //静态成员变量在类外初始化，必须加上类名
// void test01()
// {
//     person p1;
//     cout<<p1.s_age<<endl;
//     person p2;
//     p2.s_age=20;
//     cout<<p1.s_age<<endl; //静态成员变量被所有对象共享
    
// }

// void test02()
// {
//     //静态成员变量 不属于某个对象上，所有对象都共享同一份数据
//     //静态成员变量有两种访问方式
//     //1.通过对象访问
//     person p1;
//     cout<<p1.s_age<<endl;
//     //2.通过类名访问
//     cout<<person::s_age<<endl;

//     //cout<<person::m_height<<endl; 
//     //静态成员函数只能访问静态成员变量，不能访问非静态成员变量
//     //私有也不可以访问

// }

// void test03()
// {
//     //静态成员函数只能访问静态成员变量，不能访问非静态成员变量
//     //静态成员函数只能访问静态成员变量，不能访问非静态成员变量
//     person p;
//     person::func(); //通过类名访问静态成员函数
//     p.func(); //通过对象访问静态成员函数，
//     //虽然可以访问，但不推荐使用对象访问静态成员函数
// }

// int main()
// {
//     // test01();
//     // test02();
//     test03();
//     return 0;
// }