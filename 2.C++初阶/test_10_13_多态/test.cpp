
//1.��̬�Ļ���ʵ�֣�
//��̬���ɵ�������
//1.����ͨ�������ָ��������ý��е���
//2.�����õĺ����������麯���������������Ը��������д
//
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "ȫ��--��Ʊ" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "���--��Ʊ" << endl;
//	}
//};
//void test(Person&p)
//{
//	p.BuyTicket();
//}
//void test(Person* p)
//{
//	p->BuyTicket();
//}
//int main()
//{
//	Person p;
//	Student s;
//	test(p);
//	test(s);
//	cout << "---------" << endl;
//	test(&p);
//	test(&s);
//	return 0;
//}


//2.�̳е�������������
//2.1Э�䣺�������븸��ķ���ֵ���Բ�ͬ�����Ƿ���ֵ�����Ǹ������͵�ָ���������
//���Է����Լ���ָ��������ã�����Ҫ����ȫ���ã�Ҫָ��ȫָ��
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//};
//class B :public A
//{
//public:
//};
//
//class C
//{
//public:
//	virtual C&F()
//	{
//		cout << "C:: C& F()" << endl;
//		C c;
//		return c;
//	}
//};
//class D :public C
//{
//public:
//	virtual D& F()
//	{
//		cout << "D:: D&F()" << endl;
//		D a;
//		return a;
//	}
//};
//void test(C& p)
//{
//	p.F();
//}
//void test(C* p)
//{
//	p->F();
//}
//void test1()
//{
//	C c;
//	D d;
//	test(c);
//	test(d);
//	cout << "++++++++++++++" << endl;
//	test(&c);
//	test(&d);
//}
//int main()
//{
//	test1();
//	return 0;
//}


//2.2��������
//�������Ὣ��ͬ���ֵ���������ת��Ϊdistructor,һ�������������������Ҫ��д��������ĳЩ�ض�������£�����Ҫ��д���������ģ��������������
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		cout << "A::A()"<<endl;
//	}
//	virtual ~A()
//	{
//		cout << "A::~A()" << endl;
//	}
//};
//class B :public A
//{
//public:
//	B()
//	{
//		cout << "B::B()" << endl;
//	}
//	virtual~B()
//	{
//		cout << "B::~B()" << endl;
//	}
//};
//int main()
//{
//	//1.��������������ͨ������ǿ��Բ������ص�
//	//A x;
//	//B y;
//
//	//���������Ҫ����
//	//���������ֻ����ø�������������������ȵ������������������Ȼ���ٵ��ø������������
//	//�����������Ҫ��virtual���ɶ�̬
//	A* a = new A;
//	A* b = new B;
//	delete a;
//	delete b;
//	return 0;
//}

//2.3������д������麯������дʱ���Բ���virtual����������д��ϰ�߲��ã����鶼��virtual



//final�ؼ��֣����麯�������final����ú��������Ա���д
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void Func()final
//	{
//
//	}
//};
//class B :public A
//{
//public:
//	//������д������麯��ʱ�ᱨ��
//	virtual void Func()
//	{
//
//	}
//};
//
//int main()
//{
//
//	return 0;
//}

//override����������Ƿ���д������麯���Լ��Ƿ���д�ɹ������û����д�ɹ��ͻᱨ��
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void Func()
//	{
//
//	}
//};
//class B :public A
//{
//public:
//	virtual void Func()override
//	{
//
//	}
//};
//int main()
//{
//
//	return 0;
//}


//���麯�����麯����=0��β�ĺ����������麯�������д��麯��������������࣬�����಻��ʵ����������
//���̳к�ֻ��������д�˸���Ĵ��麯����������ܹ�ʵ���������󣬷�������Ҳ����ʵ����������
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual  void Func() = 0;
//};
//class B :public A
//{
//public:
//	virtual void Func()
//	{
//
//	}
//};
//int main()
//{
//
//	return 0;
//}


//��̬ʵ�ֵ�ԭ��
//���һ�����к����麯������ô�����Ķ����Ա����ǰ�����һ��_vfptr,�����麯����ָ��(������ָ��)��_vfptrָ���麯����
//�麯��������洢���麯���ĵ�ַ��ͨ����Щ�麯���ĵ�ַ�����ܷ��ʵ��麯��

