//#include<stdbool.h>
//#include<stdio.h>
//typedef struct Node
//{
//	int val;
//	struct ListNode* next;
//}ListNode;
//
//
//
////首先这是一个带头节点的单链表，那么我们先进行计数，算出链表中所有节点的个数，然后开辟空间，将这些节点保存到数组中，然后在数组中支持随机访问下标
////然后利用那个公式进行判断
//bool adjust(ListNode* head)
//{
//	ListNode* cur = head->next;//cur指向第一个节点
//	int count = 0;//计算节点的个数
//	while (cur != NULL)
//	{
//		cur = cur->next;
//		count++;
//	}
//
//	//计算完节点个数后开辟数组，将节点数据保存到数组中
//	int* arr = malloc(count * sizeof(int));
//	int i = 0;
//	cur = head->next;
//	//将节点数据保存到数组中
//	while (cur != NULL)
//	{
//		arr[i] = cur->val;
//		i++;
//		cur = cur->next;
//	}
//	//题目中说了i>=2，也就是至少有3节点
//	int d = arr[1] - arr[0];
//	for (int i = 2; i < count; i++)
//	{
//		if (arr[i] - arr[i - 1] != d)
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//
//int main()
//{
//	ListNode* Node0 = (ListNode*)malloc(sizeof(ListNode));//第一个节点为呀节点，不保存数据4
//	ListNode* Node1 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* Node2 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* Node3 = (ListNode*)malloc(sizeof(ListNode));
//	ListNode* Node4 = (ListNode*)malloc(sizeof(ListNode));
//
//	Node0->val = 0;
//	Node0->next = Node1;
//	Node1->val = 1;
//	Node2->val = 2;
//	Node3->val = 3;
//	Node4->val = 4;
//	Node1->next = Node2;
//	Node2->next = Node3;
//	Node3->next = Node4;
//	Node4->next = NULL;
//	//上面简单构建单链表0(哑节点)---->1------>2------>3------->4
//	//判断是不是等差单链表
//	bool ret = adjust(Node0);
//	if (ret)
//	{
//		printf("是等差单链表\n");
//	}
//	else
//	{
//		printf("不是等差单链表\n");
//	}
//
//
//
//
//}


#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int val;
	struct ListNode* next;
}ListNode;

//首先这是一个带头节点的单链表，那么我们先进行计数，算出链表中所有节点的个数，然后开辟空间，将这些节点保存到数组中，然后在数组中支持随机访问下标
//然后利用那个公式进行判断
bool adjust(ListNode* head)
{
	//题目中说i从2开始，那么最起码有三个有效节点，不需要考虑0，1，2个节点的情况
	//first:head->next代表第一个节点，
	ListNode* first = head->next;

	//second:head->next->next代表第二个节点
	ListNode* second = first->next;

	//d代表等差数列的公差
	int d = second->val - first->val;
	while (second != NULL&&second->next!=NULL)
	{
		first = first->next;
		second = second->next;
		int flag = second->val - first->val;
		if (flag != d)
		{
			return false;
		}
	}
	
	return true;

}


int main()
{
	ListNode* Node0 = (ListNode*)malloc(sizeof(ListNode));//第一个节点为节点，不保存数据4
	ListNode* Node1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* Node2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* Node3 = (ListNode*)malloc(sizeof(ListNode));
	ListNode* Node4 = (ListNode*)malloc(sizeof(ListNode));

	//Node0->val = 0;
	//Node0->next = Node1;
	//Node1->val = 1;
	//Node2->val = 3;
	//Node3->val = 6;
	//Node4->val = 7;
	//Node1->next = Node2;
	//Node2->next = Node3;
	//Node3->next = Node4;
	//Node4->next = NULL;
	if (Node0)
	{
		Node0->val = 0;
		Node0->next = NULL;
	}
	if (Node1)
	{
		Node1->val = 5;
		Node1->next = NULL;
	}
	if (Node2)
	{
		Node2->val = 8;
		Node2->next = NULL;
	}
	if (Node3)
	{
		Node3->val = 7;
		Node3->next = NULL;
	}
	if (Node4)
	{
		Node4->val = 8;
		Node4->next = NULL;
	}
	if(Node0&&Node1)
	Node0->next = Node1;
	if(Node1&&Node2)
	Node1->next = Node2;
	if(Node2&&Node3)
	Node2->next = Node3;
	if(Node3&&Node4)
	Node3->next = Node4;
	if(Node4)
	Node4->next = NULL;


	//上面简单构建单链表0(哑节点)---->1------>2------>3------->4
	//判断是不是等差单链表
	bool ret = adjust(Node0);
	if (ret)
	{
		printf("是等差单链表\n");
	}
	else
	{
		printf("不是等差单链表\n");
	}
}