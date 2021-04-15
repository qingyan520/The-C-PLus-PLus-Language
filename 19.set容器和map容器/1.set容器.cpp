//set/multiset容器
//1.set容器的概念
//简介：所有元素在插入时会被自动排序
//set/multiset属于关联式容器，底层结构是用二叉树实现的
//multiset和set的区别：
//set不容许容器中有重复的元素
//multiset容许容器中有重复元素

//2.set的构造和赋值
//构造：set<T>st;
//set(const set&st);
//赋值：
//set operator=(const set &st);
#include<iostream>
#include<set>
using namespace std;
void test01()
{
	set<int>s;
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}