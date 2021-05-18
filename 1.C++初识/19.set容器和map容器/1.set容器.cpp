//set/multiset容器
//1.set容器的概念
//简介：所有元素在插入时会被自动排序
//set/multiset属于关联式容器，底层结构是用二叉树实现的
//multiset和set的区别：
//set不容许容器中有重复的元素
//multiset容许容器中有重复元素

//2.set的构造和赋值
//构造：set<T>st;
//set(const set&st);
//赋值：
//set operator=(const set &st);
//set插入数据会被自动排序，set不容许插入重复值
//#include<iostream>
//#include<set>
//using namespace std;
//void Print(set<int>& s)
//{
//	for (set<int>::iterator it = s.begin(); it != s.end();it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	set<int>s;
//	s.insert(10);//插入数据insert
//	s.insert(20);
//	s.insert(5);
//	s.insert(6);
//	s.insert(5);
//	set<int>s2(s);
//	set<int>s3;
//	s3 = s2;
//	Print(s);
//	Print(s2);
//	Print(s3);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//3.set容器的大小和交换
//统计set容器的大小及交换set容器
//函数原型
//size:返回容器中元素数目
//empty():判断容器是否为空
//swap():交换两个集合容器
//#include<set>
//#include<iostream>
//using namespace std;
//void Print(set<int>& s)
//{
//	for (set<int>::iterator it = s.begin(); it != s.end();it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	set<int>s1;
//	s1.insert(10);
//	s1.insert(20);
//	s1.insert(30);
//	s1.insert(40);
//	cout << s1.size() << endl;
//	set<int>s2;
//	s2.insert(10);
//	s2.insert(10);
//	s2.insert(30);
//	s2.insert(40);
//	cout << "交换前：" << endl;
//	Print(s1);
//	Print(s2);
//	s1.swap(s2);
//	cout << "交换后" << endl;
//	Print(s1);
//	Print(s2);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//set容器不支持重新指定大小



