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


//4.2.6 初始化列表
//语法：构造函数（）：属性1（值1），属性2（值2）....{}
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
//	//初始化列表，初始化属性
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


//2.this指针的概念
//this指针指向被调用的成员函数所属的对象
//this指针是隐含每一个非静态成员变量函数内的一种指针
//this指针不需要定义，直接使用即可
//this指针的用途：
//1.当形参和成员变量重名时，可以用this指针来区分
//2.在类的非静态成员函数中返回对象本身，可以使用return*this
//例：
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	//1.this指针可以将非静态成员变量和形参分别出来
//	 person(int age)
//	{
//		this->age = age;
//	}
//	 //2.在类的非静态成员函数中返回对象本身
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
//	cout << "p的年龄是：" << p.age << endl;
//	person p1(10);
//	p1.Add(p).Add(p).Add(p);
//	cout << "p1的年龄" << p1.age << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//C++运算符重载
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