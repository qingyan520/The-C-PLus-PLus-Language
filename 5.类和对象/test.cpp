//c++����������:��װ���̳У���̬

#include<iostream>
using namespace std;
const double PI = 3.14;
//���һ��Բ�࣬��Բ���ܳ�
//class �����࣬���������
class Circle
{
	//����Ȩ��
	//����Ȩ��
public:
	//���ԣ�
	int m_r;
	//��Ϊ
	double calculate()
	{
		return 2 * PI * m_r;
	}
};
int main()
{
	//ͨ��Բ�� ���������Բ
	Circle cl;
	cl.m_r = 10;
	cout << "Բ���ܳ�:" << cl.calculate()<<endl;
	system("pause");
	return 0;
}