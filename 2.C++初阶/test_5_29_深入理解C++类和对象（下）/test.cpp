//1.const���εĳ�Ա����
//��c++���ڳ�Ա���������const���γ�Ϊconst���εĳ�Ա����
//��Ա�����ڱ�const����֮����thisָ��ָ���ֵ�Ͳ��ܱ��޸�
//ʵ���ϱ����ε���thisָ�룬��������г�Ա�����Ա��޸�
//˼���������⣺
//1. const������Ե��÷�const��Ա������
// �����ԣ��൱��Ȩ�޵ķŴ�
//2.��const������Ե���const��Ա������
// ���ԣ�Ȩ����С
//3.const��Ա�����ڿ��Ե��������ķ�const��Ա������
// �����ԣ��൱��Ȩ�޵ķŴ�
//4.��const��Ա�����ڿ��Ե���������const��Ա������
//���ԣ��൱��Ȩ�޵���С



//2.��Ԫ
//��Ԫ�������������⺯���������е�˽�г�Ա
//�ؼ��֣�friend;
//���ࣺ
//����Ԫ
//������Ԫ
//��Ԫ����������������ʵ���Զ����������͵����
//��Ԫ����������������ʵ���Զ����������͵�����
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

	//��Ԫ����������������ʵ���Զ����������͵����
	friend ostream& operator<<(ostream& cout,  Date p);
private:
	int _year;
	int _month;
	int _day;
};
//��Ԫ������������ʵ���Զ����������͵�����
istream& operator>>(istream& cin, Date p)
{
	cin >> p._year >> p._month >> p._year;
	return cin;
}
//��Ԫ����������������ʵ���Զ����������͵����
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