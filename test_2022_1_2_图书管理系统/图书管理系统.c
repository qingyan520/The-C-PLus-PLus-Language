#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ͼ����Ϣ�Ķ���
typedef struct Book_Data
{
	char name[50];//����
	char author[10];//����
	char press[20];//������
	char pushlish_time[20];//����ʱ��

}Book;


//�������Ա�ʵ��ͼ����Ϣ����ϵͳ
typedef struct Library
{
	Book* data;
	int capacity;
	int size;
}Library;


//��ʼ��ͼ����Ϣ����ϵͳ
void Init_Library(Library* p);

//����������
void Check_Capacity(Library* p);

//����ͼ����Ϣ
void Add_Book(Library* p);

//����ͼ�飬���ڷ���i
int Find_Name(Library* p, char name[]);

//ɾ��ͼ����Ϣ
void Del_Book(Library* p);

//�޸�ͼ����Ϣ
void Modify_Book(Library* p);

//����ͼ��
void Search_Book(Library* p);

//����ͼ����Ϣ
void Save_Book(Library* p);

//ÿ�ο�ʼʱ����ͼ����Ϣ
void Load_Book(Library* p);

//��ʾͼ����Ϣ
void Show_Book(Library* p);

//�˵�����
void menu();



//��ʼ��ͼ����Ϣ����ϵͳ
void Init_Library(Library* p)
{
	p->data = (Book*)malloc(sizeof(Book) * 1000);//������ʼ��Ϊ1000������ʱ����
	p->capacity = 1000;
	p->size = 0;

	Load_Book(p);
}


//����������
void Check_Capacity(Library* p)
{
	if (p->capacity == p->size)
	{
		//����
		Book* ptr = (Book*)realloc(p->data, (p->capacity + 1000) * sizeof(Book));
		if (ptr == NULL)
		{
			printf("����ʧ��\n");
			return;
		}
		else
		{
			p->data = ptr;
			p->capacity += 1000;
			return;
		}
	}
}

//����ͼ����Ϣ
void Add_Book(Library* p)
{
	Check_Capacity(p);

	printf("������ͼ������:\n");
	scanf("%s", p->data[p->size].name);
	printf("������ͼ������:\n");
	scanf("%s", p->data[p->size].author);
	printf("������ͼ�������:\n");
	scanf("%s", p->data[p->size].press);
	printf("������ͼ���������:\n");
	scanf("%s", &p->data[p->size].pushlish_time);

	p->size++;
	printf("��ӳɹ�\n");
}

