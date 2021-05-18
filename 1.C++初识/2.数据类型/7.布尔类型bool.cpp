//布尔数据类型表示真或假
//bool类型只有两个值：
//true  真(本质是一)
//false 假(本质是0)
//bool类型占一个字节大小
#include<iostream>
using namespace std;
int main7()
{
	//1.创建布尔数据类型
	bool flag = true;//true代表真
	cout << flag << endl;
	flag = false;//false为假
	cout << flag << endl;
	//本质上 1代表真  0代表假
	//2.查看bool类型所占内存空间
	cout << sizeof(bool) << endl;
	system("pause");
	return 0;
}