//3.���������㷨int
//sort���������ڵ�Ԫ�ؽ�������
//random_shuffle  //ָ����Χ�ڵ�Ԫ�������������
//merge  //����Ԫ�غϲ������洢����һ��������ȥ
//reverse  //��תָ����Χ�ڵ�Ԫ��


//1.sort
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void Print(vector<int>& v)
//{
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
//}
//class Compare
//{
//public:
//	bool operator()(int v1, int v2)
//	{
//		return v1 > v2;
//	}
//};
//void test01()
//{
//	vector<int>v;
//	v.push_back(5);
//	v.push_back(1);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(4);
//	Print(v);
//	sort(v.begin(), v.end());
//	Print(v);
//	sort(v.begin(), v.end(),Compare());
//	Print(v);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



//3.random_shuffle
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<ctime>
//using namespace std;
//void Print(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//	for_each(v.begin(), v.end(),Print);
//	cout << endl;
//	random_shuffle(v.begin(), v.end());
//	for_each(v.begin(), v.end(), Print);
//	cout << endl;
//	random_shuffle(v.begin(), v.end());
//	for_each(v.begin(), v.end(), Print);
//	cout << endl;
//	random_shuffle(v.begin(), v.end());
//	for_each(v.begin(), v.end(), Print);
//	cout << endl;
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	test01();
//	return 0;
//}



//3.merge:�������������кϲ����洢����һ��������ȥ
////ע��Ҫ�ϲ����������������������
//�ϲ��������Ҳ�������
//Ŀ������Ҫ���ٿռ�
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
//	vector<int>v3;
//
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//		v2.push_back(i + 10);
//	}
//	v3.resize(v1.size() + v2.size());
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
//	for_each(v3.begin(), v3.end(), Print);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//4.reverse:�������ڵ�Ԫ�ؽ��з�ת
//reserse(begin,end);
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
//	vector<int>v;
//	v.push_back(5);
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(4);
//	v.push_back(1);
//	for_each(v.begin(), v.end(), Print);
//	cout << endl;
//	reverse(v.begin(), v.end());
//	for_each(v.begin(), v.end(), Print);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

