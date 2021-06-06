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

// 函数模板
//template<class T>  // Type
//template<typename T>  // 定义模板参数T可以用typename，也可以用class，都一样
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	// 下面两个调用Swap函数的地方是一个函数还是两个？
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	//Swap(a, c);
//
//	// 编译器会通过实参推形参的类型T分别为int和double
//	// 这种方式是隐式实例化
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//	cout << Add(a, (int)c) << endl;
//
//	// 不让编译器推演类型，显示指定类型
//	// 这种方式叫做显示实例化
//	cout << Add<int>(a, c) << endl;
//	cout << Add<double>(a, c) << endl;
//
//	return 0;
//}

// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//void main()
//{
//	Add(1, 2);       // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2);  // 调用编译器特化的Add版本
//}

//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//// 模板调用，有现成匹配函数，绝对不去实例化模板
//// 有更匹配的，优先匹配类型最合适的
//void main()
//{
//	Add(1, 2);     // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0);   // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

// 类模板
//typedef double VDataType;
//class vector
//{
//public:
//	//
//private:
//	VDataType* _a;
//	int _size;
//	int _capacity;
//};

//int main()
//{
//	vector v1; // int
//
//	vector v2; // double
//
//
//	return 0;
//}
//
//// 类模板
#include<iostream>
#include<assert.h>
using namespace std;
namespace zj
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_a(nullptr)
			, _size(0)
			, _capacity(0)
		{}

		// 拷贝构造和operator= 这里涉及深浅拷贝问题，还挺复杂，后面具体再讲

		~vector()
		{
			delete[] _a;
			_a = nullptr;
			_size = _capacity = 0;
		}

		void push_back(const T& x)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				T* tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T) * _size);
					delete[] _a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}

			_a[_size] = x;
			++_size;
		}

		// 读+写
		T& operator[](size_t pos);
		size_t size();
	private:
		T* _a;
		size_t _size;
		size_t _capacity;
	};

	// 模板不支持分离编译，也就是声明在.h ,定义在.cpp，原因后面再讲
	// 建议就是定义在一个文件 xxx.h  xxx.hpp
	// 在类外面定义
	template<class T>
	T& vector<T>::operator[](size_t pos)
	{
		assert(pos < _size);

		return _a[pos];
	}

	template<class T>
	size_t vector<T>::size()
	{
		return _size;
	}
}

int main()
{
	zj::vector<int> v1;		// int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	// v1.operator[](3);
	//cout << v1[3] << endl;
	//cout << v1[5] << endl;
	for (size_t i = 0; i < v1.size(); ++i)
	{
		v1[i] *= 2;
	}


	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;


	zj::vector<double> v2;   // double
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);
	v2.push_back(4.4);

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	return 0;
}