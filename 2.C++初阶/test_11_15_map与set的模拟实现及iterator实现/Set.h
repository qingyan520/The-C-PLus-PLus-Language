#pragma once
#include"Rb_Tree.h"
namespace hello
{
	template<class K>
	class set
	{
		struct KeyOfT
		{
			K operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RbTree<K, const K, KeyOfT>::iterator iterator;
		typedef typename RbTree<K, const K, KeyOfT>::reverse_iterator reverse_iterator;
		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.rend();
		}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
	
		bool insert(const K&key)
		{
			_t.Insert(key);
			return true;
		}

		bool Is_Set()
		{
			
			return _t.Is_RbTree();
		}

		void inorder()
		{
			_t.Inorder();
		}

	private:
		RbTree<K, const K,KeyOfT>_t;
	};
}