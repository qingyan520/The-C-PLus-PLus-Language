//#include <stdio.h>
//int main()
//{
//	void hanoi(int n, char one, char two, char three);
//	int m;
//	printf("���������Ӹ�����\n");
//	scanf_s("%d", &m);
//	printf("��Щ�����ƶ��Ĳ������£�\n");
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


// Status �����浱ǰ״̬�Ĳ���
typedef struct Status
{
    int n;
    char start, mid, end;   // ��ʼ���������м���������Ҫ�ƶ�������
}Status;



//��ʼ��״̬
void Init_Status(Status*S,int _n,char _A,char _B,char _C )
{
    S->n = _n;
    S->start = _A;
    S->mid = _B;
    S->end = _C;
}


//ģ��ʵ��һ��ջ
typedef Status T;
typedef struct Stack
{
    int size;
    T* data;
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
    S->data = (T*)malloc((S->size) * sizeof(T));
    S->top = 0;
}
//ջ����������
void StackPush(Stack* S, T mii)
{
    //����������������
    if (S->top == S->size)
    {
        S->size += ADD;
        if (S->data != NULL)
            S->data = (T*)realloc(S->data, (S->size) * sizeof(T));
    }
    //�������
    S->data[(S->top)++] = mii;
}
//ɾ��ջ��Ԫ��
int StackPop(Stack* S)
{

    S->top--;
    return 1;
}

//����ջ��Ԫ��
T StackTop(Stack* s)
{
    /*if (s->top == 0)
    {
        return T();
    }*/

    return s->data[s->top - 1];
}

//����ջ
void DestroyStack(Stack* S)
{
    free(S->data);
    S->data = NULL;
    S->top = 0;
    S->size = 0;
}

//��ӡ���
void move(char start, char end)
{
    printf("%c->%c\n", start, end);
}

//�ǵݹ�ʵ�ֺ�ŵ������
//����ջ�����ʣ�FILO������������Ҫ��ԭ�������ĵ��÷�ʽ����������

//�ǵݹ�ģ��ʵ�ֹ���
void hanioStak(int n, char A, char B, char C)
{
    //������һ��ջ
    Stack myS;
    //��ʼ��ջ
    InitStack(&myS);


    Status s;
    //����ʼ״̬������ջ
    Init_Status(&s, n, A, B, C);
    StackPush(&myS, s);

    //����ջ������ģ��ݹ����
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
    printf("���������Ӹ���:\n");
    int n;
    scanf_s("%d", &n);
    printf("��Ҫ�Ĳ���Ϊ:\n");
    hanioStak(n, 'A', 'B', 'C');
    return 0;
}
