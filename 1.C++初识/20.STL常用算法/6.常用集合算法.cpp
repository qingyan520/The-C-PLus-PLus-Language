//6.���ü����㷨
//set_intersection  :�����������Ľ���
//set_union  �����������Ĳ���
//set_difference   �����������Ĳ

//1.set_intersection
//�����������Ľ���
//ע�⣺ԭ�����������������вſ����������
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void Print(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	//Ŀ������������ȡС������ֵ
//	v.resize(v1.size() > v2.size() ? v2.size():v1.size());
//	//��ȡ����
//	vector<int>::iterator it=set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
//	for_each(v1.begin(), v1.end(), Print);
//	cout << endl;
//	for_each(v2.begin(), v2.end(), Print);
//	cout << endl;
//	for_each(v.begin(), it, Print);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//set_union:���������ϵĲ���
//ע��:ԭ������������������
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void Print(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	for (int i = 0; i < 5; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 5);
//	}
//	vector<int>v3;
//	v3.resize(v1.size() + v2.size());
//	vector<int>::iterator it=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	for_each(v1.begin(), v1.end(), Print);
//	cout << endl;
//	for_each(v2.begin(), v2.end(), Print);
//	cout << endl;
//	for_each(v3.begin(), it, Print);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//set_difference:��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void test01()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}
	v3.resize(max(v1.size(), v2.size()));
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());


}

int main()
{
	test01();
	system("pause");
	return 0;
}