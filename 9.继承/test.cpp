//4.6�̳�
//�̳�����Զ������������֮һ
//4.6.1�̳еĻ����﷨
//#include<iostream>
//using namespace std;
//class basepage
//{
//public:
//	void header()
//	{
//		cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl; 
//	}
//	void footer()
//	{ 
//		cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
//	}
//	void left()
//	{
//		cout << "Java,Python,C++...(���������б�)" << endl;
//	}
//};
//class python:public basepage
//{
//public:
//	void content()
//	{
//		cout << "pythonѧ����Ƶ" << endl;
//	}
//};
//class java :public basepage
//{
//public:
//	void content()
//	{
//		cout << "javaѧ����Ƶ" << endl;
//	}
//};
//class cpp :public basepage
//{
//public:
//	void content()
//	{
//		cout << "C++ѧ����Ƶ" << endl;
//	}
//};
//void test()
//{
//	python py;
//	py.header();
//	py.left();
//	py.footer();
//	py.content();
//	java ja;
//	ja.header();
//	ja.left();
//	ja.footer();
//	ja.content();
//	cpp cp;
//	cp.header();
//	cp.left();
//	cp.footer();
//	cp.content();
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}
//�̳еĺô��������ظ��Ĵ���
//�̳еĻ����﷨��class ������������Ȩ�� ������
//                class A:public B
//                A���Ϊ�������������
//                B���Ϊ������߻���
//������ĳ�Ա�������󲿷֣�
//1.һ���Ǵӻ���̳й����ģ�һ�����Լ����ӵĳ�Ա
//2.�Ӽ̳й����ı����乲�ԣ��������ĳ�Ա�����������


//4.6.2�̳з�ʽ
//�̳��﷨��class ���� :�̳з�ʽ ����
//�̳з�ʽһ�������֣�
//�����̳У�������Ϊ����Ȩ�ޣ�������ҲΪ����Ȩ�ޣ�������Ϊ����Ȩ�ޣ�������Ҳ�Ǳ���Ȩ��
//�����̳У�������Ϊ����Ȩ�ޣ�����Ȩ�ޣ�������Ҳ�Ǳ���Ȩ��
//˽�м̳У�������Ϊ����Ȩ�ޡ�����Ȩ�ޣ������ж�����˽��Ȩ��
//���ּ̳з�ʽ�����ʲ���������˽�г�Ա
#include<iostream>
using namespace std;
//�����̳�
class base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son1 :public base1
{
public:
	void func()
	{
		m_A = 10;//�����еĹ���Ȩ�޳�Ա����������Ȼ�ǹ���Ȩ��
		m_B = 10;//�����еı���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
		//m_C = 10;//�����е�����Ȩ�޳�Ա��������ʲ���
	}
};
//�����̳�
class Son2 :protected base1
{
public:
	void func()
	{
		m_A = 1000;//�����й�����Ա���������б�ɱ���Ȩ��
		m_B = 100;//�����б�����Ա�������б�ɱ���Ȩ��
		//m_C = 100;������˽�г�Ա������ʲ���

	}
};
class Son3 :private base1
{
public:
	void func()
	{
		m_A = 10;//�����й�����Ա���������б��˽�г�Ա
		m_B = 10;//�����б�����Ա���������б��˽�г�Ա
		//m_C=10//������˽�г�Ա��������ʲ���
	}
};
void test01()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B=100//��son1��m_B�Ǳ���Ȩ�ޣ�������ʲ���
//	Son2 s2;
	//s2.m_A ����son2 �У�m_Ab��ɱ���Ȩ�ޣ�������ʲ���
	//Son3 s3;
	//s3.m_A;//��son3�У���Ϊ˽�г�Ա��������ʲ���
}

int main()
{
	test01();
	system("pause");
	return 0;
}
