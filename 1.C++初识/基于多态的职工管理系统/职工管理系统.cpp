#include"workerManger.h"
int main()
{
	workerManger vm;
	int choice = 0;
	while (true)
	{
		vm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			vm.ExitSystem();
			break;
		case 1:  //����ְ��
			break;
		case 2:  //��ʾְ��
			break;
		case 3:  //ɾ��ְ��
			break;
		case 4:  //�޸�ְ��
			break;
		case 5:  //����ְ��
			break;
		case 6:  //����ְ��
			break;
		case 7:  //���ְ��
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}