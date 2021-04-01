//1.多态的概念
//多态分为两类
//静态多态:重载运算符，函数重载属于静态重载，复用函数名
//动态多态:派生类和虚函数实现运行时多态
//静态多态的函数地址早绑定，编译阶段确定函数地址
//动态多态的函数地址晚绑定，运行阶段确定函数地址
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	//虚函数
//	virtual void speak()
//	{
//		cout << "动物说话" << endl;
//	}
//};
//class cat :public animal
//{
//	void speak()
//	{
//		cout << "小猫在叫" << endl;
//	}
//};
//class dog :public animal
//{
//
//	void speak()
//	{
//		cout << "小狗在叫" << endl;
//	}
//};
////地址早绑定，在编译阶段确定函数地址
////如果想让猫说话，那麽这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，也就是地址晚绑定
//
////动态多态满足条件
////1.必须有继承关系
////2.子类要重写父类中的虚函数
////重写:函数名称，返回值类型，形参列表完全相同（子类重写时virtual可写可不写）
////动态多态的使用
////1.父类的指针或引用指向子类的对象
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
////动态多态原理剖析:
////当未加virtual关键字时，父类animal大小为1，相当于一个空对象
////当加了关键字之后，父类中就增加了以=一个名为vfptr的指针，故其大小为4，这个指针指向一个虚函数表（virtable）
////这个虚函数表里记录着&aniaml::speak
////此时让cat继承父类，sizeof(cat)的大小也为4，它完美的继承了父类中的vfptr指针，以及他所指向的虚函数表
////当cat这个子类重新书写父类中的speak函数后，&cat::speak会代替掩盖掉原来virptr指向的&animal::speak
////这样我们每次调用的时候就只会调用子类的speak函数
//
//}
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//	return 0;
//}




//练习
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "动物说话" << endl;
//
//	}
//};
//class cat :public animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫会说话" << endl;
//	}
//};
//class dog :public animal
//{
//public:
//	void speak()
//	{
//		cout << "小狗会说话" << endl;
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


//多态案例1——计算器类
//分别利用普通方法和多态技术，设计实现两个操作数进行运算的计算器类
//多态的好处：
//1织结构清晰
//2.可读性强
//3.对于前期，后期的扩展及维护性高
//c++中提倡利用多态写函数
//#include<iostream>
//using namespace std;
////1.利用普通方法实现
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
////2.多态版本的计算器
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
//	//动态多态的条件：
//	//子类必须继承父类
//	//子类重写父类虚函数
//	//父类的指针或者引用指向子类的对象
//	//下面利用指针来实现
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

//3.纯虚函数和抽象类
//在多态中，通常父类中的虚函数是没有意义的，主要都是调用子类重写的内容
//因此可以将虚函数改为纯虚函数
//纯虚函数语法:virtual 返回值类型 函数名 (参数列表)=0;
//当类中有了纯虚函数，这个类也叫做抽象类
//抽象类的特点：
//            无法实例化对象
//            子类必须重写抽象类中的纯虚函数，否则也属于抽象类
//#include<iostream>
//using namespace std;
//class base
//{
//public:
//	virtual void func() = 0;//纯虚函数，这个类叫做抽象类
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
//	//base a;抽象类无法实例化对象，既无法创建去对象
//	son s;//子类必须重写父类中的纯虚函数，否则无法实例化对象
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

//多态案例二:制作饮品
//#/*include<iostream>
//using namespace std;
//int main()
//{
//	system("pause");
//	return 0;
//}*/

//4.虚析构和纯虚析构
#include<iostream>
using namespace std;
int main()
{
	system("pause");
	return 0;
}
