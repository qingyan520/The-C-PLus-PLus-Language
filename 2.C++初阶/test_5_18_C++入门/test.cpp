//1.C++����
//#include<iostream>
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}
//std ��һ�����ƿռ䣬������cout,cin
//namespace �����ռ䣬��ֹ������ͻ

//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << "hello world" << endl;
//}

//C++�������cout,������cin>>



//����ȱʡ�����ں�������ʱΪδ֪����ֵ
//����
//#include<iostream>
//using namespace std;
//void Print(int a = 10)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Print();
//	Print(20);
//}
//ȱʡ��Ϊ���֣�
//1.ȫȱʡ��(int a=10,int b=10,int c=0)
//2.��ȱʡ��(int a,int b=10,int c=0)
//ȱʡ�����Ǵ�������ȱʡ���ұ�����������


//

//�������أ��������ؼ���ͬ�ĺ�����ִ�в�ͬ�Ĺ���
//�������ص�������������ͬ�������ĺ��������Ĳ������Ͳ�ͬ���߲���������ͬ��ע�⺯���ķ���ֵ���ܳ�Ϊ�жϺ����Ƿ����ص�����
//1.ΪʲôC���Բ�֧�����أ�C++֧�����أ����صĵײ������ʵ�ֵ�

//2.extern"C"��������ʲô


//���ã�
//���ò�������дһ�����������Ǹ�һ����������������������õı�����ͬ����һ���ڴ�ռ�
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << a << endl;
//	cout << b << endl;
//	b = 100;
//	cout << a << endl;
//	cout << b << endl;
//	system("pause");
//	return 0;
//}



//#include<iostream>
//using namespace std;
//void TestFor()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : array)
//		e *= 1;
//
//	for (auto e : array)
//		cout << e << " ";
//
//}
//int main()
//{
//	TestFor();
//	cout << sizeof(nullptr);
//}



#include <iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	//cout << "new:" << p << endl;
	return 0;
}