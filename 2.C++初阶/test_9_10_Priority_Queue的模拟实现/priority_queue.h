#pragma once
#include<iostream>
#include<vector>
using namespace std;
namespace hello
{
	template<class T>
	class less//����ѣ��������
	{
	public:
		bool operator()(T& l, T& r)
		{
			return l < r;
		}
	};

	template<class T>
	class greater
	{
	public:
		bool operator()(T&l,T&r)
		{
			return l > r;
		}
	};

	template<class T,class Container =vector<T>,class Compare =less<T>>
	class priority_queue
	{
	public:
		//1.push
		void AdjustUp(size_t child)
		{
			Compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child]>_con[parent])
				if(com(_con[parent],_con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T&val)
		{
			_con.push_back(val);
			//���ϵ����㷨
			AdjustUp(_con.size() - 1);
		}

		//2.pop
		void AdjustDown(size_t parent)
		{
			Compare com;
			size_t child = 2 * parent + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child],_con[child+1]))
				{
					child++;
				}
				//if (_con[child] < _con[parent])
				if(com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = 2 * parent + 1;
				}
				else
				{
					break;
				}
			}
		}
		void pop()
		{
			//�ڶѵ�ɾ���㷨�У����Ƚ����Ѷ��Ͷ�β�����ݣ�Ȼ��ɾ����βԪ�أ����ʹ�����µ����㷨������������ʵ�λ��
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			//ʹ�����²����㷨������������ʵ�λ��
			AdjustDown(0);
		}

		//3.top
		T& top()
		{
			return _con[0];
		}

		//4.size
		size_t size()
		{
			return _con.size();
		}

		//5.empty
		bool empty()
		{
			return _con.empty();
		}


	private:
		Container _con;
	};
}

