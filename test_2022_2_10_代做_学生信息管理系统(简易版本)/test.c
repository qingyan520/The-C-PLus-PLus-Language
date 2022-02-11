#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

//����ѧ����Ϣ
typedef struct Stu_Info
{
	char Name[30];//����
	char Number[50];//ѧ��
	int Chinese;//���ĳɼ�
	int Math;//��ѧ�ɼ�
	int English;//Ӣ��ɼ�
	float average;//ƽ����
	int sum;//�ܷ�
}Stu_Info;

//�����������洢������
Stu_Info Student[MAX];
//size����ǰѧ���ĸ���
int size = 0;


//����ѧ������
void Push()
{
	printf("������ѧ������:\n");
	scanf("%s", Student[size].Name);

	printf("������ѧ��:\n");
	scanf("%s", Student[size].Number);

	printf("���������ĳɼ�:\n");
	scanf("%d", &Student[size].Chinese);

	printf("��������ѧ�ɼ�:\n");
	scanf("%d", &Student[size].Math);

	printf("������Ӣ��ɼ�:\n");
	scanf("%d", &Student[size].English);

	//����ƽ����
	Student[size].average = (Student[size].Chinese + Student[size].Math + Student[size].English) / 3.0;

	//�����ܷ�
	Student[size].sum = Student[size].Chinese + Student[size].Math + Student[size].English;

	//����+1
	++size;
}


//����ѧ�Ų���ѧ��
int Find_Name(char name[])
{
	int i = 0;
	for (; i < size; i++)
	{
		if (strcmp(Student[i].Name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


//����ѧ�Ų���
int Find_Number(char number[])
{
	int i = 0;
	for (; i < size; i++)
	{
		if (strcmp(Student[i].Number, number) == 0)
		{
			return i;
		}
	}
	return -1;
}


//������������ɾ��
void Del_Name()
{
	char name[30] = { 0 };
	if (size == 0)
	{
		printf("��ѧ����Ϣ���޷�ɾ��\n");
		return;
	}
	else
	{
		printf("������Ҫɾ����ѧ������:\n");
		scanf("%s", name);
		int pos = Find_Name(name);
		if (pos == -1)
		{
			printf("Ҫɾ����ѧ��������\n");
			return;
		}
		else
		{
			for (int j = pos; j < size - 1; j++)
			{
				Student[j] = Student[j + 1];
			}
			size--;
			printf("ɾ���ɹ�\n");
		}
	}
}

//����ѧ�Ž���ɾ��
void Del_Number()
{
	char number[50] = { 0 };
	if (size == 0)
	{
		printf("��ѧ����Ϣ���޷�ɾ��\n");
		return;
	}
	else
	{
		printf("������Ҫɾ����ѧ��ѧ��:\n");
		scanf("%s", number);
		int pos = Find_Number(number);
		if (pos == -1)
		{
			printf("Ҫɾ����ѧ��������\n");
			return;
		}
		else
		{
			for (int j = pos; j < size - 1; j++)
			{
				Student[j] = Student[j + 1];
			}
			size--;
			printf("ɾ���ɹ�\n");
		}
	}
}

//�������������޸�
void Modify_Name()
{
	char name[30] = { 0 };
	printf("������Ҫ�޸ĵ�ѧ������:\n");
	scanf("%s", name);
	int pos = Find_Name(name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ�ѧ��������\n");
	}
	else
	{
		printf("������ѧ������:\n");
		scanf("%s", Student[pos].Name);

		printf("������ѧ��:\n");
		scanf("%s", Student[pos].Number);

		printf("���������ĳɼ�:\n");
		scanf("%d", &Student[pos].Chinese);

		printf("��������ѧ�ɼ�:\n");
		scanf("%d", &Student[pos].Math);

		printf("������Ӣ��ɼ�:\n");
		scanf("%d", &Student[pos].English);

		//����ƽ����
		Student[pos].average = (Student[pos].Chinese + Student[pos].Math + Student[pos].English) / 3.0;

		//�����ܷ�
		Student[pos].sum = Student[pos].Chinese + Student[pos].Math + Student[pos].English;
		printf("�޸ĳɹ�\n");
	}
}


//����ѧ�Ž����޸�
void Modify_Number()
{
	char number[50] = { 0 };
	printf("������Ҫ�޸ĵ�ѧ��ѧ��:\n");
	scanf("%s", number);
	int pos = Find_Name(number);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ�ѧ��������\n");
	}
	else
	{
		printf("������ѧ������:\n");
		scanf("%s", Student[pos].Name);

		printf("������ѧ��:\n");
		scanf("%s", Student[pos].Number);

		printf("���������ĳɼ�:\n");
		scanf("%d", &Student[pos].Chinese);

		printf("��������ѧ�ɼ�:\n");
		scanf("%d", &Student[pos].Math);

		printf("������Ӣ��ɼ�:\n");
		scanf("%d", &Student[pos].English);

		//����ƽ����
		Student[pos].average = (Student[pos].Chinese + Student[pos].Math + Student[pos].English) / 3.0;

		//�����ܷ�
		Student[pos].sum = Student[pos].Chinese + Student[pos].Math + Student[pos].English;
		printf("�޸ĳɹ�\n");
	}
}


//�����ֽܷ�������
void Sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (Student[j].sum < Student[j + 1].sum)
			{
				Stu_Info temp = Student[j];
				Student[j] = Student[j + 1];
				Student[j + 1] = temp;
			}
		
		}
	}
}


