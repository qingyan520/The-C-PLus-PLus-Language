//c++��һ�ֱ��˼���Ƿ��ͱ�̣���Ҫ���õļ�������ģ��

//1.����ģ����﷨
//�﷨��template<typename T>
//�����������߶���
//template��������ģ��
//typename �����ķ�����һ���������ͣ�������class����
//T��ͨ�õ��������� �����ƿ����滻��ͨ��Ϊ��д��ĸ
//ģ�����ʹ�������Ͳ�����
//��ϰ
//#include<iostream>
//using namespace std;
////����ģ��ʵ���������ݵĽ���
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//	
//}
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	//ģ���ʹ�÷�����
//	//1.�Զ�ת����
//	//Swap(a, b);
//	//cout << "a=" << a<<endl;
//	//cout << "b=" << b << endl;
//	//2.����<>������������
//	Swap<int>(a, b);
//	cout << "a=" << a<<endl;
//	cout << "b=" << b << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//2.����ģ��ע������
//1.�Զ������Ƶ��������Ƶ���һ�µ���������T�ſ���ʹ��
//2.ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
//ע��(1)��ʹ��ģ���Զ������Ƶ�ʱ�������Ƶ���һ�µ��������Ͳ���ʹ�ã�Ҫ���������Ͳ�һ�����޷�ʹ��
//template<class T>
//void swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//	char c = 'c';
//}
//swap(a,b)//��ȷ
//swap(a,c)//����ȷ
//(2)ģ�����ȷ���������Ͳſ���ʹ��
//template<class T>
//void func()
//{
//	cout << "�Ǻ�" << endl;
//}
////�ú���ģ������û���������ͣ����޷�ʹ���Զ������Ƶ��Ƶ���T���������ͣ�����Ҫ��Ϊ����T����������
//func<int>();
//#include<iostream>
//using namespace std;
//int main()
//{
//	system("pause");
//	return 0;
//}

//ѡ������
//ѡ�������ȶ���һ��i�����������飬ÿ�α���ʱ����һ�����ֵΪi,
//          Ȼ��j��i+1��ʼ�ߣ����arr[max]<arr[j],����max=j;
 //         ���max�������i������ˣ��򽻻�arr[max]��arr[i]��λ��
//#include<iostream>
//using namespace std;
//int main()
//{
//	int arr[10] = { 1,4,5,2,3,9,7,8,10,6 };
//	for (int i = 0; i < 10; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < 10; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			int temp = arr[i];
//			arr[i] = arr[max];
//			arr[max] = temp;
//		}
//	}
//	for (size_t i = 0; i <10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//ʵ����ϰ������ģ��ʵ�ֶ�һ��char ���������int���������ѡ������
//#include<iostream>
//using namespace std;
//template<class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//template <class T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			Swap(arr[i], arr[max]);
//		}
//	}
//}
//void test01()
//{
//	char charArr[] = "abcdef";
//	int len = sizeof(charArr) / sizeof(char);
//	mySort(charArr, len);
//	for (int i = 0; i < len; i++)
//	{
//		cout << charArr[i] << " ";
//	}
//	cout << endl;
//}
//void test02()
//{
//	int intArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	mySort(intArr, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << intArr[i]<<" ";
//	}
//	cout << endl;
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}

//ʵ����ϰ������ģ��ʵ��bubblesort
//#include<iostream>
//using namespace std;
//template<class T>
//void BubbleSort(T arr[], int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				T temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//void test01()
//{
//	int arr[10] = { 1,7,9,4,8,2,5,3,6,10 };
//	BubbleSort(arr, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.��ͨ�����ͺ���ģ�������
//��ͨ�����ڵ���ʱ���Է����Զ�����ת��
//����ģ�����ʱ��������������Զ������Ƶ������ᷢ����ʽ����ת��
//���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
//����ʹ����ʾָ�����͵ķ�ʽ�����ú���ģ�壬��Ϊ�Լ�����ȷ��ͨ������T

//5.��ͨ�����뺯��ģ��ĵ��ù���
//1.�����ͨ������ģ�庯��������ʵ�֣����ȵ�����ͨ����
//2.����ͨ����ģ������б�ǿ�Ƶ���ģ�庯��
//3.����ģ����Է�������
//4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
//#include<iostream>
//using namespace std;
//template<class T>
//void Print(T a)
//{
//	cout << "����ģ��ĵ���" << endl;
//}
//void Print(int a)
//{
//	cout << "��ͨ�����ĵ���" << endl;
//}
//template<class T>
//void Print(T a, T b)
//{
//	cout << "ģ�庯�����صĵ���" << endl;
//}
//void test01()
//{
//	//1.�����ͨ������ģ�庯��������ʵ�֣����ȵ�����ͨ����
//	Print(10);
//	//2.����ͨ����ģ������б�ǿ�Ƶ���ģ�庯��
//	Print<>(10);
//	//3.����ģ����Է�������
//	Print(10, 10);
//	char c1 = 10;
//	char c2 = 10;
//	Print(c1, c2);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//��Ȼ�����˺���ģ�壬�Ͳ�Ҫд��ͨ����


//6.ģ�庯���ľ�����
//ģ�岢�������ܵģ���Щ�ض����������ͣ���Ҫ�þ���ת����ʽ������ʵ��

