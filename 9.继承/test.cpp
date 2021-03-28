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
#include<iostream>
using namespace std;
//公共继承
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
		m_A = 10;//父类中的公共权限成员，子类中依然是公共权限
		m_B = 10;//父类中的保护权限成员，到子类中依然是保护权限
		//m_C = 10;//父类中的四有权限成员，子类访问不到
	}
};
//保护继承
class Son2 :protected base1
{
public:
	void func()
	{
		m_A = 1000;//父类中公共成员，到子类中变成保护权限
		m_B = 100;//父类中保护成员，子类中变成保护权限
		//m_C = 100;父类中私有成员子类访问不到

	}
};
class Son3 :private base1
{
public:
	void func()
	{
		m_A = 10;//父类中公共成员，到子类中变成私有成员
		m_B = 10;//父类中保护成员，到子类中变成私有成员
		//m_C=10//父类中私有成员，子类访问不到
	}
};
void test01()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B=100//到son1中m_B是保护权限，类外访问不到
//	Son2 s2;
	//s2.m_A ，在son2 中，m_Ab变成保护权限，类外访问不到
	//Son3 s3;
	//s3.m_A;//到son3中，变为私有成员，类外访问不到
}

int main()
{
	test01();
	system("pause");
	return 0;
}
