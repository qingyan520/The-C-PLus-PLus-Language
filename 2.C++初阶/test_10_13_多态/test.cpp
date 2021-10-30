
//1.多态的基本实现：
//多态构成的条件：
//1.必须通过父类的指针或者引用进行调用
//2.被调用的函数必须是虚函数，并且子类必须对父类进行重写
//
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "全价--购票" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "半价--购票" << endl;
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


//2.继承的三个意外例子
//2.1协变：派生类与父类的返回值可以不同，但是返回值必须是父子类型的指针或者引用
//可以返回自己的指针或者引用，但是要引用全引用，要指针全指针
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


//2.2析构函数
//编译器会将不同名字的析构函数转化为distructor,一般情况下析构函数不需要重写，但是在某些特定的情况下，是需要重写析构函数的，例如下面的例子
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
//	//1.例如下面这种普通情况还是可以不用重载的
//	//A x;
//	//B y;
//
//	//下面情况需要重载
//	//这种情况下只会调用父类的析构函数而不是先调用子类的析构函数，然后再调用父类的析构函数
//	//这种情况就需要加virtual构成多态
//	A* a = new A;
//	A* b = new B;
//	delete a;
//	delete b;
//	return 0;
//}

//2.3子类重写父类的虚函数，重写时可以不加virtual，但是这种写法习惯不好，建议都加virtual



//final关键字：在虚函数后面加final代表该函数不可以被重写
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
//	//下面重写父类的虚函数时会报错
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

//override：检查子类是否重写父类的虚函数以及是否重写成功，如果没有重写成功就会报错
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


//纯虚函数：虚函数以=0结尾的函数叫做纯虚函数，含有纯虚函数的类叫做抽象类，抽象类不能实例化出对象
//被继承后只有子类重写了父类的纯虚函数，子类才能够实例化出对象，否则子类也不能实例化出对象
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


//多态实现的原理：
//如果一个类中含有虚函数，那么在他的对象成员的最前面会有一个_vfptr,叫做虚函数表指针(简称虚表指针)，_vfptr指向虚函数表
//虚函数表里面存储着虚函数的地址，通过这些虚函数的地址，就能访问到虚函数

//1.派生类对象d种也有一个虚表指针，d对象有两部分构成，一部分是父类继承下来的成员，虚表指针也就是存在部分的另一部分是自己的成员
//2.子类重写父类的虚函数，子类虚表中的函数就会变成子类的函数，所以虚函数的重写也叫做覆盖，覆盖就是指虚表中的虚函数的覆盖，重写是语法层的叫法，覆盖是原理层的叫法
//3.继承的虚函数放进虚表，不是虚函数不会放进虚表
//4.虚函数表本质是一个存放虚函数指针的指针数组，一般情况下这个数组最后面放了一个nullptr
//5.虚表指针指向虚函数表，虚函数表遍历存储了虚函数指针，虚函数表存在于代码段


//多态是运行起来后到对象中去找的
//1.静态绑定又称为前期绑定(早绑定)，在编译期间确定了重写的行为，也称为静态函数，例如：函数重载
//2.动态绑定又称作后期绑定(晚绑定)，在程序运行期间，更具拿到的类型确定函数的具体行为，调用的函数


//单继承和多继承中的虚函数表
//对象的头4个字节就是虚表的指针
//通过实验观察可知道多继承的未重写的虚函数放在第一个继承类部分的虚函数表中
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


//满足多态的条件后，构成多提：
//指针或者引用，调用虚函数时，不是在编译时确定，是运行时指向的对象中的虚表中去找对应的虚函数调用
//所以指向的父类函数对象，调用的就是父类的虚函数，指向子类就掉子类的虚函数
//
//需要注意的时，如果不构成多态，那么这里调用的时候编译器确定那个调用那个函数，主要看p的类型
//调用的时Person的BuyTciket,跟传什么没有关系
//
//
//构成多态，指向谁调用谁的虚函数，跟对象有关
//不构成多态，
//
//多态调用时必须是父类的指针或者引用调用：
//传参数会发生拷贝，如果对象调用会使得子类的虚表拷贝不过案例，找不到函数的地址，发生不了多态
//父类的指针和引用，切片时时指向或者引用子类或者子类对象中切出来的一部分
//父类对象时，
//同类型的对象，他们共享同一个虚表
//
//
//对象中的虚表指针在什么阶段初始化：构造函数初始化
//虚表在那个地方生成：虚表是在编译是就生成好了
//
//虚表里面放虚函数的指针，虚函数和普通函数一样，编译完成后，都放在代码段
//
//所有的虚函数都会放在虚表中
//
//重写是语法层的概念，覆盖是原理
//
//虚表是存在于代码段
//验证方法：取出虚表的地址(一个对象的前四个字节)与栈区，堆区，静态区，代码区进行对比
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
	printf("虚表地址:%p\n", ptr);
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