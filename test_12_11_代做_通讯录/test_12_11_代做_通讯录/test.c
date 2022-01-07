//��̬������ͨѶ¼�����ö�̬�ڴ����+�ļ�����ʵ������ϵ�˵ı��棬���룬������޸ĵ�һϵ�й���

//ÿ���˵���Ϣ��
//����
//����
//�Ա�
//�绰
//סַ

//���ܣ�
//1. ����һ���˵���Ϣ
//2. ɾ��һ��ָ������ϵ��
//3. ����һ��ָ������ϵ��
//4. �޸�һ��ָ������ϵ��
//5. ��ʾͨѶ¼�������˵���Ϣ
//6. ����
//0. �˳�

//��̬�����İ汾 - ���迪��
//�ļ��İ汾 - ���ݿ��Դ洢���ļ��У������ڶ�ʧ

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

#define DEFAULT_SZ 3


#define MAX 1000

//����һ������Ϣ�Ľṹ��
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;




//��̬������ͨѶ¼�汾
typedef struct Contact
{
	struct PeoInfo* data;
	int sz;//��ʾͨѶ¼�е�ǰ��ŵ��˵���Ϣ����
	int capacity;//��ʾͨѶ¼��ǰ���������
}Contact;


//����������

//��ʼ��ͨѶ¼�ĺ���
void InitContact(struct Contact* pc);

//����һ���˵���Ϣ
void AddContact(struct Contact* pc);

//��ӡͨѶ�е���Ϣ
void ShowContact(const struct Contact* pc);

//ɾ��һ���˵���Ϣ
void DelContact(struct Contact* pc);

//����ָ����ϵ��
void SearchContact(const struct Contact* pc);

//�޸�ָ����ϵ��
void ModifyContact(struct Contact* pc);


//����ͨѶ¼
void DestroyContact(struct Contact* pc);

//�������ݵ��ļ�
void SaveContact(Contact* pc);




//��������Ƿ���
int CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//����
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr == NULL)
		{
			printf("����ʧ��\n");
			return 0;
		}
		else
		{
			//������ݳɹ�Ҫ��ptr��ֵ��pc->data
			pc->data = ptr;
			pc->capacity += 2;
			printf("���ݳɹ�\n");
			return 1;
		}
	}
	return 1;
}


//ÿ������ʱ�����ļ��е���ϵ����Ϣ
void LoadContact(Contact* pc)
{
	//���ļ�
	FILE* pfIn = fopen("contact.dat", "rb");
	if (pfIn == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	//���ļ����ݣ��Ž�ͨѶ¼
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfIn))
	{
		//����Ƿ�Ҫ����
		if (CheckCapacity(pc) == 0)
		{
			printf("ͨѶ¼��ʼ��ʧ��\n");
			return;
		}
		//�洢Ԫ��
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//�ر��ļ�
	fclose(pfIn);
	pfIn = NULL;
}

//��̬�汾-��ʼ��ͨѶ¼
void InitContact(struct Contact* pc)
{
	pc->sz = 0;//ͨѶ¼�����õ�ʱ��û����Ч��Ϣ
	pc->capacity = DEFAULT_SZ;//ͨѶ¼�����õ�ʱ��Ĭ���ܷ�DEFAULT_SZ���˵���Ϣ
	pc->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (pc->data == NULL)
	{
		printf("��ʼ��ͨѶ¼ʧ��\n");
		exit(1);
	}
	//�����ļ�
	LoadContact(pc);
}



//��̬�����İ汾
void AddContact(struct Contact* pc)
{
	if (CheckCapacity(pc) == 0)
	{
		printf("�ռ䲻��ʹ�ã���������ʱʧ��\n");
		return;
	}

	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("�������ַ:>");
	scanf("%s", pc->data[pc->sz].addr);

	pc->sz++;
	printf("��ӳɹ�\n");
}


//��ʾͨѶ¼��Ϣ
void ShowContact(const struct Contact* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("\n");
		printf("��ӭ���ͨѶ¼��\n");
		printf("----------------------------------------------------------------------------\n");
		printf("                              ͨѶ¼                                        | \n");
		printf("----------------------------------------------------------------------------\n");
		printf("%-15s|\t%-5s|\t%-5s|\t%-12s|\t%-20s|\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("----------------------------------------------------------------------------\n");
		for (i = 0; i < pc->sz; i++)
		{
			printf("%-15s|\t%-5d|\t%-5s|\t%-12s|\t%-20s|\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr);
			printf("----------------------------------------------------------------------------\n");
		}
		printf("\n");

	}

}


//������������
static int FindByName(const struct Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}

	//û�ҵ�
	return -1;
}


//ɾ��ͨѶ¼��Ϣ
void DelContact(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };

	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û��ɾ��\n");
	}
	else
	{
		//1.�ҵ�Ҫɾ������
		printf("������Ҫɾ���˵�����:>");
		scanf("%s", name);
		int pos = FindByName(pc, name);
		if (pos == -1)
		{
			printf("Ҫɾ�����˲�����\n");
		}
		else
		{
			//2.ɾ��
			int j = 0;
			for (j = pos; j < pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}

			pc->sz--;
			printf("ɾ���ɹ�\n");
		}

	}
}

//������ϵ��
void SearchContact(const struct Contact* pc)
{
	char name[NAME_MAX];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("----------------------------------------------------------------------------\n");
		printf("%-15s|\t%-5s|\t%-5s|\t%-12s|\t%-20s|\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("----------------------------------------------------------------------------\n");
		printf("%-15s|\t%-5d|\t%-5s|\t%-12s|\t%-20s|\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
		printf("----------------------------------------------------------------------------\n");
	}
	printf("\n");
}


//�޸���ϵ��
void ModifyContact(struct Contact* pc)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[pos].name);
		printf("����������:>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("������绰:>");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", pc->data[pos].addr);

		printf("�޸ĳɹ�\n");
	}
}


//����ͨѶ¼
void DestroyContact(struct Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}


//ÿ���˳�ʱ�����ļ�
void SaveContact(Contact* pc)
{
	//���ļ�
	FILE* pfOut = fopen("contact.dat", "wb");
	if (pfOut == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	//д����
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfOut);
	}

	//�ر��ļ�
	fclose(pfOut);
	pfOut = NULL;
}



void menu()
{
	printf("***********************************************\n");
	printf("*****   1. �����ϵ��      2.ɾ����ϵ��  ******\n");
	printf("*****   3. ������ϵ��      4.�޸���ϵ��  ******\n");
	printf("*****   5. ��ʾ��ϵ��      6.������ϵ��  ******\n");
	printf("*****   0. exit                          ******\n");
	printf("***********************************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SAVE
};

void test()
{
	int input = 0;
	struct Contact con;//������һ��ͨѶ¼

	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{

		case ADD:
			AddContact(&con);
			break;

		case DEL:
			DelContact(&con);
			break;

		case SEARCH:
			SearchContact(&con);
			break;

		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;

		case SAVE:
			SaveContact(&con);
			break;

		case EXIT:
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}
