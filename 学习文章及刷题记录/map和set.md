# set和map

## set/multiset容器

### 1.set容器的概念

> 简介：所有元素在插入时会被自动排序
> set/multiset属于关联式容器，底层结构是用二叉树实现的
> multiset和set的区别：
> set不容许容器中有重复的元素
> multiset容许容器中有重复元素

### 2.set的构造和赋值

> 构造：set<T>st;
> set(const set&st);
> 赋值：
> set operator=(const set &st);
> set插入数据会被自动排序，set不容许插入重复值

```cpp
#include<iostream>
#include<set>
using namespace std;
void Print(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s;
	s.insert(10);//插入数据insert
	s.insert(20);
	s.insert(5);
	s.insert(6);
	s.insert(5);
	set<int>s2(s);
	set<int>s3;
	s3 = s2;
	Print(s);
	Print(s2);
	Print(s3);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```



### 3.set容器的大小和交换

> 统计set容器的大小及交换set容器
> 函数原型
> size:返回容器中元素数目
> empty():判断容器是否为空
> swap():交换两个集合容器

```cpp
#include<set>
#include<iostream>
using namespace std;
void Print(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);
	cout << s1.size() << endl;
	set<int>s2;
	s2.insert(10);
	s2.insert(10);
	s2.insert(30);
	s2.insert(40);
	cout << "交换前：" << endl;
	Print(s1);
	Print(s2);
	s1.swap(s2);
	cout << "交换后" << endl;
	Print(s1);
	Print(s2);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
set容器不支持重新指定大小
```

> set容器不支持重新指定大小
>

### 4.set的插入和删除

> insert(elem);//容器中插入元素
> clear();//清楚所有元素
> erase(pos);//删除pos迭代器所指向的元素，返回下一个元素的迭代器
> erase(beg,end);//删除区间[begin,end)的所有元素，返回下一个元素的迭代器
> erase(elem);//删除容器中所有值为elem的元素

```cpp
#include<set>
#include<iostream>
using namespace std;
void Print(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);
	Print(s1);
	s1.erase(5);
	Print(s1);
	s1.erase(s1.begin());
	Print(s1);
	set<int>::iterator it = s1.begin();
	it++;
	s1.erase(it, s1.end());
	Print(s1);
	s1.clear();
	Print(s1);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```



### 5.set的查找和统计

> find(key);  查找元素key是否存在，若存在，返回该元素的迭代器，若不存在，返回set.end();
> count(key);  统计元素key出现的次数
> 对于set容器而言，count统计结果，要么是0，要么是1

```cpp
#include<set>
#include<iostream>
using namespace std;
void test01()
{
	set<int>s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	cout << s1.count(1) << endl;
	cout << s1.count(22)<< endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```



### 6.set容器，multset容器区别

> set容器不能插入重复元素，要是插入重复元素，只能插入一个元素
> multset容器可以插入重复元素

```cpp
#include<iostream>
#include<set>
using namespace std;
void test01()
{
	multiset<int>m1;
	m1.insert(10);
	m1.insert(20);
	m1.insert(10);
	m1.insert(30);
	for (multiset<int>::iterator it = m1.begin(); it != m1.end(); it++)
	{
		cout << *it << endl;
	}

}
int main()
{
	test01();
	system("pause");
	return 0;
}


```



### 7.pair对组创建

> 成对出现的数据，利用对组返回两个数据
> 两种创建方式：

```cpp
pair<type,type>p(value1,value2);
pair<type,type>p=make_pair(value1,value2);
```



```cpp

#include<iostream>
#include<set>
using namespace std;
//对组的创建
void test01()
{
	pair<string, int>p("Tom", 10);
	cout << "姓名：" << p.first << endl;
	cout << "年龄：" << p.second << endl;
	pair<string, int>p1= make_pair("Tom", 10);
	cout << "姓名：" << p1.first << endl;
	cout << "年龄：" << p1.second << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```



### 8.set容器排序

> 改变set容器的排序规则

```cpp
#include<iostream>
#include<set>
using namespace std;
//set存放内置数据类型
class Compare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void Print(set<int,Compare>& s)
{
	for (set<int,Compare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	set<int>s;
	s.insert(10);
	s.insert(40);
	s.insert(20);
	s.insert(50);
	s.insert(30);
	//Print(s);
	set<int,Compare>s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(50);
	s2.insert(30);
	//Print(s2);
	for (set<int, Compare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```

> set存放内置自定义类型

```cpp
#include<iostream>
#include<string>
#include<set>
using namespace std;
//自定义数据类型指定排序规则
class person
{
public:
	person(string name, int age)
	{
		this->age = age;
		this->name = name;
	}
	int age;
	string name;
};
class Compare {
	bool operator()(const person& v1, const person& v2)
	{
		return v1.age > v2.age;
	}
};
void test01()
{
	set<person,Compare>s;
	person p1("A", 10);
	person p2("B", 15);
	person p3("C", 8);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	for (set<person, Compare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout <<"姓名：" << (*it).name<<endl;
		cout << "年龄：" << (*it).age << endl;
	}


}
int main()
{
	test01();
	system("pause");
	return 0;
}
```



## map/multimap容器

### 1.map容器的简介

> map容器中所有元素都是pair
> pair中的第一个元素为key(键值)，其索引作用，第二个元素为value（实值）
> 所有元素会根据键值自动排序
> 本质：
> map/multimap属于关联式容器，底层结构是二叉树
> 优点：
> 可以根据key值快速找到value值
> map和multimap的区别：
> map不容许容器中有重复key值元素
> mutlimap容许容器中有重复的key值元素

### 2.map构造和赋值

