#pragma once
#include<iostream>
using namespace std;
enum Color
{

	RED,
	BLACK,
};
template<class T>
struct RbTreeNode
{
	RbTreeNode<T>* _left;
	RbTreeNode<T>* _right;
	RbTreeNode<T>* _parent;
	Color _col;
	T _data;


	RbTreeNode(const T& data) :
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_col(RED),
		_data(data)
	{

	}
};

template<class T,class Ref,class Ptr>
struct _RbTreeIterator
{
	typedef RbTreeNode<T>Node;
	typedef _RbTreeIterator<T, Ref, Ptr> Self;

	Node* _node;

	_RbTreeIterator(Node* node) :_node(node)
	{

	}

	Ref operator *()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self operator++()
	{
		if (_node->_right != nullptr)
		{
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}
			_node = left;
		}
		else
		{
			Node* parent = _node->_parent;
			Node* cur = _node;
			while (parent != nullptr && parent->_right == cur)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}




};


template<class K, class T,class KeyOfT>
class RbTree
{
	typedef RbTreeNode<T> Node;
public:
	RbTree() :_root(nullptr)
	{

	}

	//
	typedef _RbTreeIterator<T, T&, T*> iterator;

	iterator begin()
	{
		Node* left = _root;
		while (left->_left)
		{
			left = left->_left;
		}
		return iterator(left);
	}

	iterator end()
	{
		return nullptr;
	}

	//���������븳ֵ���������


	//����
	pair<Node*, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = Color::BLACK;
			return make_pair(_root, true);
		}

		Node* cur = _root;
		Node* parent = _root;

		KeyOfT key;

		while (cur)
		{
			if (key(data) < key(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key(data) > key(cur->_data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		Node* newnode = new Node(data);
		if (key(data) > key(parent->_data))
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		cur = newnode;
		cur->_col = RED;
		//����������½ڵ����Ҫ����ɫ���е�������Ҫʱ������ת����Ҫ�����漸�������������
		//1.������׽ڵ������Ϊ�ڣ�����Ҫ���е���
		//2.������׽ڵ���ڲ���������ɫΪ��(��ʱһ�������游�ڵ㣬��Ϊ���׽ڵ�����Ǻ�ɫ���ܱ�֤�첻����)
		//a.��ʱ����ڵ������Ϊ��ɫ�ڵ㣬��ʹ�ø��׽ڵ������ڵ��ɺ�ɫ���游�ڵ��ɺ�ɫ��Ȼ��������ϸ���
		//b.��ʱ����ڵ㲻���ڻ���Ϊ��ɫ�ڵ�//
		//  ����¼���ڵ�ʹ��grandfather,parent,cur����ֱ�ߣ�����е���
		//  ����¼���ڵ�ʹ��grandfather��parent��cur�������֣������˫��
		//˫��֮�󷵻�

		while (parent != nullptr && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;

			//���жϵ�һ�����
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle != nullptr && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//˵������λ��һ��ֱ���ϣ��Ƚ���������Ȼ��parent->_col=BLACK,garndfather->_col=RED,cur->_col=RED;
					if (parent->_left == cur)
					{
						//��grandfatherΪ���������
						RotateR(grandfather);
						parent->_col = BLACK;
						cur->_col = RED;
						grandfather->_col = RED;
					}

					//˵�����߲���һ��ֱ���ϣ����ڵĲ�������---��-----�ң���Ҫ��������˫��
					else
					{
						RotateLR(grandfather);
						cur->_col = BLACK;
						parent->_col = RED;
						grandfather->_col = RED;
					}
					break;
				}
			}

			else
			{
				Node* uncle = grandfather->_left;
				if (uncle != nullptr && uncle->_col == RED)
				{
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}

				else
				{
					if (parent->_right == cur)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						cur->_col = RED;
						grandfather->_col = RED;
					}
					else
					{
						RotateRL(grandfather);
						cur->_col = BLACK;
						parent->_col = RED;
						grandfather->_col = RED;
					}
					break;
				}

			}

		}

		_root->_col = BLACK;
		return make_pair(newnode, true);
	}


	void Inorder()
	{
		_Inorder(_root);
	}

	//��֤�����
	//1.������Ƿ��������������(��������Ƿ�Ϊ��������)
	//2.������Ƿ���������������
	bool Is_RbTree()
	{
		if (_root == nullptr)
			return true;
		//�����ڵ��Ƿ��������
		if (_root->_col!=BLACK)
		{
			cout << "Υ�������������:���ڵ����Ϊ��ɫ" << endl;
			return false;
		}

		//��ȡ����һ��·���к�ɫ�ڵ�ĸ���
		size_t blackCount = 0;
		Node* cur = _root;
		while (cur)
		{
			if (BLACK == cur->_col)
			{
				blackCount++;
			}
			cur = cur->_left;
		}

		//����Ƿ���Ϻ���������ʣ�ÿ��·���к�ɫ�ڵ�ĸ������
		size_t k = 0;
		return _Is_RbTree(_root, k, blackCount);
	}



private:

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* grandfather = parent->_parent;

		parent->_left = subLR;
		if (subLR != nullptr)
			subLR->_parent = parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (grandfather == nullptr)
		{
			subL->_parent = nullptr;
			_root = subL;
		}
		else
		{
			if (grandfather->_left == parent)
			{
				grandfather->_left = subL;
				subL->_parent = grandfather;
			}
			else
			{
				grandfather->_right = subL;
				subL->_parent = grandfather;
			}
		}

	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* grandparent = parent->_parent;
		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

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

	//����˫��
	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	//����˫��
	void RotateRL(Node* parent)
	{
		RotateR(parent->_right);
		RotateL(parent);
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		KeyOfT key;
		cout << key(root->_data)<< endl;
		_Inorder(root->_right);
	}

	//��֤�����
	bool _Is_RbTree(Node* root, size_t k, const size_t blackCount)
	{
		//����nullptr֮���ж�k��blackCount�Ƿ����
		if (root == nullptr)
		{
			if (k != blackCount)
			{
				cout << "Υ������:�������ÿ��·���к�ɫ�ڵ�ĸ����������" << endl;
				return false;
			}
			return true;
		}

		//ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == root->_col)
		{
			k++;
		}

		//��⵱��ǰ�Ӵ�������˫���Ƿ�Ϊ��ɫ
		Node* parent = root->_parent;
		if (parent && parent->_col == RED && root->_col == RED)
		{
			cout << "Υ�������������:û������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		return _Is_RbTree(root->_left, k, blackCount) &&
			_Is_RbTree(root->_right, k, blackCount);

	}




	Node* _root;

};

