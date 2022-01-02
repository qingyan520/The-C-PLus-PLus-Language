#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000

//������Ԫ��
typedef struct Triple
{
	int row, col;//������Ԫ����кţ��к�
	int val;//������Ԫ�����
}Triple;


//����ϡ�����
typedef struct TripleMatrix
{
	Triple data[MAX];//������Ԫ��
	int mu, nu, num;//����������������Լ�����ֵ�ĸ���
}TripleMatrix;


//��ʼ��ϡ�����
void Init_TripleMatrix(TripleMatrix* t, int m, int n)
{
	t->mu = m;
	t->nu = n;
	t->num = 0;
}


//��ϡ����������Ԫ��
void Set_Val(TripleMatrix* t, int row, int col, int val)
{
	if (row > t->mu || col > t->nu)
	{
		printf("����������������ϡ�����ķ�Χ\n");
		return;
	}
	if (val == 0)
	{
		return;
	}

	//����whileѭ���ҵ��ʺϴ洢��λ��
	int index = 0;
	while (index < t->num)
	{
		//���Ҫ�ҵ�row��col�������е���Ԫ�����ֵ�����������ƶ�
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
		//��ǰԪ���Ѿ����ڣ����µ�ǰԪ�ؼ���
		t->data[index].val = val;
	}
	else
	{
		//index������Ԫ��������ƶ�һ��λ��
		for (int i = t->num; i > index; i--)
		{
			t->data[i] = t->data[i - 1];
		}
		t->data[index].col = col;
		t->data[index].row = row;
		t->data[index].val = val;
		//Ԫ�ظ���++
		t->num++;
	}
}


//�����кź��кŻ�ȡϡ������е�ֵ
int Get_Val(int row, int col, TripleMatrix* t)
{
	if (row > t->mu || col > t->nu)
	{
		return 0;
	}

	//������Ԫ��
	for (int i = 0; i < t->num; i++)
	{
		//�������ƥ�����Ԫ��ͷ��أ���ƥ��ͷ���0
		if (t->data[i].row == row && t->data[i].col == col)
		{
			return t->data[i].val;
		}
	}
	return 0;
}



//������Ԫ��
void Input_TripleMatrix(int m, int n, int num, TripleMatrix* t)
{
	int row, col, val;
	for (int i = 1; i <= num; i++)
	{
		printf("�����������С��кͷ���Ԫ:\n");
		scanf("%d %d %d", &row, &col, &val);
		if (val != 0)
		{
			Set_Val(t, row, col, val);
		}
	}
}

//��ӡϡ�����
void Print_TripleMatrix(TripleMatrix* t)
{
	int tripleIndex = 0;//������Ԫ��
	printf("��ӡ����:\n");

	for (int i = 1; i <= t->mu; i++)
	{
		for (int j = 1; j <= t->nu; j++)
		{
			//����������к�ƥ�����Ԫ�飬���������Ԫ��
			if (i == t->data[tripleIndex].row && j == t->data[tripleIndex].col)
			{
				printf("%d\t", t->data[tripleIndex].val);
				tripleIndex++;
			}
			else
			{
				//�������0
				printf("0\t");
			}
		}
		printf("\n");
	}
	printf("������%d��%d�У���%d������Ԫ��\n", t->mu, t->nu, t->num);
}


//��ӡ��Ԫ������
void Print_Triple(TripleMatrix* t)
{
	printf("��ӡ��Ԫ������:\n");
	printf("row\tcol\tval\n");
	for (int i = 0; i < t->num; i++)
	{
		printf("%d\t%d\t%d\n", t->data[i].row, t->data[i].col, t->data[i].val);
	}
}


//ϡ�����ĳ˷�����
bool Maxtrix_Multy(TripleMatrix* a, TripleMatrix* b, TripleMatrix* result)
{
	//�������a���к;���b���в���ȣ����޷����м���
	if (a->nu != b->mu)
	{
		printf("����a���к;���b���в���ȣ����޷����м���\n");

		return false;
	}

	//��ʼ��result�����ֵ
	Init_TripleMatrix(result, a->mu, b->nu);


	//�˷��������
	for (int i = 1; i <= a->mu; i++)
	{
		for (int j = 1; j <= b->nu; j++)
		{
			int sum = 0;
			for (int k = 1; k <= a->nu; k++)
			{
				sum += Get_Val(i, k, a) * Get_Val(k, j, b);
			}

			//����������ֵ��Ϊ0������뵽ϡ�������
			Set_Val(result, i, j, sum);
		}
	}
	return true;

}


//��������
//3 3 2
//1 1 5
//2 3 1
//3 2 2
//1 1 2 
// 
//3 1 4



void menu()
{
	printf("\t\t1.��������ϡ�����������\n");
	printf("\t\t0.�˳�\n");
}

void test()
{
	TripleMatrix t;
	printf("\n�������һ����Ԫ��\n");
	printf("��������Ԫ��������������Լ�Ԫ�ظ���:\n");
	int m, n, num;
	scanf("%d %d %d", &m, &n, &num);

	Init_TripleMatrix(&t, m, n);
	Input_TripleMatrix(m, n, num, &t);
	Print_Triple(&t);
	Print_TripleMatrix(&t);

	printf("\n--------------------------------------\n");
	printf("������ڶ�����Ԫ��\n");
	TripleMatrix b;
	printf("��������Ԫ��������������Լ�Ԫ�ظ���:\n");
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
		printf("������˵Ľ��Ϊ:\n");
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