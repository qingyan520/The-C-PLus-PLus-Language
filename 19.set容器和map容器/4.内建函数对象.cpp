//4.3内建函数对象
//1.内建函数的定义
//概念：
//STL建立了一些函数对象
//分类：
//算术类仿函数
//关系类仿函数
//逻辑类仿函数
//用法；
//这些仿函数所产生的对象，用法和一般函数完全相同
//使用内建函数对象，需要引入头文件#include<functional>

//4.3.2算术仿函数
//功能描述
//实现四则用算
//其中negate是一元运算，其他都是二元运算
//仿函数原型：
//template<class T>T plus <T> //加法仿函数
//template<class T>T minus <T> //减法仿函数
//template<class T>T multilies <T> //乘法类仿函数
//template<class T>T divdes <T>   //除法类仿函数
//template<class T>T moduls<T>  //取模仿函数
//template<class T>T negate<T>  //取反仿函数

//#include<iostream>
//#include<functional>
//using namespace std;
////negate:取反仿函数
////plus:加法仿函数
//void test01()
//{
//	negate<int>n;
//	cout<<n(50);
//}
//void test02()
//{
//	plus<int >v;
//	cout << v(10, 20) << endl;
//}
//int main()
//{
//	test02();
//	system("pause");
//	return 0;
//}

//4.3.3关系仿函数
//函数原型：
//template<class T>bool equal_to<T>  //等于
//template<class T>bool not_equal_to<T>  //不等于
//template<class T>bool greater <T>  //大于
//template<class T>bool greater_equal<T>  //大于等于
//template<class T>bool less<T>  //小于
//template<class T>bool less_equal<T>//小于等于
//#include<iostream>
//#include<functional>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class compare
//{
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//};
//void test01()
//{
//	equal_to<int>e;
//	cout << e(10, 10) << endl;
//	not_equal_to<int>n;
//	cout << n(10, 20) << endl;
//	greater<int>g;
//	cout << g(20, 21) << endl;
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(40);
//	sort(v.begin(), v.end(),greater<int>());
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.3.4逻辑仿函数
//实现逻辑运算
//template<class T>bool logical_and<T> // 逻辑与
//template<class T>bool logical_or<T>   //逻辑或
//template<class T>bool logical_not<T>   //逻辑非
//#include<iostream>
//#include<functional>
//using namespace std;
//void test01()
//{
//	logical_and<int>l;
//	cout << l (1, 0) << endl;
//	logical_not<int>c;
//	cout << c(10) << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


