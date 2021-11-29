#pragma once
#include"HashTable.h"
template<class K,class V>
class unordered_map
{
private:
	struct KeyOfT
	{
		const K operator()(const pair<const K, V> &kv)
		{
			return kv.first;
		}
	};
public:

	typedef typename HashTable_Open<K, pair<const K, V>, KeyOfT>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	V& operator[](const K&key)
	{
		pair<iterator, bool> it = _ht.Insert(make_pair(key, V()));
		return it.first._node->_data.second;
	}


	bool Insert(const pair<const K, V>& kv)
	{
		_ht.Insert(kv);
		return true;
	}
	HashTableNode<pair<const K, V>>* Find(const K& key)
	{
		return _ht.Find(key);
	}
	


private:
	HashTable_Open<K, pair<const K, V>, KeyOfT>_ht;
};
