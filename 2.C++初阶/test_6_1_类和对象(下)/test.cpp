//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)
//	{
//		_a = a;
//	}
//	int _a;
//};
//class Person
//{
//public:
//	Person(int i=10,int p=10):
//		_a(10),
//		_i(i),
//		_p(p)
//	{
//		
//	}
//		
//	A _a;
//	const int _i;
//	int& _p;
//};
//int main()
//{
//	return 0;
//}

//
//
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int a = 1) :
//		_a1(a),
//		_a2(_a1)
//	{
//
//	}
//	void Print()
//	{
//		cout << "_a1=" << _a1 << " " << "_a2=" << _a2 << endl;
//	}
//	int _a2;
//	int _a1;
//};
//int main()
//{
//	Person p;
//	p.Print();
//	return 0;
//}



//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	friend ostream& operator<<(ostream &cout, const Person p);
//	Person(int a = 0)
//	{
//		_a = a;
//	}
//private:
//	int _a;
//};
//ostream& operator<<(ostream &cout, const Person p)
//{
//	cout << p._a;
//	return cout;
//
//}
//int main()
//{
//	Person p;
//	cout << p;
//	return 0;
//}


#include<iostream>
using namespace std;
class A
{
	friend class Person;
	A(int a)
	{
		_a = a;
	}
private:
	int _a;

};
class Person
{
public:

	Person(int a = 0)
	{
		_a = a;

	}
	
private:
	int _a;
	A a;
};

int main()
{
	Person p;
	cout << p;
	return 0;
}