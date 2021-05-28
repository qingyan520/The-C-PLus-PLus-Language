#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	friend ostream& operator <<(ostream& cout, const Date& p);
	friend istream& operator >>(istream& cin, Date& p);

	//���ÿ���������Ƿ�Ϸ�
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


	//���캯����ʼ������
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year < 0 || month <= 0 || month>12 || day <= 0 || day > GetMonthDay(year, month))
		{
			cout << "�Ƿ�����" << endl;
			exit(-1);
		}
		else
		{
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}
	}


	//����+=day
	Date& operator+=(int day);

	//����+day
	Date operator+(int day);

	//����-=day
	Date& operator-=(int day);

	//����-day
	Date operator-(int day);

	//ǰ��++
	Date &operator ++();

	//����++
	Date operator++(int);

	//ǰ��--
	Date& operator--();

	//����--
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

	


	//����-���ڣ������������֮��Ĳ��
	int operator-(const Date& p);
	


private:
	int _year;
	int _month;
	int _day;
};


//��Ԫ+�������������ʵ���Զ����������͵����
ostream& operator <<(ostream& cout, const Date& p);

//��Ԫ+�������������ʵ���Զ����������͵�����
istream& operator >>(istream& cin, Date& p);