#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
typedef struct student
{//ѧ����Ϣ���� 
	long num;//ѧ�� 
	char name[20];//���� 
	char sex[20];//�Ա� 
	int score[6];//�ɼ� 
	int sum;//�ܳɼ� 
	struct student* next;
}Student;
int n;//ȫ�ֱ��� 
void print_data(Student* head) //��ʾѧ���ɼ���
{
	Student* p = head->next;
	if (!p) { printf("\n\n��ϵͳĿǰû���κ�ѧ������! \n\n\n"); return; }
	printf("��ϵͳĿǰ����ѧ��%d�� \n", n);
	printf("*************************ѧ���ɼ�ͳ��**************************\n");
	printf("ѧ��\t����\t�Ա�\t���ݽṹ�ɼ� �����ɼ� Ӣ��ɼ� C���Գɼ� ��ѧ����ɼ� �����ɼ� �ܳɼ�\n");
	for (; p; p = p->next)
		printf("%d\t%s\t%s\t      %d        %d       %d       %d          %d         %d      %d\n",
			p->num, p->name, p->sex, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->score[5],
			p->sum = p->score[0] + p->score[1] + p->score[2] + p->score[3] + p->score[4] + p->score[5]);
	printf("***************************************************************\n\n");
}
Student* sort_data(Student* head, int choose)///ð������,ѧ���ɼ�����  
{
	Student* p1, * p2 = head->next, * pm, * px;//p2ָ����Ԫ���
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
			case 3:if (pm->score[0] < p2->score[0])pm = p2; break; //��ѧ�����ݽṹ�ɼ�����
			case 4:if (pm->score[1] < p2->score[1])pm = p2; break; //��ѧ�������ɼ�����
			case 5:if (pm->score[2] < p2->score[2])pm = p2; break; //��ѧ��Ӣ��ɼ�����
			case 6:if (pm->score[3] < p2->score[3])pm = p2; break; //��ѧ��C���Գɼ�����
			case 7:if (pm->score[4] < p2->score[4])pm = p2; break; //��ѧ����ѧ����ɼ�����
			case 8:if (pm->score[5] < p2->score[5])pm = p2; break; //��ѧ�������ɼ�����
			}
		if (pm != p1)
		{
			pre = *pm;//��ַ�Ľ��� 
			*pm = *p1;
			*p1 = pre;
			px = pm->next;//���ݵĽ��� 
			pm->next = p1->next;
			p1->next = px;
		}
	}
	printf("\n�����ĳɼ���Ϊ:\n");
	print_data(head);
	return head;
}

