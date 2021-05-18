//4.常用拷贝和替换算法
//copy      容器内指定范围内的元素拷贝到另一个容器中去
//replace   将容器中指定范围内的旧元素修改为新元素
//replace_if  容器内指定范围满足条件的元素替换为新元素
//swap     互换两个容器中的元素


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
//目标容器记得提前开辟空间



//2.replace(begin,end,value,new value)
//将区间内所有的value值替换为new value
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
//将区间内所有满足条件的元素替换成普通元素
//replace_if(beg,end,_pred,new_value)
//_pred谓词
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


//swap 交换两个容器
//交换容器要是同一个类型
//#include<iostream>
//using namespace std;
//int main()
//{
//
//	system("pause");
//	return 0;
//}
