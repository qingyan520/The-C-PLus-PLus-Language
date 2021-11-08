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
	AVLTree() :
		_root(nullptr)
	{

	}

	bool Insert(const pair<K,V>&kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}


		//1.�ҵ�Ҫ����Ľڵ�λ�ã�����ýڵ�
		Node* cur = _root;
		Node* parent = _root;
		while (cur!=nullptr)
		{
			if (kv.first >cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
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
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
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

					else
					{
						RomateLR(parent);
					}
				}

				else
				{
					if (cur->_bf == 1)
					{
						RomateL(parent);
					}
					else
					{
						RomateRL(parent);
					}
				}
				break;


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
	void RomateR(Node* parent)
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
	void RomateL(Node* parent)
	{
		Node* grandparent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;
		subR->_bf = parent->_bf = 0;
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
	}

	void RomateRL(Node* parent)
	{
		//��������������
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RomateR(parent->_right);

		RomateL(parent);

		//��ؼ��ľ���ƽ�����ӵĸ���
		if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}


	void RomateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		//��������������
		RomateL(parent->_left);
		RomateR(parent);

		//����ƽ������
		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}


	void Inorder()
	{
		_Inorder(_root);
	}


	//��֤������ǲ���AVL��

	bool Is_Banlance()
	{
		return _Is_Banlance(_root);
	}


private:

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second <<" "<<root->_bf << endl;
		_Inorder(root->_right);
	}
	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return max(_Height(root->_left) + 1, _Height(root->_right) + 1);
	}
	bool _Is_Banlance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int left_height = _Height(root->_left);
		int right_height = _Height(root->_right);
		if ((right_height-left_height) != root->_bf)
		{
			cout << "ƽ�����ӷ����쳣" << "right_height-left_height=" << right_height - left_height << "   " << "root->key=" << root->_kv.first<<"  " << "root->_bf=" << root->_bf << endl;
			return false;
		}

		return (right_height - left_height) == root->_bf &&
			_Is_Banlance(root->_left) &&
			_Is_Banlance(root->_right);

	}

	Node* _root;
};

int main()
{
	AVLTree<int, int>a;
	int arr[]{4,2,6,1,3,5,15,7,16,14};
	for (auto e : arr)
	{
		a.Insert(make_pair(e, e));
	}
	//a.Insert(make_pair(1, 1));
	a.Inorder();

	a.Is_Banlance();
	return 0;
}