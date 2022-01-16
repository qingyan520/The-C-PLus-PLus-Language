//维护两个栈，第一个栈支持插入操作，第二个栈支持删除操作。

//根据栈先进后出的特性，我们每次往第一个栈里插入元素后，第一个栈的底部元素是最后插入的元素，第一个栈的顶部元素是下一个待删除的元素。
//为了维护队列先进先出的特性，我们引入第二个栈，用第二个栈维护待删除的元素，在执行删除操作的时候我们首先看下第二个栈是否为空。
//如果为空，我们将第一个栈里的元素一个个弹出插入到第二个栈里，这样第二个栈里元素的顺序就是待删除的元素的顺序，要执行删除操作的时候我们直接弹出第二个栈的元素返回即可。


//成员变量
//维护两个栈 s1 和 s2，其中栈s1 支持插入操作，栈s2 支持删除操作

//插入元素
//插入元素对应方法 appendTail(),s1 直接插入元素


//删除元素:删除元素对应方法 deleteHead
//如果 s2 为空，则将 s1 里的所有元素弹出插入到 s2 里
//如果 s2 仍为空，则返回 - 1，否则从 s2 弹出一个元素并返回

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<memory.h>
//
////在结构体里面封装两个int*类型的指针模拟栈,形成栈s1,s2，s1用来存数据，s2用来出数据
////然后利用两个栈相互转换数据形成队列;
//
//typedef struct CQueue{
//    int* s1; // for push
//    int* s2; // for pop
//    int h1;//标记栈1(s1)的大小
//    int h2;//标记栈2(s2)的大小
//} CQueue;
//
//
//
////创建队列
//CQueue* cQueueCreate() {
//    int len = 1e4 + 10;
//    //创建队列
//    CQueue* q = (CQueue*)malloc(sizeof(CQueue));
//    if (q == NULL)
//        return NULL;
//    //开辟栈s1,s2空间
//    q->s1 = (int*)malloc(sizeof(int) * len);
//    q->s2 = (int*)malloc(sizeof(int) * len);
//    //初始化s1,s2
//    if(q->s1!=NULL)
//    memset(q->s1, 0, sizeof(int) * len);
//    if(q->s2!=NULL)
//    memset(q->s2, 0, sizeof(int) * len);
//    //将两个栈的大小设置为-1代表栈为空
//    q->h1 = -1;
//    q->h2 = -1;
//    return q;
//}
//
////每次添加元素的时候我们都向s1中添加元素
//void cQueueAppendTail(CQueue* obj, int value) {
//    obj->s1[++obj->h1] = value;
//}
//
//
////删除队头数据
//int cQueueDeleteHead(CQueue* obj) {
//    //如果 s2 为空，则将 s1 里的所有元素弹出插入到 s2 里
//    if (obj->h2 == -1)
//    {
//        while (obj->h1 != -1)
//        {
//            obj->s2[++obj->h2] = obj->s1[obj->h1--];
//        }
//    }
//    //如果将s1的元素全部转换到s2后s2仍为空，则返回 - 1，否则从 s2 弹出一个元素并返回
//    if (obj->h2 + obj->h1 == -2) return -1;
//    return obj->s2[obj->h2--];
//}
//
////销毁队列
//void cQueueFree(CQueue* obj) {
//    free(obj->s1);
//    free(obj->s2);
//    free(obj);
//}
//
//int main()
//{
//    CQueue* p = cQueueCreate();
//    cQueueAppendTail(p, 1);
//    cQueueAppendTail(p, 2);
//    cQueueAppendTail(p, 3);
//    cQueueAppendTail(p, 4);
//    cQueueAppendTail(p, 5);
//    
//    int ret = 0;
//    while (ret != -1)
//    {
//        ret = cQueueDeleteHead(p);
//        if (ret != -1)
//            printf("%d ", ret);
//    }
//
//    cQueueFree(p);
//    return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#define START 100
#define ADD 100

