//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)
//		:_a2(a)
//		, _a1(_a2)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}


//4.2.6 ��ʼ���б�
//�﷨�����캯������������1��ֵ1��������2��ֵ2��....{}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	//person(int a, int b, int c)
//	//{
//	//	m_A = a;
//	//	m_B = b;
//	//	m_C = c;
//	//}
//
//	//��ʼ���б���ʼ������
//	person(int a,int b,int c) :m_A(a), m_B(b), m_C(c)
//	{
//
//	}
//	int m_A;
//	int m_B;
//	int m_C;
//};
//void test01()
//{
//	//person p1(10, 20, 30);
//	person p1(30,20,10);
//	cout << p1.m_A << endl;
//	cout << p1.m_B << endl;
//	cout << p1.m_C << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//2.thisָ��ĸ���
//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
//thisָ��������ÿһ���Ǿ�̬��Ա���������ڵ�һ��ָ��
//thisָ�벻��Ҫ���壬ֱ��ʹ�ü���
//thisָ�����;��
//1.���βκͳ�Ա��������ʱ��������thisָ��������
//2.����ķǾ�̬��Ա�����з��ض���������ʹ��return*this
//����
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	//1.thisָ����Խ��Ǿ�̬��Ա�������βηֱ����
//	 person(int age)
//	{
//		this->age = age;
//	}
//	 //2.����ķǾ�̬��Ա�����з��ض�����
//	 person &Add(person& p)
//	 {
//		 this->age += p.age;
//		 return  *this;
//	 }
//	int age;
//};
//void test01()
//{
//	person p(10);
//	cout << "p�������ǣ�" << p.age << endl;
//	person p1(10);
//	p1.Add(p).Add(p).Add(p);
//	cout << "p1������" << p1.age << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//C++���������
#include<iostream>
using namespace std;
class Person
{
public:
	int m_A;
	int m_B;
};

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 20;
	Person p2;
	p2.m_A = 30;
	p2.m_B = 40;

}
int main()
{

	return 0;
}