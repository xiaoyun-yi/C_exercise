#include<iostream>
using namespace std;
#include<string>

//设计立方体类
//求出立方体的面积和体积
//用全局函数和成员函数判断两个立方体是否相等

// class lifang
// {
// private:
//     double l;
//     double w;
//     double h;

// public:

//     void setl(double l1)
//     {
//         l = l1;
//     }
//     void setw(double w1)
//     {
//         w = w1;
//     }
//     void seth(double h1)
//     {
//         h = h1;
//     }

//     double getl()
//     {
//         return l;
//     }
//     double getw()
//     {
//         return w;
//     }
//     double geth()
//     {
//         return h;
//     }



//     double v()
//     {
//         return l * w * h;
//     }

//     double s()
//     {
//         return 2 * (l * w + l * h + w * h);
//     }
// //利用成员函数判断两个立方体是否一样
//     bool issame(lifang &cube)
//     {
//         if (l == cube.getl() && w == cube.getw() && h == cube.geth())
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }






// };

// //利用全局函数判断两个立方体是否相等
// bool issame(lifang &cube1,lifang &cube2)
// {
//     if (cube1.getl() == cube2.getl() && cube1.getw() == cube2.getw() && cube1.geth() == cube2.geth())
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// int main()
// {
//     lifang cube1, cube2;
//     cube1.setl(2);
//     cube1.setw(3);
//     cube1.seth(4);
//     cout<<"cube1的体积为："<<cube1.v()<<endl;
//     cout<<"cube1的表面积为："<<cube1.s()<<endl;

//     cube2.setl(2);
//     cube2.setw(3);
//     cube2.seth(4);

//     bool ret = issame(cube1,cube2);
//     if(ret)
//     {
//         cout<<"这两个立方体是相等的"<<endl;
//     }
//     else
//     {
//         cout<<"这两个立方体是不相等的"<<endl;
//     }
    
//     ret = cube1.issame(cube2);
//     if(ret) 
//     {
//         cout<<"这两个立方体是相等的"<<endl;
//     }
//     else
//     {
//         cout<<"这两个立方体是不相等的"<<endl;
//     }

//     system("pause");
//     return 0;
// }
#include<cmath>

//点和圆的关系
//设计一个圆类和点类，计算点和圆的关系
//点类
// class point
// {
//     private:
//         float x;
//         float y;
//     public:
//         void setx(float x1)
//         {
//             x = x1;
//         }
//         void sety(float y1)
//         {
//             y = y1;
//         }
//         float getx()
//         {
//             return x;
//         }
//         float gety()
//         {
//             return y;
//         }
// };
#include "test7point.h"

class circle
{
private:
    float r;
    point center;
public:
    void setr(float r1)
    {
        r = r1;
    }
    float getr()
    {
        return r;
    }

    void setcenter(float x1,float y1)
    {
        center.setx(x1);
        center.sety(y1);
    }

    point getcenter()
    {
        return center;
    }
};

//判断点和圆的关系
void relation(point &p,circle &c)
{
    float distance = sqrt(pow(p.getx() - c.getcenter().getx(), 2) + pow(p.gety() - c.getcenter().gety(), 2));
    if (distance < c.getr())
    {
        cout << "点在圆内" << endl;
    }
    else if (distance == c.getr())
    {
        cout << "点在圆上" << endl;
    }
    else
    {
        cout << "点在圆外" << endl;
    }
}

int main()
{
    point p;
    p.setx(3);
    p.sety(3);

    circle c;
    c.setr(3);
    c.setcenter(0, 0);

    relation(p, c);

    system("pause");
    return 0;
}