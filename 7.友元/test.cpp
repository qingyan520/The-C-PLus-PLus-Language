//4.4友元
//友元的作用是让一个函数或者类访问另一个类中的私有成员
//友元的关键字是：friend

//4.4.1 全局函数做友元
//#include<iostream>
//#include<string>
//using namespace std;
//class Builing
//{
//	friend void Goodbye(Builing* p);
//public:
//	Builing()
//	{
//		m_SittingRoom = "客厅";
//		m_Bedroom = "卧室";
//	}
//public:
//	string m_SittingRoom;
//private:
//	string m_Bedroom;
//};
//void Goodbye(Builing* p)
//{
//	cout << "好基友正在访问" << p->m_SittingRoom << endl;
//	cout << "好基友正在访问" << p->m_Bedroom << endl;
//}
//void test01()
//{
//	//如果不使用友元技术，全局函数只能访问类的公共成员，而不能访问私有成员
//	Builing p;
//	Goodbye(&p);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.4.2  类做友元
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
//练习
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

//4.4.3  类做友元
//#include<iostream>
//using namespace std;
//class Building
//{
//	friend class Goodbay;
//public:
//	Building()
//	{
//		m_settingRoom = "客厅";
//		m_BedRoom = "卧室";
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
//		cout << "好基友正在访问:" << building->m_settingRoom << endl;
//		cout << "好基友正在访问:" << building->m_BedRoom << endl;
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

//4.4.3 成员函数做友元
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
//		SettingRoom = "客厅";
//		BedRoom = "卧室";
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
//		cout << "好基友正在访问：" << building->SettingRoom << endl;
//		//cout << "好基友正在访问：" << building->BedRoom << endl;
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