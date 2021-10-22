
#include<iostream>
#include<string.h>
using namespace std;

//BST��<K,V>ģ�ͣ�����ʱ���Ľڵ㱣��������key,value,��keyȷ��value
template<class K,class V>
struct BST_Node
{
	BST_Node(K _k = K(), V _value = V()) :
		key(_k),
		value(_value),
		left(nullptr),
		right(nullptr)
	{

	}
	K key;
	V value;
	struct BST_Node* left;
	struct BST_Node* right;
};

template<class K,class V>
class BST
{
	typedef BST_Node<K, V> Node;
public:
	BST() :
		root(nullptr)
	{

	}

	bool insert(const K& key, const V& value)
	{
		if (root == nullptr)
		{
			root = new Node(key, value);
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key > cur->key)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (key < cur->key)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (key > parent->key)
		{
			parent->right = cur;
		}
		else
		{
			parent->left = cur;
		}
	}

	void inorder()
	{
		_InOrder(root);
	}

	Node* find(const K& key)
	{
		Node* cur = root;
		while (cur)
		{
			if (key > cur->key)
			{
				cur = cur->right;
			}
			else if (key < cur->key)
			{
				cur = cur->left;
			}
			else
			{
				break;
			}
		}
		return cur;
	}






	~BST()
	{
		delete root;
		root = nullptr;
	}
private:
	void _InOrder(Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		_InOrder(_root->left);
		cout << "key:" << _root->key << "value:" << _root->value << endl;
		_InOrder(_root->right);
	}
	Node* root;
};

int main()
{
	string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
	// ͳ��ˮ�����ֵĴ�
	BST<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.find(str);
		if (ret == NULL)
		{
			countTree.insert(str, 1);
		}
		else
		{
			ret->value++;
		}
	}
	countTree.inorder();
	return 0;
}