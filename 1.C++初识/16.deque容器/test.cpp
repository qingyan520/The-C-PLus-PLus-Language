//deque����

//1.deque�����Ļ�������
//���ܣ�˫�����飬���Զ�ͷ�˽��в����ɾ������
//deque��vector����������
//1.vector��������ͷ���Ĳ����ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
//2.deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻ��vector��
//3.vector����Ԫ��ʱ���ٶȱ�deque�죬������ߵ��ڲ�ʵ���й�ϵ
//deque����ԭ��
//deque�ڲ��и��п�����ά��ÿ�λ��������������д����ʵ����
//�п���ά������ÿ���������ĵ�ַ������ʹ��dequeʱ��һ���������ڴ�ռ�
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
//deque������Ҳ��֧��������ʵ�

//2.deque�ĸ�ֵ����
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
//	//1.�ȺŸ�ֵ
//	d2 = d1;
//	Print(d1);
//	Print(d2);
//	deque<int>d3;
//	//2.assign��ֵ
//	d3.assign(d1.begin(), d1.end());
//	Print(d3);
//	deque<int>d4;
//	//3.n������
//	d4.assign(4, 1);
//	Print(d4);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//3.deque��С����
//deque.empty():�ж������Ƿ�Ϊ�գ���Ϊ�գ�����1����Ϊ�գ�����0;
//deque.size():���������е�Ԫ�ظ���
//deque.resize(num):����ȷ�������еĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ��
//               ���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
//deque.resize(num,elem):����ָ�������ĳ���Ϊnum,�������䳤������elem���
//                       //���������̣���ĩβ�������ֽ���ɾ��
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
//	cout << "�����Ƿ�Ϊ��:" << d1.empty() << endl;
//	cout << "�����Ĵ�СΪ��" << d1.size() << endl;
//	//����ָd1��С
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

//4.deque�Ĳ����ɾ��
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
//ͷ�壺push_front
//ͷɾ��pop_front
//β�壺push_back
//βɾ��pop_back
//����λ�ò��룺insert
//����λ��ɾ����erase
//���������clear



//5.deque���ݶ�ȡ
//1.d.at(i),�����±�Ϊi��Ԫ��
//2.d.[i]�������±�Ϊi��Ԫ��
//3.d.front(),����ͷ��Ԫ��
//4.d.back(),����β��Ԫ��
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


//7.deque����������
//�����㷨��deque������������
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


//��ί����
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