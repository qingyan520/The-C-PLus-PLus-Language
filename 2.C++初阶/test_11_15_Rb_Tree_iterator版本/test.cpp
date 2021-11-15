#pragma once

//���������������ѵ㣺
//1.�������캯������ֵ��������أ���������
//�������캯��������copy���������ӽڵ�������Ҫ��ȷզ�Ƕ�����������һ��������������Ҫ���Ӹ��׽ڵ㣬������һ���⵼�¸��׽ڵ�һֱΪ�գ������������������ë�������ǵ��˵��������ͻ�������⣬����++��������س���
//��Σ��������һ������ɫ��������������Ҫ������copy���������½ڵ�ʱҪ�ǵù��캯��ͬʱ���������ڵ����ɫ�����Ծ͵ø���һ�£����ǰ�RbTreeNode�Ĺ��캯������һ��ʹ�����Խ���һ��Ĭ�ϵ���ɫ
//��ֵ���������Ҳ��ͬ���ĵ���

#include<iostream>
using namespace std;

//������ɫ��������ʶ�ڵ����ɫ
enum Color
{

	RED,
	BLACK,
};


//�ڵ��࣬������ʾһ���ڵ㣬T����ʶ���ݣ�������pair<>,Ҳ������һ��������
template<class T>
struct RbTreeNode
{
	RbTreeNode<T>* _left;
	RbTreeNode<T>* _right;
	RbTreeNode<T>* _parent;
	Color _col;

	//�ڵ����������
	T _data;


	RbTreeNode(const T& data,Color cl=RED) :
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_col(cl),
		_data(data)
	{

	}

	//struct 

};


//������������Ķ���
template<class T, class Ref, class Ptr>
struct _RbTreeIterator
{
	typedef RbTreeNode<T> Node;
	typedef typename _RbTreeIterator<T, Ref, Ptr> Self;

	Node* _node;

	

	_RbTreeIterator(Node* node) :_node(node)
	{

	}

	_RbTreeIterator(const Self&s)
	{
		_node = copy(s._node);
	}

	_RbTreeIterator& operator=(const Self& s)
	{
		if (this != &s)
		{
			Self temp(s);
			swap(_node, temp._node);
		}
		return *this;
	}

	~_RbTreeIterator()
	{
		Destory(_node);
		_node = nullptr;
	}

	//_RbTreeIterator(const Self& node)
	//{
	//	this->_node = new Self(node._node);
	//}

	Ref operator *()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		
		return &_node->_data;
	}

	bool operator!=(const Self& s)const
	{
		return _node!= s._node;
	}


	//ǰ��++
	Self& operator++()
	{
		Increament();
		return *this;
	}

	//����++���������
	Self operator++(int)
	{
		Self temp(*this);
		Increament();
		return temp;
	}

	//ǰ��--���������
	Self& operator--()
	{
		DeIncreament();
		return *this;
	}

	//����--���������
	Self operator--(int)
	{
		Self temp(*this);
		DeIncreament();
		return temp;
	}


private:

	//����++�����ʱ�Ĳ���
	void Increament()
	{
		//1.++�������Ҫ�ҵ�������һ�����Ԫ�أ������������Ϊ�գ���ô������������߾�������Ԫ��
		if (_node->_right != nullptr)
		{
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}
			_node = left;
		}
		//2.���������Ϊ�գ�˵����ǰ�����Ѿ�������ɣ���Ҫ���Ͻ��б�������ô�ҵ���һ��parent->_right!=cur�Ľڵ㼴Ϊ����
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
		
	}


	//--����������ڲ�����
	void DeIncreament()
	{
		//1.--��������أ���Ҫ�ҵ���һ�����Ԫ�أ����������������Ϊ�գ���ô�����������ұ߼�Ϊ��һ�����ֵ
		if (_node->_left != nullptr)
		{
			Node* right = _node->_left;
			while (right->_right != nullptr)
			{
				right = right->_right;
			}
			_node = right;
		}

		//2.������Ϊ�գ�˵����ǰ�������Ѿ��������ˣ���Ҫ�ҵ�parent->left!=cur��Ԫ�ؼ���
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left == cur)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}

	}

	//void copy(Node*)
	Node* copy(Node* root,Node*root_parent)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		Node* copyNode = new Node(root->_data,root->_col);
		if (root_parent != nullptr)
		{
			copyNode->_parent = root_parent;
		}
		root_parent = root;
		copyNode->_left = copy(root->_left,root);
		copyNode->_right = copy(root->_right,root);
		return copyNode;
	}


	//��������
	void Destory(Node*root)
	{
		if (root == nullptr)
		{
			return;
		}
		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}


};



