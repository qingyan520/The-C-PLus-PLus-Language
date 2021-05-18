/*
	数据类型存在的意义：给变量分配合适的内存空间，避免内存浪费
	整形：整数
	//基本类型：short(短整型) 2字节   -2^15~~2^15-1   -32768----32767
			  int(整形)     4字节      -2^31~~2^31-1   
			  long(长整型)  Windows为4字节，Linux为8字节   -2^31~~2^31-1
			  long long(长长整形)  8字节      -2^63~~2^63-1
*/
#include<iostream>
using namespace std;
int main1()
{
	short num1 = 10;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;
	system("pause");
	return 0;
}