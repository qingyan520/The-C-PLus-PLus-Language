//����ʽ������vector/list/deque
//����ʽ������map/set/unordered_map/unordered_set

////set
//#include<iostream>
//#include<set>
//using namespace std;
//int main()
//{
//	set<int>s;
//	s.insert(1);
//	s.insert(3);
//	s.insert(2);
//	s.insert(2);
//	s.insert(0);
//	cout << s.size() << endl;
//	//1.����+ȥ��
//	//��������һ:
//	for (auto &e : s)
//	{
//		cout << e <<" ";
//	}
//	cout << endl;
//
//	//������ʽ��:
//	set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	//��鵥��ƴд�Ƿ���ȷ
//	//�����ʿ���뵽set�У�Ȼ��Ҫ���ĵ��ʲ���set�У��жϸõ����Ƿ���set��
//	
//
//
//	//2.set��������������޸��Ѿ������ֵ
//
//	//ɾ����
//	//earse:
//	// 
//	//erase(val)
//	//erase(iterator*pos)
//	//
//
//
//	return 0;
//}


//multiset:���������ͬԪ�ص�set


//pair:��ֵ�ԣ����溬������Ԫ��
//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	map<int, int>m;
//	m.insert(pair<int,int>(1, 1));
//
//
//	//���ú���Ī���ҹ�����󣬲���Ҫ����pair�Ĳ�����Ȼ����ģ���Լ�����
//
//	m.insert(make_pair(1, 3));
//	map<int, int>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first <<" " <<it->second<< endl;
//		it++;
//	}
//}
////����ʱ��kΪ����

//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	string arr[] = { "�㽶","����", "ƻ��","����","����","�㽶" };
//	map<string, int>countMap;
//	for (auto str : arr)
//	{
//		countMap[str]++;
//	}
//	auto it = countMap.begin();
//	while (it != countMap.end())
//	{
//		cout << it->first << " " << it->second << endl;
//		it++;
//	}
//	return 0;
//}


//map�����ͳ�����⣺
//����ͳ��ˮ���Ĵ���
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<algorithm>
#include<set>
#include<functional>
using namespace std;
class Compare
{
public:
	bool operator()(pair<string, int>x, pair<string, int>y)
	{
		return x.second > y.second;
	}
};
struct Com
{
	bool operator()(map<string, int>::const_iterator &x, map<string, int>::const_iterator &y)
	{
		return x->second > y->second;
	}
};
int main()
{
	string arr[] = { "����","�㽶", "ƻ��", "ƻ��", "����", "����", "����", "�㽶", "ƻ��", "����", "����", "����", "ƻ��", "ƻ��", };
	map<string, int>m;
	for (auto str : arr)
	{
		m[str]++;
	}
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	cout << endl;

	//������ˮ�����ճ��ִ�����������
	//����һ������ֵ�Կ����������У�Ȼ������������������򣬵����������������
	vector<pair<string, int>>v;
	it = m.begin();
	while (it != m.end())
	{
		v.push_back(*it);
		++it;
	}
	sort(v.begin(), v.end(), Compare());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}
	cout << endl;
	//������:����һ�����������������Ҫ���п������˷ѿռ䣬������vector������ָ��map��ÿһ���ڵ�ĵ�������������һ��ָ�룬ռ���ڴ�ռ�С
	//Ȼ��������ָ��ָ���ֵ��������
	vector<map<string, int>::iterator>vv;
	it = m.begin();
	while (it != m.end())
	{
		vv.push_back(it);
		++it;
	}
	sort(vv.begin(), vv.end(), Com());
	for (int i = 0; i < vv.size(); i++)
	{
		cout << vv[i]->first << " " << vv[i]->second << endl;
	}
	cout << endl;

	//������:����set�����Զ�������ص㣬�������set������
	//set<map<string,int>::iterator,Com>s;
	//it = m.begin();
	//while (it != m.end())
	//{
	//	s.insert(it);
	//	it++;
	//}

	//�����ģ�mapֵ����
	map<int,string,greater<int>>_m;
	it = m.begin();
	while (it != m.end())
	{
		_m.insert(make_pair(it->second, it->first));
		++it;
	}

	auto _m_it = _m.begin();
	while (_m_it != _m.end())
	{
		cout << _m_it->first << " " << _m_it->second << endl;
		_m_it++;
	}
	cout << endl;

	//�����壺���ȼ����У���k��Ԫ�ؽ������ȼ������У�Ȼ����С�ѣ�����ұ���󣬾���ѣ���ô����������ͻ�ʣ������k��Ԫ��

	//������:����map��multimapʵ��
	it = m.begin();
	multimap<int, string, greater<int>>mm;
	while (it != m.end())
	{
		mm.insert(make_pair(it->second, it->first));
		it++;
	}
	auto _mm = mm.begin();
	while (_mm != mm.end())
	{
		cout << _mm->second << " " << _mm->first << endl;
		++_mm;
	}


	cout << endl;


	return 0;
}




