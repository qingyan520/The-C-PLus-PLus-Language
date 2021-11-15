#include<iostream>
#include<assert.h>
using namespace std;
template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K, V>kv) :
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
	pair<K, V>_kv;
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

	//����
	bool Insert(const pair<K,V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = _root;
		Node* cur = _root;
		while (cur)
		{
			if (kv.first > cur->_kv.first)
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


		//����ƽ�����ӣ�������ת
		while(parent!=nullptr)
		{
			if (parent->_right == cur)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}
		

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//cout << "fer" << endl;
				cur = parent;
			
				parent = parent->_parent;
			}
			//ƽ�����Ӳ������ˣ���Ҫ����ƽ������
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						//˵����ߵ����ڵ���������ұ����Ľڵ��������Ҫ�����ҵ���
						RomateR(parent);
					}
					else
					{
						//˵����Ҫ�������ҵ������ı�������״
						RomateLR(parent);
					}
				}

				else
				{
					if (cur->_bf == 1)
					{
						//˵���������߶ȴ����������߶ȣ���Ҫ��������
						RomateL(parent);
					}
					else
					{
						//������
						RomateRL(parent);
					}
				}


				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;

	}

	//�ҵ���
	void RomateR(Node* parent)
	{
		Node* grandparent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR != nullptr)
			subLR->_parent = parent;
		subL->_bf = parent->_bf = 0;
		subL->_right = parent;
		parent->_parent = subL;
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
	}


	//����
	void RomateL(Node* parent)
	{
		Node* grandparent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;
		subR->_bf = parent->_bf = 0;
		subR->_left = parent;
		parent->_parent = subR;
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

	//���ҵ���
	void RomateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RomateL(parent->_left);
		RomateR(parent);

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

	//������
	void RomateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RomateR(parent->_right);
		RomateL(parent);

		if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf=0;
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


	//�������
	void Inorder()
	{
		_Inorder(_root);
	}


	//�ж��ǲ���һ��AVL��
	bool Is_Banlance()
	{
		return _Is_Banlance(_root);
	}

private:

	void _Inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		return max(_Height(root->_left) + 1, _Height(root->_right) + 1);
	}

	bool _Is_Banlance(Node* root)
	{
		if (root == nullptr)
			return true;
		int right_Height = _Height(root->_right);
		int left_Height = _Height(root->_left);
		if ((right_Height - left_Height) != root->_bf)
		{
			cout << "ƽ�����ӷ����쳣��" << "right_Height - left_Height=" << right_Height - left_Height << "  " << "root->_kv.first=" << root->_kv.first << "  " << "root->_bf=" << root->_bf << endl;
			return false;
		}
		return abs(right_Height - left_Height)<2  && _Is_Banlance(root->_left) && _Is_Banlance(root->_right);
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