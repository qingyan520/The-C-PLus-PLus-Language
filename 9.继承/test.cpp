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
//#include<iostream>
//using namespace std;
////�����̳�
//class base1
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//class Son1 :public base1
//{
//public:
//	void func()
//	{
//		m_A = 10;//�����еĹ���Ȩ�޳�Ա����������Ȼ�ǹ���Ȩ��
//		m_B = 10;//�����еı���Ȩ�޳�Ա������������Ȼ�Ǳ���Ȩ��
//		//m_C = 10;//�����е�����Ȩ�޳�Ա��������ʲ���
//	}
//};
////�����̳�
//class Son2 :protected base1
//{
//public:
//	void func()
//	{
//		m_A = 1000;//�����й�����Ա���������б�ɱ���Ȩ��
//		m_B = 100;//�����б�����Ա�������б�ɱ���Ȩ��
//		//m_C = 100;������˽�г�Ա������ʲ���
//
//	}
//};
//class Son3 :private base1
//{
//public:
//	void func()
//	{
//		m_A = 10;//�����й�����Ա���������б��˽�г�Ա
//		m_B = 10;//�����б�����Ա���������б��˽�г�Ա
//		//m_C=10//������˽�г�Ա��������ʲ���
//	}
//};
//void test01()
//{
//	Son1 s1;
//	s1.m_A = 100;
//	//s1.m_B=100//��son1��m_B�Ǳ���Ȩ�ޣ�������ʲ���
////	Son2 s2;
//	//s2.m_A ����son2 �У�m_Ab��ɱ���Ȩ�ޣ�������ʲ���
//	//Son3 s3;
//	//s3.m_A;//��son3�У���Ϊ˽�г�Ա��������ʲ���
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//3.�̳��еĶ���ģ��
//�Ӹ���̳еĳ�Ա����Щ�������������
//#include<iostream>
//using namespace std;
//class base
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//class Son :public base
//{
//public:
//	int M;
//};
//
//int main()
//{
//	Son p;
//	cout << sizeof(p) << endl;
//	//��Ϊ16
//	//���������зǾ�̬��Ա���ᱻ�̳���ȥ
//	//�����е�˽�г�Ա���Իᱻ������������������˷��ʲ���������ȷʵ���̳���
//	system("pause");
//	return 0;
//}


//4.6.3 �̳��еĹ��캯������������
//#include<iostream>
//using namespace std;
//class base
//{
//public:
//	base()
//	{
//		cout << "base�Ĺ��캯��" << endl;
//	}
//	~base()
//	{
//		cout << "base����������" << endl;
//	}
//};
//class Son:public base
//{
//public:
//	Son()
//	{
//		cout << "Son�Ĺ��캯��" << endl;
//	}
//	~Son()
//	{
//		cout << "Son����������" << endl;
//	}
//};
//void test()
//{
//	Son s1;
//}
////�̳��еĹ��������˳�����£�
////�ȹ��츸�࣬�ڹ������࣬������˳���빹��˳���෴
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}


//4.6.4 �̳���ͬ����Ա����
//��������ͬ����Ա��ֱ�ӵ��������
//���ʸ���ͬ����Ա����Ҫ��������
//#include<iostream>
//using namespace std;
//class base
//{
//public:
//	base()
//	{
//		m_A = 10;
//	}
//	int m_A;
//	void func()
//	{
//		cout << "Base__func����" << endl;
//	}
//};
//class son:public base
//{
//public:
//	son()
//	{
//		m_A = 20;
//	}
//	int m_A;
//	void func()
//	{
//		cout << "son___func����" << endl;
//	}
//};
//void test01()
//{
//	son s;
//	cout << s.m_A << endl;
//	//ͨ��������󣬷��ʵ������е�ͬ����Ա����Ҫ��������
//	cout << s.base::m_A << endl;
//}
//void test02()
//{
//	son s;
//	s.func();//ֱ�ӵ��õ��õ��������func����
//	//���Ҫ���ø����func����Ҫ��������
//	s.base::func();
//	//��������г����ڸ���ͬ���ĳ�Ա�����������ͬ����Ա�����������ͬ����Ա�����ᱻ���ص�����������ͬ����Ա����
//	//�������ʵ������б����ص�ͬ������������Ҫ��������
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}



//4.6.6 �̳е�ͬ����̬��Ա������
//��Ǿ�̬��Աһֱ���������򼴿�


//4.7��̳��﷨
//�﷨��class ���ࣺ�̳з�ʽ ����1���̳з�ʽ ����2
//���ܻ������������⣬��Ҫ����������
//#include<iostream>
//using namespace std;
//class base1
//{
//public:
//	int m_A = 10;
//};
//class base2
//{
//public:
//	int m_A = 20;
//};
//class son :public base1, public base2
//{
//public:
//	int m_A=30;
//	int m_B = 40;
//};
//void test01()
//{
//	son s;
//	cout << sizeof(s) << endl;
//	cout << s.m_A << endl;
//	cout << s.base1::m_A << endl;
//	cout << s.base2::m_A << endl;
//}
//int main()
//{
//	test01();
//	return 0;
//}


//4.8.6 ���μ̳�
//���μ̳еĸ���
//����������̳�ͬһ������
//����ĳ����ͬʱ�̳�������������
//���ּ̳б���Ϊ���μ̳У�������ʯ�̳�
//��̳У��̳�ǰ��virtualΪ��̳�
//animal����Ϊ�����
#include<iostream>
using namespace std;
class animal
{
public:
	int m_age;
};
class sheep:public animal
{

};
class Tuo :public animal
{

};
class sheepTuo :public sheep, public Tuo
{
	
};
void test01()
{
	//virtual
}
int main()
{
	test01();
	return 0;
}