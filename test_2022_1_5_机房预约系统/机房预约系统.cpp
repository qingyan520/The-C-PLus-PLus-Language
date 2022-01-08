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
	cout << "\t---------����ԤԼϵͳ---------" << endl;
	cout << "\t\t1.ѧ�����" << endl;
	cout << "\t\t2.��ʦ" << endl;
	cout << "\t\t3.����Ա" << endl;
	cout << "\t\t0.�˳�" << endl;
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
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		}
		switch (select)
		{
		case 1:
			cout << "����˺�" << endl;
			man->addPerson();
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "�鿴�˺�" << endl;
			man->showPerson();
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "�鿴����" << endl;
			man->showComputer();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "��ջ���" << endl;
			man->cleanFile();
			system("pause");
			system("cls");
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
}

//�ļ���+����
void Login(string fileName, int type)
{
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}


	string name;
	string pwd;
	int id;
	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}

	else if (type == 2)
	{
		cout << "�������ʦ��:" << endl;
		cin >> id;
	}
	
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;

	//ѧ��
	if (type == 1)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && pwd == fpwd)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				person->operMenu();

			}
		}
		cout << "�û��������˺Ŵ���" << endl;
	}
	//��ʦ
	else if (type == 2)
	{

		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && pwd == fpwd)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				person->operMenu();

			}
		}
		cout << "�û��������˺Ŵ���" << endl;
	}

	//����Ա��֤
	else if(type==3)
	{

		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && pwd == fpwd)
			{
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manger(name, pwd);
				MangerMenu(person);

			}
		}
		cout << "�û��������˺Ŵ���" << endl;
	}
	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");
}
int main()
{
	int select;

	while (1)
	{
		menu();
		cout << "�������Ӧ��ѡ��:" << endl;
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
			cout << "�˳�,��ӭ�´�ʹ��!" << endl;
			exit(1);
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}