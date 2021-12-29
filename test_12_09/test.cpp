//栈实现队列：
//栈是一种先进后出的数据结构，而队列是一种先进先出的数据结构，想要用栈实现队列，就要定义两个栈，以下面的例子为例：
//元素[1,2,3,4,5]存储在栈中
//其中1最先进栈，5最后进栈，如果是栈的话我们的出栈顺序就变成了5，4，3，2，1
//而队列的话出栈顺序应该为1，2，3，4，5
//这时候我们再定义一个栈，我们讲前面这个栈的元素导入到这个新的栈中去，那么这个新的栈中的元素就会变成5，4，3，2，1其中5为栈底元素，1为栈顶元素
//这个时候我们访问这个新的栈顶第一个元素就会变成1，第二个出栈元素就会变成2，接下来就会变成3，4，5，这样就符合队列的操作了

#include<iostream>
#include<stack>
using namespace std;
template<class T>
class MyQueue {
public:
  
    MyQueue() {

    }

 
    void push(T& x) {
        s1.push(x);

    }


    //删除队列首元素
    T pop() {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        T ret = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return ret;
    }

  //返回队列首元素
    T front() {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        return ret;

    }

    //判断队列是否为空
    bool empty() {
        return s1.empty() && s2.empty();

    }

private:
    //用栈来实现队列：
  //建立两个栈，s1,s2，一个栈用来进数据，另一个栈用来出数据

    stack<T>s1;//用来进数据
    stack<T>s2;//用来出数据
};
int main()
{
    MyQueue<int>q;
    int arr[]{ 1,2,3,8,9,5,1,2 };
    for (auto e : arr)
    {
        q.push(e);
    }

    while (!q.empty())
    {
        cout << q.front() <<" ";
        q.pop();
    }
    cout << endl;

	return 0;
}