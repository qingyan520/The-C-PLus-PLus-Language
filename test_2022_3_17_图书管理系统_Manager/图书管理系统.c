#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200

//ͼ����Ϣ�ṹ�嶨��
typedef struct Book {
	char name[20];//����
	char sn[20];//���
	float price;//�۸�
	int inventory;//���
}Book;


//�������ϵͳ
typedef struct Manger
{
	Book* data;//�洢����
	int size;//��ǰԪ�ظ���
	int capacity;//�ܸ���

}Manger;


//��ʼ������ϵͳ
void Init(Manger* manger)
{
	manger->data = (Book*)malloc(sizeof(Book)*MAX);
	manger->size = 0;
	manger->capacity = MAX;
}


//��ӡͼ����Ϣ
void Print_Book(Manger*manger)
{
	printf("\t\tͼ����Ϣ\n");
	printf("%-20s\t%-20s\t%-5s\n", "����", "���", "�۸���Ϣ");
	for (int i = 0; i < manger->size; i++) {
		printf("%-20s\t%-20s\t%-5.2lf\n", manger->data[i].name, manger->data[i].sn, manger->data[i].price);
	}
}

//��ʾͼ����
void Print_Inventory(Manger*manger)
{
	printf("\t\t�����Ϣ\n");
	printf("%-20s\t%-5s\n", "����", "���");
	for (int i = 0; i < manger->size; i++)
	{
		printf("%-20s\t%-5d\n", manger->data[i].name, manger->data[i].inventory);
	}
}

//�������
void Check(Manger* manger)
{
	if (manger->size <= manger->capacity)
	{
		return;
	}
	else
	{
		Book* p = realloc(manger->data, sizeof(Book) * (manger->capacity + MAX));
		if (p != NULL)
		{
			manger->data = p;
		}
	}
}


//���ͼ����Ϣ
void Add_Books(Manger*manger)
{
	//��������Ƿ�����
	Check(manger);
	printf("������ͼ������:\n");
	scanf("%s", manger->data[manger->size].name);

	printf("������ͼ�����:\n");
	scanf("%s", manger->data[manger->size].sn);

	printf("������ͼ��۸�:\n");
	scanf("%f", &manger->data[manger->size].price);

	manger->data[manger->size].inventory = 1;

	manger->size++;
}


//������ͼ���Ƿ����
int Search(Manger*manger, char name[])
{
	for (int i = 0; i < manger->size; i++)
	{
		if (strcmp(manger->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//�޸Ŀ������
void Modify_Inventory(Manger*manger)
{
	printf("������Ҫ�޸Ŀ���ͼ������:\n");
	char name[20] = { 0 };
	scanf("%s", name);
	//���������޸ģ��������޸�
	int i = Search(manger, name);
	if (i == -1)
	{
		printf("δ�ҵ���ͼ�飡\n");

	}
	else
	{
		printf("������������:\n");
		scanf("%d", &manger->data[i].inventory);
		printf("�޸ĳɹ���\n");
	}
}


//���˵�
void Menu()
{
	printf("\t\tͼ�����ϵͳV0.1\n\n");
	printf("\t\t1.��ʾ��Ŀ��Ϣ\n");
	printf("\t\t2.��ʾͼ������Ϣ\n");
	printf("\t\t3.���ͼ����Ϣ\n");
	printf("\t\t4.�޸�ͼ������\n");
	printf("\t\t5.�˳�ϵͳ\n");
}

int main()
{

	Manger manger;
	Init(&manger);
	int option = 0;
	while (1)
	{
		Menu();
		printf("�������Ӧѡ��:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			Print_Book(&manger);
			break;
		case 2:
			Print_Inventory(&manger);
			break;
		case 3:
			Add_Books(&manger);
			break;
		case 4:
			Modify_Inventory(&manger);
			break;
		case 5:
			printf("�˳�����ӭ�´�ʹ�ã�\n");
			return 0;
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}


	return 0;
}
