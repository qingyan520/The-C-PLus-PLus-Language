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


//创建栈
pstack create_stack(void) {
    pstack s = (pstack)malloc(sizeof(stack));
    s->bottom = s->top = (pnode)malloc(sizeof(node));
    return s;
}


//插入数据
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



//最主要的函数
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

      printf("其对应后缀表达式为:");
      for (int i = 0; i < p ; i++) {
          printf("%c", suffix[i]);
      }
      printf("\n");

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
