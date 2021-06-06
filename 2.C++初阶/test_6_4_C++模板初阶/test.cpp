//ʵ��һ����������
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//���������������ֻ��֧�������������ݵĽ��������Ҫʵ�������������Ľ�������ô������Ҫ���������Swap����
//void Swap(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}
//���Ҫ���������ַ��ͱ��������ǻ�Ҫ����һ�����������кܶ����������ӣ���������ʵ�ָ����ͺ�int������
//����ͬ��Ҳֻ�����Ͳ�ͬ���ѣ���C++�������һ�ֽ��������ģ�弼��
//�﷨��template<class T>��classҲ�����滻��typename��
//#include<iostream>
//using namespace std;
//template <class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	float c = 1.2;
//	float d = 4.2;
//	Swap(a, b);
//	Swap(c, d);
//}

// ����ģ��
//template<class T>  // Type
//template<typename T>  // ����ģ�����T������typename��Ҳ������class����һ��
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	// ������������Swap�����ĵط���һ����������������
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	//Swap(a, c);
//
//	// ��������ͨ��ʵ�����βε�����T�ֱ�Ϊint��double
//	// ���ַ�ʽ����ʽʵ����
//	cout << Add(a, b) << endl;
//	cout << Add(c, d) << endl;
//	cout << Add(a, (int)c) << endl;
//
//	// ���ñ������������ͣ���ʾָ������
//	// ���ַ�ʽ������ʾʵ����
//	cout << Add<int>(a, c) << endl;
//	cout << Add<double>(a, c) << endl;
//
//	return 0;
//}

// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//void main()
//{
//	Add(1, 2);       // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2);  // ���ñ������ػ���Add�汾
//}

//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//// ģ����ã����ֳ�ƥ�亯�������Բ�ȥʵ����ģ��
//// �и�ƥ��ģ�����ƥ����������ʵ�
//void main()
//{
//	Add(1, 2);     // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0);   // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//}

// ��ģ��
//typedef double VDataType;
//class vector
//{
//public:
//	//
//private:
//	VDataType* _a;
//	int _size;
//	int _capacity;
//};

//int main()
//{
//	vector v1; // int
//
//	vector v2; // double
//
//
//	return 0;
//}
//
//// ��ģ��
#include<iostream>
#include<assert.h>
using namespace std;
namespace zj
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_a(nullptr)
			, _size(0)
			, _capacity(0)
		{}

		// ���������operator= �����漰��ǳ�������⣬��ͦ���ӣ���������ٽ�

		~vector()
		{
			delete[] _a;
			_a = nullptr;
			_size = _capacity = 0;
		}

		void push_back(const T& x)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				T* tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T) * _size);
					delete[] _a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}

			_a[_size] = x;
			++_size;
		}

		// ��+д
		T& operator[](size_t pos);
		size_t size();
	private:
		T* _a;
		size_t _size;
		size_t _capacity;
	};

	// ģ�岻֧�ַ�����룬Ҳ����������.h ,������.cpp��ԭ������ٽ�
	// ������Ƕ�����һ���ļ� xxx.h  xxx.hpp
	// �������涨��
	template<class T>
	T& vector<T>::operator[](size_t pos)
	{
		assert(pos < _size);

		return _a[pos];
	}

	template<class T>
	size_t vector<T>::size()
	{
		return _size;
	}
}

int main()
{
	zj::vector<int> v1;		// int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	// v1.operator[](3);
	//cout << v1[3] << endl;
	//cout << v1[5] << endl;
	for (size_t i = 0; i < v1.size(); ++i)
	{
		v1[i] *= 2;
	}


	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;


	zj::vector<double> v2;   // double
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);
	v2.push_back(4.4);

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	return 0;
}