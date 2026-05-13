//通讯录系统
//添加联系人
//显示联系人
//删除联系人
//查找
//修改
//清空
//退出

#include <iostream>
#include <string>
using namespace std;


struct person
{
    string name;
    int age;
    string sex;
    string phone;
    string address;
};

struct addressbooks
{
    person per[1000];//通讯录中的联系人数组
    int size;//记录当前通讯录中人数
};


void manu()
{
    cout << "*************************" << endl;
    cout << "*****1.添加联系人*********" << endl;
    cout << "*****2.显示联系人*********" << endl;
    cout << "*****3.删除联系人*********" << endl;
    cout << "*****4.查找联系人*********" << endl;
    cout << "*****5.修改联系人*********" << endl;
    cout << "*****6.清空联系人*********" << endl;
    cout << "*****0.退出通讯录系统*****" << endl;
    cout << "*************************" << endl;
}


void addperson(addressbooks *abs)
{
    if(abs->size == 1000)
    {
        cout << "通讯录已满，无法添加联系人" << endl;
        return;
    }
    else
    {
        string name;//临时存储姓名
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->per[abs->size].name = name;

        int age;
        cout << "请输入年龄：" << endl;
        cin >> age;
        abs->per[abs->size].age = age;

        string sex;
        cout << "请输入性别：" << endl;
        cin >> sex;
        abs->per[abs->size].sex = sex;

        string phone;
        cout << "请输入电话：" << endl;
        cin >> phone;
        abs->per[abs->size].phone = phone;

        string address;
        cout << "请输入地址：" << endl;
        cin >> address;
        abs->per[abs->size].address = address;

        abs->size++;
        cout << "添加联系人成功" << endl;

        system("pause");
        system("cls");



    }
}

void showperson(addressbooks *abs)
{
    if(abs->size == 0)
    {
        cout << "通讯录中没有联系人" << endl;
    }
    else
    {
        for(int i = 0; i < abs->size; i++)
        {
            cout << "姓名：" << abs->per[i].name << "\t";
            cout << "年龄：" << abs->per[i].age << "\t";
            cout << "性别：" << abs->per[i].sex <<"\t";
            cout << "电话：" << abs->per[i].phone << "\t";  
            cout << "地址：" << abs->per[i].address << endl;
        }
    }
    system("pause");
    system("cls");
}

//检测联系人是否存在

int isexit(addressbooks *abs, string name)
{
    for(int i = 0; i < abs->size; i++)
    {
        if(abs->per[i].name == name)
        {
            return i;//返回联系人在数组中的位置
        }
    }
    return -1;//未找到联系人
}

void deleteperson(addressbooks *abs)
{
    if(abs->size == 0)
    {
        cout << "通讯录中没有联系人" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入要删除的联系人姓名：" << endl;
        cin >> name;

        int index = isexit(abs, name);

        if(index == -1)
        {
            cout << "未找到该联系人" << endl;
        }
        else
        {
            for(int i = index; i < abs->size ; i++)
            {
                abs->per[i] = abs->per[i + 1];
            }
            abs->size--;//更新通讯录人员数量
            cout << "删除联系人成功" << endl;
        }

        system("pause");
        system("cls");
    }
}

void searchperson(addressbooks *abs)
{
    if(abs->size == 0)
    {
        cout << "通讯录中没有联系人" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入要查找的联系人姓名：" << endl;
        cin >> name;

        int index = isexit(abs, name);
        if(index == -1)
        {
            cout << "未找到该联系人" << endl;
        }
        else
        {
        cout<<"姓名："<< abs->per[index].name << "\t";
        cout<<"性别："<< abs->per[index].sex <<"\t";
        cout<<"年龄："<< abs->per[index].age <<"\t";
        cout<<"电话："<< abs->per[index].phone <<"\t";
        cout<<"住址："<< abs->per[index].address <<"\t";
        }

    }
    system("pause");
    system("cls");


}

void editperson(addressbooks *abs)
{
    if(abs->size == 0)
    {
        cout << "通讯录中没有联系人" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入要修改的联系人姓名：" << endl;
        cin >> name;

        int index = isexit(abs, name);
        if(index == -1)
        {
            cout << "未找到该联系人" << endl;
        }
        else
        {
            string newname;
            cout << "请输入新的姓名：" << endl;
            cin >> newname;
            abs->per[index].name = newname;

            int newage;
            cout << "请输入新的年龄：" << endl;
            cin >> newage;
            abs->per[index].age = newage;

            string newsex;
            cout << "请输入新的性别：" << endl;
            cin >> newsex;
            abs->per[index].sex = newsex;

            string newphone;
            cout << "请输入新的电话：" << endl;
            cin >> newphone;
            abs->per[index].phone = newphone;

            string newaddress;
            cout << "请输入新的地址：" << endl;
            cin >> newaddress;
            abs->per[index].address = newaddress;
        }
    }
    system("pause");
    system("cls");
}

void clearperson(addressbooks *abs)
{
    abs->size = 0;//将通讯录中人数置为0，即清空通讯录
    cout << "清空联系人成功" << endl;
    system("pause");
    system("cls");
}



int main()
{
    addressbooks abs;//创建通讯录对象
    abs.size = 0;//初始化通讯录中人数为0
    int select = 0;
    while(true)
    {
        manu();
        
        cin >> select;  
        switch(select)
        {
        case 1:
            cout << "添加联系人" << endl;
            addperson(&abs);
            break;
        case 2:
            cout << "显示联系人" << endl;
            showperson(&abs);   
            break;
        case 3:
            cout << "删除联系人" << endl;   
            deleteperson(&abs);
            break;
        case 4:
            cout << "查找联系人" << endl;
            searchperson(&abs);
            break;
        case 5:
            cout << "修改联系人" << endl;
            editperson(&abs);
            break;
        case 6:
            cout << "清空联系人" << endl;   
            clearperson(&abs);
            break;
        case 0:
            cout << "退出通讯录系统" << endl;   
            system("pause");
            return 0;
        default:
            cout << "输入有误，请重新输入" << endl;
        }
    }

    system("pause");
    return 0;

}