//���������Ľṹ��K��Ҫ������ʶҪѰ�ҵ�ֵ��T��Ϊ������нڵ���������ͣ�KeyOfT�º���:�ҵ�T�е�keyֵ
template<class K, class T, class KeyOfT>
class RbTree
{
	friend  KeyOfT;
	typedef RbTreeNode<T> Node;
public:
	RbTree(Node*root=nullptr) :_root(root)
	{

	}

	//�ض������������
	typedef typename _RbTreeIterator<T, T&, T*> iterator;

	//��ʼ������
	iterator begin()
	{
		Node* left = _root;
		while (left&&left->_left!=nullptr)
		{
			left = left->_left;
		}
		return iterator(left);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	


	//���������븳ֵ���������
	RbTree(RbTree<K, T, KeyOfT>& Rb_Tree)
	{
		_root = copy(Rb_Tree._root,nullptr);
	}

	//��ֵ���������
	RbTree& operator=(RbTree<K, T, KeyOfT>& Rb_Tree)
	{
		if (this != &Rb_Tree)
		{
			this->_root = copy(Rb_Tree._root,nullptr);
		}
		return *this;
	}

	//��������
	~RbTree()
	{
		Destory(_root);
		//cout << "~RbTree()" << endl;
	}



	//����
	//1.�²���ڵ���ɫΪ��ɫ�����׽ڵ�Ϊ��ɫ������Ҫ���иı䣬ֱ���˳�
	//2.�²���ڵ���ɫΪ��ɫ�����׽ڵ�ҲΪ��ɫ
	//a.���������Ϊ��ɫ��
	//  ��parent��uncle�ڵ��Ϊ��ɫ��grandfather�ڵ��Ϊ��ɫ��Ȼ����cur=grandfather,parent=cur->_parent,�������ϸ���
	//b.���岻���ڻ���Ϊ��ɫ�����ʱ�����Ҫ������ת�ˣ�Ҳ���ǽ��͸߶ȣ�
	//  (1).��ʱgrandfather,parent,cur����߳�һ��ֱ�ߣ���ô��grandfather������������ת֮��parent->_col=BLACK,cur��grandfather��Ϊ��
	//  (2).grandfather->_left=parent,parent->_right=cur,Ҳ��������߳�һ�����ߣ���ʱ����Ҫ����parentΪ���������������grandfatherΪ�����������֮��cut->_col=BALCK,parent��grandfatherΪRED
	//  (3).��ʱgrandfather,parent,cur���ұ߳�һ��ֱ�ߣ���ô��grandfather������������ת֮��parent->_col=BLACK,cur��grandfather��Ϊ��
	//  (4).grandfather->_right=parent,parent->_left=cur,Ҳ�������ұ߳�һ�����ߣ���ʱ����Ҫ����parentΪ���������������grandfatherΪ�����������֮��cut->_col=BALCK,parent��grandfatherΪRED
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
		if (_root->_col != BLACK)
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
		cout << key(root->_data) << endl;
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

	//�������캯��
	Node* copy(Node* root,Node*root_parent)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* copyNode = new Node(root->_data,root->_col);
		if (root->_parent != nullptr)
			copyNode->_parent = root_parent;
		root_parent = root;
		copyNode->_left = copy(root->_left,root);
		copyNode->_right = copy(root->_right,root);
		return copyNode;
	}

	//��������
	void Destory(Node* &root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}


	Node* _root;

};
template<class K,class T>
struct KeyOfT
{
	K operator()(const T &kv)
	{
		return kv.first;
	}
};

int main()
{
	RbTree<int, pair<const int, int>, KeyOfT<int,pair<const int,int>>>m;
	//int arr[]{16,3,7,11,9,26,18,14,15};
	int arr[]{ 4,2,6,1,3,5,15,7,16,14};
	for (auto e : arr)
	{
		m.Insert(make_pair(e, e));

	}

	cout << endl;
	RbTree<int, pair<const int, int>, KeyOfT<int, pair<const int, int>>>s;
	s = m;
	RbTree<int, pair<const int, int>, KeyOfT<int, pair<const int, int>>>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
	cout << s.Is_RbTree() << endl;
}
