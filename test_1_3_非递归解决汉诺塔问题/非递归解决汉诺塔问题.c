#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//״̬
typedef struct Status
{
	int n;
	char start, mid, end;
}Status;


//��������ʵ��һ��ջ
//��ʼ��״̬
void Init_Status(Status* S, int _n, char _A, char _B, char _C)
{
    S->n = _n;
    S->start = _A;
    S->mid = _B;
    S->end = _C;
}


typedef struct Stack
{
    Status data;
    struct Stack* next;
}Stack;


//��ջ
void Push(Stack** s, Status data)
{
    if (*s == NULL)
    {
        *s = (Stack*)malloc(sizeof(Stack));
        if (*s != NULL)
        {
            (*s)->data = data;
            (*s)->next = NULL;
            return;
        }
    }
    Stack* cur = *s;
    Stack* prev = *s;
    while (cur != NULL)
    {
        prev = cur;
        cur = cur->next;
    }

    cur = (Stack*)malloc(sizeof(Stack));
    if (cur != NULL)
    {
        cur->data = data;
        cur->next = NULL;
        prev->next = cur;
    }
   
}

//��ջ
void Pop(Stack**s)
{
    if(*s == NULL)
    {
        return;
    
    }

    if ((*s)->next == NULL)
    {
        free(*s);
        *s = NULL;
        return;
    }


    Stack* cur = *s;
    Stack* prev = *s;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    /*free(cur);*/
    cur = NULL;
    prev->next =cur;
    free(cur);



}

//����ջ��Ԫ��
Status Top(Stack* s)
{

    Stack* cur = s;


    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    return cur->data;
}

//�ж�ջ�Ƿ�Ϊ��
bool IsEmpty(Stack** s)
{
    return *s==NULL;
}

//��ӡ���
void move(char start, char end)
{
    printf("%c->%c\n", start, end);
}

//��Ҫ����
void hanioStack(int n, char A, char B, char C)
{
    //����ջs
    Stack* s=NULL;

    Status temp;

    Init_Status(&temp,n, A, B, C);
    Push(&s, temp);

    while (!IsEmpty(&s))
    {
        Status ns = Top(s);

        Pop(&s);

        if (ns.n == 1)
        {
            move(ns.start, ns.end);
        }
        else
        {
            Init_Status(&temp, ns.n - 1, ns.mid, ns.start, ns.end);
            Push(&s, temp);

            Init_Status(&temp, 1, ns.start, ns.mid, ns.end);
            Push(&s, temp);

            Init_Status(&temp, ns.n - 1, ns.start, ns.end, ns.mid);
            Push(&s, temp);
        }
    }
}

void menu()
{
    printf("\t\t1.����������\n");
    printf("\t\t0.�˳�\n");
}

void test()
{
    printf("���������Ӹ���:\n");
    int n;
    scanf_s("%d", &n);
    printf("��Ҫ�Ĳ���Ϊ:\n");
    hanioStack(n, 'A', 'B', 'C');
}
int main()
{
    int option;
    while (1)
    {
        menu();
        printf("�������Ӧѡ��:\n");
        scanf_s("%d", &option);
        if (option == 1)
        {
            test();
            system("pause");
            system("cls");
        }
        else if (option == 0)
        {
            printf("�˳�\n");
            system("pause");
            system("cls");
            break;
        }
        else
        {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
	return 0;
}