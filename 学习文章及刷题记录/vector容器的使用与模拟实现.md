# vector容器的使用与模拟实现

vector容器的构造函数及初始化

无参构造(最常见)

vector<int>v；

有参构造

vector<int>v(10,0);

迭代器构造

vector<int>v2(v.begin(),v.end());

借助另外一个容器构造

string s="hello";

vector<int>(s.begin(),s.end());

vector容器的遍历方式

for循环遍历：

```cpp
for (int i = 0; i < v.size(); i++)
{
	cout << v[i] << endl;
}
```

迭代器遍历：

```cpp
vector<int>::iterator it = v.begin();
while (it != v.end())
{
	cout << *it << endl;
	it++;
}
```

auto的范围for循环

```cpp
for (auto e :v)
	{
		cout << e << endl;
	}
```

vector容器的其它操作：

push_back()：尾插

pop_bakc():尾删；

insert(iterator,x):在迭代器位置上进行插入

erase(iterator,x)：在迭代器位置进行删除，返回下一个迭代器的位置

resize(100):将vector中的size变为100，并将里面每一个元素初始化为0

reserve(100):将vector中的capac变为100，size继续为0(capacity变大后不可以再缩小)

rbegin,rend:反向输出

vector的迭代器失效问题

1.增容导致野指针问题

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	vector<int>::iterator it = find(v.begin(), v.end(), 3);
	v.push_back(7);
	v.push_back(8);
	cout << *it << endl;
	return 0;
}
```

![image-20210729180124287](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210729180124287.png)

刚开始我们插入6个数，记录第三个数3的迭代器位置，当我们之后要进行插入可能增容，而增容需要重新开辟一块空间，然后内存拷贝，释放原来的空间，当原来的空间被释放是it的指向空间就被释放，it就变成了野指针，即迭代器失效，越界访问导致出错

```

int main()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = find(v.begin(), v.end(), 3);
	v.insert(it, 30);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

//删除3
v.erase(it);
for (auto e : v)
{
	cout << e << " ";
}
cout << endl;
return 0;

}
```

上面这段代码我们让it指向3，在它前面插入30，之后我们删除it所指位置，注意以下两点：

1.此时it已经不再指向3的位置，而是指向30这个位置，在不增容的情况下，我们这是erase(it)删除的是30

2.这里插入时存在增容问题，造成迭代器失效，在删除野指针发生错误



![image-20210729181439426](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210729181439426.png)

```cpp
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		++it;
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
```

以上代码的本意是删除所有的偶数项，但是存在迭代器失效的问题：

1    2   3   4   5   6   7

it++it

删除2之后：

1    3    4    5    6    7

​       it

it指向现在的3的位置，之后it++,到达4的位置导致3的位置没有被判断直接被忽略，要是这个位置为30，则出现了错误，这是第一个错误

在g++中当最后一个元素为奇数时，这个程序能够显示出错误的版本，而当最后一个元素为偶数是显示段错误，原因如下：

当最后一个元素为奇数时，判断一下，it指向最后一个奇数，++it，这时候it指向v.end(),程序结束

当最后一个元素为偶数时，it%==0,删除it位置的元素，it++,g++进行范围检查，发现it越界，报错

在vs中无论怎样都会报错：vs会对迭代器失效进行检查，erase(it)后vs进行检查，发现迭代器失效进行报错

修改方式如下：每次删除后重新定位迭代器

```
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it=v.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
```

![image-20210729184428430](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210729184428430.png)

迭代器失效解决方法：使用前对其进行重新赋值即可

