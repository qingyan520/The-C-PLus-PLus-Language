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


//
//#include <iostream>
//using namespace std;
//int main()
//{
//	void* p = new char[0xfffffffful];
//	//cout << "new:" << p << endl;
//	return 0;
//}


//�������أ�����C++��������ͬ���ĺ���
//�������ص������������Ĳ������Ͳ�ͬ������ֵ��ͬ
//ע�������ķ���ֵ���ܹ��ɺ������ص�����
//����
//#include<iostream>
//using namespace std;
//void Print(int a)
//{
//	cout << a << endl;
//}
//void Print(double a)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Print(1.0);
//	Print(1);
//	return 0;
//}
//��������������������Ҫʵ�������Զ����ӡ������һ����ӡ������һ����ӡ�����������������б�Ĳ������Ͳ�ͬ
//��������ȴ��ͬ�����������ڱ���ʱȴ���ᱨ������Ǻ������أ�������ʵ���˴�ӡ������ͬ���ʹ�ӡ����
//����C���������Ǿ�Ҫ��������������ʵ������£���Print_int,Print_double
//��ôΪʲô����ֺ�������������أ����Ҫ�ӱ������ӵĹ��̿�ʼ˵��
//1.Ԥ����ͷ�ļ���չ��+���滻+ȥ��ע��+��������
//2.���룺����﷨��������ת���ɻ�����
//3.��ࣺ������ת��Ϊ�����ƵĻ�����
//4.���ӣ��������ļ�������һ�����ɿ�ִ�г���
//��C++�ڱ���������к��������ι���:�����ķ���ֵ+������+�����������ͣ�����ÿ���������ܹ����ж���ʶ�𣬼Ȳ������������ͻ



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

//���ÿ�������������ֵ�����õ��β��б�
//
//
//#include<iostream>
//void  Print(int a)
//{
//	cout << a << endl;
//}
//void Print(string str)
//{
//	cout << str << endl;
//}
//using namespace std;
//int main()
//{
//	Print(1);
//	Print("hello  world");
//}

//#include<iostream>
//using namespace std;
//int Ad(int a, int b)
//{
//	return a + b;
//}
//void func(int a,  double b, int* p)
//{
//
//}
//int main()
//{
//
//	return 0;
//}