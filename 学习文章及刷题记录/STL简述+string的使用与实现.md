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

