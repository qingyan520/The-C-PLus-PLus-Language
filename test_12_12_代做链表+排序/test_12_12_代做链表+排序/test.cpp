///*
//��дһ�������ĳ���ʵ�ֵ�����Ľ��������롢ɾ��������Ȼ���������
//��1������һ����ͷ���ĵ�����
//��2�����㵥����ĳ��ȣ�Ȼ�����������
//��3������ֵΪx��ֱ��ǰ�����q��
//��4��ɾ��ֵΪx�Ľ�㡣
//��5���ѵ���������Ԫ�����ã������������µĽ��ռ䣩��
//��6�����ã�1������������ʵ�ֽ���ֽ��������������һ��ȫ��Ϊ��������һ��ȫ��Ϊż��������������֪�Ĵ洢�ռ䣩��
//��7���������������һ���򵥵Ĳ˵����ֱ���������㷨��
//*/
//
//#include "stdio.h"
//#include "stdlib.h"
////#define _CRT_SECURE_NO_WARNINGS 
//typedef int elemtype;
//typedef struct lnode    //����������
//{
//	elemtype data;
//	struct lnode* next;
//}lnode, * linklist;
//int initlist(linklist& L)   //��ʼ��������
//{
//	L = (linklist)malloc(sizeof(lnode));   //��ͷ���ӽ��
//	if (!L) exit(-2);
//	L->next = NULL;
//	return 1;
//}//��ʼ����һ���ձ�
//
//
////1.ͷ�巨���ɵ�����
//void createlist(linklist& L) //���ɵ�����
//{
//	linklist p;
//	printf("������Ԫ�أ���0��������\n");
//	int x;
//	scanf("%d", &x);
//	while (x) {
//		p = (linklist)malloc(sizeof(lnode));
//
//		//x����ʱ������һ����㲢���뵽��ͷ��
//		if (p != NULL)
//		{
//
//			p->data = x;
//			p->next = L->next;
//			L->next = p;
//		}
//		else
//		{
//			printf("malloc fail\n");
//			return;
//		}
//		scanf("%d", &x);
//	}  //ѭ������x��ֵ�����ɵ������еĽ�㣬ֱ��x=0Ϊֹ��
//
//}
//
//
////2.β�巨����Ԫ�ص�����
//void createlist_2(linklist& L)
//{
//	printf("������Ԫ�أ���0��������\n");
//	linklist p, r;
//	int x;
//	r = L;
//	scanf("%d", &x);
//	while (x) 
//	{
//		p = (linklist)malloc(sizeof(lnode));
//		//x����ʱ������һ����㲢���뵽��β��
//		if (p != NULL)
//		{
//			p->data = x;
//			p->next = NULL;
//			r->next = p;
//			r = p;
//		}
//		scanf("%d", &x);
//	}
//}
//
//
////9.��ӡ������
//void shuchulist(linklist L)
//{
//	linklist p;
//	p = L->next;
//	while (p)
//	{
//		printf("%d->", p->data);      //ͨ������ı�������������е���Ϣ
//		p = p->next;
//		if (p == NULL)
//		{
//			printf("NULL");
//		}
//	}
//	printf("\n");
//}
//
//
////8.���㵥����ĳ���
//int lengthlist(linklist L)
//{
//	linklist p;
//	int m = 0;
//	p = L->next;
//	while (p)
//	{
//		m++;  //ͨ������ı�����ͳ�Ƴ���
//		p = p->next;
//	}
//	return m;
//}
//
////10.���õ�����
//void nizhilist(linklist& L)
////���õ�������
//{
//	if (L->next == nullptr)
//		return;
//	linklist cur = L->next;
//	linklist NewHead = nullptr;
//	while (cur)
//	{
//		//ͷ�巨ʵ�����������:��ÿһ��Ԫ��ͷ�嵽������ȥ
//		linklist next = cur->next;
//		cur->next = NewHead;
//		NewHead = cur;
//		cur = next;
//	}
//	L->next= NewHead;
//
//}
//
////7.ɾ������ż���ڵ�
//void fenlielist(linklist& La, linklist& Lb)
////ʵ�ֽ�La�ֽ��������������һ��ȫ��Ϊ��������һ��ȫ��Ϊż��������������֪�Ĵ洢�ռ䣩��
//{
//	linklist p, q, r;
//	initlist(Lb);
//	p = La->next; 
//	q = p; 
//	r = Lb;
//	while (p)
//	{
//		if (p->data % 2 != 0)
//		{
//			q->next = p->next;
//			r->next = p; 
//			r = p;
//			p = q->next;
//		}
//		else 
//		{
//			q = p; p = p->next;
//		}
//	}
//	r->next = NULL;
//	linklist temp = NULL;
//	temp = La;
//	La = Lb;
//	Lb = temp;
//}
//
//
//
////3.�ǵݼ��������Ԫ��
//void insertlistnode(linklist& La, int x)
//{
//
//	linklist cur = La->next;
//	linklist prev = La;
//	while (cur!=NULL&&x > cur->data)
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//
//	//cur����NULL����ֱ���ߵ���β��������β��
//	if (cur == NULL)
//	{
//		linklist temp = (linklist)malloc(sizeof(lnode));
//		if (temp != NULL)
//		{
//			temp->data = x;
//			temp->next = NULL;
//			prev->next = temp;
//		}
//	}
//
//	//cur!=NULL�������м�λ�ý��в���
//	else
//	{
//		linklist temp = (linklist)malloc(sizeof(lnode));
//		if (temp != NULL)
//		{
//			temp->data = x;
//			temp->next = NULL;
//			prev->next = temp;
//			temp->next = cur;
//		}
//	}
//}
//
//
////6.ɾ��ָ���ڵ�
//void eraselistnode(linklist& La, int x)
//{
//	linklist cur = La->next;
//	linklist prev = La;
//	while (cur)
//	{
//		if (cur->data == x)
//		{
//			break;
//		}
//		prev = cur;
//		cur = cur->next;
//	}
//	if (cur == NULL)
//	{
//		printf("δ�ҵ�Ҫɾ����Ԫ��\n");
//	}
//	else
//	{
//		prev->next = cur->next;
//	}
//}
//
//
////4.����ͷ������ڵ�
//void insertfrontlistnode(linklist& La, int x)
//{
//	linklist temp = (linklist)malloc(sizeof(lnode));
//	if (temp != NULL)
//	{
//		temp->data = x;
//		temp->next = NULL;
//		linklist next = La->next;
//		La->next = temp;
//		temp->next = next;
//	}
//	else
//	{
//		printf("malloc fail\n");
//	}
//}
//
////5.����β������ڵ�
//void insertbacklistnode(linklist& La, int x)
//{
//	linklist cur = La->next;
//	linklist prev = La;
//	while (cur != NULL)
//	{
//		prev = cur;
//		cur = cur->next;
//	}
//	cur = (linklist)malloc(sizeof(lnode));
//	if (cur != NULL)
//	{
//		cur->data = x;
//		cur->next = NULL;
//		prev->next = cur;
//	}
//
//}
//
//
//void menu()
//{
//	printf("\t\t1.ͷ�巨��������\n");
//	printf("\t\t2.β�巨��������\n");
//	printf("\t\t3.�ǵݼ��������Ԫ��\n");
//	printf("\t\t4.����ͷ������Ԫ��\n");
//	printf("\t\t5.����β������Ԫ��\n");
//	printf("\t\t6.ɾ��ָ��Ԫ��\n");
//	printf("\t\t7.ɾ������ż���ڵ�\n");
//	printf("\t\t8.����������\n");
//	printf("\t\t9.��ʾ����\n");
//	printf("\t\t10.��������\n");
//	printf("\t\t0.�˳�\n");
//}
//
//int main()
//{
//	linklist La =NULL;
//	initlist(La);
//	linklist Lb = NULL;
//	int option = 0;
//	int x = 0;//�ǵݼ���������Ԫ��
//	int y = 0;//ͷ��Ԫ��
//	int z = 0;//β��Ԫ��
//	int w = 0;//ɾ��Ԫ��
//	while (1)
//	{
//		menu();
//		scanf("%d", &option);
//		switch (option)
//		{
//		case 0:
//			printf("��ӭ�´�ʹ��\n");
//			exit(1);
//		case 1:
//			createlist(La);
//			break;
//		case 2:
//			createlist_2(La);
//			break;
//		case 3:
//			
//			printf("������Ҫ����Ԫ��:\n");
//			scanf("%d", &x);
//			insertlistnode(La, x);
//			break;
//		case 4:
//			printf("������ͷ��Ԫ��:\n");
//			scanf("%d", &y);
//			insertfrontlistnode(La, y);
//			break;
//		case 5:
//			printf("������β��Ԫ��:\n");
//			scanf("%d", &z);
//			insertbacklistnode(La, z);
//			break;
//		case 6:
//			printf("������Ҫɾ��Ԫ��:\n");
//			scanf("%d", &w);
//			eraselistnode(La, w);
//			break;
//		case 7:
//			fenlielist(La, Lb);
//			break;
//		case 8:
//			printf("����ĳ���Ϊ:%d\n", lengthlist(La));
//			break;
//		case 9:
//			shuchulist(La);
//			break;
//		case 10:
//			nizhilist(La);
//			break;
//		default:
//			printf("�������,����������:\n");
//			break;
//		}
//	}
//	return 0;
//}



