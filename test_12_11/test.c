////判断栈的压入与弹出序列
//
//
//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
//#include<stdlib.h>
//
//#define N 100
//#define START 100
//#define ADD 100
//
////模拟实现一个栈
//typedef char T;
//typedef struct Stack
//{
//    int size;
//    T* data;
//    int top;
//}Stack;
////判断栈是否为空
//bool IsEmpty(Stack* S)
//{
//    return S->top == 0;
//}
////初始化栈
//void InitStack(Stack* S)
//{
//    S->size = START;
//    S->data = (T*)malloc((S->size) * sizeof(T));
//    S->top = 0;
//}
////栈里面入数据
//void StackPush(Stack* S, T mii)
//{
//    //容量不够进行扩容
//    if (S->top == S->size)
//    {
//        S->size += ADD;
//        if (S->data != NULL)
//            S->data = (T*)realloc(S->data, (S->size) * sizeof(T));
//    }
//    //添加数据
//    S->data[(S->top)++] = mii;
//}
////删除栈顶元素
//int StackPop(Stack* S)
//{
//    if (!IsEmpty(S))
//    {
//        return S->data[--(S->top)];
//    }
//    else
//    {
//        return 0;
//    }
//}
//
////返回栈顶元素
//int StackTop(Stack* s)
//{
//    if (s->top == 0)
//    {
//        return -1;
//    }
//    return s->data[s->top-1];
//}
//
////销毁栈
//void DestroyStack(Stack* S)
//{
//    free(S->data);
//    S->data = NULL;
//    S->top = 0;
//    S->size = 0;
//}
//
//
////判断栈的压入与弹出序列是否一致
//bool validateStackSequences(T* pushed, int m, T* popped, int n)
//{
//    if (m != n)
//    {
//        return false;
//    }
//    int i = 0; 
//    int j = 0;
//    //建立一个栈
//    Stack s;
//    InitStack(&s);
//    //循环结束条件：pushed数组遍历完
//    while (i < m)
//    {
//        //每次将pushed[i]进入栈中
//        StackPush(&s, pushed[i]);
//        //判断刚进入栈的元素，即栈顶元素是否与popped[j]相等，相等st.pop(),j++
//        while (!IsEmpty(&s) && StackTop(&s) == popped[j])
//        {
//            StackPop(&s);
//            j++;
//        }
//        //直到st,top()与popped[j]不相等之后++i;
//        i++;
//    }
//
//    DestroyStack(&s);
//    //判断是否为栈的压入与弹出只需要判断popped数组是否走完了
//    return j == n;
//}
//
//int main()
//{
//    char str1[N];//创建数组str1代表栈的压入序列
//    char str2[N];//创建数组str2代表栈的弹出序列
//    printf("输入入栈序列：");
//    scanf("%s", str1);
//
//    while (1)
//    {
//        printf("输入出栈序列：");
//        scanf("%s", &str2);
//
//        if (validateStackSequences(str1, strlen(str1), str2, strlen(str2)))
//        {
//            printf("该序列是可能的出栈序列\n");
//        }
//        else
//        {
//            printf("该序列是不可能的出栈序列\n");
//        }
//    }
//	return 0;
//}


//链表实现大数相加
//以123+456为例，我们首先将这两位数字的每一位存储到链表中，编程下面这个样子：
//3-->2-->1-->NULL
//6-->5-->4-->NULL
//然后对应位置相加然后翻转链表即可：
//9-->7-->5
//翻转链表：
//5-->7-->9
//即为所求结果

//当然，上面是简单例子，实际情况中还有可能出现进位问题，以199+9为例进行说明
//9-->9-->1
//9
//相加
//第一次相加后：8--->1
//然后
//8-->1
//    9--->1
//8-->0-->2
//即当前位置=(List1->val+List2->val+进位)%10;
//下一个位置的进位=(List1->val+List2->val+进位)/10;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;


