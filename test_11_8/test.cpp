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

	//����pizza��Ϣ
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

	//����pizza�۸�
	double calcCost()
	{
		if (Pizza_Size == "С")
		{
			return 10.0 + (a + b + c) * 2.0;
		}
		else if (Pizza_Size == "��")
		{
			return 12.0 + (a + b + c) * 2.0;
		}
		else
		{
			return 14.0 + (a + b + c) * 2.0;
		}
	}

private:
	string Pizza_Size;//pizza�ĳߴ�

	int a;//������������

	int b;//������㳦��������

	int c;//������������

};
int main()
{
	string size;
	cout << "Pizza��С��";
	cin >> size;

	int a;
	cout << "�������ϸ�����";
	cin >> a;

	int b;
	cout << "������㳦���ϣ�";
	cin >> b;

	int c;
	cout << "�㳦���ϣ�";
	cin >> c;

	Pizza p(size, a, b, c);
	cout << "һ��" << p.Get_Size() << "pizza�����" << p.Get_a() << "����������," << p.Get_b() << "��������㳦�����Լ�" << p.Get_c() << "�ݻ������ϵ��ܼ۸�Ϊ" << p.calcCost() << "��Ԫ" << endl;


	return 0;
}
