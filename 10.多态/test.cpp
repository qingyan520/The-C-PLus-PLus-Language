//1.��̬�ĸ���
//��̬��Ϊ����
//��̬��̬:����������������������ھ�̬���أ����ú�����
//��̬��̬:��������麯��ʵ������ʱ��̬
//��̬��̬�ĺ�����ַ��󶨣�����׶�ȷ��������ַ
//��̬��̬�ĺ�����ַ��󶨣����н׶�ȷ��������ַ
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	//�麯��
//	virtual void speak()
//	{
//		cout << "����˵��" << endl;
//	}
//};
//class cat :public animal
//{
//	void speak()
//	{
//		cout << "Сè�ڽ�" << endl;
//	}
//};
//class dog :public animal
//{
//
//	void speak()
//	{
//		cout << "С���ڽ�" << endl;
//	}
//};
////��ַ��󶨣��ڱ���׶�ȷ��������ַ
////�������è˵����������������ĵ�ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�Ҳ���ǵ�ַ���
//
////��̬��̬��������
////1.�����м̳й�ϵ
////2.����Ҫ��д�����е��麯��
////��д:�������ƣ�����ֵ���ͣ��β��б���ȫ��ͬ��������дʱvirtual��д�ɲ�д��
////��̬��̬��ʹ��
////1.�����ָ�������ָ������Ķ���
////
//void dospeak(animal &Animal)//animal &Animal=c;
//{
//	Animal.speak();
//
//}
//void test01()
//{
//	cat c;
//	dospeak(c);
//	dog g;
//	dospeak(g);
//}
//void test02()
//{
//
//	cout << sizeof(animal) << endl;
////��̬��̬ԭ������:
////��δ��virtual�ؼ���ʱ������animal��СΪ1���൱��һ���ն���
////�����˹ؼ���֮�󣬸����о���������=һ����Ϊvfptr��ָ�룬�����СΪ4�����ָ��ָ��һ���麯����virtable��
////����麯�������¼��&aniaml::speak
////��ʱ��cat�̳и��࣬sizeof(cat)�Ĵ�СҲΪ4���������ļ̳��˸����е�vfptrָ�룬�Լ�����ָ����麯����
////��cat�������������д�����е�speak������&cat::speak������ڸǵ�ԭ��virptrָ���&animal::speak
////��������ÿ�ε��õ�ʱ���ֻ����������speak����
//
//}
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//	return 0;
//}




//��ϰ
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "����˵��" << endl;
//
//	}
//};
//class cat :public animal
//{
//public:
//	void speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//class dog :public animal
//{
//public:
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
//void dospeak(animal& Animal)
//{
//	Animal.speak();
//}
//void test01()
//{
//	cat s;
//	dospeak(s);
//	dog d;
//	dospeak(d);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//��̬����1������������
//�ֱ�������ͨ�����Ͷ�̬���������ʵ��������������������ļ�������
//��̬�ĺô���
//1֯�ṹ����
//2.�ɶ���ǿ
//3.����ǰ�ڣ����ڵ���չ��ά���Ը�
//c++���ᳫ���ö�̬д����
//#include<iostream>
//using namespace std;
////1.������ͨ����ʵ��
//class Cal
//{
//public:
//	int calculator(string str)
//	{
//		if (str == "+")
//		{
//			return m_A + m_B;
//		}
//		else if(str=="-")
//		{
//			return m_A - m_B;
//		}
//		else if (str == "*")
//		{
//			return m_A * m_B;
//		}
//		else
//		{
//			return m_A / m_B;
//		}
//	}
//	int m_A;
//	int m_B;
//};
//void test01()
//{
//	Cal a;
//	a.m_A = 10;
//	a.m_B = 10;
//	cout << a.m_A << "+" << a.m_B << "=" << a.calculator("+")<<endl;
//	cout << a.m_A << "-" << a.m_B << "=" << a.calculator("-")<<endl;
//	cout << a.m_A << "*" << a.m_B << "=" << a.calculator("*")<<endl;
//	cout << a.m_A << "/" << a.m_B << "=" << a.calculator("/")<<endl;
//}
////2.��̬�汾�ļ�����
//class cal
//{
//public:
//	virtual int calculator(string str)
//	{
//		return 0;
//	}
//	int m_A;
//	int m_B;
//};
//class AddCal :public cal
//{
//	virtual int calculator(string str)
//	{
//		return m_A + m_B;
//	}
//};
//class SubCal :public cal
//{
//	virtual int calculator(string str)
//	{
//		return m_A - m_B;
//	}
//};
//class MulCal :public cal
//{
//	virtual int calculator(string str)
//	{
//		return m_A * m_B;
//	}
//};
//class DivCal :public cal
//{
//	virtual int calculator(string str)
//	{
//		return m_A / m_B;
//	}
//};
//void test02()
//{
//	//��̬��̬��������
//	//�������̳и���
//	//������д�����麯��
//	//�����ָ���������ָ������Ķ���
//	//��������ָ����ʵ��
//	cal* a = new AddCal;
//	a->m_A = 10;
//	a->m_B = 10;
//	cout << a->m_A << "+" << a->m_B << "=" << a->calculator("+") << endl;
//	a = new SubCal;
//	a->m_A = 10;
//	a->m_B = 10;
//	cout << a->m_A << "-" << a->m_B << "=" << a->calculator("-") << endl;
//	a = new MulCal;
//	a->m_A = 10;
//	a->m_B = 10;
//	cout << a->m_A << "*" << a->m_B << "=" << a->calculator("*") << endl;
//	a = new DivCal;
//	a->m_A = 10;
//	a->m_B = 10;
//	cout << a->m_A << "/" << a->m_B << "=" << a->calculator("/") << endl;
//}
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//	return 0;
//}

//3.���麯���ͳ�����
//�ڶ�̬�У�ͨ�������е��麯����û������ģ���Ҫ���ǵ���������д������
//��˿��Խ��麯����Ϊ���麯��
//���麯���﷨:virtual ����ֵ���� ������ (�����б�)=0;
//���������˴��麯���������Ҳ����������
//��������ص㣺
//            �޷�ʵ��������
//            ���������д�������еĴ��麯��������Ҳ���ڳ�����
//#include<iostream>
//using namespace std;
//class base
//{
//public:
//	virtual void func() = 0;//���麯������������������
//};
//class son :public base
//{
//public:
//	void func()
//	{
//		cout << "hee" << endl;
//	}
//};
//void test01()
//{
//	//base a;�������޷�ʵ�������󣬼��޷�����ȥ����
//	son s;//���������д�����еĴ��麯���������޷�ʵ��������
//	base* a = new son;
//	a->func();
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//��̬������:������Ʒ
//#/*include<iostream>
//using namespace std;
//int main()
//{
//	system("pause");
//	return 0;
//}*/

//4.�������ʹ�������
#include<iostream>
using namespace std;
int main()
{
	system("pause");
	return 0;
}