//将链表转换为数字
ListNode* Number_To_List(char*str)
{
	//创建头指针
	ListNode* p1 = NULL;
	//尾指针tail1指向p1,每次都是tail1向后走，p1保持在链表头部以便于返回头节点
	ListNode* tail1 = p1;

	//计算传入的字符串长度
	int n = strlen(str);

	//从最后一个字符开始将每一个元素添加到链表中
	int i = n - 1;
	while (i>=0)
	{
		//创建零时节点保存要存储的数据
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		if (temp == NULL)
			break;
		
		//注意将字符转换为数字
		temp->val = str[i]-'0';
		i--;
		temp->next = NULL;

		//如果头节点p1为NULL说明是插入第一个元素，那么将temp赋给头节点，尾指针tail1也指向p1
		if (p1 == NULL)
		{
			p1 = temp;
			tail1 = p1;
		}

		//头指针不为空说明tail1就是当前链表的最后一个位置，我们让tail1->next=temp，链接下一个节点，然后尾指针tail1向后移动
		else
		{
			tail1->next = temp;
			tail1 = tail1->next;

		}
	}

	//返回链表的头指针
	return p1;

}


//实现两个链表逆序相加
ListNode* Add_Numbers(ListNode* p1, ListNode* p2)
{
	//如果两个链表的节点都为空就不需要进行后面计算直接返回NULL
	if (p1 == NULL && p2 == NULL)
		return NULL;

	//ret为最终返回的指针
	ListNode* ret = NULL;
	ListNode* tail = ret;

	//next表示要进位
	//比如9+9=18，当前位置存储9，还要向前进1，而这个next就是保存这个进位的
	int next = 0;

	//p1和p2只要有一个不为空就可以向前走，代表计算未结束
	while (p1 != NULL || p2 != NULL)
	{
		//val用来代表当前两个链表对应位置数据的加和，注意加的时候要加上进位
		int val = 0;
		//但是要考虑到p1和p2当前位置是否有数据
		//分为三种情况：
		//p1和p2当前位置都有数据
		//只有p1当前位置有数据
		//只有p2当前位置有数据

		if (p1 != NULL && p2 != NULL)
		{
			val += (p1->val + p2->val+next);
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1 != NULL)
		{
			val += p1->val+next;
			p1 = p1->next;
		}
		else
		{
			val += p2->val + next;
			p2 = p2->next;
		}


		//这下就和上上面一样创建链表了，不在赘述
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		if (temp == NULL)
			return NULL;
		//当前节点的值要%10,比如val=18,当前位置只能存8，进位为1
		//则temp->val = val % 10;
		//进位next = val / 10;
		temp->val = val % 10;
		next = val / 10;
		temp->next = NULL;

		//链表的链接
		if (ret == NULL)
		{
			ret = temp;
			tail = ret;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}

	//next不等于0代表在最后一次相加的时候又产生了进位，那么我们得把这个进位继续链表到链表的尾部
	if (next != 0)
	{
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		if (temp != NULL)
		{
			temp->val = next;
			temp->next = NULL;
			tail->next = temp;
			tail = tail->next;
		}
	}

	//返回头指针
	return ret;


}


//翻转链表
 ListNode* reverse(struct ListNode* head)
{
	 //head代表头指针，如果链表没有元素或者只有一个元素就返回当前节点
	if (!head || !head->next) return head;

	//递归调用当前函数
	struct ListNode* p = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return p;
}



int main()
{
	char str1[N];
	char str2[N];
	printf("请输入两个数:\n");
	scanf("%s", str1);
	scanf("%s", str2);
	
	ListNode* p = Number_To_List(str1);//将第一个数转化为链表
	ListNode* q = Number_To_List(str2);//将第二个书转化为链表
	ListNode* p1 = Add_Numbers(p, q);//得到相加后的结果
	p1 = reverse(p1);//翻转链表

	//打印最终结果
	printf("结果为:\n");
	while (p1 != NULL)
	{
		printf("%d", p1->val);
		p1 = p1->next;
	}

}

