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


//
//#include <iostream>
//using namespace std;
//int main()
//{
//	void* p = new char[0xfffffffful];
//	//cout << "new:" << p << endl;
//	return 0;
//}


//函数重载：即在C++中容许有同名的函数
//函数重载的条件：函数的参数类型不同，返回值不同
//注：函数的返回值不能构成函数重载的条件
//例：
//#include<iostream>
//using namespace std;
//void Print(int a)
//{
//	cout << a << endl;
//}
//void Print(double a)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Print(1.0);
//	Print(1);
//	return 0;
//}
//如上述例子所述，我们要实现两个自定义打印函数，一个打印整数，一个打印浮点数，两个函数列表的参数类型不同
//而函数名却相同，但是我们在编译时却不会报错，这就是函数重载，让我们实现了打印两个不同类型打印函数
//而在C语言中我们就要起两个函数名来实现这件事，如Print_int,Print_double
//那么为什么会出现函数重载这件事呢，这就要从编译链接的过程开始说起：
//1.预处理：头文件的展开+宏替换+去掉注释+条件编译
//2.编译：检查语法，将代码转化成汇编代码
//3.汇编：汇编代码转化为二进制的机器码
//4.链接：将所有文件连接在一起，生成可执行程序
//而C++在编译过程中有函数名修饰规则:函数的返回值+函数名+函数参数类型，这样每个函数就能够进行独立识别，既不会产生命名冲突



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

//引用可以做函数返回值，引用当形参列表
//
//
//#include<iostream>
//void  Print(int a)
//{
//	cout << a << endl;
//}
//void Print(string str)
//{
//	cout << str << endl;
//}
//using namespace std;
//int main()
//{
//	Print(1);
//	Print("hello  world");
//}

//#include<iostream>
//using namespace std;
//int Ad(int a, int b)
//{
//	return a + b;
//}
//void func(int a,  double b, int* p)
//{
//
//}
//int main()
//{
//
//	return 0;
//}