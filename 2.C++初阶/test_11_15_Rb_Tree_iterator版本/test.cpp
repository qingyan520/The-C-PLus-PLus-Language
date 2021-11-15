#pragma once

//改造红黑树遇到的难点：
//1.拷贝构造函数，赋值运算符重载，析构函数
//拷贝构造函数在利用copy函数链接子节点是首先要明确咋们定义的这颗树是一个三叉链，所以要链接父亲节点，这是其一，这导致父亲节点一直为空，所以中序遍历看不出毛病，但是到了迭代器这块就会出现问题，导致++运算符重载出错
//其次，红黑树是一颗有颜色的树，所以我们要在利用copy函数构造新节点时要记得构造函数同时构造出这个节点的颜色，所以就得改造一下，我们把RbTreeNode的构造函数改造一下使他可以接受一个默认的颜色
//赋值运算符重载也是同样的道理

#include<iostream>
using namespace std;

//定义颜色，用来标识节点的颜色
enum Color
{

	RED,
	BLACK,
};


//节点类，用来表示一个节点，T来标识数据，可以是pair<>,也可以是一个单类型
template<class T>
struct RbTreeNode
{
	RbTreeNode<T>* _left;
	RbTreeNode<T>* _right;
	RbTreeNode<T>* _parent;
	Color _col;

	//节点里面的数据
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


//红黑树迭代器的定义
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


	//前置++
	Self& operator++()
	{
		Increament();
		return *this;
	}

	//后置++运算符重载
	Self operator++(int)
	{
		Self temp(*this);
		Increament();
		return temp;
	}

	//前置--运算符重载
	Self& operator--()
	{
		DeIncreament();
		return *this;
	}

	//后置--运算符重载
	Self operator--(int)
	{
		Self temp(*this);
		DeIncreament();
		return temp;
	}


private:

	//重载++运算符时的操作
	void Increament()
	{
		//1.++运算符即要找到它的下一个最大元素，如果右子树不为空，那么右子树的最左边就是所求元素
		if (_node->_right != nullptr)
		{
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}
			_node = left;
		}
		//2.如果右子树为空，说明当前子树已经遍历完成，需要向上进行遍历，那么找到下一个parent->_right!=cur的节点即为所求
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


