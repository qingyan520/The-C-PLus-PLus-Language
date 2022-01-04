//#include<stdio.h>
//#include<string.h>
//#include<stdbool.h>
//#include<stdlib.h>
//
//#define N 100
//#define START 100
//#define ADD 100
//
//
//
//模拟实现一个栈
//typedef char T;
//typedef struct Stack
//{
//    int size;
//    T* data;
//    int top;
//}Stack;
//判断栈是否为空
//bool IsEmpty(Stack* S)
//{
//    return S->top == 0;
//}
//初始化栈
//void InitStack(Stack* S)
//{
//    S->size = START;
//    S->data = (T*)malloc((S->size) * sizeof(T));
//    S->top = 0;
//}
//栈里面入数据
//void StackPush(Stack* S, T mii)
//{
//    容量不够进行扩容
//    if (S->top == S->size)
//    {
//        S->size += ADD;
//        if (S->data != NULL)
//            S->data = (T*)realloc(S->data, (S->size) * sizeof(T));
//    }
//    添加数据
//    S->data[(S->top)++] = mii;
//}
//删除栈顶元素
//int StackPop(Stack* S,T*e)
//{
//    if (IsEmpty(S))
//    {
//        return 0;
//    }
//
//    *e = S->data[S->top];
//    S->top--;
//    return 1;
//}
//
//返回栈顶元素
//int StackTop(Stack* s)
//{
//    if (s->top == 0)
//    {
//        return -1;
//    }
//    return s->data[s->top - 1];
//}
//
//销毁栈
//void DestroyStack(Stack* S)
//{
//    free(S->data);
//    S->data = NULL;
//    S->top = 0;
//    S->size = 0;
//}
//
//判断运算符的优先级
//int Priority(char c)
//{
//    switch (c)
//    {
//    case '(':
//        return 4;
//    case '*':
//    case '/':
//        return 3;
//    case '+':
//    case '-':
//        return 2;
//    case ')':
//        return 1;
//    default:
//        return 0;
//    }
//}
//
//
//判断是否为运算符
//int Inop(char ch)
//{
//    if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ||ch=='#')
//    {
//        return 1;
//    }
//    return 0;
//}
//
//
//比较运算符的优先级
//int Precede(char op1, char op2)
//{
//    if (Priority(op1) < Priority(op2))
//    {
//        return 0;
//    }
//    return 1;
//}
//
//
//判断符号并进行运算
//int _Calculation(int a, int b, char c)
//{
//    switch (c)
//    {
//    case '+':
//        return a + b;
//    case '-':
//        return a - b;
//    case '*':
//        return a * b;
//    case '/':
//        if (b == 0)
//            exit(-1);
//        return a / b;
//    }
//}
//
//计算表达式的值
//int Calculation(Stack* ra, Stack* op)
//{
//    int a, b;
//    char ch, s;
//
//    StackPush(op, '#');
//
//    printf("请输入要计算的算式(以#结尾):");
//    ch = getchar();
//    while (ch != '#' || StackTop(op) != '#')
//    {
//        if (!Inop(ch))
//        {
//            int temp;
//            temp = ch - '0';
//            ch = getchar();
//            while (!Inop(ch))
//            {
//                temp = temp * 10 + ch - '0';
//                ch = getchar();
//            }
//
//            注意！！！
//            StackPush(ra, temp);
//        }
//        else
//        {
//            if (!Precede(StackTop(op), ch))
//            {
//                StackPush(op, ch);
//                ch = getchar();
//            }
//            else
//            {
//                StackPop(ra, &(char)b);
//                StackPop(ra, &(char)a);
//                StackPop(op, &s);
//                StackPush(ra, _Calculation(a, b, s));
//            }
//        }
//        printf("运算结果为:%c\n", StackTop(ra));
//    }
//    return 0;
//
//}
//
//建立两个栈，
//int main()
//{
//    Stack operands;//操作数
//    Stack operators;//操作符
//
//    InitStack(&operands);
//    InitStack(&operators);
//
//    while (1)
//    {
//        char ch='0';
//        Calculation(&operands, &operators);
//
//        DestroyStack(&operands);
//        DestroyStack(&operators);
//
//
//        在输入运算的算是是，在#后面输入~结束程序循环
//        if (ch == '~')
//        {
//            exit(1);
//        }
//    }
//
//    return 0;
//
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//首先利用链表建议一个栈
typedef struct node {
    double date;
    char opt;
    struct node* pre;
}*pnode, node;


