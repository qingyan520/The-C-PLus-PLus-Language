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
		cout << "����base�Ĺ��캯��" << endl;
	}
	~base()
	{
		cout << "����base����������" << endl;
	}
};
class A
{
public:
	A()
	{
		cout << "������A�Ĺ��캯��" << endl;
	}
	~A()
	{
		cout << "������A����������" << endl;
	}
};
class son:public base
{
public:
	son()
	{
		cout << "son����������" << endl;
	}
	~son()
	{
		cout << "son����������" << endl;
	}
	A a;
};
int main()
{
	son s;
	return 0;
}