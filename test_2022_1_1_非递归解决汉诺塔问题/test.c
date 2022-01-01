//#include <stdio.h>
//int main()
//{
//	void hanoi(int n, char one, char two, char three);
//	int m;
//	printf("请输入盘子个数：\n");
//	scanf_s("%d", &m);
//	printf("这些盘子移动的步骤如下：\n");
//	hanoi(m, 'A', 'B', 'C');
//	return 0;
//}
//
//void hanoi(int n, char one, char two, char three)
//{
//	void move(char x, char y);
//	if (n == 1)
//	{
//		move(one, three);
//	}
//	else {
//		hanoi(n - 1, one, three, two);
//		move(one, three);
//		hanoi(n - 1, two, one, three);
//	}
//}
//
//void move(char x, char y)
//{
//	printf("%c-->%c\n", x, y);
//}



#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define N 100
#define START 100
#define ADD 100


// Status 来保存当前状态的参数
typedef struct Status
{
    int n;
    char start, mid, end;   // 初始塔，辅助中间塔，最终要移动到的塔
}Status;



//初始化状态
void Init_Status(Status*S,int _n,char _A,char _B,char _C )
{
    S->n = _n;
    S->start = _A;
    S->mid = _B;
    S->end = _C;
}


//模拟实现一个栈
typedef Status T;
typedef struct Stack
{
    int size;
    T* data;
    int top;
}Stack;
//判断栈是否为空
bool IsEmpty(Stack* S)
{
    return S->top == 0;
}
//初始化栈
void InitStack(Stack* S)
{
    S->size = START;
    S->data = (T*)malloc((S->size) * sizeof(T));
    S->top = 0;
}
//栈里面入数据
void StackPush(Stack* S, T mii)
{
    //容量不够进行扩容
    if (S->top == S->size)
    {
        S->size += ADD;
        if (S->data != NULL)
            S->data = (T*)realloc(S->data, (S->size) * sizeof(T));
    }
    //添加数据
    S->data[(S->top)++] = mii;
}
//删除栈顶元素
int StackPop(Stack* S)
{

    S->top--;
    return 1;
}

//返回栈顶元素
T StackTop(Stack* s)
{
    /*if (s->top == 0)
    {
        return T();
    }*/

    return s->data[s->top - 1];
}

//销毁栈
void DestroyStack(Stack* S)
{
    free(S->data);
    S->data = NULL;
    S->top = 0;
    S->size = 0;
}

//打印结果
void move(char start, char end)
{
    printf("%c->%c\n", start, end);
}

//非递归实现汉诺塔问题
//采用栈的性质，FILO，所以我们需要将原来函数的调用方式反过来进行

//非递归模拟实现过程
void hanioStak(int n, char A, char B, char C)
{
    //创建有一个栈
    Stack myS;
    //初始化栈
    InitStack(&myS);


    Status s;
    //将初始状态进行入栈
    Init_Status(&s, n, A, B, C);
    StackPush(&myS, s);

    //利用栈的性质模拟递归过程
    while (!IsEmpty(&myS))
    {
        Status ns = StackTop(&myS);

        StackPop(&myS);

        if (ns.n == 1)
        {
            move(ns.start, ns.end);
        }
        else
        {
            Status a;
            Init_Status(&a, ns.n - 1, ns.mid, ns.start, ns.end);
            StackPush(&myS, a);

            Init_Status(&a,1,ns.start,ns.mid,ns.end);
            StackPush(&myS, a);


            Init_Status(&a, ns.n-1, ns.start, ns.end, ns.mid);
            StackPush(&myS, a);
        }


    }
}



int main()
{
    printf("请输入盘子个数:\n");
    int n;
    scanf_s("%d", &n);
    printf("需要的步骤为:\n");
    hanioStak(n, 'A', 'B', 'C');
    return 0;
}
