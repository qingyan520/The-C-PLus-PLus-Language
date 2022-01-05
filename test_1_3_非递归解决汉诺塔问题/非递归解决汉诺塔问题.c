#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//状态
typedef struct Status
{
	int n;
	char start, mid, end;
}Status;


//首先链表实现一个栈
//初始化状态
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


//入栈
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

//出栈
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

//返回栈顶元素
Status Top(Stack* s)
{

    Stack* cur = s;


    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    return cur->data;
}

//判断栈是否为空
bool IsEmpty(Stack** s)
{
    return *s==NULL;
}

//打印结果
void move(char start, char end)
{
    printf("%c->%c\n", start, end);
}

//主要函数
void hanioStack(int n, char A, char B, char C)
{
    //创建栈s
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
    printf("\t\t1.输入盘子数\n");
    printf("\t\t0.退出\n");
}

void test()
{
    printf("请输入盘子个数:\n");
    int n;
    scanf_s("%d", &n);
    printf("需要的步骤为:\n");
    hanioStack(n, 'A', 'B', 'C');
}
int main()
{
    int option;
    while (1)
    {
        menu();
        printf("请输入对应选项:\n");
        scanf_s("%d", &option);
        if (option == 1)
        {
            test();
            system("pause");
            system("cls");
        }
        else if (option == 0)
        {
            printf("退出\n");
            system("pause");
            system("cls");
            break;
        }
        else
        {
            printf("输入错误，请重新输入\n");
            system("pause");
            system("cls");
        }
    }
	return 0;
}