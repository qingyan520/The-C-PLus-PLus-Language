#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	friend ostream& operator <<(ostream& cout, const Date& p);
	friend istream& operator >>(istream& cin, Date& p);

	//检查每个月天数是否合法
	inline int GetMonthDay(int year, int month)
	{
		int day[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
		int ret = day[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			ret += 1;
		}
		return ret;
	}


	//构造函数初始化日期
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 0 || month <= 0 || month>12 || day <= 0 || day > GetMonthDay(year, month))
		{
			cout << "非法日期" << endl;
			exit(-1);
		}
		else
		{
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
	}


	//日期+=day
	Date& operator+=(int day);

	//日期+day
	Date operator+(int day);

	//日期-=day
	Date& operator-=(int day);

	//日期-day
	Date operator-(int day);

	//前置++
	Date &operator ++();

	//后置++
	Date operator++(int);

	//前置--
	Date& operator--();

	//后置--
	Date operator--(int);

	//==
	bool operator==(const Date& p);

	//!=
	bool operator!=(const Date& p);

	//d1>d2
	bool operator>(const Date& p);

	//>=
	bool operator>=(const Date& p);


	//<
	bool operator<(const Date& p);

	//<=
	bool operator<=(const Date& p);

	


	//日期-日期，求出两个日期之间的差距
	int operator-(const Date& p);
	


private:
	int _year;
	int _month;
	int _day;
};


//友元+重载左移运算符实现自定义数据类型的输出
ostream& operator <<(ostream& cout, const Date& p);

//友元+重载右移运算符实现自定义数据类型的输入
istream& operator >>(istream& cin, Date& p);