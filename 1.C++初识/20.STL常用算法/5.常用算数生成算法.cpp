//5.�������������㷨
//accumulate  //��������Ԫ���ۼ��ܺ�
//fill      �����������Ԫ��

//1.accumulate:��������������Ԫ���ۼ��ܺ�
//accumulate(begin,end,val)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<numeric>
//using namespace std;
//void test01()
//{
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//	int total=accumulate(v.begin(), v.end(),1);
//	cout << total << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//fill:�����������ָ����ֵ
//fill(begin,end,value)
//begin:��ʼ������
//end:����������
//value:����ֵ
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<numeric>
//using namespace std;
//void Print(int val) 
//{
//	cout << val << " ";
//}
//void test01()
//{
//	vector<int>v;
//	v.resize(10);
//	fill(v.begin(), v.end(), 666);
//	for_each(v.begin(), v.end(), Print);
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
