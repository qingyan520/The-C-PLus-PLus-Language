//ϵͳ�ṩ�Ŀ������캯����
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int a)
//	{
//		this->_a = a;
//	}
//	Person( Person p)
//	{
//		this->_a = p._a;
//	}
//	void Printf()
//	{
//		cout << "_a=" << this->_a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	Person P1(10);
//	P1.Printf();
//	Person P2(P1);
//	P2.Printf();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int a)
//	{
//		_a = (int*)malloc(sizeof(int) * a);
//	}
//
//	~Person()
//	{
//		if (_a != NULL)
//		{
//			free(_a);
//			_a = NULL;
//		}
//	}
//private:
//	int *_a;
//};
//int main()
//{
//	Person P1(10);
//	Person P2(P1);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person()
//	{
//
//	}
//	person(int a, int b)
//	{
//		this->m_A = a;
//		this->m_B = b;
//	}
//	//1.��Ա����ʵ��+������
//	//person operator+(person &p)
//	//{
//	//	person temp;
//	//	temp.m_A = this->m_A + p.m_A;
//	//	temp.m_B = this->m_B + p.m_B;
//	//	return temp;
//	//}
//	int m_A;
//	int m_B;
//};

//
//#include<iostream>
//using namespace std;
//class person
//{
//public :
//	person()
//	{
//
//	}
//	person(int a, int b)
//	{
//		this->m_A = a;
//		this->m_B = b;
//	}
//	person operator+(person& p)
//	{
//		person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}
//	int m_A;
//	int m_B;
//};
//
//void test01()
//{
//	person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	person p2;
//	p2.m_A = 10;
//	p2.m_B = 10;
//	person p3;
//	p3 = p1 + p2;
//	cout << "p3.m_A=" << p3.m_A << endl;
//	cout << "p3.m_B=" << p3.m_B << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class person
//{
//public:
//
//	person()
//	{
//		m_num = 0;
//	}
//	//����ǰ��++�����������������Ϊ��һֱ��һ�����ݽ��е���
//	person &operator++()
//	{
//		this->m_num++;
//		return *this;
//	}
//	//���غ���++�������int����ռλ��������������ǰ������õ���
//	//���õ�������ֵ��ǰ�õ�����������
//	person operator++(int)
//	{
//		person temp;
//		temp.m_num =this->m_num;
//		m_num++;
//		return temp;
//	}
//
//private:
//	int m_num;
//};
//
//void test01()
//{
//	person p;
//	++p;
//	cout <<  << endl;
//}
//void test02()
//{
//	person p;
//	cout <<p++ << endl;
//	cout << p << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//ʵ��ǰ�õݼ��ͺ��õݼ�
//#include<iostream>
//using namespace std;
//class person
//{
//	friend ostream& operator<<(ostream& cout, person p);
//public:
//	person()
//	{
//		m_num = 0;
//	}
//	//ǰ��--����-֮��ֱ�ӷ��ؽ���������õķ�ʽ����
//	person& operator--()
//	{
//		this->m_num--;
//		return *this;
//	}
//	//����--���ȷ���ֵ���������ֱ�ӷ���
//	//����intΪ�������أ���ֹ������ͻ
//	person operator--(int)
//	{
//		person temp = *this;//���������*this����Ȼ�ᱨ��
//		this->m_num--;
//		return temp;
//	}
//private:
//	int m_num;
//};
//ostream& operator<<(ostream& cout, person p)
//{
//	cout << p.m_num << endl;
//	return  cout;
//}
//void test01()
//{
//	person p;
//	cout << p << endl;
//	cout << --p;
//	cout << p--;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		this->m_num = 0;
//	}
//private:
//	int m_num;
//};
//int main()
//{
//	return 0;
//}
//
//bool operator==(person& p)
//	{
//		if (this->m_num!=p->m_num)
//		{
//			return true;
//		}
//		return false;
//	}

