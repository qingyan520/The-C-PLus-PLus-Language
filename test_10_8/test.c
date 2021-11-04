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
////��������һ����ͷ�ڵ�ĵ�������ô�����Ƚ��м�����������������нڵ�ĸ�����Ȼ�󿪱ٿռ䣬����Щ�ڵ㱣�浽�����У�Ȼ����������֧����������±�
////Ȼ�������Ǹ���ʽ�����ж�
//bool adjust(ListNode* head)
//{
//	ListNode* cur = head->next;//curָ���һ���ڵ�
//	int count = 0;//����ڵ�ĸ���
//	while (cur != NULL)
//	{
//		cur = cur->next;
//		count++;
//	}
//
//	//������ڵ�����󿪱����飬���ڵ����ݱ��浽������
//	int* arr = malloc(count * sizeof(int));
//	int i = 0;
//	cur = head->next;
//	//���ڵ����ݱ��浽������
//	while (cur != NULL)
//	{
//		arr[i] = cur->val;
//		i++;
//		cur = cur->next;
//	}
//	//��Ŀ��˵��i>=2��Ҳ����������3�ڵ�
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
//	ListNode* Node0 = (ListNode*)malloc(sizeof(ListNode));//��һ���ڵ�Ϊѽ�ڵ㣬����������4
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
//	//����򵥹���������0(�ƽڵ�)---->1------>2------>3------->4
//	//�ж��ǲ��ǵȲ����
//	bool ret = adjust(Node0);
//	if (ret)
//	{
//		printf("�ǵȲ����\n");
//	}
//	else
//	{
//		printf("���ǵȲ����\n");
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

//��������һ����ͷ�ڵ�ĵ�������ô�����Ƚ��м�����������������нڵ�ĸ�����Ȼ�󿪱ٿռ䣬����Щ�ڵ㱣�浽�����У�Ȼ����������֧����������±�
//Ȼ�������Ǹ���ʽ�����ж�
bool adjust(ListNode* head)
{
	//��Ŀ��˵i��2��ʼ����ô��������������Ч�ڵ㣬����Ҫ����0��1��2���ڵ�����
	//first:head->next�����һ���ڵ㣬
	ListNode* first = head->next;

	//second:head->next->next����ڶ����ڵ�
	ListNode* second = first->next;

	//d����Ȳ����еĹ���
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
	ListNode* Node0 = (ListNode*)malloc(sizeof(ListNode));//��һ���ڵ�Ϊ�ڵ㣬����������4
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


	//����򵥹���������0(�ƽڵ�)---->1------>2------>3------->4
	//�ж��ǲ��ǵȲ����
	bool ret = adjust(Node0);
	if (ret)
	{
		printf("�ǵȲ����\n");
	}
	else
	{
		printf("���ǵȲ����\n");
	}
}