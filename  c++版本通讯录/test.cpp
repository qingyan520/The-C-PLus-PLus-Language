#include"contact.h"
void Add(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		cout << "通讯录已满无法添加" << endl;
	}
	else
	{
		cout << "请输入姓名" << endl;
		cin >> ps->contact[ps->size].Name;
		cout << "请输入性别,1代表男，2代表女" << endl;
		while (true)
		{
			cin >> ps->contact[ps->size].Sex;
			if (ps->contact[ps->size].Sex == 1 || ps->contact[ps->size].Sex == 2)
			{
				break;
			}
		}
		cout << "请输入年龄" << endl;
		cin >> ps->contact[ps->size].Age;
		cout << "请输入电话号码" << endl;
		cin >> ps->contact[ps->size].Phone;
		cout << "请输入住址" << endl;
		cin >> ps->contact[ps->size].Addr;
		ps->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
void Show(struct Contact* ps)
{
	if (ps->size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		cout << "\t\t      通讯录" << endl;
		cout << endl;
		for (int i = 0; i < ps->size; i++)
		{
			cout << "姓名:" << ps->contact[i].Name << "\t";
			cout << "性别:" << (ps->contact[i].Sex==1?"男":"女") << "\t";
			cout << "年龄:" << ps->contact[i].Age << "\t";
			cout << "电话号码:" << ps->contact[i].Phone << "\t";
			cout << "住址:" << ps->contact[i].Addr << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}
int Find(string Delete_Name,struct Contact*ps)
{
	for (int i = 0; i <ps->size ; i++)
	{
		if (Delete_Name==ps->contact[i].Name)
		{
			return i;
		}
	}
	return -1;
}
void Delete(struct Contact* ps)
{
	string Delete_Name;
	cout << "请输入要删除联系人的姓名:" << endl;
	cin >> Delete_Name;
	int ret = Find(Delete_Name,ps);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = ret; i < ps->size; i++)
		{
			ps->contact[i] = ps->contact[i + 1];
		}
	}
	ps->size--;
	cout << "删除成功" << endl;
	system("pause");
	system("cls");
}
void Search(struct Contact* ps)
{
	string Search_Name;
	cout << "请输入要查找联系人的姓名:" << endl;
	cin >> Search_Name;
	int ret = Find(Search_Name, ps);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "姓名:" << ps->contact[ret].Name << "\t";
		cout << "性别:" << (ps->contact[ret].Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:" << ps->contact[ret].Age << "\t";
		cout << "电话号码:" << ps->contact[ret].Phone << "\t";
		cout << "住址:" << ps->contact[ret].Addr << "\t" << endl;
	}
	system("pause");
	system("cls");
}
void Modity(struct Contact* ps)
{
	string Modity_Name;
	cout << "请输入要修改联系人的姓名:" << endl;
	cin >> Modity_Name;
	int ret = Find(Modity_Name, ps);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "请输入姓名" << endl;
		cin >> ps->contact[ret].Name;
		cout << "请输入性别,1代表男，2代表女" << endl;
		while (true)
		{
			cin >> ps->contact[ret].Sex;
			if (ps->contact[ret].Sex == 1 || ps->contact[ret].Sex == 2)
			{
				break;
			}
		}
		cout << "请输入年龄" << endl;
		cin >> ps->contact[ret].Age;
		cout << "请输入电话号码" << endl;
		cin >> ps->contact[ret].Phone;
		cout << "请输入住址" << endl;
		cin >> ps->contact[ret].Addr;
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}
void Sort(struct Contact* ps)
{
	for (int i = 0; i <ps->size-1 ; i++)
	{
		for (int j = 0; j <ps->size-1-i; j++)
		{
			if (ps->contact[j].Age > ps->contact[j + 1].Age)
			{
				struct PeopleInfortation temp = ps->contact[j];
				ps->contact[j] = ps->contact[j + 1];
				ps->contact[j + 1] = temp;
			}
		}
	}
	cout << "排序成功" << endl;
	system("pause");
	system("cls");
}
void Clean(struct Contact* ps)
{
	int m = 0;
	cout << "您是否要删除通讯录，确认删除请按1,退出请按2" << endl;
	cin >> m;
	while (true)
	{
		if (m == 1)
		{
			ps->size = 0;
			cout << "成功删除通讯录" << endl;
			break;
		}
		if (m == 2)
		{
			break;
		}
	}
	system("pause");
	system("cls");
}