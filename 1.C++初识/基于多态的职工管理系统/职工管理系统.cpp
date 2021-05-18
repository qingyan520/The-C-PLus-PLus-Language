#include"workerManger.h"
int main()
{
	workerManger vm;
	int choice = 0;
	while (true)
	{
		vm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			vm.ExitSystem();
			break;
		case 1:  //增加职工
			break;
		case 2:  //显示职工
			break;
		case 3:  //删除职工
			break;
		case 4:  //修改职工
			break;
		case 5:  //查找职工
			break;
		case 6:  //排序职工
			break;
		case 7:  //清空职工
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}