

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



//3.��ָ����ʳ�Ա����
//c++�п�ָ��Ҳ���Ե��ó�Ա����������Ҫע����û���õ�thisָ��
//����õ�thisָ�룬����Ҫ�����жϴ���Ľ�����
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	void show()
//	{
//		cout << "����person��" << endl;
//	}
//	void set()
//	{
//		if (this == NULL)
//		{
//			return;
//		}
//		cout << age << endl;
//	}
//	int age;
//
//};
//void test01()
//{
//	person *p;
//	p = NULL;
//	p->set();//�������thisָ�룬�����ж��Ƿ�Ϊ��
//	p->show();//��c++�У���ָ����Է��ʳ�Ա����
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.3.4const ���γ�Ա����
//��������
//1.��Ա���������const���ǳ�Ϊ������
//2.�������ڲ������޸ĳ�Ա����
//3.��Ա���Ժ��mutable���ں�������Ȼ�����޸�
//������
//1.��������ǰ��const�Ƹö���Ϊ������
//2.������ֻ�ܵ��ó�����
#include<iostream>
using namespace std;
class person
{
public:
	void set()const
	{
		cout << "�������ĵ���" << endl;
		//m_age = 0;����Գ�Ա�������г�ʼ���Ļ��ᱨ��ֻ�е���������Ա����ʱ�ڳ�Ա����ǰ��mutable���ܽ������
		//thisָ�뱾�ʣ�ָ�볣��  ָ��ָ�򲻿����޸�  
		m_Age = 0;
		cout << m_Age << endl;
	}
	void sets()
	{
		cout << "hehe" << endl;
	}
	int m_age;
	mutable int m_Age;//���޸ĵģ��ɱ�ģ���������Ҳ�����޸�
};
void test01()
{
	person p;
	p.set();
	const person p1;//const ���εĳ�����ֻ�ܵ��ó���������Ϊ��ͨ��Ա�������޸ĳ�Ա����
	//p1.sets();
	p1.set();
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
