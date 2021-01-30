//利用sizeof关键字可以统计数据类型所占内存空间
//语法：sizeof(数据类型/变量)
#include<iostream>
using namespace std;
int main2()
{
	cout << sizeof(short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	system("pause");
	return 0;
}