	//--运算符重载内部操作
	void DeIncreament()
	{
		//1.--运算符重载，即要找到上一个最大元素，如果它的左子树不为空，那么左子树的最右边即为上一个最大值
		if (_node->_left != nullptr)
		{
			Node* right = _node->_left;
			while (right->_right != nullptr)
			{
				right = right->_right;
			}
			_node = right;
		}

		//2.左子树为空，说明当前左子树已经遍历完了，需要找到parent->left!=cur的元素即可
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


	//析构函数
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



//定义红黑树的结构，K主要用来标识要寻找的值，T即为红黑树中节点的数据类型，KeyOfT仿函数:找到T中的key值
template<class K, class T, class KeyOfT>
class RbTree
{
	friend  KeyOfT;
	typedef RbTreeNode<T> Node;
public:
	RbTree(Node*root=nullptr) :_root(root)
	{

	}

	//重定义迭代器名称
	typedef typename _RbTreeIterator<T, T&, T*> iterator;

	//开始迭代器
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

	


	//拷贝构造与赋值运算符重载
	RbTree(RbTree<K, T, KeyOfT>& Rb_Tree)
	{
		_root = copy(Rb_Tree._root,nullptr);
	}

	//赋值运算符重载
	RbTree& operator=(RbTree<K, T, KeyOfT>& Rb_Tree)
	{
		if (this != &Rb_Tree)
		{
			this->_root = copy(Rb_Tree._root,nullptr);
		}
		return *this;
	}

	//析构函数
	~RbTree()
	{
		Destory(_root);
		//cout << "~RbTree()" << endl;
	}



	//插入
	//1.新插入节点颜色为红色，父亲节点为黑色，不需要进行改变，直接退出
	//2.新插入节点颜色为红色，父亲节点也为红色
	//a.叔叔存在且为红色：
	//  将parent和uncle节点变为黑色，grandfather节点变为红色，然后让cur=grandfather,parent=cur->_parent,继续向上跟新
	//b.叔叔不存在或者为黑色：这个时候就需要进行旋转了，也就是降低高度，
	//  (1).此时grandfather,parent,cur在左边成一条直线，那么以grandfather进行右旋，旋转之后将parent->_col=BLACK,cur和grandfather变为红
	//  (2).grandfather->_left=parent,parent->_right=cur,也就是在左边成一条折线，这时候需要先以parent为轴进行左旋，再以grandfather为轴进行右旋，之后将cut->_col=BALCK,parent和grandfather为RED
	//  (3).此时grandfather,parent,cur在右边成一条直线，那么以grandfather进行左旋，旋转之后将parent->_col=BLACK,cur和grandfather变为红
	//  (4).grandfather->_right=parent,parent->_left=cur,也就是在右边成一条折线，这时候需要先以parent为轴进行右旋，再以grandfather为轴进行左旋，之后将cut->_col=BALCK,parent和grandfather为RED
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
		//红黑树插入新节点后需要对颜色进行调整，必要时进行旋转，主要分下面几种情况进行讨论
		//1.如果父亲节点存在且为黑，则不需要进行调整
		//2.如果父亲节点存在并且它的颜色为红(此时一定具有祖父节点，因为父亲节点必须是红色才能保证红不连续)
		//a.此时叔叔节点存在且为红色节点，则使得父亲节点和叔叔节点变成红色，祖父节点变成黑色，然后继续向上更新
		//b.此时叔叔节点不存在或者为黑色节点//
		//  如果新加入节点使得grandfather,parent,cur构成直线，则进行单旋
		//  如果新加入节点使得grandfather，parent，cur构成折现，则进行双旋
		//双旋之后返回

		while (parent != nullptr && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;

			//先判断第一种情况
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
					//说明三者位于一条直线上，先进行右旋，然后parent->_col=BLACK,garndfather->_col=RED,cur->_col=RED;
					if (parent->_left == cur)
					{
						//以grandfather为轴进行右旋
						RotateR(grandfather);
						parent->_col = BLACK;
						cur->_col = RED;
						grandfather->_col = RED;
					}

					//说明三者不在一条直线上，现在的布局是左---左-----右，需要进行左右双旋
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

	//验证红黑树
	//1.检查其是否满足二叉搜索树(中序遍历是否为有序序列)
	//2.检测其是否满足红黑树的性质
	bool Is_RbTree()
	{
		if (_root == nullptr)
			return true;
		//检测根节点是否满足情况
		if (_root->_col != BLACK)
		{
			cout << "违反红黑树的性质:根节点必须为黑色" << endl;
			return false;
		}

		//获取任意一条路径中黑色节点的个数
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

		//检测是否符合红黑树的性质，每条路径中黑色节点的个数相等
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

	//左右双旋
	void RotateLR(Node* parent)
	{
		RotateL(parent->_left);
		RotateR(parent);
	}

	//右左双旋
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

	//验证红黑树
	bool _Is_RbTree(Node* root, size_t k, const size_t blackCount)
	{
		//到达nullptr之后，判断k和blackCount是否相等
		if (root == nullptr)
		{
			if (k != blackCount)
			{
				cout << "违反性质:红黑树中每条路径中黑色节点的个数必须相等" << endl;
				return false;
			}
			return true;
		}

		//统计黑色节点的个数
		if (BLACK == root->_col)
		{
			k++;
		}

		//检测当当前接待你与其双亲是否都为红色
		Node* parent = root->_parent;
		if (parent && parent->_col == RED && root->_col == RED)
		{
			cout << "违反红黑树的性质:没有连在一起的红色节点" << endl;
			return false;
		}

		return _Is_RbTree(root->_left, k, blackCount) &&
			_Is_RbTree(root->_right, k, blackCount);

	}

	//拷贝构造函数
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

	//析构函数
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
