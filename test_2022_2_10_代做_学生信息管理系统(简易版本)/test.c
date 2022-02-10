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
	float sum;//总分
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





int main()
{
	return 0;
}