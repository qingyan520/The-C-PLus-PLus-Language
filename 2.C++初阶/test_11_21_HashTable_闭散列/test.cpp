#include<iostream>
#include<vector>
using namespace std;
enum State
{

	EMPTY,
	EXITS,
	DELETE,
};
template<class K,class V>
struct HashData
{
	pair<K, V>_kv=make_pair(K(),V());
	State _state=EMPTY;
};
template<class K>
struct Hash
{
	size_t operator()(K k)
	{
		return k;
	}
};
//模板的特化
template<>
struct Hash<string>
{
	size_t operator()(string s)
	{
		size_t value = 0;
		for (int i = 0; i < s.size(); i++)
		{
			value += s[i];
			value *= 131;
		}
		return value;
	}
};

template<class K, class V,class HashFun=Hash<K>>
class HashTable
{
public:
	bool Insert(const pair<K, V>& kv)
	{
		HashData<K, V>* ret = Find(kv.first);
		if (ret != nullptr)
		{
			return false;
		}
			
		if (_table.size() == 0)
		{
			_table.resize(10);
		}
		else if (_table.size() != 0 && (double)n / double(_table.size()) > 0.7)
		{
			HashTable<K,V> newtable;
			newtable._table.resize(_table.size() * 2);
		
			for (size_t i = 0; i < _table.size(); i++)
			{
				if(_table[i]._state==EXITS)
				newtable.Insert(_table[i]._kv);
			}

			_table.swap(newtable._table);
		}
		HashFun value;
		size_t start = value(kv.first) % _table.size();
		size_t index = start;
		int i = 1;
		while (_table[index]._state == EXITS)
		{
			index = start + i;
			index %= _table.size();
			++i;
		}
		_table[index]._kv = kv;
		_table[index]._state = EXITS;
		n++;
		return true;
	}

	HashData<K, V>* Find(const K & key)
	{
		if (_table.size() == 0)
		{
			return nullptr;
		}
		HashFun value;
		size_t start = value(key) % _table.size();
		int index = start;
		int i = 1;
		while (_table[index]._state != EMPTY)
		{
			if (_table[index]._state == EXITS && _table[index]._kv.first == key)
			{
				return &_table[index];
			}
			index = start + i;
			index %= _table.size();
			i++;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		HashData<K, V>* ret = Find(key);
		if (ret == nullptr)
			return false;
		ret->_state = DELETE;
		n--;
		return true;
	}
	

	size_t size()
	{
		return n;
	}

	bool empty()
	{
		return n == 0;
	}

private:
	vector<HashData<K,V>>_table;
	size_t n=0;
};
int main()
{
	HashTable<int, int>ht;
	int arr[]{ 14,15,2,3,1,8,9,10,11,12 ,11};
	for (auto e : arr)
	{
		ht.Insert(make_pair(e, e));
	}
	HashTable<string, int>hs;
	string s[]{ "苹果","西瓜","苹果", "西瓜", "苹果", "苹果","苹果","玉米","小麦" };
	for (auto e : s)
	{
		HashData<string, int>* ret = hs.Find(e);
		if (ret == nullptr)
		{
			hs.Insert(make_pair(e,1));
		}
		else
		{
			ret->_kv.second++;
		}
	}
	return 0;
}