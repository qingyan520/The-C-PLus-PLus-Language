////1.赋值运算符重载
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		
//	}
//	Person(int num)
//	{
//		this->m_num = num;
//	}
//	//1.赋值运算符重载
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			this->m_num = p.m_num;
//		}
//		return *this;
//	}
////	2.前置与后置++运算符重载
//	//前置++运算符重载
//	Person& operator++()
//	{
//		this->m_num++;
//		return *this;
//	}
//	//后置++运算符重载
//	Person operator++(int)
//	{
//		Person temp;
//		temp.m_num = this->m_num;
//		this->m_num++;
//		return temp;
//	}
//	void Print()
//	{
//		cout << this->m_num << endl;
//	}
//	int m_num;
//};
//ostream &operator<<(ostream &cout,const Person& p)
//{
//	cout << p.m_num << endl;
//	return cout;
//}
//int main()
//{
//	Person P1(10);
//	Person P2;
//	P2 = P1;
//	P2.Print();
//	P1.Print();
//	P1++;
//	P1.Print();
//	cout << (P2++) << endl;
//	cout << (P2) << endl;
//	return 0;
//}

//
////运算符重载配合友元可实现自定义数据类型的输出
////成员函数不能实现左移运算符重载
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	friend ostream& operator<<(ostream& cout, const Person& p);
//	Person(int num)
//	{
//		m_num = num;
//	}
//private:
//	int m_num;
//}; 
//ostream& operator<<(ostream& cout, const Person& p)
//{
//	cout << p.m_num << endl;
//	return cout;
//}
//int main()
//{
//	Person P1(10);
//	cout << P1 << endl;
//}


//#include<iostream>
//using namespace std;
//class
//int main()
//{
//
//	return 0;
//}
//前置++，--一般返回引用，后置++，--一般返回值；