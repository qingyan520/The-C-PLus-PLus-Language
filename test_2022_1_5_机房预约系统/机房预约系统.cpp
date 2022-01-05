#include<iostream>
using namespace std;
void menu()
{
	cout << "\t---------机房预约系统---------" << endl;
	cout << "\t\t1.学生身份" << endl;
	cout << "\t\t2.老师" << endl;
	cout << "\t\t3.管理员" << endl;
	cout << "\t\t0.退出" << endl;
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
			break;
		case 2:
			break;
		case 3:
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