//4.���ÿ������滻�㷨
//copy      ������ָ����Χ�ڵ�Ԫ�ؿ�������һ��������ȥ
//replace   ��������ָ����Χ�ڵľ�Ԫ���޸�Ϊ��Ԫ��
//replace_if  ������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
//swap     �������������е�Ԫ��


//copy
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//void Print(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	vector<int>v2;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(i);
//	}
//	v2.resize(v1.size());
//	copy(v1.begin(), v1.end(), v2.begin());
//	for_each(v1.begin(), v1.end(),Print);
//	cout << endl;
//	for_each(v2.begin(), v2.end(), Print);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//Ŀ�������ǵ���ǰ���ٿռ�



//2.replace(begin,end,value,new value)
//�����������е�valueֵ�滻Ϊnew value
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//void Print(int val)
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v1;
//	for (int i = 0; i < 10; i++)
//	{
//		v1.push_back(1);
//	}
//	for_each(v1.begin(), v1.end(),Print);
//	cout << endl;
//	replace(v1.begin(), v1.end(), 1,10);
//	for_each(v1.begin(), v1.end(), Print);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//3.replace_if
//����������������������Ԫ���滻����ͨԪ��
//replace_if(beg,end,_pred,new_value)
//_predν��
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//void Print(int val)
//{
//	cout <<val << " ";
//}
//class Greater
//{
//public:
//	bool operator()(int val)
//	{
//		return val >= 30;
//	}
//};
//void test01()
//{
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//	v.push_back(60);
//	for_each(v.begin(), v.end(),Print);
//	cout << endl;
//	replace_if(v.begin(), v.end(),Greater(),300);
//	for_each(v.begin(), v.end(), Print);
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}


//swap ������������
//��������Ҫ��ͬһ������
//#include<iostream>
//using namespace std;
//int main()
//{
//
//	system("pause");
//	return 0;
//}
