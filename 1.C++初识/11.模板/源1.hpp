#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class person
{
public:
	//��Ա������������
	person(T1 name, T2 age);
	void showperson();
	T1 m_name;
	T2 m_age;
};
//���캯������ʵ��
template<class T1,class T2>
person<T1,T2>::person(T1 name, T2 age)
{
	this->m_age = age;
	this->m_name = age;
}
template<class T1, class T2>
void person<T1, T2>::showperson()
{
	cout << "hehe" << endl;
}