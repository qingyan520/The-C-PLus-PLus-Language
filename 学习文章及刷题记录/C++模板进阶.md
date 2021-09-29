# C++模板进阶

## 1.非类型模板参数

```cpp
template<class T, size_t N>
class Array
{
    private:
	T arr[N];
};
```

![非类型模板](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/%E9%9D%9E%E7%B1%BB%E5%9E%8B%E6%A8%A1%E6%9D%BF.gif)

> 模板参数分为类型参数和非类型参数，如上述所述代码就是非类型模板参数
>
> 非类型参数：出现在模板的参数类表中，更在class或者typename之类的参数类型名称
>
> 非类型参数就是作为一个类(函数)的参数，在模板中该参数可以被当作常量来使用
>

> 比如库里面的Array就是使用非类型模板参数来完成的
>

![image-20210914202755252](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210914202755252.png)

> 当然，非类型模板也可以有默认的缺省值
>

```cpp
#include<iostream>
using namespace std;
namespace hello
{
	template<class T, size_t N=100>
	class Array
	{
	private:
		T arr[N];
	};
}
int main()
{
	hello::Array<int>arr;
	
	return 0;
}
```

![非类型模板_默认参数](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/%E9%9D%9E%E7%B1%BB%E5%9E%8B%E6%A8%A1%E6%9D%BF_%E9%BB%98%E8%AE%A4%E5%8F%82%E6%95%B0.gif)

> 注意：
>
> 1.浮点数，类对象以及字符串是不容许作为非类型模板参数的
>
> 2.非类型的模板参数必须在编译器就能确认结果

## 2.模板的特化

> 在某些情况下，使用模板可能会出现一些错误的结果，例如下面对两个字符串的比较
>

```cpp
//例如利用模板来比较两个字符串是否相等
#include<iostream>
using namespace std;
template<class T>
bool Is_Same(T& left, T& right)
{
	return left == right;
}
int main()
{
	int a = 10;
	int b = 10;
	cout << Is_Same<int>(a,b) << endl;//结果为1
	char str1[] = "hello";
	char str2[] = "hello";
	cout << Is_Same(str1, str2) << endl;//结果为0
	return 0;
}
```

![str的比较](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/str%E7%9A%84%E6%AF%94%E8%BE%83.gif)

> 上面程序运行时会分别打印1，0,这说明我们在比较str1和str2这两个字符串时出现了错误,为什么会出现str1和str2不相等的情况呢？
>
> 数组名是数组首元素的地址，是一个指针，在模板参数进行实例化的时候，模板参数T会被替换成一个char*类型的指针，而这两个字符数组都是位于栈区的，二者地址不相同，所以会返回false
>

> 而这种特殊情况就需要对模板进行特化，即：在原模版的基础上，针对特殊类型所进行特殊化的实现方式，分为函数模板特化和类模板特化
>

### 1.函数模板特化

> 步骤：
>
> 1.首先必须现有一个基础的函数模板
>
> 2.template后面接一对尖括号<>
>
> 3.函数名后面跟一对健康括号，尖括号内指定需要特化的类型
>
> 4.函数形参列表:必须要和函数模板的基础参数类型完全相同，如果编译器不同可能报一些奇怪的错误

> 下面，我们对上面哪个求两个字符串是否相等做一些改变：
>

```cpp
//方法一：直接重新定义一个同名函数，里面参数写出char*，当我们执行Is_Same函数时，编译器首先会在非模板函数中查找是否有能够进行匹配的，如果参数匹配直接执行该非模板函数，不匹配则在模板函数中寻找
#include<iostream>
using namespace std;
template<class T>
bool Is_Same(T& left, T& right)
{
	return left == right;
}

//重新定义一个函数判断两个字符串是否相等
bool Is_Same(char* left,char*  right)
{
	if (strcmp(left, right) == 0)
		return true;
	return false;
}
int main()
{
	int a = 10;
	int b = 10;
	cout << Is_Same<int>(a,b) << endl;
	char str1[] = "hello";
	char str2[] = "hello";
	cout << Is_Same(str1, str2) << endl;
	return 0;
}
```

![str的比较_同名函数](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/str%E7%9A%84%E6%AF%94%E8%BE%83_%E5%90%8C%E5%90%8D%E5%87%BD%E6%95%B0.gif)

```cpp
//方法二：按照上面所说的函数模板的特化重新写一个函数模板的特化
template<>
bool Is_Same<const char*const>(const char* const &left, const char* const &right)
{
	if (strcmp(left, right) == 0)
		return true;
	return false;
}
```

### 2.类模板的特化

```cpp
//最简单的类模板
template<class T1, class T2>
class A
{
private:
	T1 a;
	T2 b;
};
```

#### 1.全特化

> 全特化即将模板参数列表的所有参数都进行确定
>

```cpp
//例如：
//在A<int,int>下我们可以执行自己想要做的是
//在A<int,double>下完成另外一件事
#include<iostream>
using namespace std;
template<class T1,class T2>
class A
{
public:
	A()
	{
		cout << "A<T1,T2>" << endl;
	}
};
template<>
class A<int, int>
{
public:
	A()
	{
		cout << "A<int ,int>" << endl;
	}
};
template<>
class A<int, double>
{
public:
	A()
	{
		cout << "A<int,double>" << endl;
	}
};

int main()
{
	A<int, int>a;
	A<int, double>b;
	A<char, int>c;
	return 0;
}
```

![image-20210914213527196](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210914213527196.png)

#### 2.偏特化

> 即给定类模板一般参数

> 1.部分特化：将模板参数列表中的一部分参数进行特化

```cpp
class A<T1,int>
{
public:
	A()
	{
		cout << "A<T1,int>" << endl;
	}
};
```

> 2.参数进一步限制

> 偏特化不仅仅使之特化部分参数，而是正对模板参数更近一步的条件限制所设计出来的一个特化版本

```cpp
//两个参数偏特化为指针类型
template<class T1,class T2>
class A<T1*,T2*>
{
public:
	A()
	{
		cout << "A<T1*，T2*>" << endl;
	}
};
//两个参数偏特化为引用类型
template<class T1, class T2>
class A<T1& ,T2&>
{
public:
	A()
	{
		cout << "A<T1&,T2&>" << endl;
	}
};
//一个参数偏特化为引用，另外一个参数偏特化为指针
template<class T1,class T2>
class A<T1&,T2*>
{
public:
	A()
	{
		cout << "A<T1&,T2*>" << endl;
	}
};
```

![image-20210915085825382](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210915085825382.png)

## 3.模板的分离编译

> 1.模板的分离编译即test.h中写类模板的声明，test.cpp中写类模板的实现，main.cpp中写主要函数功能

```cpp
-------test.h---------
模板的定义


--------test.cpp-------
模板的实现



--------main.cpp--------
模板的调用
```

> 2.在书写模板类时不能采取这种方式，会出现链接错误

![image-20210915093724895](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210915093724895.png)

> 一个c/c++程序的执行大概遵守以上图片的过程，经过预处理，编译，汇编，链接，最终形成可执行程序
>
> test.h中放函数的声明，test.cpp中放函数的实现，main.c中调用函数，经过预处理，编译，汇编之后会生成test.o和main.o,当调用这个模板函数时，发现当前只有函数的声明，则回去test.o的符号表中去找，因为模板只有在实例化时才能生成对应的代码，符号表里面没有该模板函数的地址，就会出现链接错误

> 3.解决方法
>
> 1.将声明和定义放到文件"xxx.hpp"里面或者xxx.h中
>
> 2.模板定义的位置显式实例化
>
> ps:推荐直接声明与定义直接放在.h文件中

