#include<iostream>
#include<assert.h>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K,V>kv):
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_bf(0),
		_kv(kv)
	{

	}

	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	pair<K,V>_kv;
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}


		//1.找到要插入的节点位置，插入该节点
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv->first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}


		//2.更新平衡因子
		while (parent != nullptr)
		{
			if (parent->_left == cur)
			{
				parent->_kv--;
			}
			else
			{
				parent->_kv++;
			}
			if (parent->_kv == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_parent == -2)
			{
				//不平衡了，需要进行旋转

				//如果parent->_bf==-2，
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						//这时候需要进行右旋转
						RomateR(parent);
					}
				}

				else
				{
					if (cur->_bf == 1)
					{
						RoMateL(parent);
					}
					else
					{

					}
				}



			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else
			{
				assert(false);
			}
		}
	}
	

	//当左边节点高于右边节点时，进行右旋
	void RomateR(Node*& parent)
	{
		//找到父亲节点
		Node* grandparent = parent->_parent;
		//找到左边的子节点
		Node* subL = parent->_left;

		//找到左边子节点的右节点
		Node* subLR = subL->_right;

		//让parent的左边子节点变成subLR
		parent->_left = subLR;
		if (subLR != nullptr)
		{
			subLR->_parent = parent;
		}

		subL->_bf = parent->_bf = 0;

		//让subL成为头节点或者局部父节点
		if (grandparent == nullptr)
		{
			subL->_parent = nullptr;
			_root = subL;
		}
		else
		{
			if (grandparent->_left == parent)
			{
				grandparent->_left = subL;
				subL->_parent = grandparent;
			}
			else
			{
				grandparent->_right = subL;
				subL->_parent = grandparent;
			}
		}

		//让parent成为subL的子节点
		subL->_right = parent;
		parent->_parent = subL;
		
	}

	//当右边节点高于左边节点时，进行左旋，即左边进行改变
	void RoMateL(Node*& parent)
	{
		Node* grandparent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)
		{
			subRL->_parent = parent;
		}

		subRL->_bf = parent->_bf = 0;
		if (grandparent == nullptr)
		{
			subR->_parent = nullptr;
			_root = subR;
		}
		else
		{
			if (grandparent->_left == parent)
			{
				grandparent->_left = subR;
				subR->_parent = grandparent;
			}
			else
			{
				grandparent->_right = subR;
				subR->_parent = grandparent;
			}
		}
		subR->_left = parent;
		parent->_parent = subR;
	}



private:
	Node* _root;
};

int main()
{
	AVLTree<int, int>a;

	return 0;
}