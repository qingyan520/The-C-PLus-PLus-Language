//c++11�г�Ա�����ĳ�ʼ��
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//
//	void Print()
//	{
//		cout << "_a=" << _a << endl;
//		cout << "_b=" << _b << endl;
//
//	}
//private:
//	int _a = 1;
//	int _b = 1;
//
//};
//int main()
//{
//	Person p;
//	p.Print();
//	return 0;
//}



//��̬��Ա������ʹ��
#include<iostream>
using namespace std;
class Person
{
public:
	class A
	{
	public:
		int b;
	};
	static int a;

};
int Person::a = 10;
int main()
{
	cout << Person::a << endl;
}