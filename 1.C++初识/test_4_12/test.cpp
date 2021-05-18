
////string 容器的用法：
//#include<iostream>
//#include<string>
//using namespace std;
//void test01()
//{
//	//1.赋值操作
//	//2.追加操作
//	//3.substr查找子串
//	//4.删除erase
//	//5.find查找
//	//6.replace替换
//}
//int main()
//{
//	system("pause");
//	return 0;
//}

//
//#include<iostream>
//#include<vector>
//using namespace std;
//void test01()
//{
//	vector<int>v;
//	//1.简单复制操作
//	//2.
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}



#include<iostream>
using namespace std;
void test01()
{
	int a = 1;
	int b = 1;
	int c = 1;
	int d = 12;
	if (a == b && b == c && d == c)
	{
		printf("相等\n");
	}
	else
	{
		printf("不相等\n");
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}