#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 500


//存放每一行文本
typedef struct line
{
	char* text;//存储字符串
	int len;//代表最长存储长度
	int sz;//代表当前存储的字符长度

}line;

//定义整个文档
typedef struct Text
{
	line* data;
	int size;
	int capacity;
}Text;


//初始化文档
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

//插入分为3种:
//1.插入到文本某一行的中间位置
//2.插入到末尾位置
//3.插入到某一行

//1.插入到文档某一行的中间位置
void insert_post(Text* t, int linenum, int position)
{
	char str[MAX_LEN]={0};
	printf("请输入要插入的字符串:\n");
	scanf("%s", str);
	int n = strlen(str);


	//尾部进行插入
	if (linenum == t->size+1)
	{
		for (int i = 0; i < n; i++)
		{
			t->data[linenum - 1].text[i] = str[i];
		}
		t->data[linenum - 1].sz = n;
		t->size++;
		printf("添加成功\n");
		return;
	}


	//第一行并且现在第一行没有元素，那么就进行头插
	if (linenum == 1 && t->data[linenum].sz == 0)
	{
		for (int i = 0; i < n; i++)
		{
			t->data[linenum - 1].text[i] = str[i];
		}
		t->data[linenum - 1].sz = n;
		t->size++;
		printf("添加成功\n");
		return ;
	}


	linenum = linenum - 1;
	position -= 1;
	//2.普通情况下在一个有文字的中间进行插入
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


//在某一行进行插入
void insert_line(Text* t, int linenum)
{
	char str[MAX_LEN] = { 0 };
	printf("请输入要插入的字符串:\n");
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
	printf("添加成功\n");
	
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
		printf("1.尾行添加元素:\n");
		insert_post(&t, t.size + 1, 0);

		/*printf("2.添加一行元素:\n");
		int n;
		printf("请输入要添加的行数:\n");
		scanf("%d", &n);
		insert_line(&t, n);

		printf("3.指定位置添加元素:\n");
		printf("输入行数，列数:\n");
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
		printf("2.添加一行元素:\n");
		int n;
		printf("请输入要添加的行数:\n");
		scanf("%d", &n);
		insert_line(&t, n);


		printf("\n\n\n");
		Print(&t);
		printf("\n\n\n");
	}

	a = 3;
	while (a)
	{

		printf("3.指定位置添加元素:\n");
		printf("输入行数，列数:\n");
		int m,n;
		scanf("%d", &m);
		scanf("%d", &n);
		insert_post(&t, m, n); 

		printf("\n\n\n");
		Print(&t);
		printf("\n\n\n");
	}

}