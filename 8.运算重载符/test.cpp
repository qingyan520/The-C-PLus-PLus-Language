//4.5���������
//�����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ��������

//4.5.1 �Ӻ����������
//���ã�ʵ�������Զ�������������ӵ�����
#include<iostream>
using namespace std;
class person
{
public:
	person()
	{

	}
	person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}
	//1.��Ա����ʵ��+������
	//person operator+(person &p)
	//{
	//	person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}
	int m_A;
	int m_B;
};
//2.ȫ�ֺ���ʵ��+������
person operator+(person& p1, person& p2)
{
	person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//3.��������ؿɷ�����������
person operator+(person& p, int a)
{
	person temp;
	temp.m_A = p.m_A + a;
	temp.m_B = p.m_B + a;
	return temp;
}
void test01()
{
	person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	person p2;
	p2.m_A = 10;
	p2.m_B = 20;
	person p3;
	p3 = p1 + p2;
	//p3 = p1.operator+(p2);
	cout << "p3.m_A=" << p3.m_A << endl;
	cout << "p3.m_B=" << p3.m_B << endl;
	person p4;
	p4 = p1 + p2;
	cout << "p4.m_A=" << p4.m_A << endl;
	cout << "p4.m_B=" << p4.m_B << endl;
	person p5;
	p5 = p4 + 10;
	cout << "p5.m_A=" << p5.m_A << endl;
	cout << "p5.m_B=" << p5.m_B << endl;


}
int main()
{
	test01();
	system("pause");


	return 0;
}

