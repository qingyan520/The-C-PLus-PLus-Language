//1.victor���������������
//#include<iostream>
//#include<vector>
//#include<algorithm>//��׼�㷨ͷ�ļ�
//using namespace std;
//void myPrint(int val)
//{
//	cout << val << endl;
//}
//void test01()
//{
//	//����һ������������
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//	////ͨ�����������������е�����
//	//vector<int>::iterator itBegin = v.begin();//��һ��Ԫ��λ��
//	//vector<int>::iterator itEnd = v.end();//���һ��Ԫ����һ��λ��
//	////��һ�ֱ�����ʽ
//	//while (itBegin != itEnd)
//	//{
//	//	cout << *itBegin << endl;
//	//	itBegin++;
//	//}
//	//
//
//	//�ڶ��ֵ�����ʽ
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << endl;
//	}
//
//
//	//�����ֱ�����ʽ
//	for_each(v.begin(), v.end(), myPrint);
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//2.vector����Զ�����������
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//class person
//{
//public:
//	person(string name,int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	string name;
//	int age;
//};
//void test01()
//{
//	person p1("aaa", 1);
//	person p2("bbb", 2);
//	person p3("ccc", 3);
//	person p4("ddd", 4);
//	person p5("eee", 5);
//	person p6("fff", 6);
//	vector<person>v;
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	v.push_back(p6);
//	for (vector<person>::iterator begin = v.begin(); begin != v.end(); begin++)
//	{
//		//cout << "����:" << (*begin).name << " " << "����:" << (*begin).age << endl;
//		cout << "����:" << begin->name << " " << "����:" << begin->age << endl;
//	}
//}
//void test02()
//{
//	person p1("aaa", 1);
//	person p2("bbb", 2);
//	person p3("ccc", 3);
//	person p4("ddd", 4);
//	person p5("eee", 5);
//	person p6("fff", 6);
//	vector<person*>v;
//	v.push_back(&p1);
//	v.push_back(&p2);
//	v.push_back(&p3);
//	v.push_back(&p4);
//	v.push_back(&p5);
//	v.push_back(&p6);
//	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << "����:" << (*it)->name << " " << "����" << (*it)->age << endl;
//	}
//}
//int main()
//{
//	//test01();
//	test02();
//	system("pause");
//	return 0;
//}

//3.vector����Ƕ������
#include<iostream>
#include<vector>
using namespace std;
void test01()
{
	vector<vector<int>>v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(1 + i);
		v2.push_back(2 + i);
		v3.push_back(3 + i);
		v4.push_back(4 + i);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << (*vit) << " ";
		}
		cout << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}