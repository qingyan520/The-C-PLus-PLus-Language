//
//////要求:建立不带头节点的循环单链表，其长度大于1，R为它的尾结点
//////1.采取尾插法建立一个循环单链表，然后输出该单链表的值
//////2.删除R的前驱节点，最后输出删除个节点后链表的个结点的数据值
//#include<stdio.h>
//#include<stdlib.h>
//
////循环单链表节点的定义
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode;
//
//
////向循环单链表尾部插入数据
//void Push_Back(LNode** p, int x)
//{
//	//第一次插入的时候：直接进行插入，让*p->next=(*p),形成一个封闭的环
//	LNode* cur = (*p);
//	if (cur == NULL)
//	{
//		//开辟节点
//		*p = (LNode*)malloc(sizeof(LNode));
//		if (*p != NULL)
//		{
//			(*p)->data = x;
//			(*p)->next = *p;
//			return;
//		}
//	}
//
//
//	//之后插入
//	//申请节点
//	LNode* temp = (LNode*)malloc(sizeof(LNode));
//	if (temp != NULL)
//	{
//		temp->data = x;
//
//		//找到尾结点
//		while (cur!=NULL&&cur->next!=(*p))
//		{
//			cur = cur->next;
//		}
//
//		//这里判断为空不是必要条件，主要是为了防止VS2019报错
//		if (cur != NULL)
//		{
//			LNode* next = cur->next;
//			cur->next = temp;
//			temp->next = next;
//		}
//	}
//}
//
////打印单链表
//void Print(LNode* p)
//{
//	//判断节点是否为空，为空就不进行处理
//	if (p == NULL)
//		return;
//
//	//如果只要一个节点就只进行打印这个节点之后进行退出即可
//	if (p != NULL && p->next == p)
//	{
//		printf("%d->头\n", p->data);
//		return;
//	}
//
//	//一般情况下进行打印
//	LNode* cur = p;
//	while (cur->next!=p)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("%d->头\n",cur->data);
//}
//
//
//
//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//删除前驱节点:
//我们删除最后一个前驱节点的时候可能并不好删除，那么我们换一种思路
//找到最后一个节点和它的前驱节点，然后我们交换这两个节点的值，然后删除最后一个节点的值，就会变得简单很多
//1->2->3->4->5->6
//我们要删除6的前驱节点5
//首先找到5，6的位置，5用prev标识，6用cur标识
//然后交换两个节点的值变成下面这种形式
//1->2->3->4->6->5
//此时prev指向6.cur指向5，我们只要删除cur节点即可
//void Pop_Back(LNode** p)
//{
//
//	//前后指针
//	//cur用来找到最后一个节点
//	//prev用来找到最后一个节点的前驱节点
//	//找到后直接prev->next=cur->next;free(cur)即可完成
//	LNode* cur = *p;
//	LNode* prev = cur;
//	while (cur!=NULL&&cur->next != (*p))
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//
//	//当只有一个元素时不进行删除
//	if (cur == prev)
//	{
//		return;
//	}
//	
//
//	//这里其实可以不用判断的，只是为了取消VS2019的报错
//	if (cur != NULL)
//	{
//		Swap(&prev->data, &cur->data);
//		LNode* next = cur->next;
//		prev->next = next;
//		free(cur);
//	}
//
//	
//}
//
//void menu()
//{
//	printf("\t\t1.插入元素\n");
//	printf("\t\t2.删除尾部元素\n");
//	printf("\t\t3.打印链表\n");
//	printf("\t\t0.退出\n");
//}
//int main()
//{
//	LNode* p=NULL;
//	int option = 0;
//	int x = 0;
//	menu();
//	while (1)
//	{
//		scanf("%d", &option);
//		switch (option)
//		{
//		case 0:
//			exit(0);
//			break;
//		case 1:
//			printf("输入元素:");
//			scanf("%d", &x);
//			Push_Back(&p, x);
//			printf("插入完成\n");
//			break;
//		case 2:
//			Pop_Back(&p);
//			printf("删除完成\n");
//			break;
//		case 3:
//			Print(p);
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//	}
//}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct LNode
{
	char data;
	struct LNode* next;
}LNode;