> 功能描述：
> 对map容器进行构造和赋值
> 构造：
> map<T1,T2>mp;  //map默认构造函数
> map<const map&mp> //拷贝构造函数
> 赋值：
> map& operator=(const map &mp);

```cpp
#include<iostream>
#include<string>
#include<map>
using namespace std;
void Print(map<int, int>m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << (*it).first << "  " << "value=" << (*it).second << endl;
	}
}
void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 10));
	m.insert(pair<int, int>(2, 30));
	m.insert(pair<int, int>(0, 20));
	Print(m);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```

> map容器中所有元素成对存在，必须使用对组
>
> map容器的大小和交换
> size()  //返回容器中元素数目
> empty()  //判断容器是否为空
> swap()   //交换两个集合容器

```cpp
#include<iostream>
#include<string>
#include<map>
using namespace std;
void Print(map<int, int>m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << (*it).first << "  " << "value=" << (*it).second << endl;
	}
}
void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 10));
	m.insert(pair<int, int>(2, 30));
	m.insert(pair<int, int>(0, 20));
	cout << m.size() << endl;
	cout << m.empty() << endl;
	Print(m);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```



### 3.map容器的插入和删除

> insert(elem):插入元素
> clear():删除元素
> erase()://删除pos迭代器所指的元素，返回下一个迭代器
> erase(beg,end)://删除区间[beg,end)的所有元素，返回下一个元素的迭代器
> erase(key)://删除容器中值为key的元素

### 4.map查找和统计

> find(key);//查找key是否存在，若存在，返回改建元素的迭代器，不存在，返回set.end()
> count(key);//统计key元素的个数  只能为0或者1

```cpp
#include<iostream>
#include<map>
void test01()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int>(2, 10));

}
using namespace std;
int main()
{
	test01();
	system("pause");
	return 0;
}

6.map容器的排序
#include<iostream>
#include<map>
using namespace std;
class compare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test01()
{
	map<int, int,compare>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int,int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(make_pair(4, 40));
	for (map<int, int,compare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << " " << "value=" << it->second << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}
```

> 利用仿函数可以指定map容器的排序规则
> 对于自定义数据类型，map必须指定排序规则，同set容器

### 5.map容器根据value排序



```cpp
#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<algorithm>
#include<set>
#include<functional>
using namespace std;
class Compare
{
public:
	bool operator()(pair<string, int>x, pair<string, int>y)
	{
		return x.second > y.second;
	}
};
struct Com
{
	bool operator()(map<string, int>::const_iterator &x, map<string, int>::const_iterator &y)
	{
		return x->second > y->second;
	}
};
int main()
{
	string arr[] = { "西瓜","香蕉", "苹果", "苹果", "西瓜", "西瓜", "西瓜", "香蕉", "苹果", "榴莲", "西瓜", "西瓜", "苹果", "苹果", };
	map<string, int>m;
	for (auto str : arr)
	{
		m[str]++;
	}
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	cout << endl;

	//将几种水果按照出现次数进行排序：
	//方法一：将键值对拷贝进数组中，然后按照数组排序进行排序，但是这样会产生拷贝
	vector<pair<string, int>>v;
	it = m.begin();
	while (it != m.end())
	{
		v.push_back(*it);
		++it;
	}
	sort(v.begin(), v.end(), Compare());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}
	cout << endl;
	//方法二:方法一存在最大的问题就是需要进行拷贝，浪费空间，我们让vector数组存放指向map中每一个节点的迭代器，本质是一个指针，占用内存空间小
	//然后根据这个指针指向的值进行排序
	vector<map<string, int>::iterator>vv;
	it = m.begin();
	while (it != m.end())
	{
		vv.push_back(it);
		++it;
	}
	sort(vv.begin(), vv.end(), Com());
	for (int i = 0; i < vv.size(); i++)
	{
		cout << vv[i]->first << " " << vv[i]->second << endl;
	}
	cout << endl;

	//方法三:利用set容器自动排序的特点，将其放入set容器中
	//set<map<string,int>::iterator,Com>s;
	//it = m.begin();
	//while (it != m.end())
	//{
	//	s.insert(it);
	//	it++;
	//}

	//方法四：map值拷贝
	map<int,string,greater<int>>_m;
	it = m.begin();
	while (it != m.end())
	{
		_m.insert(make_pair(it->second, it->first));
		++it;
	}

	auto _m_it = _m.begin();
	while (_m_it != _m.end())
	{
		cout << _m_it->first << " " << _m_it->second << endl;
		_m_it++;
	}
	cout << endl;

	//方法五：优先级队列，将k个元素进入优先级队列中，然后建立小堆，如果我比你大，就入堆，那么到最后堆里面就会剩下最大的k个元素

	//方法六:利用map与multimap实现
    //首先map已经统计好了key和value，然后利用multimap自动排序，这样它的相对顺序也不会变，比如力扣前k个高频单词
	it = m.begin();
	multimap<int, string, greater<int>>mm;
	while (it != m.end())
	{
		mm.insert(make_pair(it->second, it->first));
		it++;
	}
	auto _mm = mm.begin();
	while (_mm != mm.end())
	{
		cout << _mm->second << " " << _mm->first << endl;
		++_mm;
	}


	cout << endl;


	return 0;
}

```

> 实际生活中我们只需要掌握第二种，第五种，第六种即可，主要是灵活应用

## 项目地址

[The-C-PLus-PLus-Language/1.C++初识/19.set容器和map容器 at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/1.C%2B%2B初识/19.set容器和map容器)

[The-C-PLus-PLus-Language/2.C++初阶/test_10_30_map和set at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/2.C%2B%2B初阶/test_10_30_map和set)

