//动态增长的通讯录，利用动态内存管理+文件操作实现了联系人的保存，输入，输出，修改等一系列功能

//每个人的信息：
//名字
//年龄
//性别
//电话
//住址

//功能：
//1. 增加一个人的信息
//2. 删除一个指定的联系人
//3. 查找一个指定的联系人
//4. 修改一个指定的联系人
//5. 显示通讯录中所有人的信息
//6. 排序
//0. 退出

//动态增长的版本 - 按需开辟
//文件的版本 - 数据可以存储到文件中，不至于丢失

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

#define DEFAULT_SZ 3


#define MAX 1000

//描述一个人信息的结构体
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;




//动态增长的通讯录版本
typedef struct Contact
{
	struct PeoInfo* data;
	int sz;//表示通讯录中当前存放的人的信息个数
	int capacity;//表示通讯录当前的最大容量
}Contact;


//函数的声明

//初始化通讯录的函数
void InitContact(struct Contact* pc);

//增加一个人的信息
void AddContact(struct Contact* pc);

//打印通讯中的信息
void ShowContact(const struct Contact* pc);

//删除一个人的信息
void DelContact(struct Contact* pc);

//查找指定联系人
void SearchContact(const struct Contact* pc);

//修改指定联系人
void ModifyContact(struct Contact* pc);


//销毁通讯录
void DestroyContact(struct Contact* pc);

//保存数据到文件
void SaveContact(Contact* pc);




//检查容量是否够了
int CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增容
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr == NULL)
		{
			printf("扩容失败\n");
			return 0;
		}
		else
		{
			//如果增容成功要把ptr赋值给pc->data
			pc->data = ptr;
			pc->capacity += 2;
			printf("增容成功\n");
			return 1;
		}
	}
	return 1;
}


//每次启动时加载文件中的联系人信息
void LoadContact(Contact* pc)
{
	//打开文件
	FILE* pfIn = fopen("contact.dat", "rb");
	if (pfIn == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//读文件内容，放进通讯录
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfIn))
	{
		//检测是否要增容
		if (CheckCapacity(pc) == 0)
		{
			printf("通讯录初始化失败\n");
			return;
		}
		//存储元素
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//关闭文件
	fclose(pfIn);
	pfIn = NULL;
}

//动态版本-初始化通讯录
void InitContact(struct Contact* pc)
{
	pc->sz = 0;//通讯录创建好的时候，没有有效信息
	pc->capacity = DEFAULT_SZ;//通讯录创建好的时候，默认能放DEFAULT_SZ个人的信息
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (pc->data == NULL)
	{
		printf("初始化通讯录失败\n");
		exit(1);
	}
	//加载文件
	LoadContact(pc);
}



//动态增长的版本
void AddContact(struct Contact* pc)
{
	if (CheckCapacity(pc) == 0)
	{
		printf("空间不够使用，增加容量时失败\n");
		return;
	}

	printf("请输入名字:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("添加成功\n");
}


//显示通讯录信息
void ShowContact(const struct Contact* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("\n");
		printf("欢迎浏览通讯录！\n");
		printf("----------------------------------------------------------------------------\n");
		printf("                              通讯录                                        | \n");
		printf("----------------------------------------------------------------------------\n");
		printf("%-15s|\t%-5s|\t%-5s|\t%-12s|\t%-20s|\n", "名字", "年龄", "性别", "电话", "地址");
		printf("----------------------------------------------------------------------------\n");
		for (i = 0; i < pc->sz; i++)
		{
			printf("%-15s|\t%-5d|\t%-5s|\t%-12s|\t%-20s|\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr);
			printf("----------------------------------------------------------------------------\n");
		}
		printf("\n");

	}

}


//根据姓名查找
static int FindByName(const struct Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}

	//没找到
	return -1;
}


//删除通讯录信息
void DelContact(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };

	if (pc->sz == 0)
	{
		printf("通讯录为空，没法删除\n");
	}
	else
	{
		//1.找到要删除的人
		printf("请输入要删除人的名字:>");
		scanf("%s", name);
		int pos = FindByName(pc, name);
		if (pos == -1)
		{
			printf("要删除的人不存在\n");
		}
		else
		{
			//2.删除
			int j = 0;
			for (j = pos; j < pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;
			printf("删除成功\n");
		}

	}
}

//查找联系人
void SearchContact(const struct Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("----------------------------------------------------------------------------\n");
		printf("%-15s|\t%-5s|\t%-5s|\t%-12s|\t%-20s|\n", "名字", "年龄", "性别", "电话", "地址");
		printf("----------------------------------------------------------------------------\n");
		printf("%-15s|\t%-5d|\t%-5s|\t%-12s|\t%-20s|\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("----------------------------------------------------------------------------\n");
	}
	printf("\n");
}


//修改联系人
void ModifyContact(struct Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功\n");
	}
}


//销毁通讯录
void DestroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}


//每次退出时保存文件
void SaveContact(Contact* pc)
{
	//打开文件
	FILE* pfOut = fopen("contact.dat", "wb");
	if (pfOut == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//写数据
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfOut);
	}

	//关闭文件
	fclose(pfOut);
	pfOut = NULL;
}



void menu()
{
	printf("***********************************************\n");
	printf("*****   1. 添加联系人      2.删除联系人  ******\n");
	printf("*****   3. 查找联系人      4.修改联系人  ******\n");
	printf("*****   5. 显示联系人      6.保存联系人  ******\n");
	printf("*****   0. exit                          ******\n");
	printf("***********************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SAVE
};

void test()
{
	int input = 0;
	struct Contact con;//创建了一个通讯录

	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{

		case ADD:
			AddContact(&con);
			break;

		case DEL:
			DelContact(&con);
			break;

		case SEARCH:
			SearchContact(&con);
			break;

		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;

		case SAVE:
			SaveContact(&con);
			break;

		case EXIT:
			DestroyContact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
