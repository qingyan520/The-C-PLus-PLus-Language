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

//x,y,found代表该元素有没有被找到
typedef struct option
{
	int x;
	int y;
	int found;
}option;



int hehe = 1;//控制刚开始要不要继续输入文字了
//初始化文档
void Init_Text(Text* t)
{
	t->data = (line*)malloc(sizeof(line) * MAX_LEN);
	t->size = 0;
	t->capacity = MAX_LEN;
	if (t->data == NULL)
	{
		return;
	}
	for (int i = 0; i < t->capacity; i++)
	{
		t->data[i].text = (char*)malloc(sizeof(char) * MAX_LEN);
		t->data[i].len = MAX_LEN;
		if (t->data[i].text == NULL)
		{
			return;
		}
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
	char str[MAX_LEN] = { 0 };
	//printf("请输入要插入的字符串:\n");
	scanf("%s", str);
	int n = strlen(str);
	if (strcmp(str, "#") == 0)
	{
		hehe = 0;
		return;
	}

	//尾部进行插入
	if (linenum == t->size + 1)
	{
		for (int i = 0; i < n; i++)
		{
			t->data[linenum - 1].text[i] = str[i];
		}
		t->data[linenum - 1].sz = n;
		t->size++;
		//printf("添加成功\n");
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
		return;
	}


	linenum = linenum - 1;
	position -= 1;
	//2.普通情况下在一个有文字的中间进行插入
	for (int i = t->data[linenum].sz + n; i > position; i--)
	{
		t->data[linenum].text[i] = t->data[linenum].text[i - 1];
	}
	for (int i = position; i < n + position; i++)
	{
		t->data[linenum].text[i] = str[i - position];
	}
	t->data[linenum].sz += n;
}


//在某一行进行插入
void insert_line(Text* t, int linenum)
{
	char str[MAX_LEN] = { 0 };
	printf("请输入要插入的字符串\n");
	scanf("%s", str);
	int n = strlen(str);


	linenum = linenum - 1;
	for (int i = linenum + t->size; i > linenum; i--)
	{
		t->data[i].len = t->data[i - 1].len;
		t->data[i].sz = t->data[i - 1].sz;
		for (int j = 0; j < t->data[i].sz; j++)
		{
			t->data[i].text[j] = t->data[i - 1].text[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		t->data[linenum].text[i] = str[i];
	}
	t->size++;
	t->data[linenum].sz = n;
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

void del_line(Text* t, int linenum)
{

	linenum -= 1;
	if (linenum < 0 || linenum >= t->size)
	{
		printf("改行不存在\n");
		return;
	}

	for (int i = linenum; i < t->size - 1; i++)
	{
		for (int j = 0; j < t->data[i + 1].sz; j++)
		{
			t->data[i].text[j] = t->data[i + 1].text[j];
		}
		t->data[i].sz = t->data[i + 1].sz;
		t->data[i].len = t->data[i + 1].len;
	}
	t->size--;
	printf("删除成功\n");
}


//查找一段文字在该文档中
option findstr(Text* t, char* to_find)
{
	int i = 0, find_len, found = 0, j = 0;

	option ret;
	ret.x = 0;
	ret.y = 0;
	ret.found = 0;
	find_len = strlen(to_find);
	char substr[MAX_LEN];
	for (; i < t->size; i++)
	{
		for (; j <= strlen(t->data[i].text) - find_len; j++)
		{
			strncpy(substr, &t->data[i].text[j], find_len);
			substr[find_len] = '\0';
			if (strcmp(substr, to_find) == 0)
			{
				found = 1;
				break;
			}
		}
		if (found == 1)
		{
			break;
		}
	}

	if (found == 1)
	{
		printf("%s位于第%d行第%d列\n", to_find, i + 1, j + 1);
		ret.x = i;
		ret.y = j;
		ret.found = found;
	}
	else
	{
		printf("未找到该字符串\n");
	}
	return ret;
}






void count_str(Text* t)
{
	int count1 = 0;//数字
	int count2 = 0;//字母
	int count3 = 0;//其它字符
	for (int i = 0; i < t->size; i++)
	{
		for (int j = 0; j < t->data[i].sz; j++)
		{
			if (t->data[i].text[j] >= '0' && t->data[i].text[j] <= '9')
			{
				count1++;
			}
			else if ((t->data[i].text[j] >= 'a' && t->data[i].text[j] <= 'z') || (t->data[i].text[j] >= 'A' && t->data[i].text[j] <= 'B'))
			{
				count2++;
			}
			else
			{
				count3++;
			}
		}
	}

	printf("共计数字%d个，字母%d个，其它字符%d个\n", count1, count2, count3);

}


void insert_x_y(Text* t, int x, int y, char* s)
{
	x -= 1;
	y -= 1;
	if (x < 0 || x >= t->size)
	{
		printf("插入的行超出范围\n");
		return;
	}
	if (y >= t->data[x].sz || y < 0)
	{
		printf("插入的列超出范围:\n");
		return;
	}
	char str[MAX_LEN] = { 0 };
	int i = 0;
	for (i = 0; i < y; i++)
	{
		str[i] = t->data[x].text[i];
	}

	for (int j = 0; j < strlen(s); j++)
	{
		str[i++] = s[j];
	}
	for (int j = y; j < t->data[x].sz; j++)
	{
		str[i++] = t->data[x].text[j];
	}

	for (int j = 0; j <= i; j++)
	{
		t->data[x].text[j] = str[j];
	}
	t->data[x].sz = i + 1;
}


void replace(Text* t)
{
	char str[MAX_LEN];
	printf("请输入要替换的字符串:\n");
	option ret = findstr(t, str);
	if (ret.found == 0)
	{
		printf("未找到要替换的字符串\n");
		return;
	}
	if (ret.x<0 || ret.x>t->size || ret.y<0 || ret.y>t->data[ret.x].sz)
	{
		printf("替换成功\n");
		return;
	}
	char ans[MAX_LEN] = { 0 };
	int x = ret.x;
	int y = ret.y;
	int i = 0;
	for (i = 0; i < y; i++)
	{
		ans[i] = t->data[x].text[i];
	}

	for (int j = 0; j < strlen(str); j++)
	{
		ans[i++] = str[j];
	}

	for (int j = y + strlen(str); j < t->data[x].sz; j++)
	{
		ans[i++] = t->data[x].text[j];
	}

	for (int j = 0; j <= i; j++)
	{
		t->data[x].text[j] = ans[j];
	}
	t->data[x].sz = i + 1;


}


void save(Text* t)
{
	FILE* pfOut = fopen("Text.txt", "wb");
	if (pfOut == NULL)
	{
		printf("Save_Text::%s\n", strerror(errno));
		return;
	}

	//写数据
	int i = 0;
	for (i = 0; i < t->size; i++)
	{
		fwrite(t->data + i, sizeof(line), 1, pfOut);
	}
	fclose(pfOut);
	pfOut = NULL;
}

void menu()
{
	printf("\t\t1.录入文字\n");
	printf("\t\t2.添加一行文字\n");
	printf("\t\t3.指定位置添加文字\n");
	printf("\t\t4.显示文字\n");
	printf("\t\t5.删除文字\n");
	printf("\t\t6.查找文字\n");
	printf("\t\t7.统计文字\n");
	printf("\t\t8.替换文字\n");
	printf("\t\t9.保存文字\n");
	printf("\t\t0.退出\n");
}
int main()
{
	Text t;
	Init_Text(&t);
	int choice;
	char str[MAX_LEN] = { 0 };
	while (1)
	{
		menu();
		printf("请输入对应选项:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			//录入文字:也就是每次都是尾部插入
			printf("请输入字符串，按‘#’结束\n");
			while (hehe)
			{
				insert_post(&t, t.size + 1, 0);
			}
			printf("录入完成\n");
			system("pause");
			system("cls");
			break;
		case 2:
			int linenum;
			printf("请输入要插入的行:\n");
			scanf("%d", &linenum);
			insert_line(&t, linenum);
			system("pause");
			system("cls");
			break;
		case 3:
			int x, y;
			//char str[MAX_LEN] = { 0 };
			printf("请输入要插入的行和列:\n");
			scanf("%d %d", &x, &y);
			printf("请输入要插入的字符串:\n");
			scanf("%s", &str);
			insert_x_y(&t, x, y, str);
			system("pause");
			system("cls");
			break;
		case 4:
			Print(&t);
			system("pause");
			system("cls");
			break;
		case 5:
			printf("请输入要删除的行:\n");
			int m;
			scanf("%d", &m);
			del_line(&t, m);
			system("pause");
			system("cls");
			break;
		case 6:
			printf("请输入要查找的字符串:\n");
			scanf("%s", &str);
			findstr(&t, str);
			system("pause");
			system("cls");
			break;
		case 7:
			count_str(&t);
			system("pause");
			system("cls");
			break;
		case 8:
			replace(&t);
			system("pause");
			system("cls");
			break;
		case 9:
			save(&t);
			system("pause");
			system("cls");
			break;
		case 0:
			printf("退出，欢迎下次使用\n");
			system("pause");
			system("cls");
			exit(1);
			break;
		default:
			system("pause");
			system("cls");
			break;
		}
	}

}