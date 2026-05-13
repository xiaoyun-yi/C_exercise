//初始化
//构造函数 析构函数 系统可以自动调用，
//你不创建时系统会默认创建一个无参的构造函数和一个析构函数
#include <iostream>
using namespace std;

//构造函数 语法 类名(参数列表){函数体}
//析构函数 语法 ~类名(){函数体}
//构造函数和析构函数没有返回值 也不能写void

// class Person
// {
//     //构造函数 没有返回值 不能写void
//     //函数名与类名相同
//     //构造函数可以有参数，可以发生重载
//     //创建对象的时候，构造函数会自动调用，只调用一次
//     public:
//     Person()
//     {
//         cout << "构造函数调用" << endl;
//     }
//     //析构函数
//     //函数名与类名相同，在前面加一个~
//     //析构函数没有参数，不能发生重载
//     ~Person()
//     {
//         cout << "析构函数调用" << endl;
//     }
// };

// void test()
// {
//     Person p; // 创建Person对象，会自动调用构造函数
// }

// int main()
// {
   
//     //test(); 
//     Person p; // 创建Person对象，会自动调用构造函数
//     return 0;
// }

//构造函数的分类
//1.按参数分类
//无参构造函数：没有参数的构造函数，系统会默认提供一个
//有参构造函数：带参数的构造函数，系统不会提供

//2.按类型分类
//普通构造函数：最常用的构造函数，直接定义在类中
//拷贝构造函数：用来创建一个对象，并用另一个对象来初始化它
//三种调用方式：括号法，显示法，隐式转换法

// class person
// {
// public:
//     int age;
//     //普通构造函数
//     person()
//     {
//         cout << "普通构造函数调用" << endl;
//     }
//     //有参构造函数
//     person(int a)
//     {
//         age = a;
//         cout << "有参构造函数调用" << endl;
//     }
//     //拷贝构造函数
//     person(const person &p)
//     {
//         //将传入的人身上的属性值赋值给当前对象
//         age=p.age;
//         cout << "拷贝构造函数调用" << endl;
//     }
// };



// int main()
// {
//     //括号法
//     person p1; //调用普通构造函数，调用默认构造函数不要加（）
//     person p2(10); //调用有参构造函数
//     person p3(p2); //调用拷贝构造函数
//     //显示法
//     person p4 = person(20); //调用有参构造函数  
//     //person(20)是一个匿名对象，调用完就销毁了
//     person p6 = person(p2); //调用拷贝构造函数
//     //不要利用拷贝构造函数来初始化匿名对象，因为匿名对象调用完就销毁了，
//     //拷贝构造函数的参数是一个引用类型，引用类型必须有一个对象来引用，
//     //而匿名对象调用完就销毁了，所以会出问题
//     //隐式转换法
//     person p5 = 30; //调用有参构造函数
//     person p7 = p2; //调用拷贝构造函数


//     return 0;
// }

//拷贝构造函数调用时机
//使用一个已经创建完毕的对象来初始化一个新对象
//值传递的方式给函数参数传值
//值方式返回局部对象

// class person
// {
//     public:
//     int s_age;
//     person()
//     {
//         cout << "普通构造函数调用" << endl;
//     }

//     person(int age)
//     {
//         s_age = age;
//         cout << "有参构造函数调用" << endl;
//     }

//     person(const person &p)
//     {
//         s_age = p.s_age;
//         cout << "拷贝构造函数调用" << endl;
//     }

//     ~person()
//     {
//         cout << "析构函数调用" << endl;
//     }


// };

// //使用一个已经创建完毕的对象来初始化一个新对象
// void test01()
// {
//     person p1(10);
//     person p2(p1); //调用拷贝构造函数
//     cout << "p1的年龄为：" << p1.s_age << endl;
//     cout << "p2的年龄为：" << p2.s_age << endl;
// }

// //值传递的方式给函数参数传值
// void dowork(person p) //调用拷贝构造函数
// {
    
// }

// void test02() //调用拷贝构造函数
// {
//     person p1;
//     dowork(p1); //调用拷贝构造函数
// }


// //值方式返回局部对象
// person dowork2()
// {
//     person p1;
//     return p1; //调用拷贝构造函数
// }

// void test03()
// {
//     person p2 = dowork2(); //调用拷贝构造函数
// }



// int main()
// {
    
//     //test01();
//    // test02();
//    test03();
//     return 0;
    
// }

//构造函数调用规则
//默认构造函数（无参数 函数体为空）
//默认析构函数（无参数 函数体为空）
//默认拷贝构造函数，对属性值进行拷贝
//定义了有参构造函数，则不提供无参构造函数了，但是会提供默认拷贝构造函数
//定义了拷贝构造函数，不提供其他构造函数了
class person
{
    public:
    int s_age;
    person()
    {
        cout << "默认构造函数调用" << endl;
    }

    person(int age)
    {
        s_age = age;
        cout << "有参构造函数调用" << endl;
    }

    // person(const person &p)
    // {
    //     s_age = p.s_age;
    //     cout << "拷贝构造函数调用" << endl;
    // }

    ~person()
    {
        cout << "析构函数调用" << endl;
    }
};

void test01()
{
    person p1; //调用默认构造函数
    p1.s_age = 10;
    person p2(p1); //调用有参构造函数
    cout << "p2的年龄为：" << p2.s_age << endl;
}



int main()
{
    test01();
    return 0;
}