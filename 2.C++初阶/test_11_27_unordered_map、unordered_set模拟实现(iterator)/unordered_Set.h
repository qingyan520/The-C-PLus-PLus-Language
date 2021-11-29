#pragma once
#include"HashTable.h"
template<class K>
class unordered_set
{
private:
	struct KeyOfT
	{
		K operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename HashTable_Open<K, const K, KeyOfT>::iterator iterator;
	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}

	bool Insert(const K& key)
	{
		_ht.Insert(key);
		return true;
	}

	HashTableNode<const K>* Find(const K& key)
	{
		return _ht.Find(key);
	}
private:
	HashTable_Open<K, const K,KeyOfT >_ht;
};