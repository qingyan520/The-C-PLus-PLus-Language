#include"manager.h"
#include<ostream>
#include<fstream>
using namespace std;
Manger::Manger(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
}

 void Manger::operMenu()
{
	 cout << "��ӭ����Ա��" << this->m_Name << "��¼" << endl;
	 cout << "\t\t1.����˺�" << endl;
	 cout << "\t\t2.�鿴�˺�" << endl;
	 cout << "\t\t3.�鿴����" << endl;
	 cout << "\t\t4.���ԤԼ" << endl;
	 cout << "\t\t0.ע����¼" << endl;
}

 void Manger::addPerson()
 {
	 cout << "����������˺ŵ�����:" << endl;
	 cout << "1.���ѧ��" << endl;
	 cout << "2.�����ʦ" << endl;
	 string filename;
	 string tip;
	 int select = 0;
	 cin >> select;
	 if (select == 1)
	 {
		 filename = STUDENT_FILE;
		 tip = "������ѧ��:" ;
	 }
	 else
	 {
		 filename = TEACHER_FILE;
		 tip = "������ְ�����:";
	 }
	 ofstream ofs;
	 ofs.open(filename, ios::out | ios::app);
	 int id;
	 string name;
	 string pwd;
	 cout << tip << endl;
	 cin >> id;
	 cout << "����������:" << endl;
	 cin >> name;
	 cout << "����������:" << endl;
	 cin >> pwd;
	 ofs << id <<" " << name<<" " << pwd <<" " << endl;
	 cout << "��ӳɹ�" << endl;
 }