typedef struct stack {
    pnode bottom;   //指向底部
    pnode top;  //指向头部
}*pstack, stack;

pstack create_stack(void) {
    pstack s = (pstack)malloc(sizeof(stack));
    s->bottom = s->top = (pnode)malloc(sizeof(node));
    return s;
}



void push(pstack s, char date) {
    pnode t = (pnode)malloc(sizeof(node));
    t->pre = s->top;
    t->date = date;
    s->top = t;
}


//数据出栈
void pop(pstack s) {
    if (s->top == s->bottom) {
        printf("不能弹出，此时栈为空\n");
        return;
    }
    pnode t = s->top;
    s->top = s->top->pre;
    free(t);
}


//判断栈是否为空
int empty(pstack s) {
    if (s->top == s->bottom) {
        return 1;
    }
    else {
        return 0;
    }
}


//返回栈顶元素
int top(pstack s) {
    return s->top->date;
}



void push_num(pstack s, int date) {
    pnode t = (pnode)malloc(sizeof(node));
    t->pre = s->top;
    t->date = date;
    s->top = t;
}



void test()
{
    pstack s_opt = create_stack();
    pstack s_num = create_stack();
    char str[100], suffix[100];
    int opt[100];
    memset(opt, 0, sizeof(opt));
    printf("请输入表达式:\n");
    scanf_s("%s", str, 100);
    opt['+'] = opt['-'] = 1;
    opt['*'] = opt['/'] = 2;
    opt['('] = opt[')'] = 0;
    int len = strlen(str), p = 0, flag = 1;
    //printf("%d\n",len);

    //将中缀表达式转化为后缀表达式
    for (int i = 0; i < len; i++) {
        if (str[i] <= '9' && str[i] >= '0') {
            suffix[p++] = str[i];
            if (i + 1 < len && str[i + 1] <= '9' && str[i + 1] >= '0');
            else    suffix[p++] = ' ';
            flag = 0;
            continue;
        }
        else {
            flag++;
        }
        if (str[i] == '(') {
            push(s_opt, str[i]);
        }
        else if (str[i] == ')') {
            while (top(s_opt) != '(') {
                //printf("%c\n", top(s_opt));
                suffix[p++] = top(s_opt);
                pop(s_opt);
            }
            pop(s_opt);
            //printf("1");
        }
        else if (empty(s_opt) && str[i] != ' ') {
            push(s_opt, str[i]);
        }
        else {
            while (!empty(s_opt) && opt[str[i]] <= opt[top(s_opt)]) {
                suffix[p++] = top(s_opt);
                pop(s_opt);
            }
            push(s_opt, str[i]);
        }
        if (flag >= 1) {
            //    suffix[p++] = ' ';
        }
    }
    while (!empty(s_opt)) {
        suffix[p++] = top(s_opt);
        pop(s_opt);
    }

  /*  printf("其对应后缀表达式为:");
    for (int i = 0; i < p - 1; i++) {
        printf("%c", suffix[i]);
    }
    printf("\n");*/

    //后缀表达式的计算:遇到数字就入栈，遇到运算符就进行计算
    //运算完成后将结果再次返回到栈中，到最后返回值栈顶元素即为所求
    pstack number_stack = create_stack();
    flag = 0;
    double sum = 0, ans = 0;
    for (int i = 0; i < p; i++) {
        if (suffix[i] <= '9' && suffix[i] >= '0') {
            sum = sum * 10 + (suffix[i] - '0');
            flag = 1;
        }
        else {
            if (flag == 1) {
                push(number_stack, sum);
                sum = 0;
                flag = 0;
            }
            if (suffix[i] == '+' || suffix[i] == '-' || suffix[i] == '*' || suffix[i] == '/') {
                double t1 = number_stack->top->date;
                pop(number_stack);
                if (suffix[i] == '+') {
                    number_stack->top->date += t1;
                }
                else if (suffix[i] == '-') {
                    number_stack->top->date -= t1;
                }
                else if (suffix[i] == '*') {
                    number_stack->top->date *= t1;
                }
                else if (suffix[i] == '/') {
                    number_stack->top->date /= t1;
                }
            }
        }
    }

    printf("结果为:");
    printf("%lf\n", number_stack->top->date);
}

