

//1.��Ա��������Ա����
//��c++�У����ڵĳ�Ա�����ͳ�Ա�����ֱ�洢
//ֻ�зǾ�̬��Ա������������Ķ�����
//#include<iostream>
//using namespace std;
//class person
//{
//	int m_age;
//	void he()
//	{
//		;
//	}
//	static int i;
//	//��̬��Ա��������̬��Ա�����ͳ�Ա������ռ�ö���Ŀռ�
//};
//void test01()
//{
//	person p;
//	cout << "sizeof(p)=" << sizeof(p) << endl;//����һ���ն������СΪ1�ֽ�
//}
//void test02()
//{
//	person p;
//	cout << "sizeof(p)=" << sizeof(p) << endl;//��СΪ4
//
//}
//int main()
//{
//	//test01();
//	test02();
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
#include<iostream>
using namespace std;
class person
{
public:
	//1.thisָ����Խ��Ǿ�̬��Ա�������βηֱ����
	 person(int age)
	{
		this->age = age;
	}
	 //2.����ķǾ�̬��Ա�����з��ض�����
	 person &Add(person& p)
	 {
		 this->age += p.age;
		 return  *this;
	 }
	int age;
};
void test01()
{
	person p(10);
	cout << "p�������ǣ�" << p.age << endl;
	person p1(10);
	p1.Add(p).Add(p).Add(p);
	cout << "p1������" << p1.age << endl;



}
int main()
{
	test01();
	system("pause");
	return 0;
}