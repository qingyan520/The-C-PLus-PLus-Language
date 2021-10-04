# STL简述+string的使用与实现

## 1.STL简介

1.STL是C++标准库的重要组成部分，包含数据结构与算法框架

2.STL六大组件

![image-20210608160657007](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608160657007.png)

## String类的使用

注意：使用string类之前要包含头文件#include<string>

### 1.string类的构造函数

1.默认构造函数

```cpp
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string  s;
​	return 0;
}	
```

2.有参构造函数

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s("hello");
	return 0;
}
```

3.拷贝构造函数

```cpp
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string s1("hello");
    //调用拷贝构造函数
	string s2(s1);
	return 0;
}
```

4.隐式类型转换

这种因该是最常用的一种

```cpp
#include<string>
#include<iostream>
using namespace std;
int main()
{
    //先将hello转化为string类，然后调用拷贝构造函数
	string s1 = "hello";
	return 0;
}
```

5.初始化指定长度

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1 = "hello";
    //将s1从下标为0的位置开始连续四个字符赋值给s2
	string s2(s1, 0, 4);
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}
```

![image-20210608162421417](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608162421417.png)

如果上述例子到最后赋值的长度超过s1的总长度，则到结尾就结束，例：

![image-20210608162754638](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608162754638.png)

6.构造函数+指定长度

```cpp
//将hello前三个成员hel给s1进行拷贝构造
#include<iostream>
#include<string>
using namespace std;
int main()
{
    //将hello前三个成员hel给s1进行拷贝构造
	string s1("hello", 3);
	cout << s1 << endl;
	return 0;
}
```

7.string(n,'a')

