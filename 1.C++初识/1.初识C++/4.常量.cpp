/*
	常量修饰的两种方式：1.#define 常量名 常量值
						2.const 数据类型 常量名=常量值
*/
#include<iostream>
using namespace std;
#define Day 7
int main4()
{
	//常量不可以修改，一旦修改就会报错；
	const int month = 12;
	cout <<"一年一共有"<< month << "个月份"<<endl;
	cout << "一周总共有" << Day <<"天"<< endl;
	system("pause");
	return 0;
}