//为实现拷贝构造函数和赋值运算符重载，增加一个引用计算
//为实现线程安全，增加互斥锁


#include<iostream>
#include<thread>
#include<mutex>
using std::cout;
using std::endl;
template<class T>
class shared_ptr {
private:
	T* _ptr;//指针
	int* _pcount;//引用计数
	std::mutex* _pmutex;//互斥锁
	

	//原子性++
	void AddRef()
	{
		_pmutex->lock();
		++(*_pcount);
		_pmutex->unlock();
	}


	//原子性--，引用计数变为0就释放当前资源，同时释放互斥锁
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

	//默认构造函数
	shared_ptr(T* ptr):
		_ptr(ptr),
		_pcount(new int(1)),
		_pmutex(new std::mutex)
	{

	}

	//拷贝构造
	shared_ptr(const shared_ptr<T>& sp) :
		_ptr(sp._ptr),
		_pcount(sp._pcount),
		_pmutex(sp._pmutex)
	{

	}


	//赋值运算符重载
	shared_ptr<T>& operator=(const shared_ptr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			//--引用计数
			this->RealseRef();
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			_pmutex = sp._pmutex;
			//当前引用计算++
			this->AddRef();
		}
	}


	//析构函数
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