//�����㷨
#include<stdio.h>
#include<stdlib.h>
#define N 1000
//��ѡ������ֱ�Ӳ�������ð�����򡢿������򡢶�����


//1.��ѡ������
void SelectSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}


//2.ֱ�Ӳ�������
void InsertSort(int* arr, int n)
{
	//ѭ������Ϊ[0,end-2]���ɣ����һ��Ԫ���±�Ϊn-1�������䷶ΧΪ��һ��Ԫ�ص������ڶ���Ԫ�ط�Χ����
	for (int i = 0; i < n - 1; i++)
	{
		//����arr[i+1]��Ҫ��������ݣ���[0,end]��ǰ����������У���arr[i+1]����ǰ�����������
		int end = i;
		int temp = arr[i + 1];
		while (end >= 0)
		{
			//���ǰ��һ������Ҫ��������ݴ���ô�ͺ������Ԫ��
			if (arr[end] > temp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//ǰ��Ԫ�ز�����Ҫ����Ԫ�أ��˳�ѭ��
			else
			{
				break;
			}
		}
		//ѭ���˳��������
		//1.��end=-1ʱ����Ҫ�����Ԫ��Ϊ��СԪ��ʱ��end<0����ѭ������ʱend+1�պ�Ϊ��һ��Ԫ��λ�ã������ΪҪ�����Ԫ��
		//2.���Ҫ�����Ԫ�ر�ǰ��Ԫ�ش��˳�����ǰ��һ��Ԫ�ص���һ��Ԫ��ΪҪ�����Ԫ��
		arr[end + 1] = temp;
	}
}


//3.ð������
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}


