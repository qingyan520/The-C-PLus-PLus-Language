//��ϣ��ɢ��ģ��ʵ�֣�
//��ϣ��Ŀ�ɢ���б���ÿһ��λ�ô�Žڵ��ָ�룬���������ϣ��ͻ����ô�Ͱ������ص�����ڵ���ȥ


#include<iostream>
#include<vector>
using namespace std;

//�����ڵ�����
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
		for (int i = 0; i < key.size(); i++)
		{
			ret = ret * 131 + key[i];
		}
		return ret;
	}
};


//��ϣ������ʵ��
template<class K, class V,class HashFunc=Hash<K>>
class HashTable_Open
{
	typedef HashTableNode<K, V> Node;

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

	bool Insert(const pair<K, V>& kv)
	{

		if (Find(kv.first) != nullptr)
			return false;

		//�����������==1����������
		if (_table.size() == _n)
		{
			//����ʱ����ѡ��ñ�ڵ��ָ��
			vector<Node*>newtable;
			size_t new_size=Get_Next_Size(_table.size());
			newtable.resize(new_size);
			for (size_t i = 0; i<_table.size(); i++)
			{
				//��ǰͷ�ڵ㲻Ϊ��
				if (_table[i] != nullptr)
				{
					//�ӵ�ǰ�ڵ㿪ʼ���½���ӳ���ϵ
					Node* cur = _table[i];
					while (cur!=nullptr)
					{
						HashFunc hf;
						//���½���ӳ���ϵ
						size_t index = hf(cur->_kv.first )% new_size;
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
			swap(_table,newtable);
		}

		//ÿ������ͷ�巨��������
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
	string s[]{ "ƻ��","����","ƻ��", "����", "ƻ��", "ƻ��","ƻ��","����","С��" };
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