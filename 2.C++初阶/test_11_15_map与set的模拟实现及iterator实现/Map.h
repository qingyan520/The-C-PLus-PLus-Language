#pragma once
#include"Rb_Tree.h"
namespace world
{
	template<class K, class V>
	class map
	{
		struct KeyOfT
		{
			K operator()(const pair<const K, V>& key)
			{
				return key.first;
			}
		};
	public:
		typedef typename RbTree<K, pair<const K, V>, KeyOfT>::iterator iterator;
		typedef typename RbTree<K, pair<const K, V>, KeyOfT>::reverse_iterator reverse_iterator;
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

		pair<iterator,bool> insert(const pair<const K,V>&key)
		{
			return _t.Insert(key);
			
		}

		V& operator[](const K&key)
		{
			pair<iterator,bool> ret =insert(make_pair(key,V()));
			return ret.first->second;
		}

		bool Is_Map()
		{
			return _t.Is_RbTree();
		}


		void inorder()
		{
			_t.Inorder();
		}

	private:
		RbTree<K, pair<const K, V>,KeyOfT>_t;
	};
}