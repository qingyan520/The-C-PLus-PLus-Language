#include"Date.h"



ostream& operator <<(ostream& cout, const Date& p)
{
	cout << p._year << "-" << p._month << "-" << p._day << endl;
	return cout;
}


//�������������
istream& operator >>(istream& cin, Date& p)
{
	cin >> p._year >> p._month >> p._day;
	return cin;
}


//����+=day
Date& Date::operator+=(int day)
{
	//Ҫ�Ǽ�һ���������൱��-=
	if (day < 0)
	{
		 return *this -= -day;
	}

	else
	{
		this->_day += day;
		while (this->_day > this->GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
}


//����+day
Date Date:: operator+(int day)
{
	//������ʱ����
	Date temp(*this);
	temp += day;
	return temp;
}


Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	else
	{
		this->_day -= day;
		while (this->_day <= 0)
		{

			_month--;
			if (_month == 0)
			{
				--_year;
				_month == 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
}

//����-day
Date Date::operator-(int day)
{
	Date temp(*this);
	temp-= day;
	return temp;
}


//ǰ��++���������
Date& Date::operator++()
{
	return *this += 1;
}

//����++���������
Date Date::operator++(int)
{
	Date temp(*this);
	*this += 1;
	return temp;
}

//ǰ��--���������
Date& Date::operator--()
{
	return *this -= 1;
}

//����--���������
Date Date::operator--(int)
{
	Date temp(*this);
	*this -= 1;
	return temp;
}




//==���������
bool Date::operator==(const Date& p)
{
	return (_year == p._year) &&
		(_month == p._month) &&
		(_day == p._day);
}


//>����
bool Date::operator>(const Date& p)
{
	if (_year > p._year)
	{
		return true;
	}
	else if (_year == p._year)
	{
		if (_month > p._month)
		{
			return true;
		}
		else if (_month == p._month)
		{
			if (_day > p._day)
			{
				return true;
			}
		}
	}
	return false;
}

//!=����
bool Date::operator !=(const Date& p)
{
	return !(*this == p);
}

//>=����
bool Date::operator>=(const Date& p)
{
	return (*this > p) || (*this == p);
}


//<������
bool Date::operator<(const Date& p)
{
	return !(*this > p);
}

//<=����
bool Date::operator<=(const Date& p)
{
	return *this < p || *this == p;
}


//����-����  ������������֮��Ĳ��
int Date::operator -(const Date& p)
{
	Date Max = *this;
	Date Min = p;
	int flag= 1;
	int n = 0;
	if (*this < p)
	{
		Max = p;
		Min = *this;
		flag = -1;
	}
	while (Min != Max)
	{
		++Min;
		n++;
	}
	return n * flag;
}

