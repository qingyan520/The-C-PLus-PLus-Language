//1.const修饰的成员函数
//在c++中在成员函数后面加const修饰称为const修饰的成员函数
//成员函数在被const修饰之后，其this指针指向的值就不能被修改
//实际上被修饰的是this指针，表面该类中成员不可以被修改
//思考下面问题：
//1. const对象可以调用非const成员函数吗？
// 不可以，相当于权限的放大
//2.非const对象可以调用const成员函数吗？
// 可以，权限缩小
//3.const成员函数内可以调用其它的非const成员函数吗？
// 不可以，相当于权限的放大
//4.非const成员函数内可以调用其它的const成员函数吗
//可以，相当于权限的缩小



//2.友元
//友元技术可以让类外函数访问类中的私有成员
//关键字：friend;
//分类：
//类友元
//函数友元
//友元配合左移运算符可以实现自定义数据类型的输出
//友元配合右移运算符可以实现自定义数据类型的输入
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year=0, int month =0,int day=0)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}
	friend istream& operator>>(istream& cin, Date p);

	//友元配合左移运算符可以实现自定义数据类型的输出
	friend ostream& operator<<(ostream& cout,  Date p);
private:
	int _year;
	int _month;
	int _day;
};
//友元配合右移运算符实现自定义数据类型的输入
istream& operator>>(istream& cin, Date p)
{
	cin >> p._year >> p._month >> p._year;
	return cin;
}
//友元配合左移运算符可以实现自定义数据类型的输出
ostream& operator<<(ostream& cout, Date p)
{
	cout << p._year << "-" << p._month << "-" << p._day;
	return cout;
}
int main()
{
	Date p;
	cin >> p;
	cout << p;
	return 0;
}