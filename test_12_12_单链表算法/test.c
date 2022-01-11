//
//////Ҫ��:��������ͷ�ڵ��ѭ���������䳤�ȴ���1��RΪ����β���
//////1.��ȡβ�巨����һ��ѭ��������Ȼ������õ������ֵ
//////2.ɾ��R��ǰ���ڵ㣬������ɾ�����ڵ������ĸ���������ֵ
//#include<stdio.h>
//#include<stdlib.h>
//
////ѭ��������ڵ�Ķ���
//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode;
//
//
////��ѭ��������β����������
//void Push_Back(LNode** p, int x)
//{
//	//��һ�β����ʱ��ֱ�ӽ��в��룬��*p->next=(*p),�γ�һ����յĻ�
//	LNode* cur = (*p);
//	if (cur == NULL)
//	{
//		//���ٽڵ�
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
//	//֮�����
//	//����ڵ�
//	LNode* temp = (LNode*)malloc(sizeof(LNode));
//	if (temp != NULL)
//	{
//		temp->data = x;
//
//		//�ҵ�β���
//		while (cur!=NULL&&cur->next!=(*p))
//		{
//			cur = cur->next;
//		}
//
//		//�����ж�Ϊ�ղ��Ǳ�Ҫ��������Ҫ��Ϊ�˷�ֹVS2019����
//		if (cur != NULL)
//		{
//			LNode* next = cur->next;
//			cur->next = temp;
//			temp->next = next;
//		}
//	}
//}
//
////��ӡ������
//void Print(LNode* p)
//{
//	//�жϽڵ��Ƿ�Ϊ�գ�Ϊ�վͲ����д���
//	if (p == NULL)
//		return;
//
//	//���ֻҪһ���ڵ��ֻ���д�ӡ����ڵ�֮������˳�����
//	if (p != NULL && p->next == p)
//	{
//		printf("%d->ͷ\n", p->data);
//		return;
//	}
//
//	//һ������½��д�ӡ
//	LNode* cur = p;
//	while (cur->next!=p)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("%d->ͷ\n",cur->data);
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
//ɾ��ǰ���ڵ�:
//����ɾ�����һ��ǰ���ڵ��ʱ����ܲ�����ɾ������ô���ǻ�һ��˼·
//�ҵ����һ���ڵ������ǰ���ڵ㣬Ȼ�����ǽ����������ڵ��ֵ��Ȼ��ɾ�����һ���ڵ��ֵ���ͻ��ü򵥺ܶ�
//1->2->3->4->5->6
//����Ҫɾ��6��ǰ���ڵ�5
//�����ҵ�5��6��λ�ã�5��prev��ʶ��6��cur��ʶ
//Ȼ�󽻻������ڵ��ֵ�������������ʽ
//1->2->3->4->6->5
//��ʱprevָ��6.curָ��5������ֻҪɾ��cur�ڵ㼴��
//void Pop_Back(LNode** p)
//{
//
//	//ǰ��ָ��
//	//cur�����ҵ����һ���ڵ�
//	//prev�����ҵ����һ���ڵ��ǰ���ڵ�
//	//�ҵ���ֱ��prev->next=cur->next;free(cur)�������
//	LNode* cur = *p;
//	LNode* prev = cur;
//	while (cur!=NULL&&cur->next != (*p))
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//
//	//��ֻ��һ��Ԫ��ʱ������ɾ��
//	if (cur == prev)
//	{
//		return;
//	}
//	
//
//	//������ʵ���Բ����жϵģ�ֻ��Ϊ��ȡ��VS2019�ı���
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
//	printf("\t\t1.����Ԫ��\n");
//	printf("\t\t2.ɾ��β��Ԫ��\n");
//	printf("\t\t3.��ӡ����\n");
//	printf("\t\t0.�˳�\n");
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
//			printf("����Ԫ��:");
//			scanf("%d", &x);
//			Push_Back(&p, x);
//			printf("�������\n");
//			break;
//		case 2:
//			Pop_Back(&p);
//			printf("ɾ�����\n");
//			break;
//		case 3:
//			Print(p);
//			break;
//		default:
//			printf("�����������������\n");
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


//����Ĳ���
void Push_Back(LNode** p, char x)
{

	//�״β���
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

	//֮�����
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


//��������ֳ�������ͬ������
//a���������ַ�
//b������ĸ�ַ�
//c���������ַ�
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
		//���ִ���
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

		//��ĸ����
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

		//�����ַ��Ĵ���
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
	//pΪԭʼ����
	LNode* p = NULL;

	//a,b,cΪ����������
	LNode* a = NULL;
	LNode* b = NULL;
	LNode* c = NULL;

	int option = 0;
	//�����ַ���ת��Ϊ����
	char arr[1000] = {'\0'};
	printf("�����ַ���:\n");
	scanf("%s", arr);
	for (size_t i = 0; i < strlen(arr); i++)
	{
		Push_Back(&p, arr[i]);
	}
	//��ӡ
	printf("����ǰ:\n");
	Print(p);

	//��������
	Separate_List(p, &a, &b, &c);
	//��ӡ����������
	printf("�����:\n");
	Print(a);
	Print(b);
	Print(c);

	


	return 0;
}

