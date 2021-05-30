//1.实现日期的累加
//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	friend ostream& operator<<(ostream& cout, const Date p);
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date& operator +=(int day);
//	int GetMonthDay(int year, int month)
//	{
//		int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
//		{
//			day[month] += 1;
//		}
//		return day[month];
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//Date&Date:: operator +=(int day)
//{
//	this->_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year, _month);
//		_month++;
//		if (_month > 12)
//		{
//			_year++;
//			_month = 1;
//		}
//	}
//	return *this;
//}
//ostream& operator<<(ostream& cout, const Date p)
//{
//	cout << p._year << "-" << p._month << "-" << p._day << endl;
//	return cout;
//}
//int main()
//{
//	Date p(2021, 5, 30);
//	p += 2;
//	cout << p;
//	return 0;
//}