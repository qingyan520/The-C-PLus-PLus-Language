//list容器
//1.list容器基本概念
//链表由两部分组成，数据域和指针域
//功能：将数据进行链式存储
//链表是一种物理存储单元上的非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针连接实现的
//链表的组成：有一系列的节点组成
//节点的组成：一个是存储数据元素的数据域，另一个是存储下一个节点地址的指针域
//STL中的链表是一个双向循环链表
//优点：可以对任意位置进行快速插入删除元素
//缺点：容器遍历速度没有数组快，占用空间比数组大


//2.list的构造函数
//list<T>lst;   //list采用模板类实现，对象的默认构造形式
//list(begin,end); //构造函数将(begin,end)区间之内的元素拷贝到本身
//list(n,elem);  //将n个elem拷贝到本身
//list(const list &lst);// 拷贝构造函数
//#include<iostream>
//#include<list>
//using namespace std;
//void test01()
//{
//	list<int>l1;
//	l1.push_back(1);
//	cout<<l1.size()<<endl;
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//3.list的赋值与交换操作
//1.赋值：
//1.=直接赋值
//2.assigal(begin,end);
//3.assigal(n,elem)
//4.l2(l1);
//2.swap交换：
//l1.swap(l2);//交换l1,l2的值



//4.list容器大小操作
//1.empty:判断容器是否为空，若为空，返回1，不空，返回0
//2.size:判断容器的大小
//3.resize():重新指定大小：若删除变小则删除


//5.list容器的插入和删除
//push_back(elem):在容器尾部加入一个元素
//pop_back():删除容器中最后一个元素
//push_front(elem):在容器开头加入一个元素
//pop_front():在容器开头删除一个元素
//insert(pos,elem):在pos位置加入elem,并返回新数据的位置
//insert(pos,begin(),end()):在pos位置插入[begin,end)区间上的数据，无返回值
//insert(pos,n,elem):在pos位置插入n个elem
//clear():清空容器
//erase(begin(),end())清除区间[begin,end)之间的数据，返回
//remove(elem):删除所有元素elem
//#include<list>
//#include<iostream>
//using namespace std;
//void Print(const list<int>lst)
//{
//	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//void test01()
//{
//	list<int>lst;
//	lst.push_back(10);
//	lst.push_back(20);
//	lst.push_back(30);
//	lst.push_back(40);
//	Print(lst);
//	lst.push_front(100);
//	Print(lst);
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//6.list容器的数据存取
//front():返回第一个元素
//back():返回最后一个元素
//list本质是链表，不是用连续线性空间存储数据，迭代器也不支持随机访问
//#include<list>
//#include<iostream>
//using namespace std;
//void test01()
//{
//	list<int>lst;
//	lst.push_back(10);
//	lst.push_back(20);
//	lst.push_back(30);
//	lst.push_back(40);
//	cout << lst.front() << endl;
//	cout << lst.back() << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//)


//7.list反转和排序
//reverse();反转链表
//sort();排序链表
//所有不支持随机访问的迭代器不支持标准算法
//内部会提供一些成员内部的函数
//#include<iostream>
//#include<list>
//#include<algorithm>
//using namespace std;
//void Print(const list<int>lst)
//{
//	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//bool compare(int v1, int v2)
//{
//	return v1 > v2;
//}
//void test01()
//{
//	list<int>lst;
//	lst.push_back(5);
//	lst.push_back(1);
//	lst.push_back(4);
//	lst.push_back(2);
//	lst.push_back(3);
//	Print(lst);
//	lst.reverse();
//	Print(lst);
//	lst.sort();
//	Print(lst);
//	lst.sort(compare);
//	Print(lst);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//8.排序案例
//案例描述：将person的自定义数据类型进行排序，person属性中有名字，年龄，升高
//排序规则：按照年龄排序，如果年龄相同按照升高降序排列
#include<string>
#include<list>
#include<iostream>
using namespace std;
class person
{
public:
	person(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}
public:
	string name;
	int age;
	int height;
};
//指定排序规则
bool comparePerson(person& p1, person& p2)
{
	if (p1.age == p2.age)
	{
		return p1.height > p2.height;
	}
	return p1.age < p2.age;
}
void test01()
{
	list<person>lst;
	person p1("A", 15, 140);
	person p2("B", 16, 185);
	person p3("C",10,166);
	person p4("D", 15, 111);
	lst.push_back(p1);
	lst.push_back(p2);
	lst.push_back(p3);
	lst.push_back(p4);
	lst.sort(comparePerson);
	for (list<person>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << "姓名：" << (*it).name << "  " << "年龄：" << (*it).age<< "  " << "身高：" << (*it).height << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}

