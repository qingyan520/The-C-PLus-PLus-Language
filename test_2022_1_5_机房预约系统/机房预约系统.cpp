#include<iostream>
using namespace std;
void menu()
{
	cout << "\t---------����ԤԼϵͳ---------" << endl;
	cout << "\t\t1.ѧ�����" << endl;
	cout << "\t\t2.��ʦ" << endl;
	cout << "\t\t3.����Ա" << endl;
	cout << "\t\t0.�˳�" << endl;
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
			break;
		case 2:
			break;
		case 3:
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