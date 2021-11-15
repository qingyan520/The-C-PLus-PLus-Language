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
		

		bool insert(const pair<const K,V>&key)
		{
			_t.Insert(key);
			return true;
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