//
//set/multiset����
//1.set�����ĸ���
//��飺����Ԫ���ڲ���ʱ�ᱻ�Զ�����
//set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ�ֵ�
//multiset��set������
//set���������������ظ���Ԫ��
//multiset�������������ظ�Ԫ��
//
//2.set�Ĺ���͸�ֵ
//���죺set<T>st;
//set(const set&st);
//��ֵ��
//set operator=(const set &st);
//set�������ݻᱻ�Զ�����set����������ظ�ֵ
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
//	s.insert(10);//��������insert
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
//
//3.set�����Ĵ�С�ͽ���
//ͳ��set�����Ĵ�С������set����
//����ԭ��
//size:����������Ԫ����Ŀ
//empty():�ж������Ƿ�Ϊ��
//swap():����������������
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
//	cout << "����ǰ��" << endl;
//	Print(s1);
//	Print(s2);
//	s1.swap(s2);
//	cout << "������" << endl;
//	Print(s1);
//	Print(s2);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//set������֧������ָ����С
//
//
//
//4.set�Ĳ����ɾ��
//insert(elem);//�����в���Ԫ��
//clear();//�������Ԫ��
//erase(pos);//ɾ��pos��������ָ���Ԫ�أ�������һ��Ԫ�صĵ�����
//erase(beg,end);//ɾ������[begin,end)������Ԫ�أ�������һ��Ԫ�صĵ�����
//erase(elem);//ɾ������������ֵΪelem��Ԫ��
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
//
//
//5.set�Ĳ��Һ�ͳ��
//find(key);  ����Ԫ��key�Ƿ���ڣ������ڣ����ظ�Ԫ�صĵ��������������ڣ�����set.end();
//count(key);  ͳ��Ԫ��key���ֵĴ���
//����set�������ԣ�countͳ�ƽ����Ҫô��0��Ҫô��1
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
//		cout << "δ�ҵ�" << endl;
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
//
//6.set������multset��������
//set�������ܲ����ظ�Ԫ�أ�Ҫ�ǲ����ظ�Ԫ�أ�ֻ�ܲ���һ��Ԫ��
//multset�������Բ����ظ�Ԫ��
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
//
//
//
//7.pair���鴴��
//�ɶԳ��ֵ����ݣ����ö��鷵����������
//���ִ�����ʽ��
//pair<type,type>p(value1,value2);
//pair<type,type>p=make_pair(value1,value2);
//#include<iostream>
//#include<set>
//using namespace std;
////����Ĵ���
//void test01()
//{
//	pair<string, int>p("Tom", 10);
//	cout << "������" << p.first << endl;
//	cout << "���䣺" << p.second << endl;
//	pair<string, int>p1= make_pair("Tom", 10);
//	cout << "������" << p1.first << endl;
//	cout << "���䣺" << p1.second << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//
//8.set��������
//�ı�set�������������
//#include<iostream>
//#include<set>
//using namespace std;
////set���������������
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
//
//
//set��������Զ�������
//#include<iostream>
//#include<string>
//#include<set>
//using namespace std;
////�Զ�����������ָ���������
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
//		cout <<"������" << (*it).name<<endl;
//		cout << "���䣺" << (*it).age << endl;
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
//
//
//map/multimap����
//1.map�����ļ��
//map����������Ԫ�ض���pair
//pair�еĵ�һ��Ԫ��Ϊkey(��ֵ)�����������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
//����Ԫ�ػ���ݼ�ֵ�Զ�����
//���ʣ�
//map/multimap���ڹ���ʽ�������ײ�ṹ�Ƕ�����
//�ŵ㣺
//���Ը���keyֵ�����ҵ�valueֵ
//map��multimap������
//map���������������ظ�keyֵԪ��
//mutlimap�������������ظ���keyֵԪ��
//
//
//2.map����͸�ֵ
//����������
//��map�������й���͸�ֵ
//���죺
//map<T1,T2>mp;  //mapĬ�Ϲ��캯��
//map<const map&mp> //�������캯��
//��ֵ��
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
//map����������Ԫ�سɶԴ��ڣ�����ʹ�ö���
//
//
//map�����Ĵ�С�ͽ���
//size()  //����������Ԫ����Ŀ
//empty()  //�ж������Ƿ�Ϊ��
//swap()   //����������������
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
//
//
//3.map�����Ĳ����ɾ��
//insert(elem):����Ԫ��
//clear():ɾ��Ԫ��
//erase()://ɾ��pos��������ָ��Ԫ�أ�������һ��������
//erase(beg,end)://ɾ������[beg,end)������Ԫ�أ�������һ��Ԫ�صĵ�����
//erase(key)://ɾ��������ֵΪkey��Ԫ��
//
//
//4.map���Һ�ͳ��
//find(key);//����key�Ƿ���ڣ������ڣ����ظĽ�Ԫ�صĵ������������ڣ�����set.end()
//count(key);//ͳ��keyԪ�صĸ���  ֻ��Ϊ0����1
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
//
//6.map����������
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
//���÷º�������ָ��map�������������
//�����Զ����������ͣ�map����ָ���������ͬset����
