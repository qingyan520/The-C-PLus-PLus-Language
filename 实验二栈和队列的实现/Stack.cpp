#include<stdio.h>
#include<stdlib.h>
# define StackSize 100
typedef  char SElemType;
typedef struct {
    SElemType  data[StackSize];//��¼����
    int top;//��¼ջ��Ԫ�ص�λ��
}seqstack;

//1.��ʾջ�����е�Ԫ��
//2.��ջ
//3.��ջ
//4.ȡջ��Ԫ��
//0.�˳�����

//���˵�����
void menu()
{
	printf("\t\t1.��ʾջ������Ԫ��     \n");
	printf("\t\t2.��ջ                 \n");
	printf("\t\t3.��ջ                 \n");
	printf("\t\t4.ȡջ��Ԫ��           \n");
	printf("\t\t0.�˳�����             \n");
}



void StackInit(seqstack* st);  //��ʼ��ջ

void PushStack(seqstack* st);  //��ջ

void PopStack(seqstack* st);       //��ջ
SElemType TopStack(seqstack* st);  //��ʾջ��Ԫ��
int EmptyStack(seqstack* st);      //�ж�ջ�Ƿ�Ϊ��
void DestoryStack(seqstack* st);   //����ջ
void PrintStack(seqstack* st);     //��ӡջ�е�Ԫ��
void menu();                       //���˵�����

//��ʼ��ջ
void StackInit(seqstack* st)
{
	//��ջ��ÿһ��Ԫ�س�ʼ��Ϊ0
	for (int i = 0; i < StackSize; i++)
	{
		st->data[i] = '\0';
	}
	//����ջ��Ԫ���±�Ϊ0������û��Ԫ��;
	st->top = 0;
}

//2.��ջ
void PushStack(seqstack* st)
{
	
	if (st->top == StackSize)
	{
		printf("Stack Over Flow,�޷�����!\n");
		return;
	}
	SElemType val = 0;
	printf("������Ҫ�����Ԫ��:\n");
	getchar();
	scanf("%c", &val);
	st->data[st->top++] = val;
	printf("����ɹ�!\n");
}

//3.��ջ
void PopStack(seqstack* st)
{
	if (st->top == 0)
	{
		printf("ջΪ�գ��޷���ջ!\n");
		return;
	}

	st->top--;
}

//3.��ʾջ��Ԫ��
SElemType TopStack(seqstack* st)
{
	if (st->top == 0)
	{
		printf("ջΪ�գ���ջ��Ԫ��!\n");
		return -1;
	}

	return st->data[st->top - 1];
}


//4.�ж�ջ�Ƿ�Ϊ��
int EmptyStack(seqstack* st)
{
	return st->top == 0;
}

//5.����ջ
void DestoryStack(seqstack* st)
{
	st->top = 0;
}


//6.��ӡջ�е�Ԫ��
void PrintStack(seqstack* st)
{
	if (st->top == 0)
	{
		printf("ջΪ�գ���Ԫ�ؿɴ�ӡ!\n");
		return;
	}

	for (int i = st->top - 1; i >= 0; i--)
	{
		printf("%c ", st->data[i]);
	}
	printf("\n");
}


int hello01()
{
    seqstack st;//����ջ

	StackInit(&st);//��ʼ��ջ
	SElemType val = 0;//���ȡ����ջ��Ԫ��
	int option = 0;//��Ӧ��ѡ��
	while (1)
	{
		menu();
		printf("�������Ӧѡ��:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			PrintStack(&st);//��ӡջ��Ԫ��
			break;
		case 2:
			PushStack(&st);//��ջ
			break;
		case 3:
			PopStack(&st);//��ջ
			break;
		case 4:
			val=TopStack(&st);//ȡջ��Ԫ��
			printf("ջ��Ԫ��Ϊ:%c\n", val);
			break;
		case 0:
			exit(-1);//�˳�
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	}
	DestoryStack(&st);//����ջ
}

