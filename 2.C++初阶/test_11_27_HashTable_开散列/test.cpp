//哈希表开散列模拟实现：
//哈希表的开散列中表中每一个位置存放节点的指针，如果发生哈希冲突，那么就把他挂载到这个节点上去


#include<iostream>
#include<vector>
using namespace std;

//创建节点类型
template<class K,class V>
struct HashTableNode
{
	HashTableNode<K, V>* _next;
	pair<K, V>_kv;

	HashTableNode(const pair<K, V>& kv = pair<K, V>()) :
		_next(nullptr),
		_kv(kv)
	{

	}
};

//哈希函数：用于拿到每一个key，将其变为整形，方便除留取余法进行映射
template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
//模板的特化
template<>
struct Hash<string>
{
	size_t operator()(const string& key)
	{
		size_t ret = 1;
		for (int i = 0; i < key.size(); i++)
		{
			ret = ret * 131 + key[i];
		}
		return ret;
	}
};


//哈希表主体实现
template<class K, class V,class HashFunc=Hash<K>>
class HashTable_Open
{
	typedef HashTableNode<K, V> Node;

private:

	//我们认为控制哈希表的容量，让其容量变成素数，可减少哈希冲突
	size_t Get_Next_Size(size_t n)
	{
		static const size_t primeList[29] = {
			53ul,97ul,193ul,193ul,389ul,769ul,
			1543ul,3079ul,6151ul,12289ul,2493ul,
			49157ul,98317ul,196613ul,393241ul,786433ul,
			1572869ul,3145739ul,6291469ul,12582917ul,25165843ul,
			50331653ul,10063319ul,201326611ul,402653189ul,805306457ul,
			1610612741ul,3221225473ul,4294967291ul
		};
		for (int i = 0; i < 29; i++)
		{
			if (primeList[i] > n)
			{
				return primeList[i];
			}
		}
		return -1;

	}
public:

	bool Insert(const pair<K, V>& kv)
	{

		if (Find(kv.first) != nullptr)
			return false;

		//如果负载因子==1，进行增容
		if (_table.size() == _n)
		{
			//增容时我们选择该表节点的指向
			vector<Node*>newtable;
			size_t new_size=Get_Next_Size(_table.size());
			newtable.resize(new_size);
			for (size_t i = 0; i<_table.size(); i++)
			{
				//当前头节点不为空
				if (_table[i] != nullptr)
				{
					//从当前节点开始重新建立映射关系
					Node* cur = _table[i];
					while (cur!=nullptr)
					{
						HashFunc hf;
						//重新建立映射关系
						size_t index = hf(cur->_kv.first )% new_size;
						//链接前先保存当前节点
						Node* next = cur->_next;
						//头插法进行链接
						cur->_next = newtable[index];
						newtable[index] = cur;
						cur = next;
					}
					delete cur;
					cur = nullptr;
				}
			}
			swap(_table,newtable);
		}

		//每次利用头插法进行链接
		HashFunc hf;
		int index = hf(kv.first )% _table.size();
		Node* newnode = new Node(kv);
		newnode->_next = _table[index];
		_table[index] = newnode;
		++_n;
		return true;
	}

	Node* Find(const K& key)
	{
		if (_table.size() == 0)
			return nullptr;
		HashFunc hf;
		int index = hf(key) % _table.size();
		Node* cur = _table[index];
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return nullptr;
	}


	bool Erase(const K& key)
	{
		if (_table.size() == 0)
			return false;
		HashFunc hf;
		int index = hf(key) % _table.size();
		Node* cur = _table[index];
		Node* prev = nullptr;
		while (cur)
		{
			if (cur->_kv.first == key)
			{
				if (cur == _table[index])
				{
					_table[index] = cur->_next;
					delete cur;
					cur = nullptr;
				}
				else
				{
					prev->_next = cur->_next;
					delete cur;
					cur = nullptr;
				}
				_n--;
				return true;
			}

			prev = cur;
			cur = cur->_next;
		}
		return false;
	}
private:
	vector<Node*>_table;
	int _n;
};




int main()
{
	HashTable_Open<string, int>ht;
	string s[]{ "苹果","西瓜","苹果", "西瓜", "苹果", "苹果","苹果","玉米","小麦" };
	for (auto e : s)
	{
		HashTableNode<string, int>* ret = ht.Find(e);
		if (ret == nullptr)
		{
			ht.Insert(make_pair(e, 1));
		}
		else
		{
			ret->_kv.second++;
		}
	}
}