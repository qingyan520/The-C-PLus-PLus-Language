//优先级队列：
//入队列顺序随意，出队列顺序按照优先级进行出队列(比如系统提供的默认顺序是按照降序的方式进行排列的)
//主要接口有:
//1.push
//2.pop
//3.top
//4.size
//5.empty
//6.swap
//优先级队列底部是数组+堆的向上向下调整算法
//模拟实现优先级队列主要是使用适配器模式
#include"priority_queue.h"
template<class T>
class Less
{
public:
	bool operator()(T& l, T& r)
	{
		return l < r;
	}
};
int main()
{
	hello::priority_queue<int, vector<int>, hello::less<int> > q;
	q.push(5);
	q.push(6);
	q.push(1);
	q.push(3);
	q.push(4);
	q.push(10);
	q.push(-15);
	while (!q.empty())
	{
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}