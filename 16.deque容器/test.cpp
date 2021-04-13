//deque容器

//1.deque容器的基本概念
//功能：双端数组，可以对头端进行插入和删除操作
//deque和vector容器的区别：
//1.vector容器对于头部的插入和删除效率低，数据量越大，效率越低
//2.deque相对而言，对头部的插入删除速度会比vector快
//3.vector访问元素时的速度比deque快，这和两者的内部实现有关系
//deque工作原理：
//deque内部有个中控器，维护每段缓冲区，缓冲区中存放真实数据
//中控器维护的是每个缓冲区的地址，还得使用deque时像一块连续的内存空间
//#include<iostream>
//#include<deque>
//#include<vector>
//using namespace std;
//void Print(const deque<int>& d)
//{
//	for ( deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	deque<int>v;
//	v.push_back(1);
//	v.push_front(5);
//	Print(v);
//	deque<int>d1(v.begin(), v.end());
//	
//	Print(d1);
//	deque<int>d2(5, 10);
//	Print(d2);
//	deque<int>d3(d2);
//	Print(d3);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//deque迭代器也是支持随机访问的

//2.deque的赋值操作
//#include<iostream>
//#include<deque>
//using namespace std;
//void Print(const deque<int>& d)
//{
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	deque<int>d1;
//	d1.push_back(1);
//	deque<int>d2;
//	//1.等号赋值
//	d2 = d1;
//	Print(d1);
//	Print(d2);
//	deque<int>d3;
//	//2.assign赋值
//	d3.assign(d1.begin(), d1.end());
//	Print(d3);
//	deque<int>d4;
//	//3.n个几；
//	d4.assign(4, 1);
//	Print(d4);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//3.deque大小操作
//deque.empty():判断容器是否为空，若为空，返回1，不为空，返回0;
//deque.size():返回容器中的元素个数
//deque.resize(num):重新确定容器中的长度为num，若容器变长，则以默认值填充新位置
//               如果容器变短，则末尾超出容器长度的元素被删除
//deque.resize(num,elem):重新指定容器的长度为num,若容器变长，则以elem填充
//                       //如果容器变短，则末尾超出部分将被删除
//#include<iostream>
//#include<deque>
//using namespace std;
//void Print(const deque<int>& d)
//{
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	deque<int>d1;
//	for (int i = 0; i < 10; i++)
//	{
//		d1.push_back(i);
//	}
//	Print(d1);
//	cout << "容器是否为空:" << d1.empty() << endl;
//	cout << "容器的大小为：" << d1.size() << endl;
//	//重新指d1大小
//	d1.resize(5);
//	Print(d1);
//	d1.resize(15, 6);
//	Print(d1);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.deque的插入和删除
//#include<iostream>
//#include<deque>
//using namespace std;
//void Print(const deque<int>&d)
//{
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//
//void test01()
//{
//	deque<int>d;
//
//	for (int i = 0; i < 10; i++)
//	{
//		d.push_back(i);
//	}
//	Print(d);
//	d.push_front(100);
//	Print(d);
//	d.pop_back();
//	Print(d);
//	d.pop_front();
//	Print(d);
//	d.insert(d.begin(), 100);
//	Print(d);
//	deque<int>d2;
//	d2.push_back(1);
//	d2.push_back(2);
//	d2.push_back(3);
//	d.insert(d.begin(), d2.begin(), d2.end());
//	Print(d);
//	d.clear();
//	Print(d);
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//头插：push_front
//头删：pop_front
//尾插：push_back
//尾删：pop_back
//任意位置插入：insert
//任意位置删除：erase
//清除容器：clear



//5.deque数据读取
//1.d.at(i),访问下表为i的元素
//2.d.[i]，访问下标为i的元素
//3.d.front(),访问头部元素
//4.d.back(),访问尾部元素
//#include<iostream>
//#include<deque>
//using namespace std;
//void test01()
//{
//	deque<int>d;
//	for (int i = 0; i < 10; i++)
//	{
//		d.push_back(i);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << d[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << d.at(i) << " ";
//	}
//	cout << endl;
//	cout << d.front() << endl;
//	cout << d.back() << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//7.deque容器的排序
//利用算法对deque容器进行排序
//sort(iterator begin,iterator end)
//#include<iostream>
//#include<deque>
//#include<algorithm>
//using namespace std;
//void Print(const deque<int>d)
//{
//	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	deque<int>d;
//	d.push_back(10);
//
//	d.push_back(1);
//	d.push_back(15);
//	d.push_back(9);
//	d.push_back(6);
//	Print(d);
//	sort(d.begin(), d.end());
//	Print(d);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//评委评分
#include<iostream>
#include<algorithm>;
#include<vector>
using namespace std;
class person
{
	person(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
public:
	string name;
	int score;

};
void test01()
{
	vector<person>v;
	unsigned int x = -1;
	cout << x << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}