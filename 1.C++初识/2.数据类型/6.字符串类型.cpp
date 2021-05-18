//字符串型： C语言分格字符串：char 变量名[]="字符串值";
//           C++类型字符串：string 变量名="字符串值";
#include<iostream>
using namespace std;
int main6()
{
	char ch[] = "hello world!";
	cout << ch << endl;
	string str = "hello world!";
	cout << str << endl;
	cout << sizeof(ch) << endl;
	cout << sizeof(str) << endl;
	system("pause");
	return 0;
}