//ģ�����:vector���ģ��ʵ��
//#include<iostream>
//using namespace std;
//template<class T>
//class vector
//{
//public:
//	vector()
//	{
//		arr = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//	~vector()
//	{
//		delete[]arr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//	//д������
//	void push_back(const T& x)
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
//			T* temp = new T[newcapacity];
//			if (temp)
//			{
//				//memcpy�ڴ濽����
//				memcpy(temp, arr, sizeof(T) * _size);
//				delete[]arr;
//			}
//			arr = temp;
//			_capacity += newcapacity;
//		}
//		arr[_size] = x;
//		_size++;
//	}
//
//
//	//����[]ʵ����[]�±�ķ�ʽ����vector�е�Ԫ��
//	T& operator[](int pos)
//	{
//		return arr[pos];
//	}
//
//private:
//	T* arr;
//	int _size;
//	int _capacity;
//};
//int main()
//{
//	vector<int>v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//template<class T>
//class vector
//{
//public:
//	vector():
//		arr(nullptr),
//		_size(0),
//		_capacity(0)
//	{
//
//	}
//	~vector()
//	{
//		delete[]arr;
//		_size = 0;
//		_capacity = 0;
//	}
//	void push_back(const T& x)
//	{
//		if (_size == _capacity)
//		{
//			int newpacacity = _capacity == 0 ? 4 : _capacity * 2;
//			T* temp = new T[newpacacity];
//			if (temp)
//			{
//				memcpy(temp, arr, sizeof(T) * _size);
//				delete[]arr;
//			}
//			arr = temp;
//			_capacity += newpacacity;
//		}
//		arr[_size] = x;
//		_size++;
//	}
//private:
//	T* arr;
//	int _size;
//	int _capacity;
//};
//int main()
//{
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	return 0;
//}