Student* EnterData()  //��巨����������¼��ѧ������ 
{
	int flag;
	n = 0;
	Student* head, * p, * r;
	head = (Student*)malloc(sizeof(Student));
	head->next = NULL;//����һ����ͷ���Ŀ����� 
	r = head;//βָ��rָ��ͷ���
	printf("\n�������%d��ѧ����ѧ��(5λ)��ѧ��Ϊ0��ʾ��������:", n + 1);
	scanf("%d", &flag);
	while (getchar() != '\n');
	for (; flag;)
	{
		n++;
		p = (Student*)malloc(sizeof(Student));//�����½ڵ� 
		p->num = flag;//�������ѧ�Ÿ�ֵ���½ڵ�*p�������� 
		printf("�������%d��ѧ��������:", n);
		scanf("%s", p->name);
		printf("�������%d��ѧ�����Ա�:", n);
		scanf("%s", p->sex);
		printf("�������%d��ѧ�������ݽṹ�ɼ�:", n);
		scanf("%d", &p->score[0]);
		printf("�������%d��ѧ���ĸ����ɼ�:", n);
		scanf("%d", &p->score[1]);
		printf("�������%d��ѧ����Ӣ��ɼ�:", n);
		scanf("%d", &p->score[2]);
		printf("�������%d��ѧ����C���Գɼ�:", n);
		scanf("%d", &p->score[3]);
		printf("�������%d��ѧ���Ĵ�ѧ����ɼ�:", n);
		scanf("%d", &p->score[4]);
		printf("�������%d��ѧ���������ɼ�:", n);
		scanf("%d", &p->score[5]);
		p->sum = p->score[0] + p->score[1] + p->score[2] + p->score[3] + p->score[4] + p->score[5];
		r->next = p;//���½ڵ�*p��next���Ϳղ����뵽β���*r֮�� 
		r = p;//rָ���µ�β��� 
		printf("\n�������%d��ѧ����ѧ��(5λ),û�д�ѧ��������0��ʾ����:", n + 1);
		scanf("%d", &flag);
	}
	r->next = NULL;
	printf("\n\n");
	return head;
}
Student* statistic_data(Student* head)   //ѧ���ɼ�ͳ������ 
{
	int choose;
	for (;;)
	{
		printf("\n\t\t* * * * ѧ���ɼ�ͳ������ * * * *\n");
		printf("\t\t\t1.��ѧ��ѧ������\n");
		printf("\t\t\t2.��ѧ���ܷ�����\n");
		printf("\t\t\t3.��ѧ�����ݽṹ�ɼ�����\n");
		printf("\t\t\t4.��ѧ�������ɼ�����\n");
		printf("\t\t\t5.��ѧ��Ӣ��ɼ�����\n");
		printf("\t\t\t6.��ѧ��C���Գɼ�����\n");
		printf("\t\t\t7.��ѧ����ѧ����ɼ�����\n");
		printf("\t\t\t8.��ѧ�������ɼ�����\n");
		printf("\t\t\t9.��ʾ��ǰѧ���ɼ�\n");
		printf("\t\t\t0.������һ���˵�\n");
		printf("\t\t* * * * * * * * * * * * * * *\n\n");
		printf("��������Ҫִ�еĲ���:");
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
		default:printf("\n\n ������������!����������:\n\n"); break;
		}
	}
}
Student* delete_data(Student* head, int choose)	//ɾ��ѧ���ɼ�
{
	Student* p, * q;
	int snum;
	char temp[20];
	switch (choose)
	{
	case 1:	p = q = head;
		printf("\n��������Ҫɾ����ѧ����ѧ��(5λ)������0�˳�ѧ��ɾ��: ");
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
				printf("\n\n�Ҳ�����Ҫɾ����ѧ��(5λ)�����������룬����0��ʾ����: ");
				scanf("%d", &snum);
			}
			else if (p->num == snum)
			{
				q->next = p->next;
				free(p);
				n--;
				printf("\n\n�������㻹Ҫɾ����ѧ����ѧ��(5λ)������0�˳�ѧ��ɾ��: ");
				scanf("%d", &snum);
			}
		}
		break;


	case 2: p = q = head;
		printf("\n��������Ҫɾ����ѧ��������������0�˳�����ɾ��: ");
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
				printf("\n\n�Ҳ�����Ҫɾ�������������������룬����0��ʾ����: ");
				scanf("%s", temp);
			}
			else if (!strcmp(p->name, temp))
			{
				q->next = p->next;
				free(p);
				n--;
				printf("\n\n�������㻹Ҫɾ����ѧ��������(5λ)������0�˳�����ɾ��: ");
				scanf("%s", &temp);
			}
		}
		break;
	case 3:print_data(head); break;
	case 0:return head;
	default:printf("\n\n ������������!����������:\n\n"); break;


	}
	printf("\nɾ����ĳɼ���Ϊ:\n");
	print_data(head);
	return head;
}
Student* delete_choose(Student* head)
{
	int choose;
	if (n == 0) { printf("\n��ǰϵͳû���κ�ѧ�����ݡ�\n"); return NULL; }
	for (;;)
	{
		printf("\t\t\t1.��ѧ��ѧ��ɾ��\n");
		printf("\t\t\t2.��ѧ������ɾ��\n");
		printf("\t\t\t3.��ʾ��ǰѧ���ɼ�\n");
		printf("\t\t\t0.������һ���˵�\n");
		printf("��������Ҫִ�еĲ���:");
		scanf("%d", &choose);
		while (getchar() != '\n');
		switch (choose)
		{
		case 1:
		case 2:head = delete_data(head, choose); break;
		case 3:print_data(head); break;
		case 0:return head;
		default:printf("\n\n ������������!����������:\n\n"); break;
		}
	}
}

