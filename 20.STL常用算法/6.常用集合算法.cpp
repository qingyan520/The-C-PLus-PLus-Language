//6.常用集合算法
//set_intersection  :求两个容器的交集
//set_union  求两个容器的并集
//set_difference   求两个容器的差集

//1.set_intersection
//求两个容器的交集
//注意：原容器必须是有序序列才可以求出交集
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void Print(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	//目标容器的容量取小容器的值
//	v.resize(v1.size() > v2.size() ? v2.size():v1.size());
//	//获取交集
//	vector<int>::iterator it=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
//	for_each(v1.begin(), v1.end(), Print);
//	cout << endl;
//	for_each(v2.begin(), v2.end(), Print);
//	cout << endl;
//	for_each(v.begin(), it, Print);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//set_union:求两个集合的并集
//注意:原容器必须是有序容器
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void Print(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	for (int i = 0; i < 5; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	vector<int>v3;
//	v3.resize(v1.size() + v2.size());
//	vector<int>::iterator it=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	for_each(v1.begin(), v1.end(), Print);
//	cout << endl;
//	for_each(v2.begin(), v2.end(), Print);
//	cout << endl;
//	for_each(v3.begin(), it, Print);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//set_difference:求差集
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void test01()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	v3.resize(max(v1.size(), v2.size()));
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());


}

int main()
{
	test01();
	system("pause");
	return 0;
}