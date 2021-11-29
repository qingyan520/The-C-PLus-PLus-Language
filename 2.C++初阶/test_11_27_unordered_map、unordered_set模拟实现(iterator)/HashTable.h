#pragma once
#include<iostream>
#include<vector>
using namespace std;

//�����ڵ�����
template<class T>
struct HashTableNode
{
	HashTableNode<T>* _next;
	T _data;

	HashTableNode(const T&data=T()) :
		_next(nullptr),
		_data(data)
	{

	}
};



//��ϣ�����������õ�ÿһ��key�������Ϊ���Σ��������ȡ�෨����ӳ��
template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
//ģ����ػ�
template<>
struct Hash<string>
{
	size_t operator()(const string& key)
	{
		size_t ret = 1;
		for (size_t i = 0; i < key.size(); i++)
		{
			ret = ret * 131 + key[i];
		}
		return ret;
	}
};


//HashTable��������ģ��ʵ��
template<class K,class T,class KeyOfT,class HashFunc>
class HashTable_Open;

template<class K,class T,class KeyOfT,class HashFunc>
struct HashIterator
{
	typedef HashIterator<K, T, KeyOfT, HashFunc> Self;
	typedef HashTableNode<T> Node;
	typedef HashTable_Open<K, T, KeyOfT, HashFunc> HashTable;

	HashTable* _ht;
	Node* _node;

	HashIterator(Node* node, HashTable* p) :
		_ht(p),
		_node(node)
	{

	}

	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}


	Self& operator++()
	{
		KeyOfT kot;
		HashFunc hf;
		if (_node->_next != nullptr)
		{
			_node = _node->_next;
		}
		else
		{
			int index = hf(kot(_node->_data)) % _ht->_table.size()+1;
			for (; index < _ht->_table.size(); ++index)
			{
				if (_ht->_table[index] != nullptr)
				{
					_node = _ht->_table[index];
					break;
				}
			}
			if (index == _ht->_table.size())
			{
				_node = nullptr;
			}
		}
		return *this;
	}



};


//��ϣ������ʵ��
template<class K, class T, class KeyOfT, class HashFunc = Hash<K>>
class HashTable_Open
{
	typedef HashTableNode<T> Node;
	friend struct HashIterator<K,T,KeyOfT,HashFunc>;
private:


	//������Ϊ���ƹ�ϣ���������������������������ɼ��ٹ�ϣ��ͻ
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

	typedef HashIterator<K, T, KeyOfT, HashFunc> iterator;
	iterator begin()
	{
		//��ʼλ�ã��ҵ���һ����Ϊnullptr�Ľڵ�
		for (int i = 0; i < _table.size(); i++)
		{
			if (_table[i] != nullptr)
			{
				return iterator(_table[i], this);
			}
		}
		return iterator(nullptr, this);
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}


	pair<iterator,bool> Insert(const T& data)
	{

		KeyOfT Key;
		iterator it = Find(Key(data));
		if(it!= end())
			return make_pair(it,false);

		//�����������==1����������
		if (_table.size() == _n)
		{
			//����ʱ����ѡ��ñ�ڵ��ָ��
			vector<Node*>newtable;
			size_t new_size = Get_Next_Size(_table.size());
			newtable.resize(new_size);
			for (size_t i = 0; i < _table.size(); i++)
			{
				//��ǰͷ�ڵ㲻Ϊ��
				if (_table[i] != nullptr)
				{
					//�ӵ�ǰ�ڵ㿪ʼ���½���ӳ���ϵ
					Node* cur = _table[i];
					while (cur != nullptr)
					{
						HashFunc hf;
						KeyOfT Key;
						//���½���ӳ���ϵ
						size_t index = hf(Key(cur->_data)) % new_size;
						//����ǰ�ȱ��浱ǰ�ڵ�
						Node* next = cur->_next;
						//ͷ�巨��������
						cur->_next = newtable[index];
						newtable[index] = cur;
						cur = next;
					}
					delete cur;
					cur = nullptr;
				}
			}
			swap(_table, newtable);
		}

		//ÿ������ͷ�巨��������
		HashFunc hf;
		
		int index = hf(Key(data)) % _table.size();
		Node* newnode = new Node(data);
		newnode->_next = _table[index];
		_table[index] = newnode;
		++_n;
		return make_pair(iterator(newnode,this),true);
	}

	iterator Find(const K& key)
	{
		if (_table.size() == 0)
			return iterator(nullptr,this);
		HashFunc hf;
		KeyOfT Key;
		int index = hf(key) % _table.size();
		Node* cur = _table[index];
		while (cur)
		{
			if(Key(cur->_data) == key)
			{
				return iterator(cur,this);
			}
			cur = cur->_next;
		}
		return iterator(nullptr,this);
	}


	bool Erase(const K& key)
	{
		if (_table.size() == 0)
			return false;
		HashFunc hf;
		KeyOfT Key;
		int index = hf(key) % _table.size();
		Node* cur = _table[index];
		Node* prev = nullptr;
		while (cur)
		{
			if (Key(cur->_data) == key)
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

