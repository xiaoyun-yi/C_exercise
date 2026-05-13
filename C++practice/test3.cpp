//结构体
#include<iostream>
using namespace std;
#include<string>
// struct Student
// {
//     string name;
//     int age;
//     float score;
// };
// int main()
// {


//     struct Student s1; //定义一个结构体数组，包含3个学生的信息
//     s1.name = "张三";
//     s1.age = 20;
//     s1.score = 85.5;
//     cout << "学生姓名：" << s1.name << endl;
//     cout << "学生年龄：" << s1.age << endl;
//     cout << "学生分数：" << s1.score << endl;

//     //结构体数组
//     struct Student students[3] = {
//         {"张三", 20, 85.5},
//         {"李四", 22, 90.0},
//         {"王五", 21, 88.0}
//     };
//     for(int i = 0; i < 3; i++)
//     {
//         cout << "学生姓名：" << students[i].name << endl;
//         cout << "学生年龄：" << students[i].age << endl;
//         cout << "学生分数：" << students[i].score << endl;
//     }

//     //结构体指针
//     struct Student *ps = &s1; //定义一个结构体指针，指向s1
//     cout << "学生姓名：" << ps->name << endl;
//     cout << "学生年龄：" << ps->age << endl;
//     cout << "学生分数：" << ps->score << endl;

    


//     struct Student s2 = {"李四", 22, 90.0}; //定义一个结构体变量，并初始化
//     cout << "学生姓名：" << s2.name << endl;
//     system("pause");
//     return 0;
// }

//结构体嵌套结构体
// struct student
// {
//     string name;
//     int age;
//     float score;
// };
// struct class1
// {
//     string classname;
//     struct student s;
// };

// void printstudent1(struct student s)
// {
//     cout << "学生姓名：" << s.name << endl;
//     cout << "学生年龄：" << s.age << endl;
//     cout << "学生分数：" << s.score << endl;
// }

// void printstudent2(struct student *ps)
// {
//     cout << "学生姓名：" << ps->name << endl;
//     cout << "学生年龄：" << ps->age << endl;
//     cout << "学生分数：" << ps->score << endl;
// }

// int main()
// {
//     struct class1 c1 = {"一班", {"张三", 20, 85.5}}; //定义一个结构体变量，并初始化
//     cout << "班级名称：" << c1.classname << endl;
//     cout << "学生姓名：" << c1.s.name << endl;
//     cout << "学生年龄：" << c1.s.age << endl;
//     cout << "学生分数：" << c1.s.score << endl;

//     printstudent1(c1.s);
//     printstudent2(&c1.s);

//     system("pause");
//     return 0;
// }

//结构体中const的使用

// struct student
// {
//     string name;
//     int age;
//     float score;
// };

// void printstudent(const struct student s)
// {
//     cout << "学生姓名：" << s.name << endl;
//     cout << "学生年龄：" << s.age << endl;
//     cout << "学生分数：" << s.score << endl;
// }

// int main()
// {
//     const struct student s1 = {"张三", 20, 85.5}; //定义一个结构体变量，并初始化
//     cout << "学生姓名：" << s1.name << endl;
//     cout << "学生年龄：" << s1.age << endl;
//     cout << "学生分数：" << s1.score << endl;

//     //s1.name = "李四"; //错误，不能修改const结构体变量的成员
//     //const 不能修改结构体的内容

//     system("pause");
//     return 0;
// }


//每名老师带五个学生，
//有三个老师，老师结构体里面有老师的名字和五个学生的的姓名，考试分数
//创建数组存放3名老师，通过函数给每个老师及所带的学生赋值，
//最终打印老师的数据和所带学生的数据

// struct student
// {
//     string name;
//     float score;
// };

// struct teacher
// {
//     string name;
//     struct student s[2];
// };

// void allocate( struct teacher teachers[],int len1,int len2)
// {
//     string nameseed="ASDFG";
//     for(int i = 0; i < len1; i++)
//     {
//         cout << "请输入第" << i + 1 << "名老师的姓名：" << endl;
//         cin >> teachers[i].name;
//         for(int j = 0; j < len2; j++)
//         {
//             teachers[i].s[j].name="student_";
//             teachers[i].s[j].name+=nameseed[j];
            
//             int random = rand()%61 +40;
//             teachers[i].s[j].score=random;
            
            
//             // cout << "请输入第" << j + 1 << "个学生的姓名和分数：" << endl;
//             // cin >> teachers[i].s[j].name >> teachers[i].s[j].score;
//         }
//     }
// }

// void printallocate(struct teacher teachers[],int len1,int len2)
// {
//     for(int i = 0; i < len1; i++)
//     {
//         cout << "第" << i + 1 << "名老师的姓名：" << teachers[i].name << endl;
//         for(int j = 0; j < len2; j++)
//         {
//             cout << "第" << j + 1 << "个学生的姓名和分数：" << teachers[i].s[j].name << " " << teachers[i].s[j].score << endl;
//         }
//     }

// }

// #include<Ctime>

// int main()
// {
//     //随机数种子
//     srand((unsigned int )time(NULL));
//     struct teacher teachers[3]; //定义一个结构体数组，包含3名老师的信息
//     int len1 = sizeof(teachers) / sizeof(teachers[0]);
//     int len2 = sizeof(teachers[0].s) / sizeof(teachers[0].s[0]);
//     allocate(teachers, len1,len2);
//     printallocate(teachers, len1,len2);
//     system("pause");
//     return 0;
// }


//例题2

struct hero
{
    string name;
    int age;
    string sex;
};

void bubblesort (struct hero heroo[],int len)
{
    for(int i = 0; i<len-1; i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(heroo[j].age>heroo[j+1].age)
            {
                struct hero temp=heroo[j];
                heroo[j]=heroo[j+1];
                heroo[j+1]=temp;
            }
        }
    }

}

void printhero(struct hero heroo[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<"姓名："<<heroo[i].name<<" 年龄："<<heroo[i].age<<" 性别："<<heroo[i].sex<<endl;
    }
}

int main()
{
    struct hero heroo[3]=
    {
        {"qq",3,"q"},
        {"ww",4,"w"},
        {"rr",1,"r"},
    };
    int len = sizeof(heroo) / sizeof(heroo[0]);
    bubblesort(heroo,len);
    printhero(heroo,len);

    system("pause");
    return 0;
}