///*
//编写一个完整的程序，实现单链表的建立、插入、删除、输出等基本操作。
//（1）建立一个带头结点的单链表。
//（2）计算单链表的长度，然后输出单链表。
//（3）查找值为x的直接前驱结点q。
//（4）删除值为x的结点。
//（5）把单向链表中元素逆置（不允许申请新的结点空间）。
//（6）利用（1）建立的链表，实现将其分解成两个链表，其中一个全部为奇数，另一个全部为偶数（尽量利用已知的存储空间）。
//（7）在主函数中设计一个简单的菜单，分别测试上述算法。
//*/
//
//#include "stdio.h"
//#include "stdlib.h"
////#define _CRT_SECURE_NO_WARNINGS 
//typedef int elemtype;
//typedef struct lnode    //定义结点类型
//{
//	elemtype data;
//	struct lnode* next;
//}lnode, * linklist;
//int initlist(linklist& L)   //初始化单链表
//{
//	L = (linklist)malloc(sizeof(lnode));   //表头附加结点
//	if (!L) exit(-2);
//	L->next = NULL;
//	return 1;
//}//初始化了一个空表
//
//
////1.头插法生成单链表
//void createlist(linklist& L) //生成单链表
//{
//	linklist p;
//	printf("请输入元素，按0结束输入\n");
//	int x;
//	scanf("%d", &x);
//	while (x) {
//		p = (linklist)malloc(sizeof(lnode));
//
//		//x非零时，生成一个结点并插入到表头。
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
//	}  //循环输入x的值，生成单链表中的结点，直到x=0为止。
//
//}
//
//
////2.尾插法创建元素单链表
//void createlist_2(linklist& L)
//{
//	printf("请输入元素，按0结束输入\n");
//	linklist p, r;
//	int x;
//	r = L;
//	scanf("%d", &x);
//	while (x) 
//	{
//		p = (linklist)malloc(sizeof(lnode));
//		//x非零时，生成一个结点并插入到表尾。
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
////9.打印单链表
//void shuchulist(linklist L)
//{
//	linklist p;
//	p = L->next;
//	while (p)
//	{
//		printf("%d->", p->data);      //通过链表的遍历来输出链表中的信息
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
////8.计算单链表的长度
//int lengthlist(linklist L)
//{
//	linklist p;
//	int m = 0;
//	p = L->next;
//	while (p)
//	{
//		m++;  //通过链表的遍历来统计长度
//		p = p->next;
//	}
//	return m;
//}
//
////10.逆置单链表
//void nizhilist(linklist& L)
////逆置单链表函数
//{
//	if (L->next == nullptr)
//		return;
//	linklist cur = L->next;
//	linklist NewHead = nullptr;
//	while (cur)
//	{
//		//头插法实现链表的逆置:将每一个元素头插到链表当中去
//		linklist next = cur->next;
//		cur->next = NewHead;
//		NewHead = cur;
//		cur = next;
//	}
//	L->next= NewHead;
//
//}
//
////7.删除所有偶数节点
//void fenlielist(linklist& La, linklist& Lb)
////实现将La分解成两个链表，其中一个全部为奇数，另一个全部为偶数（尽量利用已知的存储空间）。
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
////3.非递减链表插入元素
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
//	//cur等于NULL代表直接走到了尾部，进行尾插
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
//	//cur!=NULL代表在中间位置进行插入
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
////6.删除指定节点
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
//		printf("未找到要删除的元素\n");
//	}
//	else
//	{
//		prev->next = cur->next;
//	}
//}
//
//
////4.链表头部插入节点
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
////5.链表尾部插入节点
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
//	printf("\t\t1.头插法生成链表\n");
//	printf("\t\t2.尾插法生成链表\n");
//	printf("\t\t3.非递减链表插入元素\n");
//	printf("\t\t4.链表头部插入元素\n");
//	printf("\t\t5.链表尾部插入元素\n");
//	printf("\t\t6.删除指定元素\n");
//	printf("\t\t7.删除所有偶数节点\n");
//	printf("\t\t8.计算链表长度\n");
//	printf("\t\t9.显示链表\n");
//	printf("\t\t10.逆置链表\n");
//	printf("\t\t0.退出\n");
//}
//
//int main()
//{
//	linklist La =NULL;
//	initlist(La);
//	linklist Lb = NULL;
//	int option = 0;
//	int x = 0;//非递减链表插入的元素
//	int y = 0;//头插元素
//	int z = 0;//尾插元素
//	int w = 0;//删除元素
//	while (1)
//	{
//		menu();
//		scanf("%d", &option);
//		switch (option)
//		{
//		case 0:
//			printf("欢迎下次使用\n");
//			exit(1);
//		case 1:
//			createlist(La);
//			break;
//		case 2:
//			createlist_2(La);
//			break;
//		case 3:
//			
//			printf("请输入要插入元素:\n");
//			scanf("%d", &x);
//			insertlistnode(La, x);
//			break;
//		case 4:
//			printf("请输入头插元素:\n");
//			scanf("%d", &y);
//			insertfrontlistnode(La, y);
//			break;
//		case 5:
//			printf("请输入尾插元素:\n");
//			scanf("%d", &z);
//			insertbacklistnode(La, z);
//			break;
//		case 6:
//			printf("请输入要删除元素:\n");
//			scanf("%d", &w);
//			eraselistnode(La, w);
//			break;
//		case 7:
//			fenlielist(La, Lb);
//			break;
//		case 8:
//			printf("链表的长度为:%d\n", lengthlist(La));
//			break;
//		case 9:
//			shuchulist(La);
//			break;
//		case 10:
//			nizhilist(La);
//			break;
//		default:
//			printf("输入错误,请重新输入:\n");
//			break;
//		}
//	}
//	return 0;
//}



