//#include<iostream>
//using namespace std;
//namespace hello
//{
//	template<class T, size_t N=100>
//	class Array
//	{
//	private:
//		T arr[N];
//	};
//}
//int main()
//{
//	hello::Array<int>arr;
//	
//	return 0;
//}


//2.ģ����ػ�
//��������ģ�����Ƚ������ַ����Ƿ����
//#include<iostream>
//using namespace std;
//template<class T>
//bool Is_Same(T& left, T& right)
//{
//	return left == right;
//}
//
//bool Is_Same(char* left,char*  right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//	return false;
//}
//��������
//template<>
//bool Is_Same<const char*const>(const char* const &left, const char* const &right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//	return false;
//}
//int main()
//{
//	int a = 10;
//	int b = 10;
//	cout << Is_Same<int>(a,b) << endl;
//	char str1[] = "hello";
//	char str2[] = "hello";
//	cout << Is_Same(str1, str2) << endl;
//	return 0;
//}

//3.��ģ����ػ�
//3.1��ģ���ȫ�ػ�
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	/*T1 _d1;
//	T2 _d2;*/
//};
//
//// �������T1 T2�� int int����һЩ���⻯��ô��ô�� �� -- ��ģ���ػ�
//// -- ȫ�ػ�
//template<>
//class Data < int, int >
//{
//public:
//	Data() { cout << "Data<int, int>" << endl; }
//};
//
//// ���ڶ��������ػ�Ϊint --ƫ�ػ�
//template <class T1>
//class Data < T1, int >
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//};
//
//// ƫ�ػ� ָ�����ģ�������ָ�룬������
//template <class T1, class T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//};
//
//template <class T1, class T2>
//class Data < T1&, T2& >
//{
//public:
//	Data() { cout << "Data<T1&, T2&>" << endl; }
//};
//
//template <class T1, class T2>
//class Data < T1&, T2* >
//{
//public:
//	Data() { cout << "Data<T1&, T2*>" << endl; }
//};
//
//// ����ģ��Ҳһ����Ҳ��ȫ�ػ���ƫ�ػ�
//
//int main()
//{
//	Data<int, int> d1;
//	Data<int, double> d2;
//	Data<double, int> d3;
//	Data<double*, int*> d4;
//	Data<int*, int*> d5;
//	Data<int&, int&> d6;
//	Data<int&, int*> d7;
//
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//template<class T1,class T2>
//class A
//{
//public:
//	A()
//	{
//		cout << "A<T1,T2>" << endl;
//	}
//};
//template<>
//class A<int, int>
//{
//public:
//	A()
//	{
//		cout << "A<int ,int>" << endl;
//	}
//};
//template<>
//class A<int, double>
//{
//public:
//	A()
//	{
//		cout << "A<int,double>" << endl;
//	}
//};

//ģ���ƫ�ػ�---��ģ������б������в����оٳ�
//template<class T1, class T2>
//class A
//{
//public:
//	cout << "A<T1,T2>" << endl;
//};
//
//template<class T1>
//class A<T1, int>
//{
//public:
//	cout << "A<T1��int>" << endl;
//};
//
//template<class T1,class T2>
//class A<T1*, T2*>
//{
//public:
//	cout<< "A<T1*,T2*>" << endl;
//};
//
//template<class T1,class T2>
//class A<T1&, T2&>
//{
//public:
//	cout << "A<T1&,T2&>" << endl;
//};
//int main()
//{
//	//A<int,int>a;
//	A<int*, int*>b;
//	A<int&, int&>c;
//	return 0;
//}


//ģ�����ƫ�ػ�
#include<iostream>
using namespace std;
template<class T1,class T2>
class A
{
public:
	A()
	{
		cout << "A<T1��T2>" << endl;
	}
};
template<class T1>
class A<T1,int>
{
public:
	A()
	{
		cout << "A<T1,int>" << endl;
	}
};
//��������ƫ�ػ�Ϊָ������
template<class T1,class T2>
class A<T1*,T2*>
{
public:
	A()
	{
		cout << "A<T1*��T2*>" << endl;
	}
};
//��������ƫ�ػ�Ϊ��������
template<class T1, class T2>
class A<T1& ,T2&>
{
public:
	A()
	{
		cout << "A<T1&,T2&>" << endl;
	}
};
//һ������ƫ�ػ�Ϊ���ã�����һ������ƫ�ػ�Ϊָ��
template<class T1,class T2>
class A<T1&,T2*>
{
public:
	A()
	{
		cout << "A<T1&,T2*>" << endl;
	}
};
int main()
{
	A<double, int>a;
	A<int*, int*>b;
	A<int&, int&>c;
	A<int&, int*>d;
	return 0;
}