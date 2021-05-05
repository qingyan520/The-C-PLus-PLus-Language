#include"speechManger.h"
int main()
{
	//创建一个管理类的对对象
	SpeechManger sm;
	int choice = 0;
	while (true)
	{
		sm.show_menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			break;
		case 2://查看往届记录
			break;
		case 3://清空比赛记录
			break;
		case 0://退出系统
			sm.exitsystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}