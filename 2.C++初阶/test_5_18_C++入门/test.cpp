//1.C++入门
//#include<iostream>
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}
//std 是一个名称空间，里面有cout,cin
//namespace 命名空间，防止命名冲突

//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//}

//C++中输出用cout,输入用cin>>



//函数缺省：即在函数定义时为未知量赋值
//例：
//#include<iostream>
//using namespace std;
//void Print(int a = 10)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Print();
//	Print(20);
//}
//缺省分为两种：
//1.全缺省：(int a=10,int b=10,int c=0)
//2.半缺省：(int a,int b=10,int c=0)
//缺省必须是从右往左缺省，且必须是连续的


//

//函数重载：函数重载即相同的函数名执行不同的功能
//函数重载的条件，具有相同函数名的函数函数的参数类型不同或者参数个数不同，注意函数的返回值不能称为判断函数是否重载的条件
//1.为什么C语言不支持重载，C++支持重载，重载的底层是如何实现的

//2.extern"C"的作用是什么


//引用：
//引用不是重新写一个变量，而是给一个变量起别名，他和他引用的变量共同访问一块内存空间
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << a << endl;
//	cout << b << endl;
//	b = 100;
//	cout << a << endl;
//	cout << b << endl;
//	system("pause");
//	return 0;
//}



//#include<iostream>
//using namespace std;
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : array)
//		e *= 1;
//
//	for (auto e : array)
//		cout << e << " ";
//
//}
//int main()
//{
//	TestFor();
//	cout << sizeof(nullptr);
//}



#include <iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	//cout << "new:" << p << endl;
	return 0;
}