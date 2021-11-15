///********** BEGIN **********/
//
//#include"Int.h"
//const Int operator+(Int const& lhs, Int const& rhs)
//{
//	const Int temp;
//	temp.setValue(lhs.getValue() + rhs.getValue());
//	return temp;
//}
//
//const Int operator-(Int const& lhs, Int const& rhs)
//{
//	const Int temp;
//	temp.setValue(lhs.getValue() - rhs.getValue());
//	return temp;
//}
//
//const Int operator*(Int const& lhs, Int const& rhs)
//{
//	const Int temp;
//	temp.setValue(lhs.getValue() * rhs.getValue());
//	return temp;
//}
//
//const Int operator/(Int const& lhs, Int const& rhs)
//{
//	const Int temp;
//	temp.setValue(lhs.getValue() / rhs.getValue());
//	return temp;
//}
//
//const Int operator%(Int const& lhs, Int const& rhs)
//{
//	const Int temp;
//	temp.setValue(lhs.getValue() % rhs.getValue());
//	return temp;
//}
//
//#include"Int.h"
//
//bool Int:: operator==(Int const& rhs)
//{
//	return this->getValue() == rhs.getValue();
//}
//
//bool Int:: operator!=(Int const& rhs)
//{
//	return this->getValue() != rhs.getValue();
//}
//bool Int:: operator<(Int const& rhs)
//{
//	return this->getValue() < rhs.getValue();
//}
//bool Int:: operator<=(Int const& rhs)
//{
//	return this->getValue() <=rhs.getValue();
//}
//
//bool Int:: operator>(Int const& rhs)
//{
//	return this->getValue() >= rhs.getValue();
//}
#include<iostream>
#include<string.h>
using namespace std;
class Pizza
{
public:
	Pizza(string pizza="", int _a=0,int _b=0,int _c=0):
		Pizza_Size(pizza),
		a(_a),
		b(_b),
		c(_c)
	{

	}

	//返回pizza信息
	string Get_Size()const
	{
		return this->Pizza_Size;
	}

	int Get_a()const
	{
		return this->a;
	}

	int Get_b()const
	{
		return this->b;
	}

	int Get_c()const
	{
		return this->c;
	}

	//计算pizza价格
	double calcCost()
	{
		if (Pizza_Size == "小")
		{
			return 10.0 + (a + b + c) * 2.0;
		}
		else if (Pizza_Size == "中")
		{
			return 12.0 + (a + b + c) * 2.0;
		}
		else
		{
			return 14.0 + (a + b + c) * 2.0;
		}
	}

private:
	string Pizza_Size;//pizza的尺寸

	int a;//奶酪配料数量

	int b;//意大利香肠配料数量

	int c;//火腿数量配料

};
int main()
{
	string size;
	cout << "Pizza大小：";
	cin >> size;

	int a;
	cout << "奶酪配料个数：";
	cin >> a;

	int b;
	cout << "意大利香肠配料：";
	cin >> b;

	int c;
	cout << "香肠配料：";
	cin >> c;

	Pizza p(size, a, b, c);
	cout << "一个" << p.Get_Size() << "pizza饼外加" << p.Get_a() << "份奶酪配料," << p.Get_b() << "份意大利香肠配料以及" << p.Get_c() << "份火腿配料的总价格为" << p.calcCost() << "美元" << endl;


	return 0;
}
