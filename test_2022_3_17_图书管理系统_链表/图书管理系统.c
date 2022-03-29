#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�����ڵ㣬ÿһ���ڵ����ͼ����Ϣ�Լ�ָ����һ���ڵ�
typedef struct Node
{
	char name[20];//����
	char sn[20];//���
	float price;//�۸�
	int inventory;//���
	struct Node* next;//ָ����һ���ڵ�
}Node;


//����ͷָ��
Node* head = NULL;


//��ӡͼ����Ϣ
void Print()
{
	if (head == NULL)
	{
		printf("ͼ��Ϊ�գ�");
		return;
	}
	Node* cur = head;
	printf("\n\t\tͼ����Ϣ\n");
	printf("%-20s\t%-20s\t%-5s\n", "����", "���", "�۸���Ϣ");
	while (cur != NULL)
	{
		printf("%-20s\t%-20s\t%-5.2lf\n", cur->name, cur->sn, cur->price);
		cur = cur->next;
	}
	printf("\n\n");
}


//��ӡ�����Ϣ
void Print_()
{
	if (head == NULL)
	{
		printf("��ͼ����Ϣ\n");
		return;
	}
	printf("\n\t\t�����Ϣ\n");
	printf("%-20s\t%-5s\n", "����", "���");
	Node* cur = head;

	while (cur != NULL)
	{
		printf("%-20s\t%-5d\n", cur->name,cur->inventory);
		cur = cur->next;
	}
	printf("\n\n");
}


//���ͼ����Ϣ
void Insert()
{
	//��һ�β���
	if (head ==NULL)
	{
		head = (Node*)malloc(sizeof(Node));
		if (head == NULL)
		{
			printf("malloc error!");
			exit(0);
		}
		printf("������ͼ������:\n");
		scanf("%s",head->name);

		printf("������ͼ�����:\n");
		scanf("%s",head->sn);

		printf("������ͼ��۸�:\n");
		scanf("%f", &head->price);
		head->inventory = 1;
		head->next = NULL;
		return;
	}

	//�Ժ����
	Node* cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	Node* Next = (Node*)malloc(sizeof(Node));
	if (Next == NULL)
	{
		exit(0);
	}

	printf("������ͼ������:\n");
	scanf("%s", Next->name);

	printf("������ͼ�����:\n");
	scanf("%s", Next->sn);

	printf("������ͼ��۸�:\n");
	scanf("%f", &Next->price);
	Next->inventory = 1;
	Next->next = NULL;
	cur->next = Next;
}


//�޸Ŀ����Ϣ
void Modify()
{
	printf("������Ҫ�޸Ŀ���ͼ������:\n");
	char Name[20] = { 0 };
	scanf("%s", Name);
	Node* cur = head;
	while (cur != NULL)
	{
		if (strcmp(cur->name, Name) == 0)
		{
			printf("������������:\n");
			scanf("%d", &cur->inventory);
			printf("�޸ĳɹ�\n");
			break;
		}
		cur = cur->next;
	}

	if (cur == NULL)
	{
		printf("δ�ҵ����飡\n");
	}
}

//���˵�
void menu() {
	printf("\t\tͼ�����ϵͳV0.1\n\n");
	printf("\t\t1.��ʾ��Ŀ��Ϣ\n");
	printf("\t\t2.��ʾͼ������Ϣ\n");
	printf("\t\t3.���ͼ����Ϣ\n");
	printf("\t\t4.�޸�ͼ������\n");
	printf("\t\t5.�˳�ϵͳ\n");
}




int main()
{

	int select = 0;
	while (1)
	{
		menu();
		printf("�������Ӧѡ��:\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			//��ӡͼ����Ϣ
			Print();
			break;
		case 2:
			//��ӡ���
			Print_();
			break;
		case 3:
			//����ͼ����Ϣ
			Insert();
			break;
		case 4:
			//�޸Ŀ��
			Modify();
			break;
		case 5:
			//�˳�
			printf("�˳�!\n");
			return 0;
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}


	return 0;

}