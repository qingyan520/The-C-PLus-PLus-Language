//1.���õĻ����﷨
//���ã������������
//�﷨���������� & ���� = ԭ��
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	b = 20;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	a = 30;
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	system("pause");
//	return 0;
//}



//2.���õĻ����﷨�������������
//#include<iostream>
//using namespace std;
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//
//	//1.�ȶ����������ͣ���ͨ���������ͣ�������������
//	typedef int(ARRAY_TYPE)[5];
//	ARRAY_TYPE& pARR = arr;
//	for ( int i = 0; i < 5; i++)
//	{
//		cout << pARR[i] << endl;
//	}
//
//	//2.�ȶ����������õ����ͣ���ͨ�������������ͣ�������������
//	typedef int(&ARRY_TYPE2)[5];
//	ARRY_TYPE2 pARR2 = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << pARR[i] << endl;
//	}
//
//	//3.ֱ�Ӷ�����������
//	int(&pARR3)[5] = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		cout << pARR[i] << endl;
//	}
//	system("pause");
//	return 0;
//}




//3.���õ�ע������
//���ñ����ʼ��
//�����ڳ�ʼ���󲻿��Ըı�
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 10;
//	int& b = a;//��ȷ
//	//1.���ñ����ʼ��
//	//int& b;����ģ����ñ����ʼ��
//
//	//2.���ó�ʼ���󲻿��Ը���
//	int c = 20;
//	b = c;//��ֵ
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c=" << c << endl;
//	system("pause");
//	return 0;
//}



//4.��������������
//���ã���������ʱ�������������õļ������β�����ʵ��
//�ŵ㣺���Լ�ָ������ʵ��
//ʵ����
//#include<iostream>
//using namespace std;
////��������
////1.ַ����
//void swap1(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//	cout << "swap1 a=" << a << endl;
//	cout << "swap2 b=" << b << endl;
//}
////2.��ַ����
//void swap2(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
////3.���ô���
//void swap3(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//swap1(a, b);//ֵ�����ββ���ı�ʵ��
//	//swap2(&a, &b);//��ַ�����βλ�ı�ʵ��
//	swap3(a, b);//���ô����β�Ҳ������ʵ��
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	system("pause");
//	return 0;
//}
//�ܽ᣺���õ�Ч���͵�ַ����Ч����һ���ģ������﷨���������



//5.��������������ֵ
//���ã������ǿ�������������ֵ���ڵ�
//ע�⣺��Ҫ���ؾֲ���������
//�÷�����������Ϊ��ֵ
//ʵ����
//#include<iostream>
//using namespace std;
////��������������ֵ
////1.��Ҫ���ؾֲ�����������
//int& test01()
//{
//	int a = 10;//�ֲ�������ջ����
//	return a;
//}
////2.�����ĵ��ÿ�����Ϊ��ֵ
//int& test02()
//{
//	static int a = 10;//ȫ�ֱ����������������ϵͳ�Զ��ͷ�
//	return a;
//}
//int main()
//{
//	int &ret=test01();
//	cout << ret << endl;//��һ����ȷ�����������˱�����
//	cout << ret << endl;//�ڶ��δ�����Ϊa���ڴ��Ѿ��ͷ�
//	int& ref = test02();
//	cout << "ref=" << ref << endl;
//	cout << "ref=" << ref << endl;
//	test02() = 1000;///�����������ֵ�����ã�����������ÿ�����Ϊ��ֵ
//	cout << "ref=" << ref << endl;
//	system("pause");
//	return 0;
//}



//6.���õı���
//���ʣ����õı�����c++�ڲ�ʵ����һ������ָ��
//int&a=b==>int* contst a=&b;
//ָ��ָ�򲻿����޸ģ�������ֵ�����޸�
//PS������һ����ʼ���Ͳ����Է����仯
//#include<iostream>
//using namespace std;
//void test(int& a)
//{
//	a = 100;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;//�൱��int* const b=&a;
//	b = 20;//�൱��*b=20
//	cout << "a=" << a<<endl;
//	cout << "b=" << b << endl;
//	test(a);
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	system("pause");
//	return 0;
//}
//�ܽ᣺���õı��ʾ���ָ�볣�������������﷨���ӷ���



//7.��������
//���ã�����������Ҫ���������βΣ���ֹ�β�����ʵ��
//�ں����б��У����Լ�const�����βΣ���ֹ�β��޸�ʵ��
//ʵ����
//#include<iostream>
//using namespace std;
//void test(const int& a)
//{
//	cout << "a=" << a << endl;
//}
//int main()
//{
//	//��������
//	//const�������ã���ֹ�β��޸�ʵ��
//	//int& b = 20;//����д��������ָ��һƬ�ڴ�ռ�
//	const int& b = 20;//�������Լ�int temp=20; int &b=temp;
//	int a = 10;
//	test(a);
//	cout << "a=" << a << endl;
//	system("pause");
//	return 0;
//}