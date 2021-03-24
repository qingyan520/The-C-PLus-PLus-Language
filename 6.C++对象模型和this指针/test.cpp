

//1.成员函数，成员变量
//在c++中，类内的成员变量和成员函数分别存储
//只有非静态成员变量才属于类的对象上
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
//	//静态成员变量，静态成员函数和成员函数不占用对象的空间
//};
//void test01()
//{
//	person p;
//	cout << "sizeof(p)=" << sizeof(p) << endl;//创建一个空对象，其大小为1字节
//}
//void test02()
//{
//	person p;
//	cout << "sizeof(p)=" << sizeof(p) << endl;//大小为4
//
//}
//int main()
//{
//	//test01();
//	test02();
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
#include<iostream>
using namespace std;
class person
{
public:
	//1.this指针可以将非静态成员变量和形参分别出来
	 person(int age)
	{
		this->age = age;
	}
	 //2.在类的非静态成员函数中返回对象本身
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
	cout << "p的年龄是：" << p.age << endl;
	person p1(10);
	p1.Add(p).Add(p).Add(p);
	cout << "p1的年龄" << p1.age << endl;



}
int main()
{
	test01();
	system("pause");
	return 0;
}