//1.���������d��Ҳ��һ�����ָ�룬d�����������ֹ��ɣ�һ�����Ǹ���̳������ĳ�Ա�����ָ��Ҳ���Ǵ��ڲ��ֵ���һ�������Լ��ĳ�Ա
//2.������д������麯������������еĺ����ͻ�������ĺ����������麯������дҲ�������ǣ����Ǿ���ָ����е��麯���ĸ��ǣ���д���﷨��Ľз���������ԭ���Ľз�
//3.�̳е��麯���Ž���������麯������Ž����
//4.�麯��������һ������麯��ָ���ָ�����飬һ����������������������һ��nullptr
//5.���ָ��ָ���麯�����麯��������洢���麯��ָ�룬�麯��������ڴ����


//��̬�����������󵽶�����ȥ�ҵ�
//1.��̬���ֳ�Ϊǰ�ڰ�(���)���ڱ����ڼ�ȷ������д����Ϊ��Ҳ��Ϊ��̬���������磺��������
//2.��̬���ֳ������ڰ�(���)���ڳ��������ڼ䣬�����õ�������ȷ�������ľ�����Ϊ�����õĺ���


//���̳кͶ�̳��е��麯����
//�����ͷ4���ֽھ�������ָ��
//ͨ��ʵ��۲��֪����̳е�δ��д���麯�����ڵ�һ���̳��ಿ�ֵ��麯������
//
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void Func1()
//	{
//
//	}
//
//	virtual void Func2()
//	{
//
//	}
//};
//class B :public A
//{
//public:
//	virtual void Func1()
//	{
//
//	}
//
//	virtual void Func2()
//	{
//
//	}
//
//	virtual void Func3()
//	{
//
//	}
//};
//int main()
//{
//	A a;
//	B b;
//	return 0;
//}


//�����̬�������󣬹��ɶ��᣺
//ָ��������ã������麯��ʱ�������ڱ���ʱȷ����������ʱָ��Ķ����е������ȥ�Ҷ�Ӧ���麯������
//����ָ��ĸ��ຯ�����󣬵��õľ��Ǹ�����麯����ָ������͵�������麯��
//
//��Ҫע���ʱ����������ɶ�̬����ô������õ�ʱ�������ȷ���Ǹ������Ǹ���������Ҫ��p������
//���õ�ʱPerson��BuyTciket,����ʲôû�й�ϵ
//
//
//���ɶ�̬��ָ��˭����˭���麯�����������й�
//�����ɶ�̬��
//
//��̬����ʱ�����Ǹ����ָ��������õ��ã�
//�������ᷢ�����������������û�ʹ�����������������������Ҳ��������ĵ�ַ���������˶�̬
//�����ָ������ã���Ƭʱʱָ��������������������������г�����һ����
//�������ʱ��
//ͬ���͵Ķ������ǹ���ͬһ�����
//
//
//�����е����ָ����ʲô�׶γ�ʼ�������캯����ʼ��
//������Ǹ��ط����ɣ�������ڱ����Ǿ����ɺ���
//
//���������麯����ָ�룬�麯������ͨ����һ����������ɺ󣬶����ڴ����
//
//���е��麯��������������
//
//��д���﷨��ĸ��������ԭ��
//
//����Ǵ����ڴ����
//��֤������ȡ�����ĵ�ַ(һ�������ǰ�ĸ��ֽ�)��ջ������������̬�������������жԱ�
//

#include<iostream>
#include<stdio.h>
using namespace std;
class A
{
public:
	virtual void Func1()
	{
		cout << "A::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "A::Func2()" << endl;
	}
	int a;
};
class B 
{
public:
	virtual void Func1()
	{
		cout << "B::Func1()" << endl;
	}
	int b;
};

class C :public A, public B
{
public:
	virtual void Func1()
	{
		cout << "C::Func1()" << endl;
	}
	virtual void Fun5()
	{
		cout << "C::Func5()" << endl;
	}

	int c;
};
typedef void(*VFunc)();
void PrintVFT(VFunc* ptr)
{
	printf("����ַ:%p\n", ptr);
	for (int i = 0; ptr[i] != nullptr; ++i)
	{
		printf("VFT[%d]:%p->\n", i, ptr[i]);
		ptr[i]();
	}
	printf("\n");
}

int main()
{
	C c;
	//PrintVFT((VFunc*)(*(int*)&c));
	PrintVFT((VFunc*)(*(int*)((char*)&c + sizeof(A))));
	return 0;
}