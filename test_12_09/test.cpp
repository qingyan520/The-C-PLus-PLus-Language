//ջʵ�ֶ��У�
//ջ��һ���Ƚ���������ݽṹ����������һ���Ƚ��ȳ������ݽṹ����Ҫ��ջʵ�ֶ��У���Ҫ��������ջ�������������Ϊ����
//Ԫ��[1,2,3,4,5]�洢��ջ��
//����1���Ƚ�ջ��5����ջ�������ջ�Ļ����ǵĳ�ջ˳��ͱ����5��4��3��2��1
//�����еĻ���ջ˳��Ӧ��Ϊ1��2��3��4��5
//��ʱ�������ٶ���һ��ջ�����ǽ�ǰ�����ջ��Ԫ�ص��뵽����µ�ջ��ȥ����ô����µ�ջ�е�Ԫ�ؾͻ���5��4��3��2��1����5Ϊջ��Ԫ�أ�1Ϊջ��Ԫ��
//���ʱ�����Ƿ�������µ�ջ����һ��Ԫ�ؾͻ���1���ڶ�����ջԪ�ؾͻ���2���������ͻ���3��4��5�������ͷ��϶��еĲ�����

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


    //ɾ��������Ԫ��
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

  //���ض�����Ԫ��
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

    //�ж϶����Ƿ�Ϊ��
    bool empty() {
        return s1.empty() && s2.empty();

    }

private:
    //��ջ��ʵ�ֶ��У�
  //��������ջ��s1,s2��һ��ջ���������ݣ���һ��ջ����������

    stack<T>s1;//����������
    stack<T>s2;//����������
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