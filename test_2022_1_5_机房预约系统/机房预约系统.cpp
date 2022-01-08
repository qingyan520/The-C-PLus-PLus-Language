#include<iostream>
#include<fstream>
#include"Identity.h"
#include"globalFile.h"
#include"manager.h"
#include"student.h"
#include"teacher.h"
using namespace std;
void menu()
{
	cout << "\t---------机房预约系统---------" << endl;
	cout << "\t\t1.学生身份" << endl;
	cout << "\t\t2.老师" << endl;
	cout << "\t\t3.管理员" << endl;
	cout << "\t\t0.退出" << endl;
}

void MangerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manger* man = (Manger*)manager;
		int select;
		cin >>select;
		if (select == 0)
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			break;
		}
		switch (select)
		{
		case 1:
			cout << "添加账号" << endl;
			man->addPerson();
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "查看账号" << endl;
			man->showPerson();
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "查看机房" << endl;
			man->showComputer();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "清空机房" << endl;
			man->cleanFile();
			system("pause");
			system("cls");
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}

//文件名+类型
void Login(string fileName, int type)
{
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}


	string name;
	string pwd;
	int id;
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}

	else if (type == 2)
	{
		cout << "请输入教师号:" << endl;
		cin >> id;
	}
	
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	//学生
	if (type == 1)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && pwd == fpwd)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				person->operMenu();

			}
		}
		cout << "用户名或者账号错误" << endl;
	}
	//教师
	else if (type == 2)
	{

		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && pwd == fpwd)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				person->operMenu();

			}
		}
		cout << "用户名或者账号错误" << endl;
	}

	//管理员验证
	else if(type==3)
	{

		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && pwd == fpwd)
			{
				cout << "登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manger(name, pwd);
				MangerMenu(person);

			}
		}
		cout << "用户名或者账号错误" << endl;
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");
}
int main()
{
	int select;

	while (1)
	{
		menu();
		cout << "请输入对应的选项:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			Login(STUDENT_FILE, 1);
			break;
		case 2:
			Login(TEACHER_FILE, 2);
			break;
		case 3:
			Login(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "退出,欢迎下次使用!" << endl;
			exit(1);
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}