//��ӡ���гɼ���Ϣ
void Show()
{
	printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-5s\n", "ѧ��", "����", "����", "��ѧ", "Ӣ��", "ƽ����", "�ܷ�", "����");
	for (int i = 0; i < size; i++)
	{
		printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10.2f\t%-10d\t%-5d\n",
			Student[i].Number,
			Student[i].Name,
			Student[i].Chinese,
			Student[i].Math,
			Student[i].English,
			Student[i].average,
			Student[i].sum,
			i + 1
		);
	}
}



//���շ����ν��в�ѯ
void Search_Sum()
{
	int left = 0;
	int right = 0;
	printf("�������������:\n");
	scanf("%d", &left);
	printf("�������������:\n");
	scanf("%d", &right);
	printf("λ�ڸ÷����ε���:\n");
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (Student[i].sum >= left && Student[i].sum <= right)
		{
			count++;
		}
	}
	if (count == 0)
	{
		printf("�÷�������û����\n");
		return;
	}
	printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "ѧ��", "����", "����", "��ѧ", "Ӣ��", "ƽ����", "�ܷ�");
	for (int i = 0; i < size; i++)
	{
		if (Student[i].sum >= left && Student[i].sum <= right)
		{
			printf("%-20s\t%-20s\t%-10d\t%-10d\t%-10d\t%-10.2f\t%-10d\n",
				Student[i].Number,
				Student[i].Name,
				Student[i].Chinese,
				Student[i].Math,
				Student[i].English,
				Student[i].average,
				Student[i].sum
			);
			count++;
		}
	}
	

}

//��������ͳ��
void Count()
{
	int count1 = 0;//0~100������
	int count2 = 0;//100~200������
	int count3 = 0;//200~300������
	for (int i = 0; i < size; i++)
	{
		if (Student[i].sum >= 0 && Student[i].sum <= 100)
		{
			count1++;
		}
		if (Student[i].sum > 100 && Student[i].sum <= 200)
		{
			count2++;
		}
		if (Student[i].sum > 200 && Student[i].sum <= 300)
		{
			count3++;
		}
	}
	printf("0~100��֮��:%d��\n", count1);
	printf("100~200��֮��:%d��\n", count2);
	printf("200~300��֮��:%d��\n", count3);
}


//�����ļ�
void Save_Student()
{
	FILE* pfOut = fopen("Score_Data.txt", "wb");
	if (pfOut == NULL)
	{
		printf("Save_Student_Data::%s\n", strerror(errno));
		return;
	}

	//д����
	for (int i = 0; i < size; i++)
	{
		fwrite(Student+i, sizeof(Stu_Info), 1, pfOut);
	}
	fclose(pfOut);
	pfOut = NULL;
}


//�տ�ʼʱ���ļ�
void Load_Student()
{
	//���ļ�
	FILE* pfIn = fopen("Score_Data.txt", "rb");
	if (pfIn == NULL)
	{
		printf("Load_Student::%s\n", strerror(errno));
		return;
	}
	Stu_Info temp = { 0 };
	while (fread(&temp, sizeof(Stu_Info),1, pfIn))
	{
		Student[size] = temp;
		size++;
	}
	fclose(pfIn);
	pfIn = NULL;

}


void menu()
{
	printf("\t\t1.���ѧ����Ϣ\n");
	printf("\t\t2.��������ɾ��ѧ����Ϣ\n");
	printf("\t\t3.����ѧ��ɾ��ѧ����Ϣ\n");
	printf("\t\t4.���������޸�ѧ����Ϣ\n");
	printf("\t\t5.����ѧ���޸�ѧ����Ϣ\n");
	printf("\t\t6.��ѯλ��ĳ�������ڵ�ѧ��\n");
	printf("\t\t7.ͳ�Ʒ�������ѧ��\n");
	printf("\t\t8.��ʾ����ѧ����Ϣ\n");
	printf("\t\t9.�����ֽܷ�������\n");
	printf("\t\t0.�˳�\n");

}


int main()
{
	int option = 0;
	Load_Student();
	while (1)
	{
		menu();
		printf("�������Ӧѡ��:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			//�����Ϣ
			Push();
			system("pause");
			system("cls");
			break;
		case 2:
			//ɾ����Ϣ
			Del_Name();
			system("pause");
			system("cls");
			break;
		case 3:
			Del_Number();
			system("pause");
			system("cls");
			break;
		case 4:
			//�޸���Ϣ
			Modify_Name();
			system("pause");
			system("cls");
			break;
		case 5:
			//�޸���Ϣ
			Modify_Number();
			system("pause");
			system("cls");
			break;
		case 6:
			//λ��ĳ���������ڵ�ѧ��
			Search_Sum();
			system("pause");
			system("cls");
			break;
		case 7:
			//����ͳ��
			Count();
			system("pause");
			system("cls");
			break;
		case 8:
			//��ʾ������Ϣ
			Sort();
			Show();
			system("pause");
			system("cls");
			break;
		case 9:
			//����
			Sort();
			system("pause");
			system("cls");
			break;
		case 0:
			printf("�˳�ϵͳ����ӭ�´�ʹ��\n");
			Save_Student();
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