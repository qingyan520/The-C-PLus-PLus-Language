//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << __cplusplus << endl;
//	return 0;
//}


#include<iostream>
using namespace std;
class base
{
public:
	base()
	{
		cout << "父类base的构造函数" << endl;
	}
	~base()
	{
		cout << "父类base的析构函数" << endl;
	}
};
class A
{
public:
	A()
	{
		cout << "复合类A的构造函数" << endl;
	}
	~A()
	{
		cout << "复合类A的析构函数" << endl;
	}
};
class son:public base
{
public:
	son()
	{
		cout << "son的析构函数" << endl;
	}
	~son()
	{
		cout << "son的析构函数" << endl;
	}
	A a;
};
int main()
{
	son s;
	return 0;
}