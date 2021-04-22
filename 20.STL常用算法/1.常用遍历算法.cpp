//for_each //遍历容器
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//class Print
//{
//public:
//	void operator()(int v)
//	{
//		cout << v << endl;
//	}
//	
//};
//void Print1(int v)
//{
//	cout << v << " ";
//}
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	for_each(v.begin(), v.end(), Print1);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//必须掌握

//transform：搬运容器到另一个容器中去
//搬运必须指定容器的大小，否则会搬运失败
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class Transform
//{
//public:
//	int operator()(int v)
//	{
//		return v;
//	}
//};
//void Print(int v)
//{
//	cout << v << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	vector<int>v2;
//	v2.resize(v1.size());
//	transform(v1.begin(), v1.end(), v2.begin(),Transform());
//	for_each(v2.begin(), v2.end(), Print);
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

