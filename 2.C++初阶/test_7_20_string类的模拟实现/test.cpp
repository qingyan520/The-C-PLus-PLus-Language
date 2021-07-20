//Ŀ�ģ�ģ��ʵ��string��
//1.���캯��
//2.�������캯��
//3.��ֵ���������
//4.��������
//5.���ֱ�����ʽģ��ʵ��
//6.���룺push_back,append,+=,reserve(����)
//7.ɾ��


#include<iostream>
using namespace std;
namespace hello
{
	class string
	{
	public:

		//���캯��
		string(const char* str = "") :
			_str(nullptr),
			_size(strlen(str)),
			_capacity(strlen(str)+1)
		{
			if (str != nullptr)
			{
				_str = new char[strlen(str) + 1];
				strcpy(_str, str);

			}
		}
		//��ͳ�汾�Ŀ������캯���͸�ֵ���������
		////�������캯��
		//string(const string& str):
		//	_str(nullptr),
		//	_size(strlen(str._str)),
		//	_capacity(strlen(str._str)+1)
		//{
		//	_str = new char[strlen(str._str) + 1];
		//	strcpy(_str, str._str);

		//}

		////��ֵ���������
		//string& operator=(const string& str)

		//{
		//	if (&str != this)
		//	{
		//		delete []_str;
		//		_str = new char[strlen(str._str) + 1];
		//		strcpy(_str, str._str);
		//		_size = strlen(str._str);
		//		_capacity = _size + 1;
		//	}
		//	return *this;
		//}

		//�ִ��汾�Ŀ������캯���͸�ֵ��������أ�
		string(const string& str):
			_str(nullptr),
			_size(strlen(str._str)),
			_capacity(_size+1)
		{
			string temp(str._str);
			swap(_str, temp._str);
		}

		//�ִ��汾�ĸ�ֵ���������
		string& operator=(const string& str)
		{
			if (this != &str)
			{
				string temp(str._str);
				swap(_str, temp._str);
				_size = strlen(temp._str);
				cout << strlen(temp._str) << endl;
				_capacity = _size + 1;
			}
			return *this;
		}



		//�������ݸ���
		int size()
		{
			return _size;
		}

		//��������
		int capacity()
		{
			return _capacity;
		}

		//��������
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}


		//����C���Է����ַ���
		char* c_str()
		{
			return _str;
		}


		//string�����ݲ��֣�str������̬�����ڴ�ռ䣬size��¼��ǰԪ�ظ�����capacity������¼����
	private:
		char* _str;
		int _size;
		int _capacity;
	};
}

void test01()
{
	hello::string s="jeeeeeee";
	cout << s.c_str() << endl;
	hello::string s1 = "hello";
	cout << s1.c_str() << endl;
	s = s1;
	cout << s.c_str() << endl;
	cout << s1.c_str() << endl;
	cout << s.size() << endl;
	cout << s1.size() << endl;

}
int main()
{
	test01();
	return 0;
}