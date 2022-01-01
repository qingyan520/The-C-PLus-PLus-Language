#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//��������������һ��ջ
typedef struct node {
    double date;
    char opt;
    struct node* pre;
}*pnode, node;


typedef struct stack {
    pnode bottom;   //ָ��ײ�
    pnode top;  //ָ��ͷ��
}*pstack, stack;


//����ջ
pstack create_stack(void) {
    pstack s = (pstack)malloc(sizeof(stack));
    s->bottom = s->top = (pnode)malloc(sizeof(node));
    return s;
}


//��������
void push(pstack s, char date) {
    pnode t = (pnode)malloc(sizeof(node));
    t->pre = s->top;
    t->date = date;
    s->top = t;
}


//���ݳ�ջ
void pop(pstack s) {
    if (s->top == s->bottom) {
        printf("���ܵ�������ʱջΪ��\n");
        return;
    }
    pnode t = s->top;
    s->top = s->top->pre;
    free(t);
}


//�ж�ջ�Ƿ�Ϊ��
int empty(pstack s) {
    if (s->top == s->bottom) {
        return 1;
    }
    else {
        return 0;
    }
}


//����ջ��Ԫ��
int top(pstack s) {
    return s->top->date;
}



void push_num(pstack s, int date) {
    pnode t = (pnode)malloc(sizeof(node));
    t->pre = s->top;
    t->date = date;
    s->top = t;
}



//����Ҫ�ĺ���
void test()
{
    pstack s_opt = create_stack();
    pstack s_num = create_stack();
    char str[100], suffix[100];
    int opt[100];
    memset(opt, 0, sizeof(opt));
    printf("��������ʽ:\n");
    scanf_s("%s", str, 100);
    opt['+'] = opt['-'] = 1;
    opt['*'] = opt['/'] = 2;
    opt['('] = opt[')'] = 0;
    int len = strlen(str), p = 0, flag = 1;
    //printf("%d\n",len);

    //����׺���ʽת��Ϊ��׺���ʽ
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

      printf("���Ӧ��׺���ʽΪ:");
      for (int i = 0; i < p ; i++) {
          printf("%c", suffix[i]);
      }
      printf("\n");

      //��׺���ʽ�ļ���:�������־���ջ������������ͽ��м���
      //������ɺ󽫽���ٴη��ص�ջ�У�����󷵻�ֵջ��Ԫ�ؼ�Ϊ����
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

    printf("���Ϊ:");
    printf("%lf\n", number_stack->top->date);
}

void menu()
{
    printf("\t\t1.������ʽ\n");
    printf("\t\t2.�˳�\n");
}
int main(void) {

    int option;
    while (1)
    {
        menu();
        printf("�������Ӧѡ��:\n");
        scanf_s("%d", &option);
        switch (option)
        {
        case 1:
            test();
            system("pause");
            system("cls");
            break;
        case 0:
            printf("�˳�!\n");
            system("pause");
            system("cls");
            exit(0);
        default:
            printf("�������,����������\n");
            system("pause");
            system("cls");
        }
    }
    return 0;
}
