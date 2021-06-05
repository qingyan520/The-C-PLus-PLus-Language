# C++模板初阶

## 1.函数模板

### 1.函数模板的语法

> C++支持模板这一泛性编程，提高了C++的复用性，代码的简洁度

```cpp
看下面的例子

实现一个交换函数
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
```

> 但是上面这个函数只能支持两个整形数据的交换，如果要实现两个浮点数的交换，那么我们又要重载上面的Swap函数

```cpp
void Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
如
```

> 果要交换两个字符型变量，我们还要重载一个函数，含有很多这样的例子，比如排序，实现浮点型和int的排序
> 这里同样也只是类型不同而已，在C++中提出了一种解决方案：模板技术
> 语法：template<class T>（class也可以替换成typename）

```cpp
#include<iostream>
using namespace std;
template <class T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	float c = 1.2;
	float d = 4.2;
	Swap(a, b);
	Swap(c, d);
}
```

![image-20210604093657400](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210604093657400.png)

### 2.函数模板的实例化

> 用不同类型的参数使用函数模板时，称为函数模板的实例化。
>
> 模板参数实例化分为：隐式实例化和显式实例

> 隐式实例化：

```cpp
#include<iostream>
using namespace std;
template <class T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	float c = 1.2;
	float d = 4.2;
	//在传参数时不指定参数类型，由编译器自动推导称为隐式实例化
	Swap(a, b);
}
```

> 显示实例化：

```cpp
#include<iostream>
using namespace std;
template <class T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a = 10;
	int b = 20;
	float c = 1.2;
	float d = 4.2;
//指明模板的类型，叫做显示实例化
	Swap<int>(a, b);
}
```

### 3 模板参数的匹配原则

> 1. 一个非模板函数可以和一个同名的函数模板同时存在，而且该函数模板还可以被实例化为这个非模板
>
> 2. 对于非模板函数和同名函数模板，如果其他条件都相同，在调动时会优先调用非模板函数而不会从该模板产生出一个实例。如果模板可以产生一个具有更好匹配的函数， 那么将选择模版
> 3. 模板函数不允许自动类型转换，但普通函数可以进行自动类型

## 2.类模板

### 1.类模板的定义格式

```cpp
template<class T1, class T2, ..., class Tn>class 类模板名{ // 类内成员定义}
```

### 3.2 类模板的实例化

> 类模板实例化与函数模板实例化不同，类模板实例化需要在类模板名字后跟<>，然后将实例化的类型放在<>中即可，类模板名字不是真正的类，而实例化的结果才是真正的

```cpp
// Vector类名，Vector<int>才是类型
Vector<int> s1;
Vector<double> s
```

简单实现vector容器的插入功能

```cpp
#include<iostream>
using namespace std;
template<class T>
class vector
{
public:
	vector():
		arr(nullptr),
		_size(0),
		_capacity(0)
	{

}
~vector()
{
	delete[]arr;
	_size = 0;
	_capacity = 0;
}
void push_back(const T& x)
{
	if (_size == _capacity)
	{
		int newpacacity = _capacity == 0 ? 4 : _capacity * 2;
		T* temp = new T[newpacacity];
		if (temp)
		{
			memcpy(temp, arr, sizeof(T) * _size);
			delete[]arr;
		}
		arr = temp;
		_capacity += newpacacity;
	}
	arr[_size] = x;
	_size++;
}

private:
	T* arr;
	int _size;
	int _capacity;
};
int main()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	return 0;
}
```