//4.��������
// //ѡȡ��߻����ұߵ�ֵ��Ϊkeyֵ
//�ұ��������ұ�keyС�����֣�����������ұ�key������֣��ҵ��󽻻�λ��
//���������key�ᵽ���ʵ�λ�ã�����ߵ����ֶ���keyС���ұߵ����ֶ���key��
//֮��������Ϊkey��ߺ��ұߣ�Ȼ�����������������ڽ����������裬
// ������ÿ����������һ�����ֵ�������ָ��λ�ã�������������ֶ��������λ��
// 

//��������ʱ�临�Ӷ�O(N*logN),����������ʱ��Ϊ������ʱ�临�Ӷ�ΪO(N*N)
//��ʱ����ͨ���Ż����
int GetMid(int* arr, int left, int right)
{
	int mid = (left + right) / 2;
	if ((arr[mid] - arr[right]) * (arr[mid] - arr[left]) <= 0)
	{
		return mid;
	}
	else if ((arr[left] - arr[mid]) * (arr[left] - arr[right]) <= 0)
	{
		return left;
	}
	else
	{
		return right;
	}
}
void QuickSort(int* arr, int begin, int end)
{
	//�ݹ���ֹ����
	if (begin >= end)
	{
		return;
	}
	//�ҵ���������
	int left = begin, right = end;
	int mid = GetMid(arr, left, right);
	Swap(&arr[left], &arr[mid]);
	int key = begin;
	//�ұ��������ұ�keyС�����֣�����������ұ�key������֣��ҵ��󽻻�λ��
	//���������key�ᵽ���ʵ�λ�ã�����ߵ����ֶ���keyС���ұߵ����ֶ���key��
	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
		{
			right--;
		}
		while (left < right && arr[left] <= arr[key])
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	//����λ��ʹԪ�ش��ں��ʵ�λ����
	Swap(&arr[key], &arr[left]);
	//������������ʹ֮������
	QuickSort(arr, begin, left - 1);
	QuickSort(arr, left + 1, end);
}


