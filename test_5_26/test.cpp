////1.��ֵ���������
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		
//	}
//	Person(int num)
//	{
//		this->m_num = num;
//	}
//	//1.��ֵ���������
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			this->m_num = p.m_num;
//		}
//		return *this;
//	}
////	2.ǰ�������++���������
//	//ǰ��++���������
//	Person& operator++()
//	{
//		this->m_num++;
//		return *this;
//	}
//	//����++���������
//	Person operator++(int)
//	{
//		Person temp;
//		temp.m_num = this->m_num;
//		this->m_num++;
//		return temp;
//	}
//	void Print()
//	{
//		cout << this->m_num << endl;
//	}
//	int m_num;
//};
//ostream &operator<<(ostream &cout,const Person& p)
//{
//	cout << p.m_num << endl;
//	return cout;
//}
//int main()
//{
//	Person P1(10);
//	Person P2;
//	P2 = P1;
//	P2.Print();
//	P1.Print();
//	P1++;
//	P1.Print();
//	cout << (P2++) << endl;
//	cout << (P2) << endl;
//	return 0;
//}

//
////��������������Ԫ��ʵ���Զ����������͵����
////��Ա��������ʵ���������������
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	friend ostream& operator<<(ostream& cout, const Person& p);
//	Person(int num)
//	{
//		m_num = num;
//	}
//private:
//	int m_num;
//}; 
//ostream& operator<<(ostream& cout, const Person& p)
//{
//	cout << p.m_num << endl;
//	return cout;
//}
//int main()
//{
//	Person P1(10);
//	cout << P1 << endl;
//}


//#include<iostream>
//using namespace std;
//class
//int main()
//{
//
//	return 0;
//}
//ǰ��++��--һ�㷵�����ã�����++��--һ�㷵��ֵ��