//4.set的插入和删除
//insert(elem);//容器中插入元素
//clear();//清楚所有元素
//erase(pos);//删除pos迭代器所指向的元素，返回下一个元素的迭代器
//erase(beg,end);//删除区间[begin,end)的所有元素，返回下一个元素的迭代器
//erase(elem);//删除容器中所有值为elem的元素
//#include<set>
//#include<iostream>
//using namespace std;
//void Print(set<int>& s)
//{
//	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	set<int>s1;
//	s1.insert(1);
//	s1.insert(2);
//	s1.insert(3);
//	s1.insert(4);
//	s1.insert(5);
//	Print(s1);
//	s1.erase(5);
//	Print(s1);
//	s1.erase(s1.begin());
//	Print(s1);
//	set<int>::iterator it = s1.begin();
//	it++;
//	s1.erase(it, s1.end());
//	Print(s1);
//	s1.clear();
//	Print(s1);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//5.set的查找和统计
//find(key);  查找元素key是否存在，若存在，返回该元素的迭代器，若不存在，返回set.end();
//count(key);  统计元素key出现的次数
//对于set容器而言，count统计结果，要么是0，要么是1
//#include<set>
//#include<iostream>
//using namespace std;
//void test01()
//{
//	set<int>s1;
//	s1.insert(1);
//	s1.insert(2);
//	s1.insert(3);
//	set<int>::iterator pos = s1.find(30);
//	if (pos != s1.end())
//	{
//		cout << *pos << endl;
//	}
//	else
//	{
//		cout << "未找到" << endl;
//	}
//	cout << s1.count(1) << endl;
//	cout << s1.count(22)<< endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//6.set容器，multset容器区别
//set容器不能插入重复元素，要是插入重复元素，只能插入一个元素
//multset容器可以插入重复元素
//#include<iostream>
//#include<set>
//using namespace std;
//void test01()
//{
//	multiset<int>m1;
//	m1.insert(10);
//	m1.insert(20);
//	m1.insert(10);
//	m1.insert(30);
//	for (multiset<int>::iterator it = m1.begin(); it != m1.end(); it++)
//	{
//		cout << *it << endl;
//	}
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//7.pair对组创建
//成对出现的数据，利用对组返回两个数据
//两种创建方式：
//pair<type,type>p(value1,value2);
//pair<type,type>p=make_pair(value1,value2);
//#include<iostream>
//#include<set>
//using namespace std;
////对组的创建
//void test01()
//{
//	pair<string, int>p("Tom", 10);
//	cout << "姓名：" << p.first << endl;
//	cout << "年龄：" << p.second << endl;
//	pair<string, int>p1= make_pair("Tom", 10);
//	cout << "姓名：" << p1.first << endl;
//	cout << "年龄：" << p1.second << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//8.set容器排序
//改变set容器的排序规则
//#include<iostream>
//#include<set>
//using namespace std;
////set存放内置数据类型
//class Compare
//{
//public:
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//};
//void Print(set<int,Compare>& s)
//{
//	for (set<int,Compare>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	set<int>s;
//	s.insert(10);
//	s.insert(40);
//	s.insert(20);
//	s.insert(50);
//	s.insert(30);
//	//Print(s);
//	set<int,Compare>s2;
//	s2.insert(10);
//	s2.insert(40);
//	s2.insert(20);
//	s2.insert(50);
//	s2.insert(30);
//	//Print(s2);
//	for (set<int, Compare>::iterator it = s2.begin(); it != s2.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//	
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//set存放内置自定义类型
//#include<iostream>
//#include<string>
//#include<set>
//using namespace std;
////自定义数据类型指定排序规则
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->age = age;
//		this->name = name;
//	}
//	int age;
//	string name;
//};
//class Compare {
//	bool operator()(const person& v1, const person& v2)
//	{
//		return v1.age > v2.age;
//	}
//};
//void test01()
//{
//	set<person,Compare>s;
//	person p1("A", 10);
//	person p2("B", 15);
//	person p3("C", 8);
//	s.insert(p1);
//	s.insert(p2);
//	s.insert(p3);
//	for (set<person, Compare>::iterator it = s.begin(); it != s.end(); it++)
//	{
//		cout <<"姓名：" << (*it).name<<endl;
//		cout << "年龄：" << (*it).age << endl;
//	}
//
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//map/multimap容器
//1.map容器的简介
//map容器中所有元素都是pair
//pair中的第一个元素为key(键值)，其索引作用，第二个元素为value（实值）
//所有元素会根据键值自动排序
//本质：
//map/multimap属于关联式容器，底层结构是二叉树
//优点：
//可以根据key值快速找到value值
//map和multimap的区别：
//map不容许容器中有重复key值元素
//mutlimap容许容器中有重复的key值元素


//2.map构造和赋值
//功能描述：
//对map容器进行构造和赋值
//构造：
//map<T1,T2>mp;  //map默认构造函数
//map<const map&mp> //拷贝构造函数
//赋值：
//map& operator=(const map &mp);
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//void Print(map<int, int>m)
//{
//	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << "key=" << (*it).first << "  " << "value=" << (*it).second << endl;
//	}
//}
//void test01()
//{
//	map<int, int>m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(3, 10));
//	m.insert(pair<int, int>(2, 30));
//	m.insert(pair<int, int>(0, 20));
//	Print(m);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//map容器中所有元素成对存在，必须使用对组


//map容器的大小和交换
//size()  //返回容器中元素数目
//empty()  //判断容器是否为空
//swap()   //交换两个集合容器
//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//void Print(map<int, int>m)
//{
//	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << "key=" << (*it).first << "  " << "value=" << (*it).second << endl;
//	}
//}
//void test01()
//{
//	map<int, int>m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int, int>(3, 10));
//	m.insert(pair<int, int>(2, 30));
//	m.insert(pair<int, int>(0, 20));
//	cout << m.size() << endl;
//	cout << m.empty() << endl;
//	Print(m);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//3.map容器的插入和删除
//insert(elem):插入元素
//clear():删除元素
//erase()://删除pos迭代器所指的元素，返回下一个迭代器
//erase(beg,end)://删除区间[beg,end)的所有元素，返回下一个元素的迭代器
//erase(key)://删除容器中值为key的元素


