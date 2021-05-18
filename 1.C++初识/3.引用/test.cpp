//1.引用的基本语法
//引用：给变量起别名
//语法：数据类型 & 别名 = 原名
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	b = 20;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	a = 30;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	system("pause");
//	return 0;
//}



//2.引用的基本语法及对数组的引用
//#include<iostream>
//using namespace std;
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//
//	//1.先定义数组类型，在通过数组类型，定义数组引用
//	typedef int(ARRAY_TYPE)[5];
//	ARRAY_TYPE& pARR = arr;
//	for ( int i = 0; i < 5; i++)
//	{
//		cout << pARR[i] << endl;
//	}
//
//	//2.先定义数组引用的类型，再通过数组引用类型，定义数组引用
//	typedef int(&ARRY_TYPE2)[5];
//	ARRY_TYPE2 pARR2 = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << pARR[i] << endl;
//	}
//
//	//3.直接定义数组引用
//	int(&pARR3)[5] = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << pARR[i] << endl;
//	}
//	system("pause");
//	return 0;
//}




//3.引用的注意事项
//引用必须初始化
//引用在初始化后不可以改变
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;//正确
//	//1.引用必须初始化
//	//int& b;错误的，引用必须初始化
//
//	//2.引用初始化后不可以更改
//	int c = 20;
//	b = c;//赋值
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//	system("pause");
//	return 0;
//}



//4.引用做函数参数
//作用：函数传参时，可以利用引用的技术让形参修饰实参
//优点：可以简化指针修饰实参
//实例：
//#include<iostream>
//using namespace std;
////交换函数
////1.址传递
//void swap1(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "swap1 a=" << a << endl;
//	cout << "swap2 b=" << b << endl;
//}
////2.地址传递
//void swap2(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
////3.引用传递
//void swap3(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//swap1(a, b);//值传递形参不会改变实参
//	//swap2(&a, &b);//地址传递形参会改变实参
//	swap3(a, b);//引用传递形参也会修饰实参
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	system("pause");
//	return 0;
//}
//总结：引用的效果和地址传递效果是一样的，引用语法更加清楚简单



//5.引用做函数返回值
//作用：引用是可以做函数返回值存在的
//注意：不要返回局部变量引用
//用法：函数调用为左值
//实例：
//#include<iostream>
//using namespace std;
////引用做函数返回值
////1.不要返回局部变量的引用
//int& test01()
//{
//	int a = 10;//局部变量在栈区中
//	return a;
//}
////2.函数的调用可以作为左值
//int& test02()
//{
//	static int a = 10;//全局变量程序运行完后由系统自动释放
//	return a;
//}
//int main()
//{
//	int &ret=test01();
//	cout << ret << endl;//第一次正确，编译器做了保留，
//	cout << ret << endl;//第二次错误，因为a的内存已经释放
//	int& ref = test02();
//	cout << "ref=" << ref << endl;
//	cout << "ref=" << ref << endl;
//	test02() = 1000;///如果函数返回值是引用，这个函数调用可以作为左值
//	cout << "ref=" << ref << endl;
//	system("pause");
//	return 0;
//}



//6.引用的本质
//本质：引用的本质在c++内部实现是一个常量指针
//int&a=b==>int* contst a=&b;
//指针指向不可以修改，但是其值可以修改
//PS：引用一旦初始化就不可以发生变化
//#include<iostream>
//using namespace std;
//void test(int& a)
//{
//	a = 100;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;//相当于int* const b=&a;
//	b = 20;//相当于*b=20
//	cout << "a=" << a<<endl;
//	cout << "b=" << b << endl;
//	test(a);
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	system("pause");
//	return 0;
//}
//总结：引用的本质就是指针常量，但是引用语法更加方便



//7.常量引用
//作用：常量引用主要用来修饰形参，防止形参修饰实参
//在函数列表中，可以加const修饰形参，防止形参修改实参
//实例：
//#include<iostream>
//using namespace std;
//void test(const int& a)
//{
//	cout << "a=" << a << endl;
//}
//int main()
//{
//	//常量引用
//	//const修饰引用，防止形参修改实参
//	//int& b = 20;//错误写法，必须指向一片内存空间
//	const int& b = 20;//编译器自己int temp=20; int &b=temp;
//	int a = 10;
//	test(a);
//	cout << "a=" << a << endl;
//	system("pause");
//	return 0;
//}