//5.2
//算法介绍
//find      //查找元素
//find_if   //按条件查找元素
//adjacent_find    //查找相邻重复元素
//binary_search    //二分查找
//count     //统计元素个数
//count_if   //按条件统计元素个数


//5.2.1 find
//查找指定元素，找到返回指定元素的迭代器找不到返回迭代器end()
//函数原型：
//find(iterator beg,iterator end,value);
//beg开始迭代器
//end结束迭代器
//value 查找的元素
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	vector<int>::iterator it=find(v.begin(), v.end(), 10);
//	if (it == v.end())
//	{
//		cout << "没有该元素" << endl;
//	}
//	else
//	{
//		cout << *it << endl;
//	}
//}
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	bool operator==(const person& p)
//	{
//		if (this->age == p.age && this->name == p.name)
//		{
//			return true;
//		}
//		return false;
//	}
//	string name;
//	int age;
//};
//void test02()
//{
//	vector<person>v;
//	person p1("A", 10);
//	person p2("B", 20);
//	person p3("C", 30);
//	person p4("D", 40);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	vector<person>::iterator it=find(v.begin(), v.end(), p2);
//	if (it != v.end())
//	{
//		cout << (*it).name << endl;
//		cout << (*it).age << endl;
//	}
//}
//int main()
//{
//	test02();
//	system("pause");
//	return 0;
//}


//5.2.2 find_if
//find_if(iterator beg,iterator end ,_pred)
//按值查找元素，返回指定位置迭代器，找不到返回结束迭代器位置
//beg开始迭代器
//end结束迭代器
//——pred 函数或者谓词(返回值为bool的仿函数)
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//
//}
//int main()
//{
//
//	test01();
//	system("pause");
//	return 0;
//}