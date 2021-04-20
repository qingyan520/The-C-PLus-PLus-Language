//stack容器
//1.stack容器容器基本概念
//概念：stack是一种先进后出的(First Last Out,FILO)的数据结构，他只有一个出口
//栈中只有顶端的元素才能被使用，因此栈不容许有遍历行为
//栈可以判断是否为空，以及求元素大小

//2.stack的常用接口
//构造函数：
//stack<T>stk;  stack采用模板类实现，stack对象的默认构造形式
//stack(const stack &stk)  //拷贝构造函数
//赋值操作：
//stack operator=(const stack &stk);//重载等号操作符
//数据存取：
//push(elm):向栈顶添加元素
//pop():移除栈顶第一个元素
//top():返回栈顶元素
//大小操作：
//empty():判断堆栈是否为空
//size():返回栈的大小

//
//#include<iostream>
//#include<stack>
//using namespace std;
//void test01()
//{
//	stack<int>s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	cout << s.size() << endl;
//	while (s.empty() != 1)
//	{
//		cout << s.top() << endl;
//		s.pop();
//	}
//	cout << s.size() << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//queue容器
//1.queue容器的基本概念
//概念:queue是一种先进先出的(First In Out FIFO)的数据结构，它有两种接口
////队列容器容许从一端新增元素，另一端移除元素
//队列中只有队头和队尾才能被外界使用，因此队列不容许有遍历行为
//队列中的入队--插入数据：push   第一个元素叫队头   最后一个元素叫队尾
//队列中删除数据--；pop 
//empty:判断队列是否为空
//size:判断队列大小

#include<iostream>
#include<queue>
using namespace std;
void test01()
{
	queue<int>q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.size() << endl;
	cout << q.back() << endl;
	cout << q.front() << endl;
	while (q.empty() != 1)
	{
		
		cout << q.front() << endl;
		cout << q.back() << endl;
		q.pop();
	}
	cout << q.size() << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
