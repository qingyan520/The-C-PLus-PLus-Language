//4.6继承
//继承是面对对象的三大特性之一
//4.6.1继承的基本语法
//#include<iostream>
//using namespace std;
//class basepage
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...（公共头部）" << endl; 
//	}
//	void footer()
//	{ 
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "Java,Python,C++...(公共分类列表)" << endl;
//	}
//};
//class python:public basepage
//{
//public:
//	void content()
//	{
//		cout << "python学科视频" << endl;
//	}
//};
//class java :public basepage
//{
//public:
//	void content()
//	{
//		cout << "java学科视频" << endl;
//	}
//};
//class cpp :public basepage
//{
//public:
//	void content()
//	{
//		cout << "C++学科视频" << endl;
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
//继承的好处：减少重复的代码
//继承的基本语法：class 子类名：访问权限 父类名
//                class A:public B
//                A类称为子类或者派生类
//                B类称为父类或者基类
//派生类的成员包括两大部分：
//1.一类是从基类继承过来的，一类是自己增加的成员
//2.从继承过来的表现其共性，而新增的成员体现了其个性


//4.6.2继承方式
//继承语法：class 子类 :继承方式 父类
//继承方式一共有三种：
//公共继承：父类中为公共权限，子类中也为公共权限，父类中为保护权限，子类中也是保护权限
//保护继承：父类中为公共权限，保护权限，子类中也是保护权限
//私有继承：父类中为公共权限、保护权限，子类中都会变成私有权限
//三种继承方式都访问不到父类中私有成员
//#include<iostream>
//using namespace std;
////公共继承
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
//		m_A = 10;//父类中的公共权限成员，子类中依然是公共权限
//		m_B = 10;//父类中的保护权限成员，到子类中依然是保护权限
//		//m_C = 10;//父类中的四有权限成员，子类访问不到
//	}
//};
////保护继承
//class Son2 :protected base1
//{
//public:
//	void func()
//	{
//		m_A = 1000;//父类中公共成员，到子类中变成保护权限
//		m_B = 100;//父类中保护成员，子类中变成保护权限
//		//m_C = 100;父类中私有成员子类访问不到
//
//	}
//};
//class Son3 :private base1
//{
//public:
//	void func()
//	{
//		m_A = 10;//父类中公共成员，到子类中变成私有成员
//		m_B = 10;//父类中保护成员，到子类中变成私有成员
//		//m_C=10//父类中私有成员，子类访问不到
//	}
//};
//void test01()
//{
//	Son1 s1;
//	s1.m_A = 100;
//	//s1.m_B=100//到son1中m_B是保护权限，类外访问不到
////	Son2 s2;
//	//s2.m_A ，在son2 中，m_Ab变成保护权限，类外访问不到
//	//Son3 s3;
//	//s3.m_A;//到son3中，变为私有成员，类外访问不到
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//3.继承中的对象模型
//从父类继承的成员，哪些属于子类对象中
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
//	//答案为16
//	//父类中所有非静态成员都会被继承下去
//	//父类中的私有成员属性会被编译器隐藏起来，因此访问不到，但是确实被继承了
//	system("pause");
//	return 0;
//}


//4.6.3 继承中的构造函数和析构函数
//#include<iostream>
//using namespace std;
//class base
//{
//public:
//	base()
//	{
//		cout << "base的构造函数" << endl;
//	}
//	~base()
//	{
//		cout << "base的析构函数" << endl;
//	}
//};
//class Son:public base
//{
//public:
//	Son()
//	{
//		cout << "Son的构造函数" << endl;
//	}
//	~Son()
//	{
//		cout << "Son的析构函数" << endl;
//	}
//};
//void test()
//{
//	Son s1;
//}
////继承中的构造和析构顺序如下：
////先构造父类，在构造子类，析构的顺序与构造顺序相反
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}


//4.6.4 继承中同名成员处理
//访问子类同名成员，直接点出来即可
//访问父类同名成员，需要加作用域
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
//		cout << "Base__func调用" << endl;
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
//		cout << "son___func调用" << endl;
//	}
//};
//void test01()
//{
//	son s;
//	cout << s.m_A << endl;
//	//通过子类对象，访问到父类中的同名成员，需要加作用域
//	cout << s.base::m_A << endl;
//}
//void test02()
//{
//	son s;
//	s.func();//直接调用调用的是子类的func函数
//	//如果要调用父类的func函数要加作用域
//	s.base::func();
//	//如果子类中出现于父类同名的成员函数，子类的同名成员函数，子类的同名成员函数会被隐藏掉父类中所有同名成员函数
//	//如果想访问到父类中被隐藏的同名函数，有需要加作用域
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}



//4.6.6 继承的同名静态成员处理方法
//与非静态成员一直，加作用域即可


//4.7多继承语法
//语法：class 子类：继承方式 父类1，继承方式 父类2
//可能会引发重名问题，需要加作用域解决
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


//4.8.6 菱形继承
//菱形继承的概念
//两个派生类继承同一个基类
//又有某个类同时继承这两个派生类
//这种继承被称为菱形继承，或者钻石继承
//虚继承：继承前加virtual为虚继承
//animal被称为虚基类
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