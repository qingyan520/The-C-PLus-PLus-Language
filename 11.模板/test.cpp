//c++另一种编程思想是泛型编程，主要利用的技术就是模板

//1.函数模板的语法
//语法：template<typename T>
//函数声明或者定义
//template声明创建模板
//typename 其后面的符号是一种数据类型，可以用class代替
//T—通用的数据类型 ，名称可以替换，通常为大写字母
//模板可以使数据类型参数化
//练习
//#include<iostream>
//using namespace std;
////利用模板实现两个数据的交换
//template<typename T>
//void Swap(T& a, T& b)
//{
//	T temp;
//	temp = a;
//	a = b;
//	b = temp;
//	
//}
//void test01()
//{
//	int a = 10;
//	int b = 20;
//	//模板的使用方法：
//	//1.自动转化法
//	//Swap(a, b);
//	//cout << "a=" << a<<endl;
//	//cout << "b=" << b << endl;
//	//2.利用<>传入数据类型
//	Swap<int>(a, b);
//	cout << "a=" << a<<endl;
//	cout << "b=" << b << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//2.函数模板注意事项
//1.自动类型推导，必须推导出一致的数据类型T才可以使用
//2.模板必须要确定出T的数据类型，才可以使用
//注：(1)在使用模板自动类型推导时，必须推导出一致的数据类型才能使用，要是数据类型不一样则无法使用
//template<class T>
//void swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//	char c = 'c';
//}
//swap(a,b)//正确
//swap(a,c)//不正确
//(2)模板必须确定数据类型才可以使用
//template<class T>
//void func()
//{
//	cout << "呵呵" << endl;
//}
////该函数模板里面没有数据类型，故无法使用自动类型推导推导出T的数据类型，我们要人为补齐T的数据类型
//func<int>();
//#include<iostream>
//using namespace std;
//int main()
//{
//	system("pause");
//	return 0;
//}

//选择排序
//选择排序：先定义一个i遍历整个数组，每次遍历时定义一个最大值为i,
//          然后j从i+1开始走，如果arr[max]<arr[j],则另max=j;
 //         如果max和最初的i不相等了，则交换arr[max]和arr[i]的位置
//#include<iostream>
//using namespace std;
//int main()
//{
//	int arr[10] = { 1,4,5,2,3,9,7,8,10,6 };
//	for (int i = 0; i < 10; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < 10; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			int temp = arr[i];
//			arr[i] = arr[max];
//			arr[max] = temp;
//		}
//	}
//	for (size_t i = 0; i <10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
//实例练习：利用模板实现对一个char 类型数组和int泪下数组的选择排序
//#include<iostream>
//using namespace std;
//template<class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//template <class T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			Swap(arr[i], arr[max]);
//		}
//	}
//}
//void test01()
//{
//	char charArr[] = "abcdef";
//	int len = sizeof(charArr) / sizeof(char);
//	mySort(charArr, len);
//	for (int i = 0; i < len; i++)
//	{
//		cout << charArr[i] << " ";
//	}
//	cout << endl;
//}
//void test02()
//{
//	int intArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	mySort(intArr, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << intArr[i]<<" ";
//	}
//	cout << endl;
//}
//int main()
//{
//	test01();
//	test02();
//	system("pause");
//	return 0;
//}

//实例练习：利用模板实现bubblesort
//#include<iostream>
//using namespace std;
//template<class T>
//void BubbleSort(T arr[], int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				T temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//void test01()
//{
//	int arr[10] = { 1,7,9,4,8,2,5,3,6,10 };
//	BubbleSort(arr, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//4.普通函数和函数模板的区别：
//普通函数在调用时可以发生自动类型转化
//函数模板调用时，如果可以利用自动类型推导，不会发生隐式类型转化
//如果利用显示指定类型的方式，可以发生隐式类型转换
//建议使用显示指定类型的方式，调用函数模板，因为自己可以确定通用类型T

//5.普通函数与函数模板的调用规则：
//1.如果普通函数和模板函数都可以实现，优先调用普通函数
//2.可以通过空模板参数列表强制调用模板函数
//3.函数模板可以发生重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板
//#include<iostream>
//using namespace std;
//template<class T>
//void Print(T a)
//{
//	cout << "函数模板的调用" << endl;
//}
//void Print(int a)
//{
//	cout << "普通函数的调用" << endl;
//}
//template<class T>
//void Print(T a, T b)
//{
//	cout << "模板函数重载的调用" << endl;
//}
//void test01()
//{
//	//1.如果普通函数和模板函数都可以实现，优先调用普通函数
//	Print(10);
//	//2.可以通过空模板参数列表强制调用模板函数
//	Print<>(10);
//	//3.函数模板可以发生重载
//	Print(10, 10);
//	char c1 = 10;
//	char c2 = 10;
//	Print(c1, c2);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//既然出现了函数模板，就不要写普通函数


//6.模板函数的局限性
//模板并不是万能的，有些特定的数据类型，需要用具体转化方式做特殊实现

//对比两个数据是否相等
//#include<iostream>
//#include<string>
//using namespace std;
//class person
//{
//public:
//	person(string name, int age)
//	{
//		this->m_name = name;
//		this->m_age = age;
//	}
//	string m_name;
//	int m_age;
//};
//template<class T>
//bool compare(T& a, T& b)
//{
//
//}
// template<> bool compare(person &a, person& b)
//{
//	 if (a.m_name == b.m_name && b.m_age == a.m_age)
//	 {
//		 return true;
//	 }
//	 return false;
//}
//void test01()
//{
//	person p1("Tom", 10);
//	person p2("Tom", 10);
//	int ret = compare(p1, p2);
//	if (ret)
//	{
//		cout << "p1==p2";
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



//类模板
//1.类模板基本语法：

//类模板与函数模板区别：
//1.类模板没有自动类型推导：只能用显示指定类型
//2.类模板在模板参数列表中可以用默认参数
#include<iostream>
using namespace std;
template<class NameType,class AgeType>
class person
{
public:
	person(NameType name, AgeType age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void show()
	{
		cout << "姓名：" << this->m_name << "  " << "年龄：" << this->m_age << endl;
	}
	NameType m_name;
	AgeType m_age;
};
void test01()
{
	person<string, int>p("Tom", 10);
	p.show();
}
int main()
{
	test01();
	system("pause");
	return 0;
}



