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


		//1.�ҵ�Ҫ����Ľڵ�λ�ã�����ýڵ�
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


		//2.����ƽ������
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
				//��ƽ���ˣ���Ҫ������ת

				//���parent->_bf==-2��
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						//��ʱ����Ҫ��������ת
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
	

	//����߽ڵ�����ұ߽ڵ�ʱ����������
	void RomateR(Node*& parent)
	{
		//�ҵ����׽ڵ�
		Node* grandparent = parent->_parent;
		//�ҵ���ߵ��ӽڵ�
		Node* subL = parent->_left;

		//�ҵ�����ӽڵ���ҽڵ�
		Node* subLR = subL->_right;

		//��parent������ӽڵ���subLR
		parent->_left = subLR;
		if (subLR != nullptr)
		{
			subLR->_parent = parent;
		}

		subL->_bf = parent->_bf = 0;

		//��subL��Ϊͷ�ڵ���߾ֲ����ڵ�
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

		//��parent��ΪsubL���ӽڵ�
		subL->_right = parent;
		parent->_parent = subL;
		
	}

	//���ұ߽ڵ������߽ڵ�ʱ����������������߽��иı�
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