//5.����
////������
////1.�Ƚ��ѣ������򣬽���ѣ��Ž��򣬽�С��
////2.������һ���������һ������λ�ã�Ȼ��ʹ�����µ����㷨
////ע�⣺����ʱ�����һ����Ҷ�ӽ�㿪ʼ������n-1-1��/2��ʼʹ��ʹ�����µ����㷨���н���
////      ����֮����бȽϣ�������һ���������һ������λ�ã�Ȼ��ʹ�����µ����㷨����ѡ���ڶ������

//�������
void AdjustDown(int* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1<n&&arr[child + 1] > arr[child])
		{
			child = child + 1;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	//1.�Ƚ������
	for (int i = (n-1-1)/2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}
	//2.������һ��Ԫ��λ�ú����һ��Ԫ��λ�ã�--end��Ȼ��ʹ�����µ����㷨��������
	int end = n - 1;
	while (end >0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}
}

void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void menu()
{
	printf("\t\t1.��ѡ������\n");
	printf("\t\t2.ֱ�Ӳ�������\n");
	printf("\t\t3.ð������\n");
	printf("\t\t4.��������\n");
	printf("\t\t5.����\n");
	printf("\t\t0.�˳�\n");
}

int main()
{
	int arr[N] = { 0 };
	printf("������Ҫ�����Ԫ�ظ���\n");
	int n;
	scanf_s("%d", &n);
	printf("������Ԫ��:\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	int option = 0;
	while (1)
	{
		//��������arr2:
		int arr2[N];
		for (int i = 0; i < n; i++)
		{
			arr2[i] = arr[i];
		}
		menu();
		printf("����ǰ��");
		Print(arr2, n);
		printf("�������Ӧ��ѡ��:\n");
		scanf_s("%d", &option);
		switch (option)
		{
		case 0:
			printf("�˳�!\n");
			exit(1);

		case 1:
			//1.��ѡ������
			SelectSort(arr2, n);
			printf("�����");
			Print(arr2, n);
			break;

		case 2:
			//2.ֱ�Ӳ�������
			InsertSort(arr2, n);
			printf("�����");
			Print(arr2, n);
			break;

		case 3:
			//3.ð������
			BubbleSort(arr2, n);
			printf("�����");
			Print(arr2, n);
			break;
		
		case 4:
			//4.��������
			QuickSort(arr2, 0, n - 1);
			printf("�����");
			Print(arr2, n);
			break;

		case 5:
			//����
			HeapSort(arr2, n);
			printf("�����");
			Print(arr2, n);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}

}

