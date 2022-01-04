#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//学生信息的定义
typedef struct Student_Data
{
	char Number[10];//学生学号
	char Name[20];//学生姓名
	char ClassName[20];//班级名称
	float Data_Structure;//数据结构成绩
	float English;//大学英语成绩
	float Math;//高等数学成绩
	float score;//记录平均成绩

}Student_Data;


//利用线性表实现学生成绩管理系统
typedef struct Score_Management
{
	Student_Data* data;
	int capacity;
	int size;
}Score_Management;



//初始化学生信息管理系统
void Init_Score_Management(Score_Management* p)
{
	p->data = (Student_Data*)malloc(sizeof(Score_Management) * 1000);//容量初始化为1000，不够时增容
	p->capacity = 1000;
	p->size = 0;
}


//检测容量检测
void Check_Capacity(Score_Management* p)
{
	if (p->capacity == p->size)
	{
		//增容
		Student_Data* ptr = (Student_Data*)realloc(p->data, (p->capacity + 1000) * sizeof(Student_Data));
		if (ptr == NULL)
		{
			printf("增容失败\n");
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

//增加学生信息
void Add_Student_Data(Score_Management* p)
{
	Check_Capacity(p);

	printf("请输入学号:\n");
	scanf("%s", p->data[p->size].Number);
	printf("请输入姓名:\n");
	scanf("%s", p->data[p->size].Name);
	printf("请输入班级:\n");
	scanf("%s", p->data[p->size].ClassName);
	printf("请输入数据结构成绩:\n");
	scanf("%f", &p->data[p->size].Data_Structure);
	printf("请输入英语成绩:\n");
	scanf("%f", &p->data[p->size].English);
	printf("请输入高等数学成绩:\n");
	scanf("%f", &p->data[p->size].Math);

	//计算平均成绩
	p->data[p->size].score = (p->data[p->size].Data_Structure + p->data[p->size].English + p->data[p->size].Math) / 3.0;
	p->size++;
	printf("添加成功\n");
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


//删除学生信息
void Del_Student_Data(Score_Management* p)
{
	char name[20] = { 0 };
	if (p->size == 0)
	{
		printf("无学生信息,无法删除\n");
		return;
	}
	else
	{
		printf("请输入要删除的学生姓名:\n");
		scanf("%s", name);
		int pos = Find_Name(p, name);
		if (pos == -1)
		{
			printf("要删除的人不存在\n");
		}
		else
		{
			//删除
			int j = 0;
			for (j = pos; j < p->size - 1; j++)
			{
				p->data[j] = p->data[j + 1];
			}
			p->size--;
			printf("删除成功\n");
		}

	}
}


//修改学生信息
void Modify_Student_Data(Score_Management* p)
{
	char name[20];
	printf("请输入要修改的名字:\n");
	scanf("%s", name);
	int pos = Find_Name(p, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{

		printf("请输入学号:\n");
		scanf("%s", p->data[pos].Number);
		printf("请输入姓名:\n");
		scanf("%s", p->data[pos].Name);
		printf("请输入班级:\n");
		scanf("%s", p->data[pos].ClassName);
		printf("请输入数据结构成绩:\n");
		scanf("%f", &p->data[pos].Data_Structure);
		printf("请输入英语成绩:\n");
		scanf("%f", &p->data[pos].English);
		printf("请输入高等数学成绩:\n");
		scanf("%f", &p->data[pos].Math);
		//计算平均成绩
		p->data[pos].score = (p->data[pos].Data_Structure + p->data[pos].English + p->data[pos].Math) / 3.0;
		printf("修改成功\n");
	}
}


//查找学生
void Search_Student_Data(Score_Management* p)
{
	char name[20];
	printf("请输入要查找的学生的姓名:\n");
	scanf("%s",name);
	int pos = Find_Name(p, name);
	if (pos == -1)
	{
		printf("要查找的学生不存在\n");
	}
	else
	{
		printf("%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\n", "学号", "姓名", "班级", "数据结构", "大学英语", "高等数学", "平均分");
		printf("%-10s\t%-20s\t%-20s\t%-10.2f\t%-10.2f\t%-10.2f\t%-10.2f\n",
			p->data[pos].Number,p->data[pos].Name,p->data[pos].ClassName,
			p->data[pos].Data_Structure,p->data[pos].English,p->data[pos].Math,
			p->data[pos].score);
	}
}


//保存文件
void Save_Student_Data(Score_Management* p)
{
	FILE* pfOut = fopen("Score_Data.txt", "wb");
	if (pfOut == NULL)
	{
		printf("Save_Student_Data::%s\n", strerror(errno));
		return;
	}

	//写数据
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		fwrite(p->data + i, sizeof(Student_Data), 1, pfOut);
	}
	fclose(pfOut);
	pfOut = NULL;
}


//显示成绩
void Show_Student_Data(Score_Management* p)
{
	printf("%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t\n", "学号", "姓名", "班级", "数据结构", "大学英语", "高等数学", "平均分");
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

//根据平均分进行排序并输出成绩
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
	printf("%-10s\t%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-5s\n", "学号", "姓名", "班级", "数据结构", "大学英语", "高等数学", "平均分","排名");
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
	printf("\t\t1.添加学生信息\n");
	printf("\t\t2.删除学生信息\n");
	printf("\t\t3.查找学生信息\n");
	printf("\t\t4.修改学生信息\n");
	printf("\t\t5.显示所有信息\n");
	printf("\t\t6.保存学生信息\n");
	printf("\t\t7.根据平均分高低排序并且输出排名\n");
	printf("\t\t0.退出\n");

}
int main()
{
	int option=0;
	Score_Management p;
	Init_Score_Management(&p);
	while (1)
	{
		menu();
		printf("请输入对应选项:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			//添加信息
			Add_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 2:
			//删除信息
			Del_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 3:
			//查询信息
			Search_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 4:
			//修改信息
			Modify_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 5:
			//显示所有信息
			Show_Student_Data(&p);
		case 6:
			//保存信息
			Save_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 7:
			//根据平均分进行排序
			Sort_Student_Data(&p);
			system("pause");
			system("cls");
			break;
		case 0:
			printf("退出系统，欢迎下次使用\n");
			system("pause");
			system("cls");
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入\n");
			system("pause");
			system("cls");
			break;

		}
	}
	return 0;
}