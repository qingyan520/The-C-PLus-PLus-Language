//#include<iostream>
//using namespace std;
//int main()
//{
//	////C���Զ�̬����ռ�
//	//int* p = (int*)malloc(sizeof(int));
//	////C++��̬�ڴ�����
//	//int* p = new int;
//	////C++�������ڴ�ռ�ʱ���Զ�����г�ʼ��
//	//int* p = new int(10);//��ʼ�����������ڴ�ռ�Ϊ10
//	////C���Զ��ڶ�̬���������
//	//int* arr = (int*)malloc(sizeof(int) * 10);
//	////C++���ڶ�̬���������
//	//int* arr = new int[10];
//	////C++�ڶ�̬��������ʱ�����Զ�����г�ʼ��
//	//int* arr = new int[3]{ 1,2,3 };//���¿��ٵ�int���ͣ���СΪ3�����鸳ֵΪ1��2��3
//	//int* p = (int*)malloc(sizeof(int));
//	//free(p);
//
//	//int* p = new int;
//	//delete p;
//
//	//int* arr = (int*)malloc(sizeof(int) * 4);
//	//free(arr);
//
//	//int* arr = new int[10];
//	//delete[]arr;
//	return 0;
//}


#include<iostream>
using namespace std;
class A
{
public:
	A(int a=10, int b=11)
	{
		_a = a;
		_b = b;
	}
	~A()
	{
		cout << "���������ĵ���" << endl;
	}
private:
	int _a;
	int _b;
};
int main()
{
	//C���Է�ʽ���Զ������ͽ��ж�̬����
	A* p1 = (A*)malloc(sizeof(A));
	//C++��ʽ���Զ������ͽ��ж�̬����
	A* p2 = new A;
	free(p1);
	delete p2;
	return 0;
}