////#include "people.h"     // People �ඨ����������
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
//    cout << "������" << this->name << endl;
//}
///**********  Begin **********/
////���м̳� People
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
//    //��� SID
//    cout << "ѧ�ţ�" << this->SID << endl;
//
//
//    /********* End *********/
//}
//
//void Set(int sid, string name, Student* ptr)
//{
//    /********* Begin *********/
//    //�� ptr ������������Ը�ֵ
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


//#include "people.h" //People�ඨ����������
#include <string>
#include <iostream>
using namespace std;

/********* Begin *********/
//˽�м̳� People ��
class People
{
public:
    string name;
    void PrintName();
};

void People::PrintName()
{
    cout << "������" << this->name << endl;
}



class Student:private People
{
public:
    int SID;
    void PrintSID();
    //���һ�� Set ���������ø���� Name ��Ա
    void Set(string name)
    {
        this->name = name;
    }
};


/********* End *********/

void Student::PrintSID()
{
    /********* Begin *********/
    //���ѧ�� SID
    cout << "ѧ�ţ�" << this->SID << endl;


    /********* End *********/
}

/********* Begin *********/
// ���м̳� Student ��
class Graduate :public Student
{
public:
    int ResearchID;
    void PrintResearchID();
    //���һ�� Set ���������ø���� SID ��Ա
    void SetSID(int sid)
    {
        this->SID = sid;
    }
    //���һ�� Set ���������ø���� SetName ����
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
    //����о����� ResearchID
    cout << "�о�����" << this->ResearchID << endl;


    /********* End *********/
}

void Set(string name, int sid, int rid, Graduate* ptr)
{
    /********* Begin *********/
    //���� ptr ��ָ�����������Ա
    ptr->Setname(name);
    ptr->SetSID(sid);
    ptr->SetRearchID(rid);


    /********* End *********/
}