//�Ա����������Ƿ����
//#include<iostream>
//#include<string>
//using namespace std;
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	string m_name;
//	int m_age;
//};
//template<class T>
//bool compare(T& a, T& b)
//{
//
//}
// template<> bool compare(person &a, person& b)
//{
//	 if (a.m_name == b.m_name && b.m_age == a.m_age)
//	 {
//		 return true;
//	 }
//	 return false;
//}
//void test01()
//{
//	person p1("Tom", 10);
//	person p2("Tom", 10);
//	int ret = compare(p1, p2);
//	if (ret)
//	{
//		cout << "p1==p2";
//	}
//
//	
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//��ģ��
//1.��ģ������﷨��

//��ģ���뺯��ģ������
//1.��ģ��û���Զ������Ƶ���ֻ������ʾָ������
//2.��ģ����ģ������б��п�����Ĭ�ϲ���
//#include<iostream>
//using namespace std;
//template<class NameType,class AgeType>
//class person
//{
//public:
//	person(NameType name, AgeType age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	void show()
//	{
//		cout << "������" << this->m_name << "  " << "���䣺" << this->m_age << endl;
//	}
//	NameType m_name;
//	AgeType m_age;
//};
//void test01()
//{
//	person<string, int>p("Tom", 10);
//	p.show();
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//ģ�帴ϰTemplate<class T>
//#include<iostream>
//using namespace std;
//template<class NameType,class AgeType>
//class person
//{
//public:
//	person(NameType name, AgeType age)
//	{
//		this->age = age;
//		this->name = name;
//	}
//	NameType name;
//	AgeType age;
//	void show()
//	{
//		cout << name << endl;
//		cout << age << endl;
//	}
//	
//};
//int main()
//{
//	person<string, int>p("Tom", 18);
//	p.show();
//	system("pause");
//	return 0;
//}


//2.��ģ���뺯��ģ�������
//1.��ģ��û���Զ������Ƶ���ʹ�÷���
//2.��ģ����ģ������б��п�����Ĭ�ϲ���


//3.��ģ���г�Ա�����Ĵ���ʱ��
//��ͨ���г�Ա����һ��ʼ�Ϳ��Դ���
//��ģ���еĳ�Ա�����ڵ���ʱ����


//4.��ģ������������
//#include<iostream>
//using namespace std;
//template<class T1,class T2>
//class person
//{
//public:
//	person(T1 name,T2 age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	void showperson()
//	{
//		cout << "����:" << this->m_name << "  " << "����:" << this->m_age << endl;
//	}
//	T1 m_name;
//	T2 m_age;
//};
//
////1.ֱ�Ӵ��η�
//void printperson1(person<string, int>& p)
//{
//	p.showperson();
//}
//void test01()
//{
//		person<string, int>p("Tom", 18);
//		printperson1(p);
//}
//
////2.ģ�廯����
//template<class T1,class T2>
//void printperson2(person<T1, T2>& p)
//{
//	p.showperson();
//}
//void test02()
//{
//	person<string, int>p("Tom", 17);
//	printperson2(p);
//}
////3.ֱ�ӽ�����ģ�廯
//template<class T>
//void printperson3(T &p)
//{
//	p.showperson();
//}
//void test03()
//{
//	person<string, int>p("Tom", 16);
//	printperson3(p);
//}
//int main()
//{
//	test01();
//	test02();
//	test03();
//	system("pause");
//	return 0;
//}


//5.��ģ����̳�
//����ģ�������̳�ʱ����Ҫע�����¼���
//1.������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ���������е�����
//2.�����ָ�����������޷�����������ڴ�
//3.���������ָ�������е�T���������ͣ�����Ҳ��Ҫ��Ϊ��ģ��
//#include<iostream>
//using namespace std;
//template<class T>
//class base
//{
//	T s1;
//};
////1.��һ�ַ�����ֱ��ָ����������
//class son :public base<int>
//{
//public:
//
//};
////2.�ڶ��ַ��������ڶ����ඨ��Ϊģ�壬Ȼ���ڴ���ʱָ������
//template<class T1,class T2 >
//class son2 :public base<T2>
//{
//public:
//};
//
//void test01()
//{
//	son2<int, char>p;
//	//��ʱT1Ϊint,T2Ϊchar,�������е�s1ҲΪchar����
//};
//int main()
//{
//	system("pause");
//	return 0;
//}


//6.��ģ���Ա����������ʵ��
//#include<iostream>
//#include<string>
//using namespace std;
//template<class T1,class T2>
//class person
//{
//public:
//	//��Ա������������
//	person(T1 name, T2 age);
//	void showperson();
//	T1 m_name;
//	T2 m_age;
//};
////���캯������ʵ��
//template<class T1,class T2>
//person<T1,T2>::person(T1 name, T2 age)
//{
//	this->m_age = age;
//	this->m_name = age;
//}
//template<class T1, class T2>
//void person<T1, T2>::showperson()
//{
//	cout << "hehe" << endl;
//}
//void test01()
//{
//	person<string, int>p("tom", 15);
//	p.showperson();
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//7.��ģ��ķ��ļ���д
//��ģ���еĳ�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���д���Ӳ���
//���������
//1.ֱ�Ӱ���.cppԴ�ļ�
//2.��������ʵ��д��ͬһ���ļ��У������ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�����ǿ��
//#include<iostream>
//#include<string>
//using namespace std;
//#include"Դ1.hpp"
//void test01()
//{
//	person<string, int>p("Tom", 18);
//	p.showperson();
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//�����������Ϊ�ڶ���


//8.��ģ������Ԫ
//#include<iostream>
//using namespace std;
//template<class T1,class T2>
//class person
//{
//public:
//	person(T1 name, T2 age)
//	{
//
//	}
//};
//int main()
//{
//	system("pause");
//	return 0;
//}


//������ʵ��һ��ͨ�õ�������
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
public:

};
int main()
{
	system("pause");
	return 0;
}