#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//建立节点，每一个节点包括图书信息以及指向下一个节点
typedef struct Node
{
	char name[20];//书名
	char sn[20];//书号
	float price;//价格
	int inventory;//库存
	struct Node* next;//指向下一个节点
}Node;


//建立头指针
Node* head = NULL;


//打印图书信息
void Print()
{
	if (head == NULL)
	{
		printf("图书为空！");
		return;
	}
	Node* cur = head;
	printf("\n\t\t图书信息\n");
	printf("%-20s\t%-20s\t%-5s\n", "书名", "书号", "价格信息");
	while (cur != NULL)
	{
		printf("%-20s\t%-20s\t%-5.2lf\n", cur->name, cur->sn, cur->price);
		cur = cur->next;
	}
	printf("\n\n");
}


//打印库存信息
void Print_()
{
	if (head == NULL)
	{
		printf("无图书信息\n");
		return;
	}
	printf("\n\t\t库存信息\n");
	printf("%-20s\t%-5s\n", "书名", "库存");
	Node* cur = head;

	while (cur != NULL)
	{
		printf("%-20s\t%-5d\n", cur->name,cur->inventory);
		cur = cur->next;
	}
	printf("\n\n");
}


//添加图书信息
void Insert()
{
	//第一次插入
	if (head ==NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		if (head == NULL)
		{
			printf("malloc error!");
			exit(0);
		}
		printf("请输入图书名称:\n");
		scanf("%s",head->name);

		printf("请输入图书书号:\n");
		scanf("%s",head->sn);

		printf("请输入图书价格:\n");
		scanf("%f", &head->price);
		head->inventory = 1;
		head->next = NULL;
		return;
	}

	//以后插入
	Node* cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	Node* Next = (Node*)malloc(sizeof(Node));
	if (Next == NULL)
	{
		exit(0);
	}

	printf("请输入图书名称:\n");
	scanf("%s", Next->name);

	printf("请输入图书书号:\n");
	scanf("%s", Next->sn);

	printf("请输入图书价格:\n");
	scanf("%f", &Next->price);
	Next->inventory = 1;
	Next->next = NULL;
	cur->next = Next;
}


//修改库存信息
void Modify()
{
	printf("请输入要修改库存的图书名称:\n");
	char Name[20] = { 0 };
	scanf("%s", Name);
	Node* cur = head;
	while (cur != NULL)
	{
		if (strcmp(cur->name, Name) == 0)
		{
			printf("请输入库存数量:\n");
			scanf("%d", &cur->inventory);
			printf("修改成功\n");
			break;
		}
		cur = cur->next;
	}

	if (cur == NULL)
	{
		printf("未找到该书！\n");
	}
}

//主菜单
void menu() {
	printf("\t\t图书管理系统V0.1\n\n");
	printf("\t\t1.显示书目信息\n");
	printf("\t\t2.显示图书库存信息\n");
	printf("\t\t3.添加图书信息\n");
	printf("\t\t4.修改图书库存量\n");
	printf("\t\t5.退出系统\n");
}




int main()
{

	int select = 0;
	while (1)
	{
		menu();
		printf("请输入对应选项:\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			//打印图书信息
			Print();
			break;
		case 2:
			//打印库存
			Print_();
			break;
		case 3:
			//增加图书信息
			Insert();
			break;
		case 4:
			//修改库存
			Modify();
			break;
		case 5:
			//退出
			printf("退出!\n");
			return 0;
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}


	return 0;

}