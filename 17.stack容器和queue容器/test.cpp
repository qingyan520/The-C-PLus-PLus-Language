//stack����
//1.stack����������������
//���stack��һ���Ƚ������(First Last Out,FILO)�����ݽṹ����ֻ��һ������
//ջ��ֻ�ж��˵�Ԫ�ز��ܱ�ʹ�ã����ջ�������б�����Ϊ
//ջ�����ж��Ƿ�Ϊ�գ��Լ���Ԫ�ش�С

//2.stack�ĳ��ýӿ�
//���캯����
//stack<T>stk;  stack����ģ����ʵ�֣�stack�����Ĭ�Ϲ�����ʽ
//stack(const stack &stk)  //�������캯��
//��ֵ������
//stack operator=(const stack &stk);//���صȺŲ�����
//���ݴ�ȡ��
//push(elm):��ջ�����Ԫ��
//pop():�Ƴ�ջ����һ��Ԫ��
//top():����ջ��Ԫ��
//��С������
//empty():�ж϶�ջ�Ƿ�Ϊ��
//size():����ջ�Ĵ�С

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


//queue����
//1.queue�����Ļ�������
//����:queue��һ���Ƚ��ȳ���(First In Out FIFO)�����ݽṹ���������ֽӿ�
////�������������һ������Ԫ�أ���һ���Ƴ�Ԫ��
//������ֻ�ж�ͷ�Ͷ�β���ܱ����ʹ�ã���˶��в������б�����Ϊ
//�����е����--�������ݣ�push   ��һ��Ԫ�ؽж�ͷ   ���һ��Ԫ�ؽж�β
//������ɾ������--��pop 
//empty:�ж϶����Ƿ�Ϊ��
//size:�ж϶��д�С

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
