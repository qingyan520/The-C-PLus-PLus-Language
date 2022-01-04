////��������������ϲ���һ����������
//#include<stdio.h>
//#include<stdlib.h>
//
////����ڵ㶨��
//typedef struct  ListNode
//{
//	int val;
//	struct ListNode* next;
//}ListNode;
//
//
////�ϲ�������������
//ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
//{
//	ListNode* list = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* tail = list;
//	if (list == NULL)
//	{
//		printf("malloc fail\n");
//		return NULL;
//	}
//
//	//��ͷ�ڵ㲻�õ��Ĵ��������ǿ�ָ��
//	ListNode* p1 = list1->next;
//	ListNode* p2 = list2->next;
//
//
//
//	//˫ָ�������
//	while (p1 && p2)
//	{
//		if (p1->val > p2->val)
//		{
//			tail->next = p2;
//			tail = tail->next;
//			p2 = p2->next;
//		}
//		else if (p1->val < p2->val)
//		{
//			tail->next = p1;
//			tail = tail->next;
//			p1 = p1->next;
//		}
//		else
//		{
//			tail->next = p1;
//			tail = tail->next;
//			p1 = p1->next;
//			p2 = p2->next;
//		}
//	}
//	if (p1)
//	{
//		tail->next = p1;
//	}
//
//	if (p2)
//	{
//		tail->next = p2;
//	}
//
//	return list;
//
//}
//
//
//
//void Print(ListNode* list)
//{
//	ListNode* cur = list->next;
//
//	while (cur)
//	{
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}
//
//
//void test()
//{
//
//	//�ֶ�����������Ϊ��������
//	ListNode* list1 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* p2 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* p3 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* p4 = (ListNode*)malloc(sizeof(ListNode));
//
//	if (!(list1 && p1 && p2 && p3 && p4))
//	{
//		return;
//	}
//	p1->val = 1;
//	p2->val = 2;
//	p3->val = 3;
//	p4->val = 4;
//	
//	list1->next = p1;
//	p1->next = p2;
//	p2->next = p3;
//	p3->next = p4;
//	p4->next = NULL;
//
//
//	ListNode* list2 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* p5 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* p6 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* p7 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* p8 = (ListNode*)malloc(sizeof(ListNode));
//
//	if (!(list2&& p5 && p6 && p7 && p8))
//	{
//		return;
//	}
//	p5->val = 1;
//	p6->val = 2;
//	p7->val = 7;
//	p8->val = 8;
//
//	list2->next = p5;
//	p5->next = p6;
//	p6->next = p7;
//	p7->next = p8;
//	p8->next = NULL;
//
//
//	printf("�ϲ�ǰ:\n");
//	Print(list1);
//	Print(list2);
//
//
//	//�ϲ�����
//	ListNode* list = mergeTwoLists(list1, list2);
//
//	printf("�ϲ���:\n");
//	Print(list);
//
//
//
//}
//int main()
//{
//	test();
//	return 0;
//}




//KMP�㷨Ѱ���Ӵ�λ��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int next[1000] = { 0 };
char str1[1000] = { 0 };
char str2[1000] = { 0 };
void getNext(char*s)
{
	int j = 0;
	next[0] = 0;
	for (size_t i = 1; i < strlen(s); i++)//ע��i��1��ʼ
	{
		while (j > 0 && s[i] != s[j])//ǰ��׺����ͬ��
		{
			j = next[j - 1];//��ǰ����
		}
		if (s[i] == s[j])//�ҵ���ͬ��ǰ��׺
		{
			j++;
		}
		next[i] = j;//��j(ǰ׺�ĳ���)����next[j]
	}
}


int mystrstr(char* haystack, char* needle)
{
	if (strlen(needle) == 0)
	{
		return 0;
	}
	int n =(int)strlen(needle);
	getNext(needle);
	int j = 0;//��Ϊnext�������¼����ʼλ��Ϊ-1
	for (int i = 0; i < strlen(haystack); i++)
	{
		while (j > 0 && haystack[i] != needle[j])//��ƥ��
		{
			j = next[j - 1];//jѰ��֮ǰƥ���λ��
		}
		if (haystack[i] == needle[j])//ƥ�䣬i,jͬʱ����
		{
			j++;
		}
		if (j == n)//�������Ӵ���λ��
		{
			return (i - n + 1);
		}
	}

	//δ�ҵ�������-1
	return -1;

}

int main()
{
	printf("����DNA����:\n");
	scanf("%s", str1);
	printf("�����Ӵ�����:\n");
	scanf("%s", str2);
	size_t ret = mystrstr(str1, str2);
	if (ret == -1)
	{
		printf("δ�ҵ��Ӵ�\n");
	}
	else
	{
		printf("�ҵ��ˣ��Ӵ�λ��%s��%d��λ��\n",str1,ret+1);
	}
	return 0;
}