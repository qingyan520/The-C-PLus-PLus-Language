#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200

//����ѧ����Ϣ
typedef struct Stu_Info
{
	char Name[30];//����
	char Number[50];//ѧ��
	int Chinese;//���ĳɼ�
	int Math;//��ѧ�ɼ�
	int English;//Ӣ��ɼ�
	float average;//ƽ����
	float sum;//�ܷ�
}Stu_Info;

//�����������洢������
Stu_Info Student[MAX];
//size����ǰѧ���ĸ���
int size = 0;


//����ѧ������
void Push()
{
	printf("������ѧ������:\n");
	scanf("%s", Student[size].Name);

	printf("������ѧ��:\n");
	scanf("%s", Student[size].Number);

	printf("���������ĳɼ�:\n");
	scanf("%d", &Student[size].Chinese);

	printf("��������ѧ�ɼ�:\n");
	scanf("%d", &Student[size].Math);

	printf("������Ӣ��ɼ�:\n");
	scanf("%d", &Student[size].English);

	//����ƽ����
	Student[size].average = (Student[size].Chinese + Student[size].Math + Student[size].English) / 3.0;

	//�����ܷ�
	Student[size].sum = Student[size].Chinese + Student[size].Math + Student[size].English;

	//����+1
	++size;
}





int main()
{
	return 0;
}