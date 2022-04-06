//Ϊʵ�ֿ������캯���͸�ֵ��������أ�����һ�����ü���
//Ϊʵ���̰߳�ȫ�����ӻ�����


#include<iostream>
#include<thread>
#include<mutex>
using std::cout;
using std::endl;
template<class T>
class shared_ptr {
private:
	T* _ptr;//ָ��
	int* _pcount;//���ü���
	std::mutex* _pmutex;//������
	

	//ԭ����++
	void AddRef()
	{
		_pmutex->lock();
		++(*_pcount);
		_pmutex->unlock();
	}


	//ԭ����--�����ü�����Ϊ0���ͷŵ�ǰ��Դ��ͬʱ�ͷŻ�����
	void RealseRef()
	{
		bool flage = false;
		_pmutex->lock();
		--(*_pcount);

		if (*_pcount == 0)
		{
			delete _ptr;
			delete _pcount;
			_ptr = nullptr;
			_pcount = nullptr;
		}
		_pmutex->unlock();
		if (flage)
		{
			delete _pmutex;
			_pmutex = nullptr;
		}
	}
public:

	//Ĭ�Ϲ��캯��
	shared_ptr(T* ptr):
		_ptr(ptr),
		_pcount(new int(1)),
		_pmutex(new std::mutex)
	{

	}

	//��������
	shared_ptr(const shared_ptr<T>& sp) :
		_ptr(sp._ptr),
		_pcount(sp._pcount),
		_pmutex(sp._pmutex)
	{

	}


	//��ֵ���������
	shared_ptr<T>& operator=(const shared_ptr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			//--���ü���
			this->RealseRef();
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			_pmutex = sp._pmutex;
			//��ǰ���ü���++
			this->AddRef();
		}
	}


	//��������
	~shared_ptr()
	{
		RealseRef();
	}
};
int main()
{
	shared_ptr<int>sp(new int(4));

	return 0;
}