//链表的插入
void Push_Back(LNode** p, char x)
{

	//首次插入
	LNode* cur = (*p);
	if (cur == NULL)
	{
		cur = (LNode*)malloc(sizeof(LNode));
		if (cur != NULL)
		{
			cur->data = x;
			cur->next = NULL;
			*p = cur;
			return;
		}
	}

	//之后插入
	LNode* prev = *p;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	cur = (LNode*)malloc(sizeof(LNode));
	if (cur != NULL)
	{
		cur->data = x;
		cur->next = NULL;
		if(prev)
		prev->next = cur;
		return;
	}
}


//将单链表分成三个不同的链表
//a代表数字字符
//b代表字母字符
//c代表其它字符
void  Separate_List(LNode* p, LNode** a, LNode** b, LNode** c)
{
	LNode* cur = p;
	if (cur == NULL)
		return;
	*a = NULL;
	*b = NULL;
	*c = NULL;	
	LNode* _a = *a;
	LNode* _b = *b;
	LNode* _c = *c;
	while (cur != NULL)
	{
		//数字处理
		if (cur->data >= '0' && cur->data <= '9')
		{
			if (_a == NULL)
			{
				_a = (LNode*)malloc(sizeof(LNode));
				if (_a)
				{
					_a->data = cur->data;
					_a->next = NULL;
					*a = _a;
				}
			}
			else
			{
				LNode* temp = (LNode*)malloc(sizeof(LNode));
				if (temp)
				{
					temp->data = cur->data;
					temp->next = NULL;
					_a->next = temp;
					_a = _a->next;
				}
			}
		}

		//字母处理
		else if ((cur->data >= 'a' && cur->data <= 'z') || (cur->data >= 'A' && cur->data <= 'Z'))
		{
			if (_b == NULL)
			{
				_b = (LNode*)malloc(sizeof(LNode));
				if (_b)
				{
					_b->data = cur->data;
					_b->next = NULL;
					*b = _b;
				}
			}
			else
			{
				LNode* temp = (LNode*)malloc(sizeof(LNode));
				if (temp)
				{
					temp->data = cur->data;
					temp->next = NULL;
					_b->next = temp;
					_b = _b->next;
				}
			}
		}

		//特殊字符的处理
		else
		{
			if (_c == NULL)
			{
				_c = (LNode*)malloc(sizeof(LNode));
				if (_c)
				{
					_c->data = cur->data;
					_c->next = NULL;
					*c = _c;
				}
			}
			else
			{
				LNode* temp = (LNode*)malloc(sizeof(LNode));
				if (temp)
				{
					temp->data = cur->data;
					temp->next = NULL;
					_c->next = temp;
					_c = _c->next;
				}
			}
		}
		cur = cur->next;
	}
}

void Print(LNode*p)
{
	if (p == NULL)
	{
		return;
	}
	LNode* cur = p;
	while (cur != NULL)
	{
		printf("%c->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


int main()
{
	//p为原始链表
	LNode* p = NULL;

	//a,b,c为分离后的链表
	LNode* a = NULL;
	LNode* b = NULL;
	LNode* c = NULL;

	int option = 0;
	//输入字符串转化为链表
	char arr[1000] = {'\0'};
	printf("输入字符串:\n");
	scanf("%s", arr);
	for (size_t i = 0; i < strlen(arr); i++)
	{
		Push_Back(&p, arr[i]);
	}
	//打印
	printf("分离前:\n");
	Print(p);

	//分离链表
	Separate_List(p, &a, &b, &c);
	//打印分离后的链表
	printf("分离后:\n");
	Print(a);
	Print(b);
	Print(c);

	


	return 0;
}

