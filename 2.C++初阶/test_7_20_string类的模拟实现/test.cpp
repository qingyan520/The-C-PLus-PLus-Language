//目的：模拟实现string类
//1.构造函数
//2.拷贝构造函数
//3.赋值运算符重载
//4.析构函数
//5.三种遍历方式模拟实现
//6.插入：push_back,append,+=,reserve(增容)
//7.删除


#include<iostream>
using namespace std;
namespace hello
{
	class string
	{
	public:

		//构造函数
		string(const char* str = "") :
			_str(nullptr),
			_size(strlen(str)),
			_capacity(strlen(str)+1)
		{
			if (str != nullptr)
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);

			}
		}
		//传统版本的拷贝构造函数和赋值运算符重载
		////拷贝构造函数
		//string(const string& str):
		//	_str(nullptr),
		//	_size(strlen(str._str)),
		//	_capacity(strlen(str._str)+1)
		//{
		//	_str = new char[strlen(str._str) + 1];
		//	strcpy(_str, str._str);

		//}

		////赋值运算符重载
		//string& operator=(const string& str)

		//{
		//	if (&str != this)
		//	{
		//		delete []_str;
		//		_str = new char[strlen(str._str) + 1];
		//		strcpy(_str, str._str);
		//		_size = strlen(str._str);
		//		_capacity = _size + 1;
		//	}
		//	return *this;
		//}

		//现代版本的拷贝构造函数和赋值运算符重载：
		string(const string& str):
			_str(nullptr),
			_size(strlen(str._str)),
			_capacity(_size+1)
		{
			string temp(str._str);
			swap(_str, temp._str);
		}

		//现代版本的赋值运算符重载
		string& operator=(const string& str)
		{
			if (this != &str)
			{
				string temp(str._str);
				swap(_str, temp._str);
				_size = strlen(temp._str);
				cout << strlen(temp._str) << endl;
				_capacity = _size + 1;
			}
			return *this;
		}



		//返回数据个数
		int size()
		{
			return _size;
		}

		//返回容量
		int capacity()
		{
			return _capacity;
		}

		//析构函数
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}


		//返回C语言风格的字符串
		char* c_str()
		{
			return _str;
		}


		//string的数据部分：str用来动态申请内存空间，size记录当前元素个数，capacity用来记录容量
	private:
		char* _str;
		int _size;
		int _capacity;
	};
}

void test01()
{
	hello::string s="jeeeeeee";
	cout << s.c_str() << endl;
	hello::string s1 = "hello";
	cout << s1.c_str() << endl;
	s = s1;
	cout << s.c_str() << endl;
	cout << s1.c_str() << endl;
	cout << s.size() << endl;
	cout << s1.size() << endl;

}
int main()
{
	test01();
	return 0;
}