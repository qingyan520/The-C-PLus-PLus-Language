//4.4��Ԫ
//��Ԫ����������һ�����������������һ�����е�˽�г�Ա
//��Ԫ�Ĺؼ����ǣ�friend

//4.4.1 ȫ�ֺ�������Ԫ
//#include<iostream>
//#include<string>
//using namespace std;
//class Builing
//{
//	friend void Goodbye(Builing* p);
//public:
//	Builing()
//	{
//		m_SittingRoom = "����";
//		m_Bedroom = "����";
//	}
//public:
//	string m_SittingRoom;
//private:
//	string m_Bedroom;
//};
//void Goodbye(Builing* p)
//{
//	cout << "�û������ڷ���" << p->m_SittingRoom << endl;
//	cout << "�û������ڷ���" << p->m_Bedroom << endl;
//}
//void test01()
//{
//	//�����ʹ����Ԫ������ȫ�ֺ���ֻ�ܷ�����Ĺ�����Ա�������ܷ���˽�г�Ա
//	Builing p;
//	Goodbye(&p);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.4.2  ������Ԫ
//#include<iostream>
//using namespace std;
//class
//{
//
//};
//void test01()
//{
//
//}
//int main()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}
//��ϰ
//#include<iostream>
//using namespace std;
//class person
//{
//	friend void test01(person* p);
//public:
//	void set()
//	{
//		this->ch = 'a';
//	}
//private :
//	char ch;
//};
//void test01(person*p)
//{
//	cout << p->ch << endl;
//}
//int main()
//{
//	person p;
//	test01(&p);
//	system("pause");
//	return 0;
//}

//4.4.3  ������Ԫ
//#include<iostream>
//using namespace std;
//class Building
//{
//	friend class Goodbay;
//public:
//	Building()
//	{
//		m_settingRoom = "����";
//		m_BedRoom = "����";
//	}
//	string m_settingRoom;
//private:
//	string m_BedRoom;
//};
//class Goodbay
//{
//public :
//	Building* building;
//	Goodbay()
//	{
//		building = new Building;
//	}
//	void visit()
//	{
//		cout << "�û������ڷ���:" << building->m_settingRoom << endl;
//		cout << "�û������ڷ���:" << building->m_BedRoom << endl;
//	}
//	
//};
//
//void test01()
//{
//	Goodbay gg;
//	gg.visit();
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.4.3 ��Ա��������Ԫ
//#include<iostream>
//
//using namespace std;
//class Building
//{
//	
//public:
//	friend void Goodbay  ::  visit();
//	Building()
//	{
//		SettingRoom = "����";
//		BedRoom = "����";
//	}
//	string SettingRoom;
//private:
//	string BedRoom;
//};
//class Goodbay
//{
//public:
//	Goodbay()
//	{
//		building = new Building;
//	}
//	void visit()
//	{
//		cout << "�û������ڷ��ʣ�" << building->SettingRoom << endl;
//		//cout << "�û������ڷ��ʣ�" << building->BedRoom << endl;
//	}
//	Building* building;
//
//};
//int main()
//{
//	Goodbay p;
//	p.visit();
//	system("pause");
//	return 0;
//}