#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
typedef struct student
{//学生信息定义 
	long num;//学号 
	char name[20];//姓名 
	char sex[20];//性别 
	int score[6];//成绩 
	int sum;//总成绩 
	struct student* next;
}Student;
int n;//全局变量 
void print_data(Student* head) //显示学生成绩表
{
	Student* p = head->next;
	if (!p) { printf("\n\n此系统目前没有任何学生数据! \n\n\n"); return; }
	printf("此系统目前共计学生%d名 \n", n);
	printf("*************************学生成绩统计**************************\n");
	printf("学号\t姓名\t性别\t数据结构成绩 高数成绩 英语成绩 C语言成绩 大学物理成绩 体育成绩 总成绩\n");
	for (; p; p = p->next)
		printf("%d\t%s\t%s\t      %d        %d       %d       %d          %d         %d      %d\n",
			p->num, p->name, p->sex, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->score[5],
			p->sum = p->score[0] + p->score[1] + p->score[2] + p->score[3] + p->score[4] + p->score[5]);
	printf("***************************************************************\n\n");
}
Student* sort_data(Student* head, int choose)///冒泡排序,学生成绩排序  
{
	Student* p1, * p2 = head->next, * pm, * px;//p2指向首元结点
	Student pre;
	if (!p2) return head;
	for (p1 = p2; p1->next != NULL; p1 = p1->next)
	{
		pm = p1;
		for (p2 = p1->next; p2 != NULL; p2 = p2->next)
			switch (choose)
			{
			case 1:if (pm->num > p2->num)pm = p2; break;
			case 2:if (pm->sum < p2->sum)pm = p2; break;
			case 3:if (pm->score[0] < p2->score[0])pm = p2; break; //按学生数据结构成绩排序
			case 4:if (pm->score[1] < p2->score[1])pm = p2; break; //按学生高数成绩排序
			case 5:if (pm->score[2] < p2->score[2])pm = p2; break; //按学生英语成绩排序
			case 6:if (pm->score[3] < p2->score[3])pm = p2; break; //按学生C语言成绩排序
			case 7:if (pm->score[4] < p2->score[4])pm = p2; break; //按学生大学物理成绩排序
			case 8:if (pm->score[5] < p2->score[5])pm = p2; break; //按学生体育成绩排序
			}
		if (pm != p1)
		{
			pre = *pm;//地址的交换 
			*pm = *p1;
			*p1 = pre;
			px = pm->next;//数据的交换 
			pm->next = p1->next;
			p1->next = px;
		}
	}
	printf("\n排序后的成绩表为:\n");
	print_data(head);
	return head;
}

