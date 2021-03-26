//4.5重载用算符
//对已有的运算符重新进行定义，赋予其另一种功能，以适应不同数据类型

//4.5.1 加号运算符重载
//作用：实现两个自定义数据类型相加的运算
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person()
//	{
//
//	}
//	person(int a, int b)
//	{
//		this->m_A = a;
//		this->m_B = b;
//	}
//	//1.成员函数实现+号重载
//	//person operator+(person &p)
//	//{
//	//	person temp;
//	//	temp.m_A = this->m_A + p.m_A;
//	//	temp.m_B = this->m_B + p.m_B;
//	//	return temp;
//	//}
//	int m_A;
//	int m_B;
//};
////2.全局函数实现+号重载
//person operator+(person& p1, person& p2)
//{
//	person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
////3.运算符重载可发生函数重载
//person operator+(person& p, int a)
//{
//	person temp;
//	temp.m_A = p.m_A + a;
//	temp.m_B = p.m_B + a;
//	return temp;
//}
//void test01()
//{
//	person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	person p2;
//	p2.m_A = 10;
//	p2.m_B = 20;
//	person p3;
//	p3 = p1 + p2;
//	//p3 = p1.operator+(p2);
//	cout << "p3.m_A=" << p3.m_A << endl;
//	cout << "p3.m_B=" << p3.m_B << endl;
//	person p4;
//	p4 = p1 + p2;
//	cout << "p4.m_A=" << p4.m_A << endl;
//	cout << "p4.m_B=" << p4.m_B << endl;
//	person p5;
//	p5 = p4 + 10;
//	cout << "p5.m_A=" << p5.m_A << endl;
//	cout << "p5.m_B=" << p5.m_B << endl;
//
//
//}
//int main()
//{
//	test01();
//	system("pause");
//
//
//	return 0;
//}
//加号重载符练习
//#include<iostream>
//using namespace std;
//class person
//{
//public :
//	person()
//	{
//
//	}
//	person(int a, int b)
//	{
//		this->m_A = a;
//		this->m_B = b;
//	}
//	/*person operator+(person& p)
//	{
//		person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}*/
//	int m_A;
//	int m_B;
//};
//person operator+(person p1, person p2)
//{
//	person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return  temp;
//}
//void test01()
//{
//	person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	person p2;
//	p2.m_A = 10;
//	p2.m_B = 10;
//	person p3;
//	p3 = p1 + p2;
//	cout << "p3.m_A=" << p3.m_A << endl;
//	cout << "p3.m_B=" << p3.m_B << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//总结1：对于内置数据类型的表达式的运算符是不可以改变的
//总结2：不要滥用运算重载符


//4.5.2左移运算符重载
//作用：可以输出自定义数据类型
//成员函数无法实现左移运算符重载
//#include<iostream>
//using namespace std;
//class person
//{
//	friend ostream& operator<<(ostream& cout, person p);
//public:
//	person(int a,int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//private:
//	int m_A;
//	int m_B;
//	
//};
//ostream &operator<<(ostream& cout, person p)
//{
//	cout << "p.m_A=" <<p.m_A <<endl<< "p.m_B=" << p.m_B << endl;
//	return cout;
//}
//void test01()
//{
//	person p(10, 10);
//	cout << p <<"hehe"<< endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//左移运算符配合友元可以实现自定义数据类型的输出
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	int a;
//	int b;
//};
//ostream& operator<<(ostream& cout, person& p)
//{
//	cout << "p.a=" << p.a << endl << "p.b=" << p.b << endl;
//	return cout;
//}
//void test01()
//{
//	person p1;
//	p1.a = 10;
//	p1.b = 10;
//	cout << p1 << "hello world" << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.5.3递增运算符重载
//对于内置数据类型编译器知道如何进行运算
//
//#include<iostream>
//using namespace std;
//class person
//{
//	friend ostream& operator<<(ostream& cout, person p);
//public:
//
//	person()
//	{
//		m_num = 0;
//	}
//	//重载前置++运算符，返回引用是为了一直对一个数据进行递增
//	person &operator++()
//	{
//		this->m_num++;
//		return *this;
//	}
//	//重载后置++运算符，int代表占位参数，用来区分前置与后置递增
//	//后置递增返回值，前置递增返回引用
//	person operator++(int)
//	{
//		person temp;
//		temp.m_num =this->m_num;
//		m_num++;
//		return temp;
//	}
//
//private:
//	int m_num;
//};
//ostream& operator<<(ostream& cout, person p)
//{
//	cout << p.m_num << endl;
//	return cout;
//}
//void test01()
//{
//	person p;
//	cout << ++(++p) << endl;
//}
//void test02()
//{
//	person p;
//	cout <<p++ << endl;
//	cout << p << endl;
//}
//int main()
//{
//	test02();
//	system("pause");
//	return 0;
//}

//4.5.3.2  递减运算符重载
//实现前置递减和后置递减
//#include<iostream>
//using namespace std;
//class person
//{
//	friend ostream& operator<<(ostream& cout, person p);
//public:
//	person()
//	{
//		m_num = 0;
//	}
//	前置--，先-之后直接返回结果，用引用的方式返回
//	person& operator--()
//	{
//		this->m_num--;
//		return *this;
//	}
//	后置--，先返回值，后减减，直接返回
//	其中int为函数重载，防止命名冲突
//	person operator--(int)
//	{
//		person temp = *this;//这里必须是*this，不然会报错
//		this->m_num--;
//		return temp;
//	}
//private:
//	int m_num;
//};
//ostream& operator<<(ostream& cout, person p)
//{
//	cout << p.m_num << endl;
//	return  cout;
//}
//void test01()
//{
//	person p;
//	cout << p << endl;
//	cout << --p;
//	cout << p--;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//4.5.4 赋值运算符重载
//c++编译器至少给一个类添加4个函数
//1.默认构造函数(无参，函数体为空)
//2.默认析构函数(无参，函数题为空)
//3.默认拷贝构造函数,对属性值拷贝
//4.赋值运算符operator=，对属性进行值拷贝
//如果类中有属性指向堆区，做赋值操作时会出现深拷贝问题

//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person(int age)
//	{
//		m_age = new int(age);
//	}
//	person &operator=(person &p)
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//		m_age = new int(*p.m_age);
//		return *this;
//	}
//	~person()
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//				m_age = NULL;
//		}
//	}
//	int* m_age;
//};
//void test01()
//{
//	person p1(10);
//	person p2(20);
//	person p3(10);
//	p3=p2 =p1;
//	cout << *p1.m_age << endl;
//	cout << *p2.m_age << endl;
//	cout << *p3.m_age << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.6逻辑关系运算符重载：==，！=
//#include<iostream>
//#include<string>
//using namespace std;
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	bool operator==(person& p)
//	{
//		if (this->name == p.name && this->age == p.age)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool operator!=(person& p)
//	{
//		if (this->name == p.name && this->age == p.age)
//		{
//			return false;
//		}
//		return true;
//	}
//	string name;
//
//	int age;
//
//};
//void test01()
//{
//	person p1("tom", 10);
//	person p2("qom", 10);
//	if (p1 == p2)
//	{
//		cout << "p1,p2相等" << endl;
//	}
//	else
//	{
//		cout << "p1,p2不相等" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1,p2不相等" << endl;
//	}
//	else
//	{
//		cout << "p1,p2相等" << endl;
//	}
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

