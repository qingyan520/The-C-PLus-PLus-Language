//整体思路：先将数据进行拆分，生成年月日，然后重载-号运算符

#include<iostream>
using namespace std;
class Date
{
public:
    Date(int year = 0, int month = 0, int day = 0)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    //判断每个月的月份
    int GetMonthDay(int year, int month)
    {
        int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            day[month]++;
        }
        return day[month];
    }

    //重载>
    bool operator>(const Date& p);
    //重载<
    bool operator<(const Date& p);

    //重载++运算符
    Date& operator++();
    //重载==运算符
    bool operator==(const Date p);
    //重载！=运算符
    bool operator!=(const Date p);

    //重载-号运算符,计算天数
    int operator-(Date p);
private:
    int _year;
    int _month;
    int _day;
};
//重载>号，方便后面比较
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
    else
    {
        return false;
    }
}
//++运算符重载
Date& Date::operator++()
{
    _day += 1;
    while (_day > GetMonthDay(_year, _month))
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
//==运算符重载
bool Date::operator==(const Date p)
{
    return _year == p._year &&
        _month == p._month &&
        _day == p._day;
}
//!=运算符重载
bool Date::operator!=(const Date p)
{
    return !(*this == p);
}
//重载<
bool Date::operator<(const Date& p)
{
    return !(*this > p);
}
//重载-号计算符计算天数
int Date::operator-(Date p)
{
    Date Max = *this;
    Date Min = p;
    int flag = 1;
    if (*this<p)
    {
        Max = p;
        Min = *this;
        flag = -1;
    }
    int n = 0;
    while (Min!= Max)
    {
        ++Min;
        ++n;
    }
    return n * flag;
}
int main()
{
    //分割数据
    int a = 0, b = 0;
    while (scanf_s("%d%d", &a, &b) != EOF)
    {
        int year1 = 0, month1 = 0, day1 = 0;
        int year2 = 0, month2 = 0, day2 = 0;
        int dayflag1 = 1, monthflag1 = 1, yearfalg1 = 1;
        int dayflag2 = 1, monthflag2 = 1, yearfalg2 = 1;
        int c = 2, d = 2, f = 4;
        while (c--)
        {
            day1 += (a % 10) * dayflag1;
            dayflag1 *= 10;
            a = a / 10;
        }
        while (d--)
        {
            month1 += (a % 10) * monthflag1;
            monthflag1 *= 10;
            a = a / 10;
        }
        while (f--)
        {
            year1 += (a % 10) * yearfalg1;
            yearfalg1 *= 10;
            a = a / 10;
        }
        //求第二个数据日期
        c = 2, d = 2, f = 4;
        while (c--)
        {
            day2 += (b % 10) * dayflag2;
            dayflag2 *= 10;
            b = b / 10;
        }
        while (d--)
        {
            month2 += (b % 10) * monthflag2;
            monthflag2 *= 10;
            b = b / 10;
        }
        while (f--)
        {
            year2 += (b % 10) * yearfalg2;
            yearfalg2 *= 10;
            b= b / 10;
        }
        cout << year1 << "  " << month1 << "  " << day1 << endl;
        cout << year2 << "  " << month2 << "  " << day2 << endl;
a        Date d1(year1, month1, day1);
        Date d2(year2, month2, day2);
        cout << (d2 - d1) << endl;
    }
    return 0;
}