Student* EnterData()  //后插法创建单链表，录入学生数据 
{
	int flag;
	n = 0;
	Student* head, * p, * r;
	head = (Student*)malloc(sizeof(Student));
	head->next = NULL;//建立一个带头结点的空链表 
	r = head;//尾指针r指向头结点
	printf("\n请输入第%d名学生的学号(5位)，学号为0表示结束输入:", n + 1);
	scanf("%d", &flag);
	while (getchar() != '\n');
	for (; flag;)
	{
		n++;
		p = (Student*)malloc(sizeof(Student));//生成新节点 
		p->num = flag;//将输入的学号赋值给新节点*p的数据域 
		printf("请输入第%d名学生的姓名:", n);
		scanf("%s", p->name);
		printf("请输入第%d名学生的性别:", n);
		scanf("%s", p->sex);
		printf("请输入第%d名学生的数据结构成绩:", n);
		scanf("%d", &p->score[0]);
		printf("请输入第%d名学生的高数成绩:", n);
		scanf("%d", &p->score[1]);
		printf("请输入第%d名学生的英语成绩:", n);
		scanf("%d", &p->score[2]);
		printf("请输入第%d名学生的C语言成绩:", n);
		scanf("%d", &p->score[3]);
		printf("请输入第%d名学生的大学物理成绩:", n);
		scanf("%d", &p->score[4]);
		printf("请输入第%d名学生的体育成绩:", n);
		scanf("%d", &p->score[5]);
		p->sum = p->score[0] + p->score[1] + p->score[2] + p->score[3] + p->score[4] + p->score[5];
		r->next = p;//将新节点*p的next域滞空并插入到尾结点*r之后 
		r = p;//r指向新的尾结点 
		printf("\n请输入第%d名学生的学号(5位),没有此学生则输入0表示结束:", n + 1);
		scanf("%d", &flag);
	}
	r->next = NULL;
	printf("\n\n");
	return head;
}
Student* statistic_data(Student* head)   //学生成绩统计排行 
{
	int choose;
	for (;;)
	{
		printf("\n\t\t* * * * 学生成绩统计排序 * * * *\n");
		printf("\t\t\t1.按学生学号排序\n");
		printf("\t\t\t2.按学生总分排序\n");
		printf("\t\t\t3.按学生数据结构成绩排序\n");
		printf("\t\t\t4.按学生高数成绩排序\n");
		printf("\t\t\t5.按学生英语成绩排序\n");
		printf("\t\t\t6.按学生C语言成绩排序\n");
		printf("\t\t\t7.按学生大学物理成绩排序\n");
		printf("\t\t\t8.按学生体育成绩排序\n");
		printf("\t\t\t9.显示当前学生成绩\n");
		printf("\t\t\t0.返回上一级菜单\n");
		printf("\t\t* * * * * * * * * * * * * * *\n\n");
		printf("请输入你要执行的操作:");
		scanf("%d", &choose);
		while (getchar() != '\n');
		switch (choose)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:head = sort_data(head, choose); break;
		case 9:print_data(head); break;
		case 0:return head;
		default:printf("\n\n 您的输入有误!请重新输入:\n\n"); break;
		}
	}
}
Student* delete_data(Student* head, int choose)	//删除学生成绩
{
	Student* p, * q;
	int snum;
	char temp[20];
	switch (choose)
	{
	case 1:	p = q = head;
		printf("\n请输入你要删除的学生的学号(5位)，输入0退出学号删除: ");
		scanf("%d", &snum);
		while (getchar() != '\n');
		for (; snum;)
		{
			while (p != NULL && p->num != snum)
			{
				q = p;
				p = p->next;
			}
			if (!p)
			{
				printf("\n\n找不到你要删除的学号(5位)，请重新输入，输入0表示结束: ");
				scanf("%d", &snum);
			}
			else if (p->num == snum)
			{
				q->next = p->next;
				free(p);
				n--;
				printf("\n\n请输入你还要删除的学生的学号(5位)，输入0退出学号删除: ");
				scanf("%d", &snum);
			}
		}
		break;


	case 2: p = q = head;
		printf("\n请输入你要删除的学生的姓名，输入0退出姓名删除: ");
		scanf("%s", temp);
		while (getchar() != '\n');
		for (; strcmp(temp, "0");)
		{
			while (p != NULL && strcmp(p->name, temp))
			{
				q = p;
				p = p->next;
			}
			if (!p)
			{
				printf("\n\n找不到你要删除的姓名，请重新输入，输入0表示结束: ");
				scanf("%s", temp);
			}
			else if (!strcmp(p->name, temp))
			{
				q->next = p->next;
				free(p);
				n--;
				printf("\n\n请输入你还要删除的学生的姓名(5位)，输入0退出姓名删除: ");
				scanf("%s", &temp);
			}
		}
		break;
	case 3:print_data(head); break;
	case 0:return head;
	default:printf("\n\n 您的输入有误!请重新输入:\n\n"); break;


	}
	printf("\n删除后的成绩表为:\n");
	print_data(head);
	return head;
}
Student* delete_choose(Student* head)
{
	int choose;
	if (n == 0) { printf("\n当前系统没有任何学生数据。\n"); return NULL; }
	for (;;)
	{
		printf("\t\t\t1.按学生学号删除\n");
		printf("\t\t\t2.按学生姓名删除\n");
		printf("\t\t\t3.显示当前学生成绩\n");
		printf("\t\t\t0.返回上一级菜单\n");
		printf("请输入你要执行的操作:");
		scanf("%d", &choose);
		while (getchar() != '\n');
		switch (choose)
		{
		case 1:
		case 2:head = delete_data(head, choose); break;
		case 3:print_data(head); break;
		case 0:return head;
		default:printf("\n\n 您的输入有误!请重新输入:\n\n"); break;
		}
	}
}

