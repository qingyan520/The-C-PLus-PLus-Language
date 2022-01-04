#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ѧ����Ϣ�Ķ���
typedef struct Student_Data
{
	char Number[10];//ѧ��ѧ��
	char Name[20];//ѧ������
	char ClassName[20];//�༶����
	float Data_Structure;//���ݽṹ�ɼ�
	float English;//��ѧӢ��ɼ�
	float Math;//�ߵ���ѧ�ɼ�
	float score;//��¼ƽ���ɼ�

}Student_Data;


//�������Ա�ʵ��ѧ���ɼ�����ϵͳ
typedef struct Score_Management
{
	Student_Data* data;
	int capacity;
	int size;
}Score_Management;



//��ʼ��ѧ����Ϣ����ϵͳ
void Init_Score_Management(Score_Management* p)
{
	p->data = (Student_Data*)malloc(sizeof(Score_Management) * 1000);//������ʼ��Ϊ1000������ʱ����
	p->capacity = 1000;
	p->size = 0;
}


//����������
void Check_Capacity(Score_Management* p)
{
	if (p->capacity == p->size)
	{
		//����
		Student_Data* ptr = (Student_Data*)realloc(p->data, (p->capacity + 1000) * sizeof(Student_Data));
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

//����ѧ����Ϣ
void Add_Student_Data(Score_Management* p)
{
	Check_Capacity(p);

	printf("������ѧ��:\n");
	scanf("%s", p->data[p->size].Number);
	printf("����������:\n");
	scanf("%s", p->data[p->size].Name);
	printf("������༶:\n");
	scanf("%s", p->data[p->size].ClassName);
	printf("���������ݽṹ�ɼ�:\n");
	scanf("%f", &p->data[p->size].Data_Structure);
	printf("������Ӣ��ɼ�:\n");
	scanf("%f", &p->data[p->size].English);
	printf("������ߵ���ѧ�ɼ�:\n");
	scanf("%f", &p->data[p->size].Math);

	//����ƽ���ɼ�
	p->data[p->size].score = (p->data[p->size].Data_Structure + p->data[p->size].English + p->data[p->size].Math) / 3.0;
	p->size++;
	printf("��ӳɹ�\n");
}


int Find_Name(Score_Management* p, char name[])
{
	int i = 0;
	for (int i = 0; i < p->size; i++)
	{
		if (strcmp(p->data[i].Name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


//ɾ��ѧ����Ϣ
void Del_Student_Data(Score_Management* p)
{
	char name[20] = { 0 };
	if (p->size == 0)
	{
		printf("��ѧ����Ϣ,�޷�ɾ��\n");
		return;
	}
	else
	{
		printf("������Ҫɾ����ѧ������:\n");
		scanf("%s", name);
		int pos = Find_Name(p, name);
		if (pos == -1)
		{
			printf("Ҫɾ�����˲�����\n");
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


//�޸�ѧ����Ϣ
void Modify_Student_Data(Score_Management* p)
{
	char name[20];
	printf("������Ҫ�޸ĵ�����:\n");
	scanf("%s", name);
	int pos = Find_Name(p, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{

		printf("������ѧ��:\n");
		scanf("%s", p->data[pos].Number);
		printf("����������:\n");
		scanf("%s", p->data[pos].Name);
		printf("������༶:\n");
		scanf("%s", p->data[pos].ClassName);
		printf("���������ݽṹ�ɼ�:\n");
		scanf("%f", &p->data[pos].Data_Structure);
		printf("������Ӣ��ɼ�:\n");
		scanf("%f", &p->data[pos].English);
		printf("������ߵ���ѧ�ɼ�:\n");
		scanf("%f", &p->data[pos].Math);
		//����ƽ���ɼ�
		p->data[pos].score = (p->data[pos].Data_Structure + p->data[pos].English + p->data[pos].Math) / 3.0;
		printf("�޸ĳɹ�\n");
	}
}


//����ѧ��
void Search_Student_Data(Score_Management* p)
{
	char name[20];
	printf("������Ҫ���ҵ�ѧ��������:\n");
	scanf("%s",name);
	int pos = Find_Name(p, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ�ѧ��������\n");
	}
	else
	{
		printf("%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\n", "ѧ��", "����", "�༶", "���ݽṹ", "��ѧӢ��", "�ߵ���ѧ", "ƽ����");
		printf("%-10s\t%-20s\t%-20s\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f\n",
			p->data[pos].Number,p->data[pos].Name,p->data[pos].ClassName,
			p->data[pos].Data_Structure,p->data[pos].English,p->data[pos].Math,
			p->data[pos].score);
	}
}


//�����ļ�
void Save_Student_Data(Score_Management* p)
{
	FILE* pfOut = fopen("Score_Data.txt", "wb");
	if (pfOut == NULL)
	{
		printf("Save_Student_Data::%s\n", strerror(errno));
		return;
	}

	//д����
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		fwrite(p->data + i, sizeof(Student_Data), 1, pfOut);
	}
	fclose(pfOut);
	pfOut = NULL;
}


//��ʾ�ɼ�
void Show_Student_Data(Score_Management* p)
{
	printf("%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "ѧ��", "����", "�༶", "���ݽṹ", "��ѧӢ��", "�ߵ���ѧ", "ƽ����");
	for (int i = 0; i < p->size; i++)
	{
		printf("%-10s\t%-20s\t%-20s\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f\n",
			p->data[i].Number, p->data[i].Name, p->data[i].ClassName,
			p->data[i].Data_Structure, p->data[i].English, p->data[i].Math,
			p->data[i].score);
	}
}


void Swap(Student_Data* a, Student_Data* b)
{
	Student_Data temp = *a;
	*a = *b;
	*b = temp;
}

//����ƽ���ֽ�����������ɼ�
void Sort_Student_Data(Score_Management* p)
{
	for (int i = 0; i < p->size - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < p->size - 1 - i; j++)
		{
			if (p->data[j].score < p->data[j + 1].score)
			{
				Swap(&p->data[j], &p->data[j + 1]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
	printf("%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-5s\n", "ѧ��", "����", "�༶", "���ݽṹ", "��ѧӢ��", "�ߵ���ѧ", "ƽ����","����");
	for (int i = 0; i < p->size; i++)
	{
		printf("%-10s\t%-20s\t%-20s\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f\t%-5d\n",
			p->data[i].Number, p->data[i].Name, p->data[i].ClassName,
			p->data[i].Data_Structure, p->data[i].English, p->data[i].Math,
			p->data[i].score,i+1);
	}


}


void menu()
{
	printf("\t\t1.���ѧ����Ϣ\n");
	printf("\t\t2.ɾ��ѧ����Ϣ\n");
	printf("\t\t3.����ѧ����Ϣ\n");
	printf("\t\t4.�޸�ѧ����Ϣ\n");
	printf("\t\t5.��ʾ������Ϣ\n");
	printf("\t\t6.����ѧ����Ϣ\n");
	printf("\t\t7.����ƽ���ָߵ��������������\n");
	printf("\t\t0.�˳�\n");

}
int main()
{
	int option=0;
	Score_Management p;
	Init_Score_Management(&p);
	while (1)
	{
		menu();
		printf("�������Ӧѡ��:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			//�����Ϣ
			Add_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 2:
			//ɾ����Ϣ
			Del_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 3:
			//��ѯ��Ϣ
			Search_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 4:
			//�޸���Ϣ
			Modify_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 5:
			//��ʾ������Ϣ
			Show_Student_Data(&p);
		case 6:
			//������Ϣ
			Save_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 7:
			//����ƽ���ֽ�������
			Sort_Student_Data(&p);
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