上面这种是利用n个a进行构造

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1(3,'a');
	cout << s1 << endl;
	return 0;
}
```

![image-20210608163344397](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608163344397.png)

8.赋值初始化

```cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1 = "hello";
	string s2;
	s2 = s1;
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}
```

![image-20210608163533136](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608163533136.png)

### 2.string类的3种遍历方式

1.利用方括号进行遍历

1.在string类中重载了[]，因此也可以通过[]+下标的方式来访问

```cpp
//1.支持与数组下标一样的访问方式
#include<iostream>
using namespace std;
int main()
{
	string s1 = "hello";
    //s1.size()求s1的长度
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	return 0;
}
```

![image-20210608164132312](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608164132312.png)

2.s1.at(i)来访问

```cpp
#include<iostream>
using namespace std;
int main()
{
	string s1 = "hello";
	for (int i = 0; i < s1.size(); i++)
	{
		cout <<s1.at(i)<< " ";
	}
	cout << endl;
	return 0;
}
```

![image-20210608164400170](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608164400170.png)

这两种访问方式几乎没有什么差别，唯一的差别就是[]+下标在越界访问的时候会直接断言报错，而s1.at(i)这种访问方式在出错时会通过抛异常来报错，需要进行捕获

2.C++11的循环方式

```cpp
//基于C++11的循环遍历方式
#include<iostream>
using namespace std;
int main()
{
	string s1 = "hello";
	for (auto x : s1)
	{
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
```

auto为自动变量，自动识别每一个变量的类型，将其赋值给x，然后进行打印，如果想要改变这个元素就需要传引用

如下，将每一个元素在函数体内部进行加1，使得每一个字符加1

```cpp
#include<iostream>
using namespace std;
int main()
{
	string s1 = "hello";
	for (auto &x : s1)
	{
		x++;
		cout << x << " ";
	}
	cout << endl;
	cout<<s1 << endl;
	return 0;
}
```



![image-20210608165300276](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608165300276.png)

3.基于迭代器的遍历

```cpp
//3.基于迭代器的遍历
#include<iostream>
using namespace std;
int main()
{
	string s = "hello";
	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
```

string::iterator it=s.begin():定义初始迭代器

s.end():结束迭代器

两者构成一个左闭右开的区间：[s.begin(),s.end()）

反向迭代器：rbegin(),rend(),反向遍历整个容器

```cpp
//设置反向迭代器反向遍历整个容器
#include<iostream>
using namespace std;
int main()
{
	string s = "hello";
	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
```

![image-20210608170517683](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608170517683.png)

### 3.4种常见的迭代器

iterator

const_iterator

reverse_iterator

cosnt_reverse_iterator

### 4.string常见的插入接口

push_back(i):尾插一个字符i

append("hello"):尾插一个字符串“hello”

append(s):尾插一个对象s

append(s.begin(),s.end()):将s的[begin,end)区间数据尾插到这个对象中去

append(5,'a')：向末尾添加5个字符a

[string::append - C++ Reference (cplusplus.com)](http://cplusplus.com/reference/string/string/append/)

![image-20210608171829247](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608171829247.png)

operator+=:重载+=号，可以轻松连接两个字符或者字符串[string::operator+= - C++ Reference (cplusplus.com)](http://cplusplus.com/reference/string/string/operator+=/)

![image-20210608171911376](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608171911376.png)

intset(0,"hello"):从第0个位置开始插入字符串hello[string::insert - C++ Reference (cplusplus.com)](http://cplusplus.com/reference/string/string/insert/)



![image-20210608171944944](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608171944944.png)

### 5.常见的删除接口

s.pop_back():删除末尾元素

s.earse():删除接口[string::erase - C++ Reference (cplusplus.com)](http://cplusplus.com/reference/string/string/erase/)

![image-20210608172226802](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608172226802.png)

1.从第i个位置开始删除n个位置，最大删除到这个字符串结尾

2.删除指定字符后者字符串

3.传起始与结束位置的迭代器进行删除

### 6.string类的模拟实现

> string类的模拟实现主要包括它的构造函数，拷贝构造函数，赋值运算符重载，析构函数，三种遍历方式模拟实现，插入，删除

##### 1.构造函数

```cpp
string的拷贝构造函数采取初始化列表的方式进行书写，其中str是我们要传入的字符串，_str是我们string类里面封装的指针
//构造函数
string(const char* str = "") :
	_str(nullptr),
	_size(strlen(str)),
	_capacity(strlen(str)+1)
	{
        //如果传入的字符串不为空，就开一段新的空间，注意要比str的长度多一，然后将str拷贝到_str当中
		if (str != nullptr)
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);

		}
	}
```

##### 2.拷贝构造函数

> 深浅拷贝：如果一个类的数据里面含有指针，那么我们一定要自己写一个拷贝构造函数和赋值运算符重载，不然编译器会自动生成拷贝构造函数和赋值运算符重载进行浅拷贝，使两个对象中的指针指向同一块内存空间，这样在最终析构函数进行析构的时候会造成同一块内存空间被释放了两个，造成内存泄漏，而我们自己写一个拷贝构造函数和赋值运算符重载就不会出现深浅拷贝了

```cpp
//传统版本的拷贝构造函数和赋值运算符重载
//拷贝构造函数
string(const string& str):
	_str(nullptr),
	_size(strlen(str._str)),
	_capacity(strlen(str._str)+1)
	{
		_str = new char[strlen(str._str) + 1];
        if(_str!=nullptr)
		strcpy(_str, str._str);

	}
```



```cpp
//现代版本的拷贝构造函数：
string(const string& str):
	_str(nullptr),
	_size(strlen(str._str)),
	_capacity(_size+1)
	{
        //创建一个临时对象，调用临时对象的默认构造函数，然后交换两块指针的指向
		string temp(str._str);
		swap(_str, temp._str);
	}
```

##### 3.赋值运算符重载

```cpp
//传统写法
//赋值运算符重载
string& operator=(const string& str)
{
    //首先判断是不是自己给自己赋值
	if (&str != this)
	{
        //删除就空间
		delete []_str;
        //开辟新空间并且将数据拷贝进来(注意开空间时多开一个存储'\0')
		_str = new char[strlen(str._str) + 1];
		strcpy(_str, str._str);
        //改变size和capacity的数值
		_size = strlen(str._str);
		_capacity = _size + 1;
		}
    //返回引用，方便连续赋值
	return *this;
}
```



```cpp
//赋值运算符重载的现代写法
//现代版本的赋值运算符重载
string& operator=(const string& str)
{
    //判断是否在给自己赋值
	if (this != &str)
	{
        //和上面拷贝构造一样，创建临时对象，然后调用临时对象的默认构造函数
		string temp(str._str);
        //交换两个指针的指向
		swap(_str, temp._str);
        //更新size和capacity的值
		_size = strlen(temp._str);
		cout << strlen(temp._str) << endl;
		_capacity = _size + 1;
	}
    //返回对象的引用，方便后面连续赋值
	return *this;
}
```

##### 4.其它功能

```cpp
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

```

> 致于像push_back,pop_back之类的接口比较简单，这里就不再过多的赘述了

> 源码地址：[The-C-PLus-PLus-Language/2.C++初阶/test_7_20_string类的模拟实现 at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/2.C%2B%2B初阶/test_7_20_string类的模拟实现)

