//字符型：字符型变量用于显示单个字符
 //语法：char ch='a';
//注意1：在显示字符型变量时，用单引号将字符括起来，不要用双引号
//注意2：单引号内只能有一个字符，不可以是字符串
//C和C++中字符型变量只占一个字节
//字符型变量并不是将字符本身放到内存中存储，而是将对应的ASCII编码放入到对应的存储单元
#include<iostream>
using namespace std;
int main4()
{
	char ch = 'a';
	cout <<(int) ch << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(ch) << endl;
	system("pause");
	return 0;
}