//排序算法
#include<stdio.h>
#include<stdlib.h>
#define N 1000
//简单选择排序、直接插入排序、冒泡排序、快速排序、堆排序


//1.简单选择排序
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


//2.直接插入排序
void InsertSort(int* arr, int n)
{
	//循环区间为[0,end-2]即可，最后一个元素下表为n-1，即区间范围为第一个元素到倒数第二个元素范围即可
	for (int i = 0; i < n - 1; i++)
	{
		//假设arr[i+1]是要插入的数据，而[0,end]是前面的有序数列，将arr[i+1]插入前面的有序数列
		int end = i;
		int temp = arr[i + 1];
		while (end >= 0)
		{
			//如果前面一个数比要插入的数据大，那么就后移这个元素
			if (arr[end] > temp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//前面元素不大于要插入元素，退出循环
			else
			{
				break;
			}
		}
		//循环退出的情况：
		//1.当end=-1时，即要插入的元素为最小元素时，end<0结束循环，此时end+1刚好为第一个元素位置，让其称为要插入的元素
		//2.如果要插入的元素比前面元素大，退出，让前面一个元素的下一个元素为要插入的元素
		arr[end + 1] = temp;
	}
}


//3.冒泡排序
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


//4.快速排序
// //选取左边或者右边的值作为key值
//右边往左走找比key小的数字，左边往右走找比key大的数字，找到后交换位置
//这样到最后key会到合适的位置，而左边的数字都比key小，右边的数字都比key大
//之后将区间后分为key左边和右边，然后让在这两个区间内进行上述步骤，
// 这样，每次下来就有一个数字到达它的指定位置，到最后所有数字都到达合适位置
// 

//快速排序时间复杂度O(N*logN),当其是有序时，为最坏情况，时间复杂度为O(N*N)
//这时可以通过优化解决
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
	//递归终止条件
	if (begin >= end)
	{
		return;
	}
	//找到左右区间
	int left = begin, right = end;
	int mid = GetMid(arr, left, right);
	Swap(&arr[left], &arr[mid]);
	int key = begin;
	//右边往左走找比key小的数字，左边往右走找比key大的数字，找到后交换位置
	//这样到最后key会到合适的位置，而左边的数字都比key小，右边的数字都比key大
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
	//交换位置使元素处于合适的位置上
	Swap(&arr[key], &arr[left]);
	//遍历左右区间使之变有序
	QuickSort(arr, begin, left - 1);
	QuickSort(arr, left + 1, end);
}


//5.堆排
////堆排序
////1.先建堆：排升序，建大堆，排降序，建小堆
////2.交换第一个数和最后一个数的位置，然后使用向下调整算法
////注意：建堆时从最后一个非叶子结点开始，即（n-1-1）/2开始使用使用向下调整算法进行建堆
////      建堆之后进行比较，交换第一个数和最后一个数的位置，然后使用向下调整算法重新选出第二大的数

//建立大堆
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
	//1.先建立大堆
	for (int i = (n-1-1)/2; i >= 0; i--)
	{
		AdjustDown(arr, i, n);
	}
	//2.交换第一个元素位置和最后一个元素位置，--end，然后使用向下调整算法继续调整
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
	printf("\t\t1.简单选择排序\n");
	printf("\t\t2.直接插入排序\n");
	printf("\t\t3.冒泡排序\n");
	printf("\t\t4.快速排序\n");
	printf("\t\t5.堆排\n");
	printf("\t\t0.退出\n");
}

int main()
{
	int arr[N] = { 0 };
	printf("请输入要排序的元素个数\n");
	int n;
	scanf_s("%d", &n);
	printf("请输入元素:\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	int option = 0;
	while (1)
	{
		//建立数组arr2:
		int arr2[N];
		for (int i = 0; i < n; i++)
		{
			arr2[i] = arr[i];
		}
		menu();
		printf("排序前：");
		Print(arr2, n);
		printf("请输入对应的选项:\n");
		scanf_s("%d", &option);
		switch (option)
		{
		case 0:
			printf("退出!\n");
			exit(1);

		case 1:
			//1.简单选择排序
			SelectSort(arr2, n);
			printf("排序后：");
			Print(arr2, n);
			break;

		case 2:
			//2.直接插入排序
			InsertSort(arr2, n);
			printf("排序后：");
			Print(arr2, n);
			break;

		case 3:
			//3.冒泡排序
			BubbleSort(arr2, n);
			printf("排序后：");
			Print(arr2, n);
			break;
		
		case 4:
			//4.快速排序
			QuickSort(arr2, 0, n - 1);
			printf("排序后：");
			Print(arr2, n);
			break;

		case 5:
			//堆排
			HeapSort(arr2, n);
			printf("排序后：");
			Print(arr2, n);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}

}

