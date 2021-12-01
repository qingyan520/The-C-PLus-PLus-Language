#include<iostream>
using namespace std;
class A
{

public:
	friend ostream&operator<<(ostream& cout, A& s);

};
ostream& operator<<(ostream& cout, A& s)
{
	return cout;
}

class B :public A
{
public:
	int a;
};


int main()
{
	B b;
	b.a = 10;
	A* p = &b;
	
}