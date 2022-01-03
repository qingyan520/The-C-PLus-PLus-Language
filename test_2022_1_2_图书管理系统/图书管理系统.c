#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//图书信息的定义
typedef struct Book_Data
{
	char name[50];//书名
	char author[10];//作者
	char press[20];//出版社
	char pushlish_time[20];//出版时间

}Book;


//利用线性表实现图书信息管理系统
typedef struct Library
{
	Book* data;
	int capacity;
	int size;
}Library;


//初始化图书信息管理系统
void Init_Library(Library* p);

//检测容量检测
void Check_Capacity(Library* p);

//增加图书信息
void Add_Book(Library* p);

//查找图书，存在返回i
int Find_Name(Library* p, char name[]);

//删除图书信息
void Del_Book(Library* p);

//修改图书信息
void Modify_Book(Library* p);

//查找图书
void Search_Book(Library* p);

//保存图书信息
void Save_Book(Library* p);

//每次开始时加载图书信息
void Load_Book(Library* p);

//显示图书信息
void Show_Book(Library* p);

//菜单界面
void menu();



//初始化图书信息管理系统
void Init_Library(Library* p)
{
	p->data = (Book*)malloc(sizeof(Book) * 1000);//容量初始化为1000，不够时增容
	p->capacity = 1000;
	p->size = 0;

	Load_Book(p);
}


//检测容量检测
void Check_Capacity(Library* p)
{
	if (p->capacity == p->size)
	{
		//增容
		Book* ptr = (Book*)realloc(p->data, (p->capacity + 1000) * sizeof(Book));
		if (ptr == NULL)
		{
			printf("增容失败\n");
			return;
		}
		else
		{
			p->data = ptr;
			p->capacity += 1000;
			return;
		}
	}
}

//增加图书信息
void Add_Book(Library* p)
{
	Check_Capacity(p);

	printf("请输入图书名称:\n");
	scanf("%s", p->data[p->size].name);
	printf("请输入图书作者:\n");
	scanf("%s", p->data[p->size].author);
	printf("请输入图书出版社:\n");
	scanf("%s", p->data[p->size].press);
	printf("请输入图书出版日期:\n");
	scanf("%s", &p->data[p->size].pushlish_time);

	p->size++;
	printf("添加成功\n");
}

//查找图书，存在返回i
int Find_Name(Library* p, char name[])
{
	int i = 0;
	for (int i = 0; i < p->size; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


//删除图书信息
void Del_Book(Library* p)
{
	char name[20] = { 0 };
	if (p->size == 0)
	{
		printf("无图书信息,无法删除\n");
		return;
	}
	else
	{
		printf("请输入要删除的图书姓名:\n");
		scanf("%s", name);
		int pos = Find_Name(p, name);
		if (pos == -1)
		{
			printf("要删除的图书不存在\n");
		}
		else
		{
			//删除
			int j = 0;
			for (j = pos; j < p->size - 1; j++)
			{
				p->data[j] = p->data[j + 1];
			}
			p->size--;
			printf("删除成功\n");
		}

	}
}


//修改图书信息
void Modify_Book(Library* p)
{
	char name[20];
	printf("请输入要修改的图书的名字:\n");
	scanf("%s", name);
	int pos = Find_Name(p, name);
	if (pos == -1)
	{
		printf("要修改的图书不存在\n");
	}
	else
	{

		printf("请输入图书名称:\n");
		scanf("%s", p->data[pos].name);
		printf("请输入图书作者:\n");
		scanf("%s", p->data[pos].author);
		printf("请输入图书出版社:\n");
		scanf("%s", p->data[pos].press);
		printf("请输入图书出版日期:\n");
		scanf("%s", &p->data[pos].pushlish_time);
		printf("请输入英语成绩:\n");
		printf("修改成功\n");
	}
}


//查找图书
void Search_Book(Library* p)
{
	char name[20];
	printf("请输入要查找的图书的名称:\n");
	scanf("%s", name);
	int pos = Find_Name(p, name);
	if (pos == -1)
	{
		printf("要查找的图书不存在\n");
	}
	else
	{
		printf("%-20s\t%-10s\t%-20s\t%-20s\n","图书名称","作者","出版社","出版日期");
		printf("%-20s\t%-10s\t%-20s\t%-20s\n",p->data[pos].name,
			p->data[pos].author, p->data[pos].press,
			p->data[pos].pushlish_time);
	}
}


//保存图书信息
void Save_Book(Library* p)
{
	FILE* pfOut = fopen("Book.txt", "wb");
	if (pfOut == NULL)
	{
		printf("Save_Book::%s\n", strerror(errno));
		return;
	}

	//写数据
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		fwrite(p->data + i, sizeof(Book), 1, pfOut);
	}
	fclose(pfOut);
	pfOut = NULL;
}


//每次开始时加载图书信息
void Load_Book(Library* p)
{
	//打开文件
	FILE* pfIn = fopen("Book.txt", "rb");
	if (pfIn == NULL)
	{
		printf("Load_Book::%s\n", strerror(errno));
		return;
	}
	//读文件内容，放进通讯录
	Book tmp = { 0 };
	while (fread(&tmp, sizeof(Book), 1, pfIn))
	{
		//检测是否要增容
		Check_Capacity(p);
		//存储元素
		p->data[p->size] = tmp;
		p->size++;
	}

	//关闭文件
	fclose(pfIn);
	pfIn = NULL;
}


//显示图书信息
void Show_Book(Library* p)
{
	printf("%-20s\t%-10s\t%-20s\t%-20s\n", "图书名称", "作者", "出版社", "出版日期");
	for (int i = 0; i < p->size; i++)
	{
		printf("%-20s\t%-10s\t%-20s\t%-20s\n", p->data[i].name,
			p->data[i].author, p->data[i].press,
			p->data[i].pushlish_time);
	}
}

void menu()
{
	printf("\t\t1.添加图书信息\n");
	printf("\t\t2.删除图书信息\n");
	printf("\t\t3.查找图书信息\n");
	printf("\t\t4.修改图书信息\n");
	printf("\t\t5.显示图书信息\n");
	printf("\t\t6.保存图书信息\n");
	printf("\t\t0.退出\n");

}
int main()
{
	int option = 0;
	Library p;
	Init_Library(&p);
	while (1)
	{
		menu();
		printf("请输入对应选项:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			//添加信息
			Add_Book(&p);
			system("pause");
			system("cls");
			break;
		case 2:
			//删除信息
			Del_Book(&p);
			system("pause");
			system("cls");
			break;
		case 3:
			//查询信息
			Search_Book(&p);
			system("pause");
			system("cls");
			break;
		case 4:
			//修改信息
			Modify_Book(&p);
			system("pause");
			system("cls");
			break;
		case 5:
			//显示所有信息
			Show_Book(&p);
		case 6:
			//保存信息
			Save_Book(&p);
			system("pause");
			system("cls");
			break;
		case 0:
			printf("退出系统，欢迎下次使用\n");
			system("pause");
			system("cls");
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入\n");
			system("pause");
			system("cls");
			break;

		}
	}
	return 0;
}