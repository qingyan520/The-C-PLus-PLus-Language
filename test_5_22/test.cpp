
//C++运算符重载
//==运算符重载
#include<iostream>
using namespace std;
class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}
	bool operator==(const Person& p)
	{
		return this->age == p.age;
	}
	private:
	int age;
};
int main()
{
	Person p1(10);
	Person p2(10);
	cout << (p1 == p2 )<< endl;
	return 0;
}