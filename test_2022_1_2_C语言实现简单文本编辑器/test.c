#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 500


//���ÿһ���ı�
typedef struct line
{
	char* text;//�洢�ַ���
	int len;//������洢����
	int sz;//����ǰ�洢���ַ�����

}line;

//���������ĵ�
typedef struct Text
{
	line* data;
	int size;
	int capacity;
}Text;


//��ʼ���ĵ�
void Init_Text(Text* t)
{
	t->data = (line*)malloc(sizeof(line) * MAX_LEN);
	t->size = 0;
	t->capacity = MAX_LEN;
	for (int i = 0; i < t->capacity; i++)
	{
		t->data[i].text = (char*)malloc(sizeof(char) * MAX_LEN);
		t->data[i].len = MAX_LEN;
		for (int j = 0; j < MAX_LEN; j++)
		{
			t->data[i].text[j] = '\0';
		}
		t->data[i].sz = 0;
	}
}

//�����Ϊ3��:
//1.���뵽�ı�ĳһ�е��м�λ��
//2.���뵽ĩβλ��
//3.���뵽ĳһ��

//1.���뵽�ĵ�ĳһ�е��м�λ��
void insert_post(Text* t, int linenum, int position)
{
	char str[MAX_LEN]={0};
	printf("������Ҫ������ַ���:\n");
	scanf("%s", str);
	int n = strlen(str);


	//β�����в���
	if (linenum == t->size+1)
	{
		for (int i = 0; i < n; i++)
		{
			t->data[linenum - 1].text[i] = str[i];
		}
		t->data[linenum - 1].sz = n;
		t->size++;
		printf("��ӳɹ�\n");
		return;
	}


	//��һ�в������ڵ�һ��û��Ԫ�أ���ô�ͽ���ͷ��
	if (linenum == 1 && t->data[linenum].sz == 0)
	{
		for (int i = 0; i < n; i++)
		{
			t->data[linenum - 1].text[i] = str[i];
		}
		t->data[linenum - 1].sz = n;
		t->size++;
		printf("��ӳɹ�\n");
		return ;
	}


	linenum = linenum - 1;
	position -= 1;
	//2.��ͨ�������һ�������ֵ��м���в���
	for (int i = t->data[linenum].sz+n; i > position; i--)
	{
		t->data[linenum].text[i] = t->data[linenum].text[i - 1];
	}
	for (int i = position; i < n + position; i++)
	{
		t->data[linenum].text[i] = str[i-position];
	}
	t->data[linenum].sz += n;
}


//��ĳһ�н��в���
void insert_line(Text* t, int linenum)
{
	char str[MAX_LEN] = { 0 };
	printf("������Ҫ������ַ���:\n");
	scanf("%s", str);
	int n = strlen(str);

	linenum = linenum - 1;
	for (int i = linenum + t->size; i > linenum; i--)
	{
		t->data[i].len = t->data[i - 1].len;
		t->data[i].sz = t->data[i - 1].sz;
		for (int j = 0; j < t->data[i].sz; j++)
		{
			t->data[i].text[j] = t->data[i-1].text[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		t->data[linenum].text[i] = str[i];
	}
	t->size++;
	t->data[linenum].sz =n;
	printf("��ӳɹ�\n");
	
}

void Print(Text* t)
{
	for (int i = 0; i < t->size; i++)
	{
		printf("%d: ", i + 1);
		for (int j = 0; j < t->data[i].sz; j++)
		{
			printf("%c", t->data[i].text[j]);
		}
		printf("\n");
	}
}
int main()
{
	Text t;
	Init_Text(& t);
	int a = 3;
	while (a--)
	{
		printf("1.β�����Ԫ��:\n");
		insert_post(&t, t.size + 1, 0);

		/*printf("2.���һ��Ԫ��:\n");
		int n;
		printf("������Ҫ��ӵ�����:\n");
		scanf("%d", &n);
		insert_line(&t, n);

		printf("3.ָ��λ�����Ԫ��:\n");
		printf("��������������:\n");
		int m;
		scanf("%d", &m);
		scanf("%d", &n);
		insert_post(&t,m,n);*/

		printf("\n\n\n");
		Print(&t);
		printf("\n\n\n");
	}

	a = 3;
	while (a--)
	{
		printf("2.���һ��Ԫ��:\n");
		int n;
		printf("������Ҫ��ӵ�����:\n");
		scanf("%d", &n);
		insert_line(&t, n);


		printf("\n\n\n");
		Print(&t);
		printf("\n\n\n");
	}

	a = 3;
	while (a)
	{

		printf("3.ָ��λ�����Ԫ��:\n");
		printf("��������������:\n");
		int m,n;
		scanf("%d", &m);
		scanf("%d", &n);
		insert_post(&t, m, n); 

		printf("\n\n\n");
		Print(&t);
		printf("\n\n\n");
	}

}