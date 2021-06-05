# C++模板初阶

### 1.函数模板

1.函数模板的语法

C++支持模板这一泛性编程，提高了C++的复用性，代码的简洁度

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

但是上面这个函数只能支持两个整形数据的交换，如果要实现两个浮点数的交换，那么我们又要重载上面的Swap函数

```cpp
void Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
如
```

果要交换两个字符型变量，我们还要重载一个函数，含有很多这样的例子，比如排序，实现浮点型和int的排序
这里同样也只是类型不同而已，在C++中提出了一种解决方案：模板技术
语法：template<class T>（class也可以替换成typename）

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

![image-20210605131323308](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210605131323308.png)
