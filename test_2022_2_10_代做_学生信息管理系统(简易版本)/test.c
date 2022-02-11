#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

//创建学生信息
typedef struct Stu_Info
{
	char Name[30];//姓名
	char Number[50];//学号
	int Chinese;//语文成绩
	int Math;//数学成绩
	int English;//英语成绩
	float average;//平均分
	int sum;//总分
}Stu_Info;

//创建数组代表存储的数据
Stu_Info Student[MAX];
//size代表当前学生的个数
int size = 0;


//增加学生数据
void Push()
{
	printf("请输入学生姓名:\n");
	scanf("%s", Student[size].Name);

	printf("请输入学号:\n");
	scanf("%s", Student[size].Number);

	printf("请输入语文成绩:\n");
	scanf("%d", &Student[size].Chinese);

	printf("请输入数学成绩:\n");
	scanf("%d", &Student[size].Math);

	printf("请输入英语成绩:\n");
	scanf("%d", &Student[size].English);

	//计算平均分
	Student[size].average = (Student[size].Chinese + Student[size].Math + Student[size].English) / 3.0;

	//计算总分
	Student[size].sum = Student[size].Chinese + Student[size].Math + Student[size].English;

	//个数+1
	++size;
}


//按照学号查找学生
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


//按照学号查找
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


//按照姓名进行删除
void Del_Name()
{
	char name[30] = { 0 };
	if (size == 0)
	{
		printf("无学生信息，无法删除\n");
		return;
	}
	else
	{
		printf("请输入要删除的学生姓名:\n");
		scanf("%s", name);
		int pos = Find_Name(name);
		if (pos == -1)
		{
			printf("要删除的学生不存在\n");
			return;
		}
		else
		{
			for (int j = pos; j < size - 1; j++)
			{
				Student[j] = Student[j + 1];
			}
			size--;
			printf("删除成功\n");
		}
	}
}

//按照学号进行删除
void Del_Number()
{
	char number[50] = { 0 };
	if (size == 0)
	{
		printf("无学生信息，无法删除\n");
		return;
	}
	else
	{
		printf("请输入要删除的学生学号:\n");
		scanf("%s", number);
		int pos = Find_Number(number);
		if (pos == -1)
		{
			printf("要删除的学生不存在\n");
			return;
		}
		else
		{
			for (int j = pos; j < size - 1; j++)
			{
				Student[j] = Student[j + 1];
			}
			size--;
			printf("删除成功\n");
		}
	}
}

//按照姓名进行修改
void Modify_Name()
{
	char name[30] = { 0 };
	printf("请输入要修改的学生姓名:\n");
	scanf("%s", name);
	int pos = Find_Name(name);
	if (pos == -1)
	{
		printf("要修改的学生不存在\n");
	}
	else
	{
		printf("请输入学生姓名:\n");
		scanf("%s", Student[pos].Name);

		printf("请输入学号:\n");
		scanf("%s", Student[pos].Number);

		printf("请输入语文成绩:\n");
		scanf("%d", &Student[pos].Chinese);

		printf("请输入数学成绩:\n");
		scanf("%d", &Student[pos].Math);

		printf("请输入英语成绩:\n");
		scanf("%d", &Student[pos].English);

		//计算平均分
		Student[pos].average = (Student[pos].Chinese + Student[pos].Math + Student[pos].English) / 3.0;

		//计算总分
		Student[pos].sum = Student[pos].Chinese + Student[pos].Math + Student[pos].English;
		printf("修改成功\n");
	}
}


//按照学号进行修改
void Modify_Number()
{
	char number[50] = { 0 };
	printf("请输入要修改的学生学号:\n");
	scanf("%s", number);
	int pos = Find_Name(number);
	if (pos == -1)
	{
		printf("要修改的学生不存在\n");
	}
	else
	{
		printf("请输入学生姓名:\n");
		scanf("%s", Student[pos].Name);

		printf("请输入学号:\n");
		scanf("%s", Student[pos].Number);

		printf("请输入语文成绩:\n");
		scanf("%d", &Student[pos].Chinese);

		printf("请输入数学成绩:\n");
		scanf("%d", &Student[pos].Math);

		printf("请输入英语成绩:\n");
		scanf("%d", &Student[pos].English);

		//计算平均分
		Student[pos].average = (Student[pos].Chinese + Student[pos].Math + Student[pos].English) / 3.0;

		//计算总分
		Student[pos].sum = Student[pos].Chinese + Student[pos].Math + Student[pos].English;
		printf("修改成功\n");
	}
}


//按照总分进行排序
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


//打印所有成绩信息
void Show()
{
	printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-5s\n", "学号", "姓名", "语文", "数学", "英语", "平均分", "总分", "排名");
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



//按照分数段进行查询
void Search_Sum()
{
	int left = 0;
	int right = 0;
	printf("请输入分数下限:\n");
	scanf("%d", &left);
	printf("请输入分数上限:\n");
	scanf("%d", &right);
	printf("位于该分数段的有:\n");
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
		printf("该分数段内没有人\n");
		return;
	}
	printf("%-20s\t%-20s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "学号", "姓名", "语文", "数学", "英语", "平均分", "总分");
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

//各分数段统计
void Count()
{
	int count1 = 0;//0~100分数段
	int count2 = 0;//100~200分数段
	int count3 = 0;//200~300分数段
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
	printf("0~100分之间:%d人\n", count1);
	printf("100~200分之间:%d人\n", count2);
	printf("200~300分之间:%d人\n", count3);
}


//保存文件
void Save_Student()
{
	FILE* pfOut = fopen("Score_Data.txt", "wb");
	if (pfOut == NULL)
	{
		printf("Save_Student_Data::%s\n", strerror(errno));
		return;
	}

	//写数据
	for (int i = 0; i < size; i++)
	{
		fwrite(Student+i, sizeof(Stu_Info), 1, pfOut);
	}
	fclose(pfOut);
	pfOut = NULL;
}


//刚开始时读文件
void Load_Student()
{
	//打开文件
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
	printf("\t\t1.添加学生信息\n");
	printf("\t\t2.按照姓名删除学生信息\n");
	printf("\t\t3.按照学号删除学生信息\n");
	printf("\t\t4.按照姓名修改学生信息\n");
	printf("\t\t5.按照学号修改学生信息\n");
	printf("\t\t6.查询位于某分数段内的学生\n");
	printf("\t\t7.统计分数段内学生\n");
	printf("\t\t8.显示所有学生信息\n");
	printf("\t\t9.按照总分进行排序\n");
	printf("\t\t0.退出\n");

}


int main()
{
	int option = 0;
	Load_Student();
	while (1)
	{
		menu();
		printf("请输入对应选项:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			//添加信息
			Push();
			system("pause");
			system("cls");
			break;
		case 2:
			//删除信息
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
			//修改信息
			Modify_Name();
			system("pause");
			system("cls");
			break;
		case 5:
			//修改信息
			Modify_Number();
			system("pause");
			system("cls");
			break;
		case 6:
			//位于某个分数段内的学生
			Search_Sum();
			system("pause");
			system("cls");
			break;
		case 7:
			//人数统计
			Count();
			system("pause");
			system("cls");
			break;
		case 8:
			//显示所有信息
			Sort();
			Show();
			system("pause");
			system("cls");
			break;
		case 9:
			//排序
			Sort();
			system("pause");
			system("cls");
			break;
		case 0:
			printf("退出系统，欢迎下次使用\n");
			Save_Student();
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