void locate_data(Student* head) //查询学生数据
{
	Student* p;
	int choose, fnum;
	char tem[20];
	if (n == 0) { printf("\n当前系统没有任何学生数据。\n"); return; }
	for (;;)
	{
		printf("\n请输入您要查询学生的方式: \n\n");
		printf("1.按学号查询;2.按姓名查询。\n\n");
		printf("请选择: ");
		scanf("%d", &choose);
		while (getchar() != '\n');
		if (choose == 1)
		{
			printf("\n请输入你要查询的学生的学号(5位)，输入0退出学号查询: ");
			scanf("%d", &fnum);
			for (; fnum;)
			{
				for (p = head->next; p != NULL && p->num != fnum; p = p->next);
				if (!p)
				{
					printf("\n\n找不到你要查询的学号(5位)，请重新输入，输入0表示结束: ");
					scanf("%d", &fnum);
				}
				else if (p->num == fnum)
				{
					printf("\n学号为%d学生的数据为:\n", p->num);
					printf("学号\t姓名\t性别\t数据结构成绩 高数成绩 英语成绩 C语言成绩 大学物理成绩 体育成绩 总成绩\n");
					printf("%d\t%s\t%s\t      %d        %d       %d       %d          %d         %d      %d\n",
						p->num, p->name, p->sex, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->score[5], p->sum);
					printf("\n\n请输入你还要查询的学生的学号(5位)，输入0退出学号查询: ");
					scanf("%d", &fnum);
				}
			}
		}
		else if (choose == 2)
		{
			printf("\n请输入你要查询的学生的姓名，输入0退出姓名查询: ");
			scanf("%s", tem);
			for (; strcmp(tem, "0");)//strcmp(tem,"0")表示如果tem的内容为"0"，那么strcmp(tem,"0")的结果就是0
			{
				for (p = head->next; p != NULL && strcmp(p->name, tem); p = p->next);
				if (!p)
				{
					printf("\n\n找不到你要查询的姓名，请重新输入，输入0表示结束: ");
					scanf("%s", tem);
				}
				else if (!strcmp(p->name, tem))
				{
					printf("\n姓名为%s学生的数据为:\n", p->name);
					printf("学号\t姓名\t性别\t数据结构成绩 高数成绩 英语成绩 C语言成绩 大学物理成绩 体育成绩 总成绩\n");
					printf("%d\t%s\t%s\t      %d        %d       %d       %d          %d         %d      %d\n",
						p->num, p->name, p->sex, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->score[5], p->sum);
					printf("\n\n请输入你还要查询的学生的姓名，输入0退出姓名查询: ");
					scanf("%s", &tem);
				}
			}
		}
		else { printf("\n你选择不查询! \n"); break; }
	}
}
Student* insert_data(Student* head) //插入学生数据 
{
	Student* p;
	int flag;
	printf("\n\n请输入要新加入的学生的学号(5位)，学号为0表示结束输入: ");
	scanf("%d", &flag);
	while (getchar() != '\n');
	for (; flag;)
	{
		p = (Student*)malloc(sizeof(Student));
		p->num = flag;
		printf("请输入新加入学生的姓名:\n");
		scanf("%s", p->name);
		printf("请输入新加入学生的性别:\n");
		scanf("%s", p->sex);
		printf("请输入新加入学生的数据结构成绩:\n");
		scanf("%d", &p->score[0]);
		printf("请输入新加入学生的高数成绩:\n");
		scanf("%d", &p->score[1]);
		printf("请输入新加入学生的英语成绩:\n");
		scanf("%d", &p->score[2]);
		printf("请输入新加入学生的C语言成绩:\n");
		scanf("%d", &p->score[3]);
		printf("请输入新加入学生的大学物理成绩:\n");
		scanf("%d", &p->score[4]);
		printf("请输入新加入学生的体育成绩:\n");
		scanf("%d", &p->score[5]);
		p->sum = p->score[0] + p->score[1] + p->score[2] + p->score[3] + p->score[4] + p->score[5];
		p->next = head->next;
		head->next = p;
		n++;
		printf("\n请输入还要加入的学生的学号(5位)，输入0表示结束: ");
		scanf("%d", &flag);
	}
	printf("加入后的成绩表为\n");
	return head;
}
void stats(Student* head) //统计各分数段人数 
{
	Student* p = head->next;

	//创建6个数组
	int cou0[5] = { 0,0,0,0,0 }, cou1[5] = { 0,0,0,0,0 }, cou2[5] = { 0,0,0,0,0 },cou3[5]={0},cou4[5]={0,0,0,0},cou5[5]={0};

	if (!p)
	{
		printf("\n当前系统没有任何学生数据。\n");
		return;
	}
	printf("\n\t\t  数据结构  高数  英语  C语言  大学物理  体育");
	while (p)
	{
		if (p->score[0] < 60)
			cou0[0]++;
		if (p->score[1] < 60)
			cou1[0]++;
		if (p->score[2] < 60)
			cou2[0]++;
		if (p->score[3] < 60)
			cou3[0]++;
		if (p->score[4] < 60)
			cou4[0]++;
		if (p->score[5] < 6)
			cou5[0]++;
		p = p->next;
	}
	printf("\n  0-60的学生人数是:    %d      %d     %d     %d     %d        %d", cou0[0], cou1[0], cou2[0],cou3[0],cou4[0],cou5[0]);
	p = head->next;
	while (p)
	{
		if (p->score[0] >= 60 && p->score[0] < 70)
			cou0[1]++;
		if (p->score[1] >= 60 && p->score[1] < 70)
			cou1[1]++;
		if (p->score[2] >= 60 && p->score[2] < 70)
			cou2[1]++;
		if (p->score[3] >= 60 && p->score[3] < 70)
			cou3[1]++;
		if (p->score[4] >= 60 && p->score[4] < 70)
			cou4[1]++;
		if (p->score[5] >= 60 && p->score[5] < 70)
			cou5[1]++;
		p = p->next;
	}
	printf("\n 60-70的学生人数是:    %d      %d     %d     %d     %d        %d", cou0[1], cou1[1], cou2[1],cou3[1],cou4[1],cou5[1]);
	p = head->next;
	while (p)
	{
		if (p->score[0] >= 70 && p->score[0] < 80)
			cou0[2]++;
		if (p->score[1] >= 70 && p->score[1] < 80)
			cou1[2]++;
		if (p->score[2] >= 70 && p->score[2] < 80)
			cou2[2]++;
		if (p->score[3] >= 70 && p->score[3] < 80)
			cou3[2]++;
		if (p->score[4] >= 70 && p->score[4] < 80)
			cou4[2]++;
		if (p->score[5] >= 70 && p->score[5] < 80)
			cou5[2]++;
		p = p->next;
	}
	printf("\n 70-80的学生人数是:    %d      %d     %d     %d     %d        %d", cou0[2], cou1[2], cou2[2],cou3[2],cou4[2],cou5[2]);
	p = head->next;
	while (p)
	{
		if (p->score[0] >= 80 && p->score[0] < 90)
			cou0[3]++;
		if (p->score[1] >= 80 && p->score[1] < 90)
			cou1[3]++;
		if (p->score[2] >= 80 && p->score[2] < 90)
			cou2[3]++;
		if (p->score[3] >= 80 && p->score[3] < 90)
			cou3[3]++;
		if (p->score[4] >= 80 && p->score[4] < 90)
			cou4[3]++;
		if (p->score[5] >= 80 && p->score[5] < 90)
			cou5[3]++;
		p = p->next;
	}
	printf("\n 80-90的学生人数是:    %d      %d     %d     %d     %d        %d", cou0[3], cou1[3], cou2[3],cou3[3],cou4[3],cou5[3]);
	p = head->next;
	while (p)
	{
		if (p->score[0] >= 90)
			cou0[4]++;
		if (p->score[1] >= 90)
			cou1[4]++;
		if (p->score[2] >= 90)
			cou2[4]++;
		if (p->score[3] >= 90)
			cou3[4]++;
		if (p->score[4] >= 90)
			cou4[4]++;
		if (p->score[5] >= 90)
			cou5[4]++;
		p = p->next;
	}
	printf("\n90-100的学生人数是:    %d      %d     %d     %d     %d        %d", cou0[4], cou1[4], cou2[4],cou3[4],cou4[4],cou5[4]);



	printf("\n\n");
	printf("各科目成绩分析如下:\n");
	//80~100为优秀，70！~80为良好，及格人数为60~100，不及格人数为0~60之间
	printf("\t\t%-10s\t%-10s\t%-10s\t%-10s\t%10s\t%10s\t%10s\n","优秀人数","良好人数","及格人数","不及格人数","优秀率","及格率","不及格率");
	printf("数据结构    \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou0[4] + cou0[3], cou0[2], n - cou0[0], cou0[0],(float)(cou0[4]+cou0[3])/n*100.0,(float)(n-cou0[0])/n*100.0,(float)(cou0[0])/n*100.0);
	printf("高数        \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou1[4] + cou1[3], cou1[2], n - cou1[0], cou1[0],(float)(cou1[4]+cou1[3])/n*100.0,(float)(n-cou1[0])/n*100.0,(float)(cou1[0])/n*100.0);
	printf("英语        \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou2[4] + cou2[3], cou2[2], n - cou2[0], cou2[0],(float)(cou2[4]+cou2[3])/n*100.0,(float)(n-cou2[0])/n*100.0,(float)(cou2[0])/n*100.0);
	printf("C语言       \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou3[4] + cou3[3], cou3[2], n - cou3[0], cou3[0],(float)(cou3[4]+cou3[3])/n*100.0,(float)(n-cou3[0])/n*100.0,(float)(cou3[0])/n*100.0);
	printf("大学物理    \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou4[4] + cou4[3], cou4[2], n - cou4[0], cou4[0],(float)(cou4[4]+cou4[3])/n*100.0,(float)(n-cou4[0])/n*100.0,(float)(cou4[0])/n*100.0);
	printf("体育        \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou5[4] + cou5[3], cou5[2], n - cou5[0], cou5[0],(float)(cou5[4]+cou5[3])/n*100.0,(float)(n-cou5[0])/n*100.0,(float)(cou5[0])/n*100.0);

}
int main() //主函数
{
	system("color f0");
	Student* head;
	int choose, i;
	head = (Student*)malloc(sizeof(Student));
	head->next = NULL;
	for (;;)
	{
		printf("\n\t\t********学生成绩管理系统********\n");
		printf("\t\t\t1.学生数据键盘录入\n");
		printf("\t\t\t2.学生成绩统计排序\n");
		printf("\t\t\t3.查询学生数据\n");
		printf("\t\t\t4.插入学生数据\n");
		printf("\t\t\t5.显示当前成绩表\n");
		printf("\t\t\t6.删除学生数据\n");
		printf("\t\t\t7.统计各分数段学生人数及成绩分析\n");
		printf("\t\t\t0.退出成绩管理系统\n");
		printf("\t\t********************************\n\n");
		printf("\n请输入你要执行的操作: ");
		scanf("%d", &choose);
		while (getchar() != '\n');
		switch (choose)
		{
		case 1:printf("\n建立新的数据系统。\n\n");
			printf("请继续选择: ");
			scanf("%d", &i);
			if (i == 1) { head = EnterData(); print_data(head); break; }  //学生数据键盘录入
			else
			{
				printf("\n你选择放弃建立新的数据系统! \n");
				break;
			}
		case 2:head = statistic_data(head); break; //学生成绩统计排序
		case 3:locate_data(head); break; 	//查询学生数据
		case 4:head = insert_data(head);  //插入学生数据
		case 5:print_data(head); break;  //显示当前成绩表 
		case 6:head = delete_choose(head); break;//删除学生数据
		case 7:stats(head); break; //统计人数
		case 0:system("pause"); return 0; //退出成绩管理系统
		default:printf("\n\n您的输入有误!请重新输入: \n\n"); break;
		}
	}
}















