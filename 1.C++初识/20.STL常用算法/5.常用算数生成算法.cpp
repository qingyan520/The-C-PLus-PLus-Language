//5.常用算数生成算法
//accumulate  //计算容器元素累计总和
//fill      向容器中添加元素

//1.accumulate:计算区间内容器元素累计总和
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

//fill:向容器中填充指定的值
//fill(begin,end,value)
//begin:开始迭代器
//end:结束迭代器
//value:填充的值
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
