//���ȼ����У�
//�����˳�����⣬������˳�������ȼ����г�����(����ϵͳ�ṩ��Ĭ��˳���ǰ��ս���ķ�ʽ�������е�)
//��Ҫ�ӿ���:
//1.push
//2.pop
//3.top
//4.size
//5.empty
//6.swap
//���ȼ����еײ�������+�ѵ��������µ����㷨
//ģ��ʵ�����ȼ�������Ҫ��ʹ��������ģʽ
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