//实现一个交换函数
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//但是上面这个函数只能支持两个整形数据的交换，如果要实现两个浮点数的交换，那么我们又要重载上面的Swap函数
//void Swap(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}
//如果要交换两个字符型变量，我们还要重载一个函数，含有很多这样的例子，比如排序，实现浮点型和int的排序
//这里同样也只是类型不同而已，在C++中提出了一种解决方案：模板技术
//语法：template<class T>（class也可以替换成typename）
//#include<iostream>
//using namespace std;
//template <class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	float c = 1.2;
//	float d = 4.2;
//	Swap(a, b);
//	Swap(c, d);
//}
