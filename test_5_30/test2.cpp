//����˼·���Ƚ����ݽ��в�֣����������գ�Ȼ������-�������

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

    //�ж�ÿ���µ��·�
    int GetMonthDay(int year, int month)
    {
        int day[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            day[month]++;
        }
        return day[month];
    }

    //����>
    bool operator>(const Date& p);
    //����<
    bool operator<(const Date& p);

    //����++�����
    Date& operator++();
    //����==�����
    bool operator==(const Date p);
    //���أ�=�����
    bool operator!=(const Date p);

    //����-�������,��������
    int operator-(Date p);
private:
    int _year;
    int _month;
    int _day;
};
//����>�ţ��������Ƚ�
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
//++���������
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
//==���������
bool Date::operator==(const Date p)
{
    return _year == p._year &&
        _month == p._month &&
        _day == p._day;
}
//!=���������
bool Date::operator!=(const Date p)
{
    return !(*this == p);
}
//����<
bool Date::operator<(const Date& p)
{
    return !(*this > p);
}
//����-�ż������������
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
    //�ָ�����
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
        //��ڶ�����������
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