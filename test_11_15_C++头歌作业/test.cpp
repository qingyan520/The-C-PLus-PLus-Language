////#include "people.h"     // People 类定义在这里面
//#include <string>
//#include <iostream>
//
//using namespace std;
//class People
//{
//public:
//    string name;
//    void PrintName();
//};
//
//void People::PrintName()
//{
//    cout << "姓名：" << this->name << endl;
//}
///**********  Begin **********/
////公有继承 People
//class Student:protected People
//{
//public:
//    void SetName(string name)
//    {
//        this->name = name;
//    }
//    void PrintSID();
//    void PrintName()
//    {
//        this->People::PrintName();
//    }
//    int SID=0;
//};
///**********  End **********/
//
//void Student::PrintSID()
//{
//    /********* Begin *********/
//    //输出 SID
//    cout << "学号：" << this->SID << endl;
//
//
//    /********* End *********/
//}
//
//void Set(int sid, string name, Student* ptr)
//{
//    /********* Begin *********/
//    //给 ptr 对象的两个属性赋值
//
//    ptr->SID = sid;
//
//    ptr->SetName(name);
//    /********* End *********/
//}
//
//int main()
//{
//    Student* p = new Student;
//    Set(1, "name", p);
//    p->PrintName();
//    p->PrintSID();
//}


//#include "people.h" //People类定义在这里面
#include <string>
#include <iostream>
using namespace std;

/********* Begin *********/
//私有继承 People 类
class People
{
public:
    string name;
    void PrintName();
};

void People::PrintName()
{
    cout << "姓名：" << this->name << endl;
}



class Student:private People
{
public:
    int SID;
    void PrintSID();
    //添加一个 Set 函数来设置父类的 Name 成员
    void Set(string name)
    {
        this->name = name;
    }
};


/********* End *********/

void Student::PrintSID()
{
    /********* Begin *********/
    //输出学号 SID
    cout << "学号：" << this->SID << endl;


    /********* End *********/
}

/********* Begin *********/
// 公有继承 Student 类
class Graduate :public Student
{
public:
    int ResearchID;
    void PrintResearchID();
    //添加一个 Set 函数来设置父类的 SID 成员
    void SetSID(int sid)
    {
        this->SID = sid;
    }
    //添加一个 Set 函数来调用父类的 SetName 函数
    void Setname(string name)
    {
        this->Set(name);
    }
    void SetRearchID(int rid)
    {
        this->ResearchID = rid;
    }
};

/********* End *********/

void Graduate::PrintResearchID()
{
    /********* Begin *********/
    //输出研究方向 ResearchID
    cout << "研究方向：" << this->ResearchID << endl;


    /********* End *********/
}

void Set(string name, int sid, int rid, Graduate* ptr)
{
    /********* Begin *********/
    //设置 ptr 所指对象的三个成员
    ptr->Setname(name);
    ptr->SetSID(sid);
    ptr->SetRearchID(rid);


    /********* End *********/
}
