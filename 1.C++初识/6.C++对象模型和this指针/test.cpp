

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



//3.空指针访问成员函数
//c++中空指针也可以调用成员函数，但是要注意有没有用到this指针
//如果用到this指针，必须要加以判断代码的健康性
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	void show()
//	{
//		cout << "我是person类" << endl;
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
//	p->set();//如果遇到this指针，必须判断是否为空
//	p->show();//在c++中，空指针可以访问成员函数
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.3.4const 修饰成员函数
//常函数：
//1.成员函数后面加const我们成为常函数
//2.常函数内不可以修改成员属性
//3.成员属性后加mutable后，在函数内仍然可以修改
//常对象：
//1.声明对象前加const称该对象为常对象
//2.常对象只能调用常函数
#include<iostream>
using namespace std;
class person
{
public:
	void set()const
	{
		cout << "常函数的调用" << endl;
		//m_age = 0;如果对成员变量进行初始化的话会报错，只有当在声明成员变量时在成员变量前加mutable才能解决问题
		//this指针本质：指针常量  指针指向不可以修改  
		m_Age = 0;
		cout << m_Age << endl;
	}
	void sets()
	{
		cout << "hehe" << endl;
	}
	int m_age;
	mutable int m_Age;//可修改的，可变的，常对象下也可以修改
};
void test01()
{
	person p;
	p.set();
	const person p1;//const 修饰的常对象只能调用常函数，因为普通成员函数会修改成员变量
	//p1.sets();
	p1.set();
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
