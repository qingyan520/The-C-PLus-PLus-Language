#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000

//定义三元组
typedef struct Triple
{
	int row, col;//定义三元组的行号，列号
	int val;//定义三元组的列
}Triple;


//定义稀疏矩阵
typedef struct TripleMatrix
{
	Triple data[MAX];//非零三元组
	int mu, nu, num;//矩阵的行数、列数以及非零值的个数
}TripleMatrix;


//初始化稀疏矩阵
void Init_TripleMatrix(TripleMatrix* t, int m, int n)
{
	t->mu = m;
	t->nu = n;
	t->num = 0;
}


//向稀疏矩阵中添加元素
void Set_Val(TripleMatrix* t, int row, int col, int val)
{
	if (row > t->mu || col > t->nu)
	{
		printf("行数或者列数超过稀疏矩阵的范围\n");
		return;
	}
	if (val == 0)
	{
		return;
	}

	//利用while循环找到适合存储的位置
	int index = 0;
	while (index < t->num)
	{
		//如果要找的row和col，比已有的三元组的行值大，则继续向后移动
		if (row > t->data[index].row)
		{
			index++;
		}
		else if (row == t->data[index].row && (col > t->data[index].col))
		{
			index++;
		}
		else
		{
			break;
		}
	}
	if (row == t->data[index].row && col == t->data[index].col)
	{
		//当前元素已经存在，更新当前元素即可
		t->data[index].val = val;
	}
	else
	{
		//index后所有元素像后面移动一个位置
		for (int i = t->num; i > index; i--)
		{
			t->data[i] = t->data[i - 1];
		}
		t->data[index].col = col;
		t->data[index].row = row;
		t->data[index].val = val;
		//元素个数++
		t->num++;
	}
}


//根据行号和列号获取稀疏矩阵中的值
int Get_Val(int row, int col, TripleMatrix* t)
{
	if (row > t->mu || col > t->nu)
	{
		return 0;
	}

	//遍历三元组
	for (int i = 0; i < t->num; i++)
	{
		//如果发现匹配的三元组就返回，不匹配就返回0
		if (t->data[i].row == row && t->data[i].col == col)
		{
			return t->data[i].val;
		}
	}
	return 0;
}



//输入三元组
void Input_TripleMatrix(int m, int n, int num, TripleMatrix* t)
{
	int row, col, val;
	for (int i = 1; i <= num; i++)
	{
		printf("请依次输入行、列和非零元:\n");
		scanf("%d %d %d", &row, &col, &val);
		if (val != 0)
		{
			Set_Val(t, row, col, val);
		}
	}
}

//打印稀疏矩阵
void Print_TripleMatrix(TripleMatrix* t)
{
	int tripleIndex = 0;//控制三元组
	printf("打印矩阵:\n");

	for (int i = 1; i <= t->mu; i++)
	{
		for (int j = 1; j <= t->nu; j++)
		{
			//如果发现行列号匹配的三元组，则输出非零元素
			if (i == t->data[tripleIndex].row && j == t->data[tripleIndex].col)
			{
				printf("%d\t", t->data[tripleIndex].val);
				tripleIndex++;
			}
			else
			{
				//否则输出0
				printf("0\t");
			}
		}
		printf("\n");
	}
	printf("矩阵有%d行%d列，共%d个非零元素\n", t->mu, t->nu, t->num);
}


//打印三元组数组
void Print_Triple(TripleMatrix* t)
{
	printf("打印三元组数组:\n");
	printf("row\tcol\tval\n");
	for (int i = 0; i < t->num; i++)
	{
		printf("%d\t%d\t%d\n", t->data[i].row, t->data[i].col, t->data[i].val);
	}
}


//稀疏矩阵的乘法运算
bool Maxtrix_Multy(TripleMatrix* a, TripleMatrix* b, TripleMatrix* result)
{
	//如果矩阵a的行和矩阵b的列不相等，就无法进行计算
	if (a->nu != b->mu)
	{
		printf("矩阵a的列和矩阵b的行不相等，就无法进行计算\n");

		return false;
	}

	//初始化result矩阵的值
	Init_TripleMatrix(result, a->mu, b->nu);


	//乘法运算代码
	for (int i = 1; i <= a->mu; i++)
	{
		for (int j = 1; j <= b->nu; j++)
		{
			int sum = 0;
			for (int k = 1; k <= a->nu; k++)
			{
				sum += Get_Val(i, k, a) * Get_Val(k, j, b);
			}

			//如果算出来的值不为0，则插入到稀疏矩阵中
			Set_Val(result, i, j, sum);
		}
	}
	return true;

}


//测试用例
//3 3 2
//1 1 5
//2 3 1
//3 2 2
//1 1 2 
// 
//3 1 4



void menu()
{
	printf("\t\t1.输入两个稀疏矩阵进行相乘\n");
	printf("\t\t0.退出\n");
}

void test()
{
	TripleMatrix t;
	printf("\n请输入第一个三元组\n");
	printf("请输入三元组的行数、列数以及元素个数:\n");
	int m, n, num;
	scanf("%d %d %d", &m, &n, &num);

	Init_TripleMatrix(&t, m, n);
	Input_TripleMatrix(m, n, num, &t);
	Print_Triple(&t);
	Print_TripleMatrix(&t);

	printf("\n--------------------------------------\n");
	printf("请输入第二个三元组\n");
	TripleMatrix b;
	printf("请输入三元组的行数、列数以及元素个数:\n");
	scanf("%d %d %d", &m, &n, &num);
	Init_TripleMatrix(&b, m, n);
	Input_TripleMatrix(m, n, num, &b);
	Print_Triple(&b);
	Print_TripleMatrix(&b);



	printf("\n--------------------------------------\n");
	TripleMatrix result;

	bool ret = Maxtrix_Multy(&t, &b, &result);

	if (ret == true)
	{
		Print_Triple(&result);
		printf("矩阵相乘的结果为:\n");
		Print_TripleMatrix(&result);
	}
	system("pause");
	system("cls");

}


int main()
{
	int option;
	while (1)
	{
		menu();
		scanf("%d", &option);
		if (option == 1)
		{
			test();
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