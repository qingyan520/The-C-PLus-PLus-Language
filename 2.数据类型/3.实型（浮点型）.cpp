//float 单精度  4字节  7位有效数字
//double 双精度  8字节   15-16位有效数字
//默认情况下，输出一个小数，会显示出6位有效数字
#include <iostream>
using namespace std;
int main3()
{
	float f1 = 3.14f;
	cout << f1 << endl;
	double d1 = 3.14;
	cout << d1 << endl;
	return 0;
}
//科学计数法：float f2=3e2;//3*10^2
// 3e-2=3*10^(-2)=3*0.1^2;