void menu()
{
    printf("\t\t1.输入表达式\n");
    printf("\t\t2.退出\n");
}
int main(void) {
    
    int option;
    while (1)
    {
        menu();
        printf("请输入对应选项:\n");
        scanf_s("%d", &option);
        switch (option)
        {
        case 1:
            test();
            system("pause");
            system("cls");
            break;
        case 0:
            printf("退出!\n");
            system("pause");
            system("cls");
            exit(0);
        default:
            printf("输入错误,请重新输入\n");
            system("pause");
            system("cls");
        }
    }
    return 0;
}



//#include<stdio.h>
//#include<stdlib.h>
//#define maxSize 100
//
////获取运算符优先级
//int getpriority(char m)
//{
//	switch (m)
//	{
//	case'+':
//	case'-':
//		return 1;
//		break;
//	case'*':
//	case'/':
//		return 2;
//		break;
//	}
//}
//
//
////首先将中缀表达式转换为后缀表达式
//void trans(char infix[], char s2[], int *top2)
//{
//	char s1[maxSize]={0};//存运算符辅助栈 
//	int top1 = -1;
//	int i = 0;
//	while (infix[i] != '\0')
//	{
//		if ('0' <= infix[i] && '9' >= infix[i])
//		{
//			s2[++(*top2)] = infix[i];
//			++i;
//		}
//		else if (infix[i] == '(')
//		{
//			s1[++top1] = '(';
//			++i;
//		}
//		else if (infix[i] == '+' ||
//			infix[i] == '-' ||
//			infix[i] == '*' ||
//			infix[i] == '/')
//		{
//			if (top1 == -1 ||
//				s1[top1] == '(' ||
//				getpriority(infix[i]) > getpriority(s1[top1]))
//			{
//				s1[++top1] = infix[i];
//				++i;
//			}
//			else
//				s2[++(*top2)] = s1[top1--];
//		}
//		else if (infix[i] == ')')
//		{
//			while (s1[top1] != '(')
//				s2[++(*top2)] = s1[top1--];
//			--top1;//出栈左括号 
//			++i;
//		}
//	}
//	while (top1 != -1)
//	s2[++(*top2)] = s1[top1--];//出栈辅助栈剩余表达式 
//}
//
//
////进行运算
//double op(double a, double Op, double b)//运算函数 
//{
//	if (Op == '+') return a + b;
//	if (Op == '-') return a - b;
//	if (Op == '*') return a * b;
//	if (Op == '/')//题目是非负整数
//	{
//		if (b == 0)
//		{
//			printf("error\n");
//			return 0;
//		}
//		else
//			return a / b;
//	}
//}
//
////后缀式计算函数 
//double cal(char exp[])
//{
//	int i;
//	double a, b, c;
//	double stack[maxSize]; int top = -1;
//
//	char Op;
//	for (i = 0; exp[i] != '\0'; ++i)
//	{
//		if (exp[i] >= '0' && exp[i] <= '9')
//			stack[++top] = exp[i] - '0';
//		else
//		{
//			Op = exp[i];
//			b = stack[top--];
//
//			a = stack[top--];//后进先出
//			c = op(a, Op, b);
//			stack[++top] = c;
//		}
//	}
//	return stack[top];
//}
//
//int main()
//{
//	char infix[maxSize]={0};
//	printf("请输入表达式:\n");
//	gets(infix);
//	char rinfix[maxSize] = { 0 };
//	int top2 = -1;
//	trans(infix, rinfix, &top2);
//	printf("结果为:");
//	printf("%.2f", cal(rinfix));
//	return 0;
//}