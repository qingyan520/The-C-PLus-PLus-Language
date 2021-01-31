//1.内联函数的引出—宏函数的缺点
//宏函数的缺点
//#include<iostream>
//using namespace std;
////缺陷1：需要加括号完成完整的运算
////#define my_add(x,y) x+y
////缺陷2：即使加入括号，有的情况下依然与预期效果不同
////#define a<b? a:b
//void test01()
//{
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//内联函数:即解决了宏函数的缺点，因为是普通函数，又带来了宏的优点，以空间换时间
//关键字：inline
//函数的声明与实现必需都加inline
//类内部的成员函数，都隐藏了inline
//内联函数即普通函数前面加inline
//内联函数仅仅是给编译器一个意见，不一定执行
//#include<iostream>
//using namespace std;
//int main()
//{
//	system("pause");
//	return 0;
//}



//2.函数的默认参数
//在c++中，函数的形参列表是有默认值的
//语法：返回值类型名 函数名 (参数=默认值)
//如果传入数据，就用出入参数，没有传入就用默认形参（形参=默认值）
//注意事项：1.如果某个默认位置已经有了默认参数，那么从这个位置向后，从左到右必须都必须有默认参数
//          2.如果函数声明有默认参数，函数实现就不能有默认参数
//            声明和实现只能有一个默认参数
//            例:int fun(int a=10,int b=20);
//               int fun(int a,int b);
//实例：
//#include<iostream>
//using namespace std;
//int test01(int a,int b=20,int c=30)
//{
//	return a + b + c;
//}
//int main()
//{
//	int ret=test01(10,50,60);
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}



//3.函数的占位参数
//c++的函数形参列表中容许有占位参数，用来占位，调用函数时必须填补该位置
//语法：返回值类型 函数名（数据类型）{}
//目前没啥用
//占位参数也可以有默认参数
//#include<iostream>
//using namespace std;
//void test01(int a,int=10)
//{
//	cout << "fet" << endl;
//}
//int main()
//{
//	test01(10, 20);
//	system("pause");
//	return 0;
//}



//4.函数重载
//作用：函数名相同，提高复用性
//函数重载满足的条件：
//1.同一作用域下
//2.函数名相同
//3.函数参数类型不同，个数不同或者顺序不同
//注意：函数的返回值不可以作为函数重载的条件
//示例：
//#include<iostream>
//using namespace std;
//void fun()
//{
//	cout << "hello world" << endl;
//}
//void fun(int a)
//{
//	cout << a << endl;
//}
//void fun(double a)
//{
//	cout << a << endl;
//}
////函数的返回值不能做重载条件
////int fun()
////{
////
////}
//int main()
//{
//	int a = 10;
//	double b = 3.14;
//	fun();
//	fun(a);
//	fun(b);
//	system("pause");
//	return 0;
//}



//5.函数重载的注意事项
//引用作为函数重载
//函数重载碰到函数默认参数
//#include<iostream>
//using namespace std;
////1.引用作为重载条件
//void fun(int& a)
//{
//	cout << "int &a"<<endl;
//}
//void fun()
//{
//	cout << "  " << endl;
//}
//void fun(const int& a)
//{
//	cout << "const int&a" << endl;
//}
////2.函数重载碰到函数默认参数
//void fun1(int a,int b=10)
//{
//	cout << "int a,int b=10" << endl;
//}
//void fun1(int a)
//{
//	cout << "int a" << endl;
//}
//int main()
//{
//	int a = 10;
//	const int b = 10;
//	fun(a);//无const
//	fun();
//	fun(b);//有const
//	fun1(a, b);
//	//fun1(a);//碰到默认参数时容易发生歧义
//	system("pause");
//	return 0;
//}