#include"contact.h"
void menu()
{
	cout << "\t\t      通讯录管理系统" << endl;
	cout << "\t\t ------------------------"<<endl;
	cout << "\t\t|\t1.添加联系人     |"<<endl;
	cout << "\t\t|\t2.显示联系人     |" << endl;
	cout << "\t\t|\t3.删除联系人     |" << endl;
	cout << "\t\t|\t4.查找联系人     |" << endl;
	cout << "\t\t|\t5.修改联系人     |" << endl;
	cout << "\t\t|\t6.排序联系人     |" << endl;
	cout << "\t\t|\t7.清空联系人     |" << endl;
	cout << "\t\t|\t0.退出通讯录     |" << endl;
	cout << "\t\t ------------------------" << endl;
}
int main()
{
	int n = 0;
	struct Contact con;
	do
	{
		menu();
		cout << "请输入要实现的功能" << endl;
		cin >> n;
		switch (n)
		{
			case AddContact:
				Add(&con);
				break;
			case ShowContact:
				Show(&con);
				break;
			case DeleteContact:
				Delete(&con);
				break;
			case SearchContact:
				Search(&con);
				break;
			case MOdityContact:
				Modity(&con);
				break;
			case SortContact:
				Sort(&con);
				break;
			case CleanContact:
				Clean(&con);
				break;
			case ExitContact:
				cout << "退出成功，欢迎下次使用" << endl;
				break;
			default:
				cout << "输入错误，请重新输入"<<endl;
				break;
		}
	} while (n);
	system("pause");
	return 0;
}