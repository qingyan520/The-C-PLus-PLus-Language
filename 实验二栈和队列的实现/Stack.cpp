#include<stdio.h>
#include<stdlib.h>
# define StackSize 100
typedef  char SElemType;
typedef struct {
    SElemType  data[StackSize];//记录数据
    int top;//记录栈顶元素的位置
}seqstack;

//1.显示栈中所有的元素
//2.入栈
//3.出栈
//4.取栈顶元素
//0.退出程序

//主菜单界面
void menu()
{
	printf("\t\t1.显示栈中所有元素     \n");
	printf("\t\t2.入栈                 \n");
	printf("\t\t3.出栈                 \n");
	printf("\t\t4.取栈顶元素           \n");
	printf("\t\t0.退出程序             \n");
}



void StackInit(seqstack* st);  //初始化栈

void PushStack(seqstack* st);  //入栈

void PopStack(seqstack* st);       //出栈
SElemType TopStack(seqstack* st);  //显示栈顶元素
int EmptyStack(seqstack* st);      //判断栈是否为空
void DestoryStack(seqstack* st);   //销毁栈
void PrintStack(seqstack* st);     //打印栈中的元素
void menu();                       //主菜单界面

//初始化栈
void StackInit(seqstack* st)
{
	//将栈中每一个元素初始化为0
	for (int i = 0; i < StackSize; i++)
	{
		st->data[i] = '\0';
	}
	//现在栈顶元素下标为0，代表没有元素;
	st->top = 0;
}

//2.入栈
void PushStack(seqstack* st)
{
	
	if (st->top == StackSize)
	{
		printf("Stack Over Flow,无法插入!\n");
		return;
	}
	SElemType val = 0;
	printf("请输入要插入的元素:\n");
	getchar();
	scanf("%c", &val);
	st->data[st->top++] = val;
	printf("插入成功!\n");
}

//3.出栈
void PopStack(seqstack* st)
{
	if (st->top == 0)
	{
		printf("栈为空，无法出栈!\n");
		return;
	}

	st->top--;
}

//3.显示栈顶元素
SElemType TopStack(seqstack* st)
{
	if (st->top == 0)
	{
		printf("栈为空，无栈顶元素!\n");
		return -1;
	}

	return st->data[st->top - 1];
}


//4.判断栈是否为空
int EmptyStack(seqstack* st)
{
	return st->top == 0;
}

//5.销毁栈
void DestoryStack(seqstack* st)
{
	st->top = 0;
}


//6.打印栈中的元素
void PrintStack(seqstack* st)
{
	if (st->top == 0)
	{
		printf("栈为空，无元素可打印!\n");
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
    seqstack st;//创建栈

	StackInit(&st);//初始化栈
	SElemType val = 0;//标记取出的栈顶元素
	int option = 0;//对应的选项
	while (1)
	{
		menu();
		printf("请输入对应选项:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			PrintStack(&st);//打印栈中元素
			break;
		case 2:
			PushStack(&st);//入栈
			break;
		case 3:
			PopStack(&st);//出栈
			break;
		case 4:
			val=TopStack(&st);//取栈顶元素
			printf("栈顶元素为:%c\n", val);
			break;
		case 0:
			exit(-1);//退出
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	}
	DestoryStack(&st);//销毁栈
}

