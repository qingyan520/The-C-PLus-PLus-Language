////将两个有序链表合并成一个有序链表
//#include<stdio.h>
//#include<stdlib.h>
//
////链表节点定义
//typedef struct  ListNode
//{
//	int val;
//	struct ListNode* next;
//}ListNode;
//
//
////合并两个有序链表
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
//	//带头节点不用担心传过来的是空指针
//	ListNode* p1 = list1->next;
//	ListNode* p2 = list2->next;
//
//
//
//	//双指针向后走
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
//	//手动创建链表作为测试用例
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
//	printf("合并前:\n");
//	Print(list1);
//	Print(list2);
//
//
//	//合并链表
//	ListNode* list = mergeTwoLists(list1, list2);
//
//	printf("合并后:\n");
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




//KMP算法寻找子串位置
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
	for (size_t i = 1; i < strlen(s); i++)//注意i从1开始
	{
		while (j > 0 && s[i] != s[j])//前后缀不相同了
		{
			j = next[j - 1];//向前回退
		}
		if (s[i] == s[j])//找到相同的前后缀
		{
			j++;
		}
		next[i] = j;//将j(前缀的长度)赋给next[j]
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
	int j = 0;//因为next数组里记录的起始位置为-1
	for (int i = 0; i < strlen(haystack); i++)
	{
		while (j > 0 && haystack[i] != needle[j])//不匹配
		{
			j = next[j - 1];//j寻找之前匹配的位置
		}
		if (haystack[i] == needle[j])//匹配，i,j同时后移
		{
			j++;
		}
		if (j == n)//出现了子串的位置
		{
			return (i - n + 1);
		}
	}

	//未找到，返回-1
	return -1;

}

int main()
{
	printf("输入DNA序列:\n");
	scanf("%s", str1);
	printf("输入子串序列:\n");
	scanf("%s", str2);
	size_t ret = mystrstr(str1, str2);
	if (ret == -1)
	{
		printf("未找到子串\n");
	}
	else
	{
		printf("找到了，子串位于%s的%d号位置\n",str1,ret+1);
	}
	return 0;
}