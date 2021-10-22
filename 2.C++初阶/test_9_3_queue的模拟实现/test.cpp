#include"queue.h"
int main()
{
	hello::queue<int>q;
	q.push(1);
	q.push(2);
	cout << q.front() << endl;
	return 0;
}