/*
	�������ʹ��ڵ����壺������������ʵ��ڴ�ռ䣬�����ڴ��˷�
	���Σ�����
	//�������ͣ�short(������) 2�ֽ�   -2^15~~2^15-1   -32768----32767
			  int(����)     4�ֽ�      -2^31~~2^31-1   
			  long(������)  WindowsΪ4�ֽڣ�LinuxΪ8�ֽ�   -2^31~~2^31-1
			  long long(��������)  8�ֽ�      -2^63~~2^63-1
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