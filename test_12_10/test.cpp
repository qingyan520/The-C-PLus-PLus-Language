//ά������ջ����һ��ջ֧�ֲ���������ڶ���ջ֧��ɾ��������

//����ջ�Ƚ���������ԣ�����ÿ������һ��ջ�����Ԫ�غ󣬵�һ��ջ�ĵײ�Ԫ�����������Ԫ�أ���һ��ջ�Ķ���Ԫ������һ����ɾ����Ԫ�ء�
//Ϊ��ά�������Ƚ��ȳ������ԣ���������ڶ���ջ���õڶ���ջά����ɾ����Ԫ�أ���ִ��ɾ��������ʱ���������ȿ��µڶ���ջ�Ƿ�Ϊ�ա�
//���Ϊ�գ����ǽ���һ��ջ���Ԫ��һ�����������뵽�ڶ���ջ������ڶ���ջ��Ԫ�ص�˳����Ǵ�ɾ����Ԫ�ص�˳��Ҫִ��ɾ��������ʱ������ֱ�ӵ����ڶ���ջ��Ԫ�ط��ؼ��ɡ�


//��Ա����
//ά������ջ s1 �� s2������ջs1 ֧�ֲ��������ջs2 ֧��ɾ������

//����Ԫ��
//����Ԫ�ض�Ӧ���� appendTail(),s1 ֱ�Ӳ���Ԫ��


//ɾ��Ԫ��:ɾ��Ԫ�ض�Ӧ���� deleteHead
//��� s2 Ϊ�գ��� s1 �������Ԫ�ص������뵽 s2 ��
//��� s2 ��Ϊ�գ��򷵻� - 1������� s2 ����һ��Ԫ�ز�����

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<memory.h>
//
////�ڽṹ�������װ����int*���͵�ָ��ģ��ջ,�γ�ջs1,s2��s1���������ݣ�s2����������
////Ȼ����������ջ�໥ת�������γɶ���;
//
//typedef struct CQueue{
//    int* s1; // for push
//    int* s2; // for pop
//    int h1;//���ջ1(s1)�Ĵ�С
//    int h2;//���ջ2(s2)�Ĵ�С
//} CQueue;
//
//
//
////��������
//CQueue* cQueueCreate() {
//    int len = 1e4 + 10;
//    //��������
//    CQueue* q = (CQueue*)malloc(sizeof(CQueue));
//    if (q == NULL)
//        return NULL;
//    //����ջs1,s2�ռ�
//    q->s1 = (int*)malloc(sizeof(int) * len);
//    q->s2 = (int*)malloc(sizeof(int) * len);
//    //��ʼ��s1,s2
//    if(q->s1!=NULL)
//    memset(q->s1, 0, sizeof(int) * len);
//    if(q->s2!=NULL)
//    memset(q->s2, 0, sizeof(int) * len);
//    //������ջ�Ĵ�С����Ϊ-1����ջΪ��
//    q->h1 = -1;
//    q->h2 = -1;
//    return q;
//}
//
////ÿ�����Ԫ�ص�ʱ�����Ƕ���s1�����Ԫ��
//void cQueueAppendTail(CQueue* obj, int value) {
//    obj->s1[++obj->h1] = value;
//}
//
//
////ɾ����ͷ����
//int cQueueDeleteHead(CQueue* obj) {
//    //��� s2 Ϊ�գ��� s1 �������Ԫ�ص������뵽 s2 ��
//    if (obj->h2 == -1)
//    {
//        while (obj->h1 != -1)
//        {
//            obj->s2[++obj->h2] = obj->s1[obj->h1--];
//        }
//    }
//    //�����s1��Ԫ��ȫ��ת����s2��s2��Ϊ�գ��򷵻� - 1������� s2 ����һ��Ԫ�ز�����
//    if (obj->h2 + obj->h1 == -2) return -1;
//    return obj->s2[obj->h2--];
//}
//
////���ٶ���
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

//ģ��ʵ��һ��ջ
typedef struct Stack
{
    int size;
    int* data;
    int top;
}Stack;
//�ж�ջ�Ƿ�Ϊ��
bool IsEmpty(Stack* S)
{
    return S->top == 0;
}
//��ʼ��ջ
void InitStack(Stack* S)
{
    S->size = START;
    S->data = (int*)malloc((S->size) * sizeof(int));
    S->top = 0;
}
//ջ����������
void StackPush(Stack* S, int mii)
{
    //����������������
    if (S->top == S->size)
    {
        S->size += ADD;
        if(S->data!=NULL)
        S->data = (int*)realloc(S->data, (S->size) * sizeof(int));
    }
    //�������
    S->data[(S->top)++] = mii;
}
//ɾ��ջ��Ԫ��
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
//����ջ
void DestroyStack(Stack* S)
{
    free(S->data);
    S->data = NULL;
    S->top = 0;
    S->size = 0;
}
////////////////////////////////////////////////////////////////////
//ά������ջ����һ��ջ֧�ֲ���������ڶ���ջ֧��ɾ��������

//����ջ�Ƚ���������ԣ�����ÿ������һ��ջ�����Ԫ�غ󣬵�һ��ջ�ĵײ�Ԫ�����������Ԫ�أ���һ��ջ�Ķ���Ԫ������һ����ɾ����Ԫ�ء�
//Ϊ��ά�������Ƚ��ȳ������ԣ���������ڶ���ջ���õڶ���ջά����ɾ����Ԫ�أ���ִ��ɾ��������ʱ���������ȿ��µڶ���ջ�Ƿ�Ϊ�ա�
//���Ϊ�գ����ǽ���һ��ջ���Ԫ��һ�����������뵽�ڶ���ջ������ڶ���ջ��Ԫ�ص�˳����Ǵ�ɾ����Ԫ�ص�˳��Ҫִ��ɾ��������ʱ������ֱ�ӵ����ڶ���ջ��Ԫ�ط��ؼ��ɡ�

//����
typedef struct
{
    Stack* S1;//ջ1����������
    Stack* S2;//ջ2����������
}MyQueue;
//��������
MyQueue* myQueueCreate()
{
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    if (obj == NULL)
        return NULL;
    //��ʼ��s1��s2
    obj->S1 = (Stack*)malloc(sizeof(Stack));
    InitStack(obj->S1);
    obj->S2 = (Stack*)malloc(sizeof(Stack));
    InitStack(obj->S2);
    return obj;
}

//������������s1��������
void myQueuePush(MyQueue* obj, int x)
{
    StackPush(obj->S1, x);
}

//�����г�����
int myQueuePop(MyQueue* obj)
{
    //��� s2 Ϊ�գ��� s1 �������Ԫ�ص������뵽 s2 ��,Ȼ��ɾ��s2��Ԫ��

    if (IsEmpty(obj->S2))
    {
        while (!IsEmpty(obj->S1))
        {
            StackPush(obj->S2, StackPop(obj->S1));
        }
    }
    return StackPop(obj->S2);
}

//���ض���ͷ��Ԫ��
int myQueuePeek(MyQueue* obj)
{
    //���s2Ϊ�գ���s1������Ԫ�ز��뵽s2��ȥ
    if (IsEmpty(obj->S2))
    {
        while (!IsEmpty(obj->S1))
        {
            StackPush(obj->S2, StackPop(obj->S1));
        }
    }
    return obj->S2->data[obj->S2->top - 1];
}

//�ж϶����Ƿ�Ϊ��
bool myQueueEmpty(MyQueue* obj)
{
    //s1��s2��Ϊ�մ������Ϊ��
    return IsEmpty(obj->S1) && IsEmpty(obj->S2);
}

//���ٶ���
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