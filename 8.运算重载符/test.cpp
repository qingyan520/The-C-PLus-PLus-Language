//4.5���������
//�����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ��������

//4.5.1 �Ӻ����������
//���ã�ʵ�������Զ�������������ӵ�����
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
////2.ȫ�ֺ���ʵ��+������
//person operator+(person& p1, person& p2)
//{
//	person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
////3.��������ؿɷ�����������
//person operator+(person& p, int a)
//{
//	person temp;
//	temp.m_A = p.m_A + a;
//	temp.m_B = p.m_B + a;
//	return temp;
//}
//void test01()
//{
//	person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	person p2;
//	p2.m_A = 10;
//	p2.m_B = 20;
//	person p3;
//	p3 = p1 + p2;
//	//p3 = p1.operator+(p2);
//	cout << "p3.m_A=" << p3.m_A << endl;
//	cout << "p3.m_B=" << p3.m_B << endl;
//	person p4;
//	p4 = p1 + p2;
//	cout << "p4.m_A=" << p4.m_A << endl;
//	cout << "p4.m_B=" << p4.m_B << endl;
//	person p5;
//	p5 = p4 + 10;
//	cout << "p5.m_A=" << p5.m_A << endl;
//	cout << "p5.m_B=" << p5.m_B << endl;
//
//
//}
//int main()
//{
//	test01();
//	system("pause");
//
//
//	return 0;
//}
//�Ӻ����ط���ϰ
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
//	/*person operator+(person& p)
//	{
//		person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}*/
//	int m_A;
//	int m_B;
//};
//person operator+(person p1, person p2)
//{
//	person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return  temp;
//}
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
//�ܽ�1�����������������͵ı��ʽ��������ǲ����Ըı��
//�ܽ�2����Ҫ�����������ط�


//4.5.2�������������
//���ã���������Զ�����������
//��Ա�����޷�ʵ���������������
//#include<iostream>
//using namespace std;
//class person
//{
//	friend ostream& operator<<(ostream& cout, person p);
//public:
//	person(int a,int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//private:
//	int m_A;
//	int m_B;
//	
//};
//ostream &operator<<(ostream& cout, person p)
//{
//	cout << "p.m_A=" <<p.m_A <<endl<< "p.m_B=" << p.m_B << endl;
//	return cout;
//}
//void test01()
//{
//	person p(10, 10);
//	cout << p <<"hehe"<< endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//��������������Ԫ����ʵ���Զ����������͵����
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	int a;
//	int b;
//};
//ostream& operator<<(ostream& cout, person& p)
//{
//	cout << "p.a=" << p.a << endl << "p.b=" << p.b << endl;
//	return cout;
//}
//void test01()
//{
//	person p1;
//	p1.a = 10;
//	p1.b = 10;
//	cout << p1 << "hello world" << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.5.3�������������
//���������������ͱ�����֪����ν�������
//
//#include<iostream>
//using namespace std;
//class person
//{
//	friend ostream& operator<<(ostream& cout, person p);
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
//ostream& operator<<(ostream& cout, person p)
//{
//	cout << p.m_num << endl;
//	return cout;
//}
//void test01()
//{
//	person p;
//	cout << ++(++p) << endl;
//}
//void test02()
//{
//	person p;
//	cout <<p++ << endl;
//	cout << p << endl;
//}
//int main()
//{
//	test02();
//	system("pause");
//	return 0;
//}

//4.5.3.2  �ݼ����������
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
//	ǰ��--����-֮��ֱ�ӷ��ؽ���������õķ�ʽ����
//	person& operator--()
//	{
//		this->m_num--;
//		return *this;
//	}
//	����--���ȷ���ֵ���������ֱ�ӷ���
//	����intΪ�������أ���ֹ������ͻ
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



//4.5.4 ��ֵ���������
//c++���������ٸ�һ�������4������
//1.Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
//2.Ĭ����������(�޲Σ�������Ϊ��)
//3.Ĭ�Ͽ������캯��,������ֵ����
//4.��ֵ�����operator=�������Խ���ֵ����
//�������������ָ�����������ֵ����ʱ������������

//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person(int age)
//	{
//		m_age = new int(age);
//	}
//	person &operator=(person &p)
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//		m_age = new int(*p.m_age);
//		return *this;
//	}
//	~person()
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//				m_age = NULL;
//		}
//	}
//	int* m_age;
//};
//void test01()
//{
//	person p1(10);
//	person p2(20);
//	person p3(10);
//	p3=p2 =p1;
//	cout << *p1.m_age << endl;
//	cout << *p2.m_age << endl;
//	cout << *p3.m_age << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.6�߼���ϵ��������أ�==����=
//#include<iostream>
//#include<string>
//using namespace std;
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	bool operator==(person& p)
//	{
//		if (this->name == p.name && this->age == p.age)
//		{
//			return true;
//		}
//		return false;
//	}
//	bool operator!=(person& p)
//	{
//		if (this->name == p.name && this->age == p.age)
//		{
//			return false;
//		}
//		return true;
//	}
//	string name;
//
//	int age;
//
//};
//void test01()
//{
//	person p1("tom", 10);
//	person p2("qom", 10);
//	if (p1 == p2)
//	{
//		cout << "p1,p2���" << endl;
//	}
//	else
//	{
//		cout << "p1,p2�����" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1,p2�����" << endl;
//	}
//	else
//	{
//		cout << "p1,p2���" << endl;
//	}
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

