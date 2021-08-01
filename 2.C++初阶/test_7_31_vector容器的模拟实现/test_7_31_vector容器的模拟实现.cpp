//vector容器的模拟实现

#include<iostream>
using namespace std;
namespace hello
{
	template<class T>
	class vector
	{
		typedef T* iterator;
	public:
		vector() :
			_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

		size_t size()
		{
			return _finish - _start;
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}


		//resize;
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* temp = new T[n];
				if (_start)
				{
					memcpy(temp, _start,sz);
					delete[] _start;
				}
				_start = temp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}


		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity()==0? 4:capacity*2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;
		}


		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t newcapacity = (0 == capacity() ? 1 : capacity() * 2);
				reserve(newcapacity);
				pos = _start + size();
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;

		}


		iterator erase(iterator pos)
		{
			iterator begin = pos + 1;
			while (begin()!= _finish)
			{
				*(begin - 1) = *begin;
				++begin();
			}
			--_finish;
			return pos;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};
}
int main()
{



	return 0;
}