//模拟实现一个栈
typedef struct Stack
{
    int size;
    int* data;
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
    S->data = (int*)malloc((S->size) * sizeof(int));
    S->top = 0;
}
//栈里面入数据
void StackPush(Stack* S, int mii)
{
    //容量不够进行扩容
    if (S->top == S->size)
    {
        S->size += ADD;
        if(S->data!=NULL)
        S->data = (int*)realloc(S->data, (S->size) * sizeof(int));
    }
    //添加数据
    S->data[(S->top)++] = mii;
}
//删除栈顶元素
int StackPop(Stack* S)
{
    if (!IsEmpty(S))
    {
        return S->data[--(S->top)];
    }
    else
    {
        return 0;
    }
}
//销毁栈
void DestroyStack(Stack* S)
{
    free(S->data);
    S->data = NULL;
    S->top = 0;
    S->size = 0;
}
////////////////////////////////////////////////////////////////////
//维护两个栈，第一个栈支持插入操作，第二个栈支持删除操作。

//根据栈先进后出的特性，我们每次往第一个栈里插入元素后，第一个栈的底部元素是最后插入的元素，第一个栈的顶部元素是下一个待删除的元素。
//为了维护队列先进先出的特性，我们引入第二个栈，用第二个栈维护待删除的元素，在执行删除操作的时候我们首先看下第二个栈是否为空。
//如果为空，我们将第一个栈里的元素一个个弹出插入到第二个栈里，这样第二个栈里元素的顺序就是待删除的元素的顺序，要执行删除操作的时候我们直接弹出第二个栈的元素返回即可。

//队列
typedef struct
{
    Stack* S1;//栈1用来入数据
    Stack* S2;//栈2用来出数据
}MyQueue;
//创建队列
MyQueue* myQueueCreate()
{
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    if (obj == NULL)
        return NULL;
    //初始化s1和s2
    obj->S1 = (Stack*)malloc(sizeof(Stack));
    InitStack(obj->S1);
    obj->S2 = (Stack*)malloc(sizeof(Stack));
    InitStack(obj->S2);
    return obj;
}

//队列入数据想s1中入数据
void myQueuePush(MyQueue* obj, int x)
{
    StackPush(obj->S1, x);
}

//队列中出数据
int myQueuePop(MyQueue* obj)
{
    //如果 s2 为空，则将 s1 里的所有元素弹出插入到 s2 里,然后删除s2的元素

    if (IsEmpty(obj->S2))
    {
        while (!IsEmpty(obj->S1))
        {
            StackPush(obj->S2, StackPop(obj->S1));
        }
    }
    return StackPop(obj->S2);
}

//返回队列头部元素
int myQueuePeek(MyQueue* obj)
{
    //如果s2为空，将s1中所有元素插入到s2中去
    if (IsEmpty(obj->S2))
    {
        while (!IsEmpty(obj->S1))
        {
            StackPush(obj->S2, StackPop(obj->S1));
        }
    }
    return obj->S2->data[obj->S2->top - 1];
}

//判断队列是否为空
bool myQueueEmpty(MyQueue* obj)
{
    //s1和s2都为空代表队列为空
    return IsEmpty(obj->S1) && IsEmpty(obj->S2);
}

//销毁队列
void myQueueFree(MyQueue* obj)
{
    DestroyStack(obj->S1);
    DestroyStack(obj->S2);
    free(obj->S1);
    obj->S1 = NULL;
    free(obj->S2);
    obj->S2 = NULL;
}

int main()
{
    MyQueue* p = myQueueCreate();
    myQueuePush(p,1);
    myQueuePush(p, 2);
    myQueuePush(p, 3);
    myQueuePush(p, 4);
    myQueuePush(p, 5);


    while (!myQueueEmpty(p))
    {
        int ret = myQueuePeek(p);
        printf("%d ", ret);
        myQueuePop(p);
    }

    return 0;
}