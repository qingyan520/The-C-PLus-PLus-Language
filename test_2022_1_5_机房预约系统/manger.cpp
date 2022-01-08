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
	 cout << "欢迎管理员：" << this->m_Name << "登录" << endl;
	 cout << "\t\t1.添加账号" << endl;
	 cout << "\t\t2.查看账号" << endl;
	 cout << "\t\t3.查看机房" << endl;
	 cout << "\t\t4.清空预约" << endl;
	 cout << "\t\t0.注销登录" << endl;
}

 void Manger::addPerson()
 {
	 cout << "请输入添加账号的类型:" << endl;
	 cout << "1.添加学生" << endl;
	 cout << "2.添加老师" << endl;
	 string filename;
	 string tip;
	 int select = 0;
	 cin >> select;
	 if (select == 1)
	 {
		 filename = STUDENT_FILE;
		 tip = "请输入学号:" ;
	 }
	 else
	 {
		 filename = TEACHER_FILE;
		 tip = "请输入职工编号:";
	 }
	 ofstream ofs;
	 ofs.open(filename, ios::out | ios::app);
	 int id;
	 string name;
	 string pwd;
	 cout << tip << endl;
	 cin >> id;
	 cout << "请输入姓名:" << endl;
	 cin >> name;
	 cout << "请输入密码:" << endl;
	 cin >> pwd;
	 ofs << id <<" " << name<<" " << pwd <<" " << endl;
	 cout << "添加成功" << endl;
 }