#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200

//图书信息结构体定义
typedef struct Book {
	char name[20];//书名
	char sn[20];//书号
	float price;//价格
	int inventory;//库存
}Book;


//定义管理系统
typedef struct Manger
{
	Book* data;//存储数据
	int size;//当前元素个数
	int capacity;//总个数

}Manger;


//初始化管理系统
void Init(Manger* manger)
{
	manger->data = (Book*)malloc(sizeof(Book)*MAX);
	manger->size = 0;
	manger->capacity = MAX;
}


//打印图书信息
void Print_Book(Manger*manger)
{
	printf("\t\t图书信息\n");
	printf("%-20s\t%-20s\t%-5s\n", "书名", "书号", "价格信息");
	for (int i = 0; i < manger->size; i++) {
		printf("%-20s\t%-20s\t%-5.2lf\n", manger->data[i].name, manger->data[i].sn, manger->data[i].price);
	}
}

//显示图书库存
void Print_Inventory(Manger*manger)
{
	printf("\t\t库存信息\n");
	printf("%-20s\t%-5s\n", "书名", "库存");
	for (int i = 0; i < manger->size; i++)
	{
		printf("%-20s\t%-5d\n", manger->data[i].name, manger->data[i].inventory);
	}
}

//检查容量
void Check(Manger* manger)
{
	if (manger->size <= manger->capacity)
	{
		return;
	}
	else
	{
		Book* p = realloc(manger->data, sizeof(Book) * (manger->capacity + MAX));
		if (p != NULL)
		{
			manger->data = p;
		}
	}
}


//添加图书信息
void Add_Books(Manger*manger)
{
	//检查容量是否满了
	Check(manger);
	printf("请输入图书名称:\n");
	scanf("%s", manger->data[manger->size].name);

	printf("请输入图书书号:\n");
	scanf("%s", manger->data[manger->size].sn);

	printf("请输入图书价格:\n");
	scanf("%f", &manger->data[manger->size].price);

	manger->data[manger->size].inventory = 1;

	manger->size++;
}


//搜索该图书是否存在
int Search(Manger*manger, char name[])
{
	for (int i = 0; i < manger->size; i++)
	{
		if (strcmp(manger->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//修改库存数量
void Modify_Inventory(Manger*manger)
{
	printf("请输入要修改库存的图书名称:\n");
	char name[20] = { 0 };
	scanf("%s", name);
	//不存在则不修改，存在则修改
	int i = Search(manger, name);
	if (i == -1)
	{
		printf("未找到该图书！\n");

	}
	else
	{
		printf("请输入库存数量:\n");
		scanf("%d", &manger->data[i].inventory);
		printf("修改成功！\n");
	}
}


//主菜单
void Menu()
{
	printf("\t\t图书管理系统V0.1\n\n");
	printf("\t\t1.显示书目信息\n");
	printf("\t\t2.显示图书库存信息\n");
	printf("\t\t3.添加图书信息\n");
	printf("\t\t4.修改图书库存量\n");
	printf("\t\t5.退出系统\n");
}

int main()
{

	Manger manger;
	Init(&manger);
	int option = 0;
	while (1)
	{
		Menu();
		printf("请输入对应选项:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			Print_Book(&manger);
			break;
		case 2:
			Print_Inventory(&manger);
			break;
		case 3:
			Add_Books(&manger);
			break;
		case 4:
			Modify_Inventory(&manger);
			break;
		case 5:
			printf("退出，欢迎下次使用！\n");
			return 0;
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}


	return 0;
}
