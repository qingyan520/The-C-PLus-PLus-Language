//�ַ����ͣ� C���Էָ��ַ�����char ������[]="�ַ���ֵ";
//           C++�����ַ�����string ������="�ַ���ֵ";
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