//����ͼ�飬���ڷ���i
int Find_Name(Library* p, char name[])
{
	int i = 0;
	for (int i = 0; i < p->size; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


//ɾ��ͼ����Ϣ
void Del_Book(Library* p)
{
	char name[20] = { 0 };
	if (p->size == 0)
	{
		printf("��ͼ����Ϣ,�޷�ɾ��\n");
		return;
	}
	else
	{
		printf("������Ҫɾ����ͼ������:\n");
		scanf("%s", name);
		int pos = Find_Name(p, name);
		if (pos == -1)
		{
			printf("Ҫɾ����ͼ�鲻����\n");
		}
		else
		{
			//ɾ��
			int j = 0;
			for (j = pos; j < p->size - 1; j++)
			{
				p->data[j] = p->data[j + 1];
			}
			p->size--;
			printf("ɾ���ɹ�\n");
		}

	}
}


//�޸�ͼ����Ϣ
void Modify_Book(Library* p)
{
	char name[20];
	printf("������Ҫ�޸ĵ�ͼ�������:\n");
	scanf("%s", name);
	int pos = Find_Name(p, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ�ͼ�鲻����\n");
	}
	else
	{

		printf("������ͼ������:\n");
		scanf("%s", p->data[pos].name);
		printf("������ͼ������:\n");
		scanf("%s", p->data[pos].author);
		printf("������ͼ�������:\n");
		scanf("%s", p->data[pos].press);
		printf("������ͼ���������:\n");
		scanf("%s", &p->data[pos].pushlish_time);
		printf("������Ӣ��ɼ�:\n");
		printf("�޸ĳɹ�\n");
	}
}


//����ͼ��
void Search_Book(Library* p)
{
	char name[20];
	printf("������Ҫ���ҵ�ͼ�������:\n");
	scanf("%s", name);
	int pos = Find_Name(p, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ�ͼ�鲻����\n");
	}
	else
	{
		printf("%-20s\t%-10s\t%-20s\t%-20s\n","ͼ������","����","������","��������");
		printf("%-20s\t%-10s\t%-20s\t%-20s\n",p->data[pos].name,
			p->data[pos].author, p->data[pos].press,
			p->data[pos].pushlish_time);
	}
}


//����ͼ����Ϣ
void Save_Book(Library* p)
{
	FILE* pfOut = fopen("Book.txt", "wb");
	if (pfOut == NULL)
	{
		printf("Save_Book::%s\n", strerror(errno));
		return;
	}

	//д����
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		fwrite(p->data + i, sizeof(Book), 1, pfOut);
	}
	fclose(pfOut);
	pfOut = NULL;
}


//ÿ�ο�ʼʱ����ͼ����Ϣ
void Load_Book(Library* p)
{
	//���ļ�
	FILE* pfIn = fopen("Book.txt", "rb");
	if (pfIn == NULL)
	{
		printf("Load_Book::%s\n", strerror(errno));
		return;
	}
	//���ļ����ݣ��Ž�ͨѶ¼
	Book tmp = { 0 };
	while (fread(&tmp, sizeof(Book), 1, pfIn))
	{
		//����Ƿ�Ҫ����
		Check_Capacity(p);
		//�洢Ԫ��
		p->data[p->size] = tmp;
		p->size++;
	}

	//�ر��ļ�
	fclose(pfIn);
	pfIn = NULL;
}


//��ʾͼ����Ϣ
void Show_Book(Library* p)
{
	printf("%-20s\t%-10s\t%-20s\t%-20s\n", "ͼ������", "����", "������", "��������");
	for (int i = 0; i < p->size; i++)
	{
		printf("%-20s\t%-10s\t%-20s\t%-20s\n", p->data[i].name,
			p->data[i].author, p->data[i].press,
			p->data[i].pushlish_time);
	}
}

void menu()
{
	printf("\t\t1.���ͼ����Ϣ\n");
	printf("\t\t2.ɾ��ͼ����Ϣ\n");
	printf("\t\t3.����ͼ����Ϣ\n");
	printf("\t\t4.�޸�ͼ����Ϣ\n");
	printf("\t\t5.��ʾͼ����Ϣ\n");
	printf("\t\t6.����ͼ����Ϣ\n");
	printf("\t\t0.�˳�\n");

}
int main()
{
	int option = 0;
	Library p;
	Init_Library(&p);
	while (1)
	{
		menu();
		printf("�������Ӧѡ��:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			//�����Ϣ
			Add_Book(&p);
			system("pause");
			system("cls");
			break;
		case 2:
			//ɾ����Ϣ
			Del_Book(&p);
			system("pause");
			system("cls");
			break;
		case 3:
			//��ѯ��Ϣ
			Search_Book(&p);
			system("pause");
			system("cls");
			break;
		case 4:
			//�޸���Ϣ
			Modify_Book(&p);
			system("pause");
			system("cls");
			break;
		case 5:
			//��ʾ������Ϣ
			Show_Book(&p);
		case 6:
			//������Ϣ
			Save_Book(&p);
			system("pause");
			system("cls");
			break;
		case 0:
			printf("�˳�ϵͳ����ӭ�´�ʹ��\n");
			system("pause");
			system("cls");
			exit(0);
			break;
		default:
			printf("�����������������\n");
			system("pause");
			system("cls");
			break;

		}
	}
	return 0;
}