void locate_data(Student* head) //��ѯѧ������
{
	Student* p;
	int choose, fnum;
	char tem[20];
	if (n == 0) { printf("\n��ǰϵͳû���κ�ѧ�����ݡ�\n"); return; }
	for (;;)
	{
		printf("\n��������Ҫ��ѯѧ���ķ�ʽ: \n\n");
		printf("1.��ѧ�Ų�ѯ;2.��������ѯ��\n\n");
		printf("��ѡ��: ");
		scanf("%d", &choose);
		while (getchar() != '\n');
		if (choose == 1)
		{
			printf("\n��������Ҫ��ѯ��ѧ����ѧ��(5λ)������0�˳�ѧ�Ų�ѯ: ");
			scanf("%d", &fnum);
			for (; fnum;)
			{
				for (p = head->next; p != NULL && p->num != fnum; p = p->next);
				if (!p)
				{
					printf("\n\n�Ҳ�����Ҫ��ѯ��ѧ��(5λ)�����������룬����0��ʾ����: ");
					scanf("%d", &fnum);
				}
				else if (p->num == fnum)
				{
					printf("\nѧ��Ϊ%dѧ��������Ϊ:\n", p->num);
					printf("ѧ��\t����\t�Ա�\t���ݽṹ�ɼ� �����ɼ� Ӣ��ɼ� C���Գɼ� ��ѧ����ɼ� �����ɼ� �ܳɼ�\n");
					printf("%d\t%s\t%s\t      %d        %d       %d       %d          %d         %d      %d\n",
						p->num, p->name, p->sex, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->score[5], p->sum);
					printf("\n\n�������㻹Ҫ��ѯ��ѧ����ѧ��(5λ)������0�˳�ѧ�Ų�ѯ: ");
					scanf("%d", &fnum);
				}
			}
		}
		else if (choose == 2)
		{
			printf("\n��������Ҫ��ѯ��ѧ��������������0�˳�������ѯ: ");
			scanf("%s", tem);
			for (; strcmp(tem, "0");)//strcmp(tem,"0")��ʾ���tem������Ϊ"0"����ôstrcmp(tem,"0")�Ľ������0
			{
				for (p = head->next; p != NULL && strcmp(p->name, tem); p = p->next);
				if (!p)
				{
					printf("\n\n�Ҳ�����Ҫ��ѯ�����������������룬����0��ʾ����: ");
					scanf("%s", tem);
				}
				else if (!strcmp(p->name, tem))
				{
					printf("\n����Ϊ%sѧ��������Ϊ:\n", p->name);
					printf("ѧ��\t����\t�Ա�\t���ݽṹ�ɼ� �����ɼ� Ӣ��ɼ� C���Գɼ� ��ѧ����ɼ� �����ɼ� �ܳɼ�\n");
					printf("%d\t%s\t%s\t      %d        %d       %d       %d          %d         %d      %d\n",
						p->num, p->name, p->sex, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->score[5], p->sum);
					printf("\n\n�������㻹Ҫ��ѯ��ѧ��������������0�˳�������ѯ: ");
					scanf("%s", &tem);
				}
			}
		}
		else { printf("\n��ѡ�񲻲�ѯ! \n"); break; }
	}
}
Student* insert_data(Student* head) //����ѧ������ 
{
	Student* p;
	int flag;
	printf("\n\n������Ҫ�¼����ѧ����ѧ��(5λ)��ѧ��Ϊ0��ʾ��������: ");
	scanf("%d", &flag);
	while (getchar() != '\n');
	for (; flag;)
	{
		p = (Student*)malloc(sizeof(Student));
		p->num = flag;
		printf("�������¼���ѧ��������:\n");
		scanf("%s", p->name);
		printf("�������¼���ѧ�����Ա�:\n");
		scanf("%s", p->sex);
		printf("�������¼���ѧ�������ݽṹ�ɼ�:\n");
		scanf("%d", &p->score[0]);
		printf("�������¼���ѧ���ĸ����ɼ�:\n");
		scanf("%d", &p->score[1]);
		printf("�������¼���ѧ����Ӣ��ɼ�:\n");
		scanf("%d", &p->score[2]);
		printf("�������¼���ѧ����C���Գɼ�:\n");
		scanf("%d", &p->score[3]);
		printf("�������¼���ѧ���Ĵ�ѧ����ɼ�:\n");
		scanf("%d", &p->score[4]);
		printf("�������¼���ѧ���������ɼ�:\n");
		scanf("%d", &p->score[5]);
		p->sum = p->score[0] + p->score[1] + p->score[2] + p->score[3] + p->score[4] + p->score[5];
		p->next = head->next;
		head->next = p;
		n++;
		printf("\n�����뻹Ҫ�����ѧ����ѧ��(5λ)������0��ʾ����: ");
		scanf("%d", &flag);
	}
	printf("�����ĳɼ���Ϊ\n");
	return head;
}
void stats(Student* head) //ͳ�Ƹ����������� 
{
	Student* p = head->next;

	//����6������
	int cou0[5] = { 0,0,0,0,0 }, cou1[5] = { 0,0,0,0,0 }, cou2[5] = { 0,0,0,0,0 },cou3[5]={0},cou4[5]={0,0,0,0},cou5[5]={0};

	if (!p)
	{
		printf("\n��ǰϵͳû���κ�ѧ�����ݡ�\n");
		return;
	}
	printf("\n\t\t  ���ݽṹ  ����  Ӣ��  C����  ��ѧ����  ����");
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
	printf("\n  0-60��ѧ��������:    %d      %d     %d     %d     %d        %d", cou0[0], cou1[0], cou2[0],cou3[0],cou4[0],cou5[0]);
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
	printf("\n 60-70��ѧ��������:    %d      %d     %d     %d     %d        %d", cou0[1], cou1[1], cou2[1],cou3[1],cou4[1],cou5[1]);
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
	printf("\n 70-80��ѧ��������:    %d      %d     %d     %d     %d        %d", cou0[2], cou1[2], cou2[2],cou3[2],cou4[2],cou5[2]);
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
	printf("\n 80-90��ѧ��������:    %d      %d     %d     %d     %d        %d", cou0[3], cou1[3], cou2[3],cou3[3],cou4[3],cou5[3]);
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
	printf("\n90-100��ѧ��������:    %d      %d     %d     %d     %d        %d", cou0[4], cou1[4], cou2[4],cou3[4],cou4[4],cou5[4]);



	printf("\n\n");
	printf("����Ŀ�ɼ���������:\n");
	//80~100Ϊ���㣬70��~80Ϊ���ã���������Ϊ60~100������������Ϊ0~60֮��
	printf("\t\t%-10s\t%-10s\t%-10s\t%-10s\t%10s\t%10s\t%10s\n","��������","��������","��������","����������","������","������","��������");
	printf("���ݽṹ    \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou0[4] + cou0[3], cou0[2], n - cou0[0], cou0[0],(float)(cou0[4]+cou0[3])/n*100.0,(float)(n-cou0[0])/n*100.0,(float)(cou0[0])/n*100.0);
	printf("����        \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou1[4] + cou1[3], cou1[2], n - cou1[0], cou1[0],(float)(cou1[4]+cou1[3])/n*100.0,(float)(n-cou1[0])/n*100.0,(float)(cou1[0])/n*100.0);
	printf("Ӣ��        \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou2[4] + cou2[3], cou2[2], n - cou2[0], cou2[0],(float)(cou2[4]+cou2[3])/n*100.0,(float)(n-cou2[0])/n*100.0,(float)(cou2[0])/n*100.0);
	printf("C����       \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou3[4] + cou3[3], cou3[2], n - cou3[0], cou3[0],(float)(cou3[4]+cou3[3])/n*100.0,(float)(n-cou3[0])/n*100.0,(float)(cou3[0])/n*100.0);
	printf("��ѧ����    \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou4[4] + cou4[3], cou4[2], n - cou4[0], cou4[0],(float)(cou4[4]+cou4[3])/n*100.0,(float)(n-cou4[0])/n*100.0,(float)(cou4[0])/n*100.0);
	printf("����        \t%-10d\t%-10d\t%-10d\t%-10d\t%10.2lf%%\t%10.2lf%%\t%10.2lf%%\n", cou5[4] + cou5[3], cou5[2], n - cou5[0], cou5[0],(float)(cou5[4]+cou5[3])/n*100.0,(float)(n-cou5[0])/n*100.0,(float)(cou5[0])/n*100.0);

}
int main() //������
{
	system("color f0");
	Student* head;
	int choose, i;
	head = (Student*)malloc(sizeof(Student));
	head->next = NULL;
	for (;;)
	{
		printf("\n\t\t********ѧ���ɼ�����ϵͳ********\n");
		printf("\t\t\t1.ѧ�����ݼ���¼��\n");
		printf("\t\t\t2.ѧ���ɼ�ͳ������\n");
		printf("\t\t\t3.��ѯѧ������\n");
		printf("\t\t\t4.����ѧ������\n");
		printf("\t\t\t5.��ʾ��ǰ�ɼ���\n");
		printf("\t\t\t6.ɾ��ѧ������\n");
		printf("\t\t\t7.ͳ�Ƹ�������ѧ���������ɼ�����\n");
		printf("\t\t\t0.�˳��ɼ�����ϵͳ\n");
		printf("\t\t********************************\n\n");
		printf("\n��������Ҫִ�еĲ���: ");
		scanf("%d", &choose);
		while (getchar() != '\n');
		switch (choose)
		{
		case 1:printf("\n�����µ�����ϵͳ��\n\n");
			printf("�����ѡ��: ");
			scanf("%d", &i);
			if (i == 1) { head = EnterData(); print_data(head); break; }  //ѧ�����ݼ���¼��
			else
			{
				printf("\n��ѡ����������µ�����ϵͳ! \n");
				break;
			}
		case 2:head = statistic_data(head); break; //ѧ���ɼ�ͳ������
		case 3:locate_data(head); break; 	//��ѯѧ������
		case 4:head = insert_data(head);  //����ѧ������
		case 5:print_data(head); break;  //��ʾ��ǰ�ɼ��� 
		case 6:head = delete_choose(head); break;//ɾ��ѧ������
		case 7:stats(head); break; //ͳ������
		case 0:system("pause"); return 0; //�˳��ɼ�����ϵͳ
		default:printf("\n\n������������!����������: \n\n"); break;
		}
	}
}















