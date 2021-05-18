//4.1函数对象
//1.函数对象的概念
//概念：
//1.重载函数调用操作符类，其对象常称为函数对象
//2.函数对象使用重载()时，行为类似函数调用，又叫仿函数
//本质：
//函数对象(仿函数)是一个类，不是一个函数



//2.函数对象的使用
//特点：
//函数对象在使用时，可以像普通函数一样调用，可以有参数，可以有返回值
//函数对象超出普通函数的概念，函数对象可以有自己的状态
//函数对象可以作为参数传递
//
//#include<iostream>
//using namespace std;
//class MyAdd
//{
//public:
//	int operator()(int v1, int v2)
//	{
//		return v1 + v2;
//	}
//};
// void test01()
//{
//	 MyAdd myadd;
//	 cout << myadd(1, 2) << endl;
//}
// class MyPrint
// {
// public:
//	 MyPrint()
//	 {
//		 this->count = 0;
//	 }
//	 void operator()(string test)
//	 {
//		 cout << test << endl;
//		 this->count++;
//	 }
//	 int count;
//};
// void test02()
// {
//	 MyPrint m;
//	 m("hello");
//	 cout << m.count << endl;
// }
// void doPrint(MyPrint& mp, string test)
// {
//	 mp(test);
// }
// void test03()
// {
//	 MyPrint myprint;
//	 doPrint(myprint, "hello c++");
// }
//int main()
//{
//	test03();
//	system("pause");
//	return 0;
//}

