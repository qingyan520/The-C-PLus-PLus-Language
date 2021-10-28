//#include<iostream>
//using namespace std;
//namespace hello
//{
//	template<class T, size_t N=100>
//	class Array
//	{
//	private:
//		T arr[N];
//	};
//}
//int main()
//{
//	hello::Array<int>arr;
//	
//	return 0;
//}


//2.模板的特化
//例如利用模板来比较两个字符串是否相等
//#include<iostream>
//using namespace std;
//template<class T>
//bool Is_Same(T& left, T& right)
//{
//	return left == right;
//}
//
//bool Is_Same(char* left,char*  right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//	return false;
//}
//方法二：
//template<>
//bool Is_Same<const char*const>(const char* const &left, const char* const &right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//	return false;
//}
//int main()
//{
//	int a = 10;
//	int b = 10;
//	cout << Is_Same<int>(a,b) << endl;
//	char str1[] = "hello";
//	char str2[] = "hello";
//	cout << Is_Same(str1, str2) << endl;
//	return 0;
//}

//3.类模板的特化
//3.1类模板的全特化
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	/*T1 _d1;
//	T2 _d2;*/
//};
//
//// 假设针对T1 T2是 int int想做一些特殊化那么怎么办 ？ -- 类模板特化
//// -- 全特化
//template<>
//class Data < int, int >
//{
//public:
//	Data() { cout << "Data<int, int>" << endl; }
//};
//
//// 将第二个参数特化为int --偏特化
//template <class T1>
//class Data < T1, int >
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//};
//
//// 偏特化 指定如何模板参数是指针，就走我
//template <class T1, class T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//};
//
//template <class T1, class T2>
//class Data < T1&, T2& >
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//};
//
//template <class T1, class T2>
//class Data < T1&, T2* >
//{
//public:
//	Data() { cout << "Data<T1&, T2*>" << endl; }
//};
//
//// 函数模板也一样，也有全特化和偏特化
//
//int main()
//{
//	Data<int, int> d1;
//	Data<int, double> d2;
//	Data<double, int> d3;
//	Data<double*, int*> d4;
//	Data<int*, int*> d5;
//	Data<int&, int&> d6;
//	Data<int&, int*> d7;
//
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//template<class T1,class T2>
//class A
//{
//public:
//	A()
//	{
//		cout << "A<T1,T2>" << endl;
//	}
//};
//template<>
//class A<int, int>
//{
//public:
//	A()
//	{
//		cout << "A<int ,int>" << endl;
//	}
//};
//template<>
//class A<int, double>
//{
//public:
//	A()
//	{
//		cout << "A<int,double>" << endl;
//	}
//};

//模板的偏特化---将模板参数列表中所有参数列举出
//template<class T1, class T2>
//class A
//{
//public:
//	cout << "A<T1,T2>" << endl;
//};
//
//template<class T1>
//class A<T1, int>
//{
//public:
//	cout << "A<T1，int>" << endl;
//};
//
//template<class T1,class T2>
//class A<T1*, T2*>
//{
//public:
//	cout<< "A<T1*,T2*>" << endl;
//};
//
//template<class T1,class T2>
//class A<T1&, T2&>
//{
//public:
//	cout << "A<T1&,T2&>" << endl;
//};
//int main()
//{
//	//A<int,int>a;
//	A<int*, int*>b;
//	A<int&, int&>c;
//	return 0;
//}


//模板类的偏特化
#include<iostream>
using namespace std;
template<class T1,class T2>
class A
{
public:
	A()
	{
		cout << "A<T1，T2>" << endl;
	}
};
template<class T1>
class A<T1,int>
{
public:
	A()
	{
		cout << "A<T1,int>" << endl;
	}
};
//两个参数偏特化为指针类型
template<class T1,class T2>
class A<T1*,T2*>
{
public:
	A()
	{
		cout << "A<T1*，T2*>" << endl;
	}
};
//两个参数偏特化为引用类型
template<class T1, class T2>
class A<T1& ,T2&>
{
public:
	A()
	{
		cout << "A<T1&,T2&>" << endl;
	}
};
//一个参数偏特化为引用，另外一个参数偏特化为指针
template<class T1,class T2>
class A<T1&,T2*>
{
public:
	A()
	{
		cout << "A<T1&,T2*>" << endl;
	}
};
int main()
{
	A<double, int>a;
	A<int*, int*>b;
	A<int&, int&>c;
	A<int&, int*>d;
	return 0;
}