//4.map查找和统计
//find(key);//查找key是否存在，若存在，返回改建元素的迭代器，不存在，返回set.end()
//count(key);//统计key元素的个数  只能为0或者1
//#include<iostream>
//#include<map>
//void test01()
//{
//	map<int, int>m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int>(2, 10));
//
//}
//using namespace std;
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//6.map容器的排序
//#include<iostream>
//#include<map>
//using namespace std;
//class compare
//{
//public:
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//};
//void test01()
//{
//	map<int, int,compare>m;
//	m.insert(pair<int, int>(1, 10));
//	m.insert(pair<int,int>(2, 20));
//	m.insert(pair<int, int>(3, 30));
//	m.insert(make_pair(4, 40));
//	for (map<int, int,compare>::iterator it = m.begin(); it != m.end(); it++)
//	{
//		cout << "key=" << it->first << " " << "value=" << it->second << endl;
//	}
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//利用仿函数可以指定map容器的排序规则
//对于自定义数据类型，map必须指定排序规则，同set容器



//STL案例:员工分组
//员工信息有姓名，工资，部门有美术，策划，研发
//随机给10名员工分配部门与工资
//通过nultimap进行信息插入key(部门编号)，value，员工信息
//分部门显示员工信息

//步骤实现
//1.创建10名员工，放到vector容器，取出每名员工，进行随机分组
//分组后，将员工部门编号作为key,具体员工工作为value,放到multimap容器中去
//4.分部门显示员工信息
//#include<iostream>
//#include<map>
//#include<vector>
//#include<string>
//#include<ctime>
//using namespace std;
//#define 策划 0
//#define 美术  1
//#define  研发 2
//class person
//{
//public:
//
//	string name;
//	int salary;
//
//};
//void Creater(vector<person>&v)
//{
//	string nameseed = "ABCDEFGHIJ";
//	for (int i =0 ; i < 10; i++)
//	{
//		person p;
//		p.name = "员工";
//		p.name += nameseed[i];
//		p.salary = rand()%1000+10000;
//		v.push_back(p);
//	}
//}
////v\
//
//void setgroup(vector<person>&v,multimap<int ,person>&m)
//{
//	//产生部门随机编号
//	for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		int x = rand() % 3;
//		//将员工插入分组中
//		m.insert(pair<int, person>(x, *it));
//	}
//}
//
//void Print(multimap<int, person >& m)
//{
//	cout << "策划部门：" << endl;
//	multimap<int, person>::iterator  pos = m.find(策划);
//	int count = m.count(策划);//统计策划部门人数、
//	int index = 0;
//	for (; pos != m.end()&&index<count; index++,pos++)
//	{
//		cout << "姓名：" << (pos)->second.name << " " << "工资："<<pos->second.salary << endl;
//	}
//	cout << "美术部门：" << endl;
//	multimap<int, person>::iterator  pos1 = m.find(美术);
//	 count = m.count(美术);//统计策划部门人数、
//	 index = 0;
//	for (; pos1 != m.end() && index < count; index++, pos1++)
//	{
//		cout << "姓名：" << (pos1)->second.name << " " << "工资：" << pos1->second.salary << endl;
//	}
//
//	cout << "研发部门：" << endl;
//	multimap<int, person>::iterator  pos2 = m.find(研发);
//	count = m.count(研发);//统计策划部门人数、
//	index = 0;
//	for (; pos2 != m.end() && index < count; index++, pos2++)
//	{
//		cout << "姓名：" << (pos2)->second.name << " " << "工资：" << pos2->second.salary << endl;
//	}
//
//}
//void test01()
//{
//	vector<person>v;
//	Creater(v);
//	/*for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "姓名：" << (*it).name << " " << "年龄：" << (*it).salary << endl;
//	}*/
//	multimap<int, person>m;
//	setgroup(v, m);
//
//
//	Print(m);
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	test01();
//	system("pause");
//	return 0;
//}
