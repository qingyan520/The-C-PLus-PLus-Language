//c++的三大特性:封装，继承，多态

#include<iostream>
using namespace std;
const double PI = 3.14;
//设计一个圆类，求圆的周长
//class 代表类，后面跟名称
class Circle
{
	//访问权限
	//公共权限
public:
	//属性；
	int m_r;
	//行为
	double calculate()
	{
		return 2 * PI * m_r;
	}
};
int main()
{
	//通过圆类 创建具体的圆
	Circle cl;
	cl.m_r = 10;
	cout << "圆的周长:" << cl.calculate()<<endl;
	system("pause");
	return 0;
}