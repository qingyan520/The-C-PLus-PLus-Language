[TOC]

# 红黑树/map/set模拟实现

## 红黑树(Rb_Tree)

### 最初版本红黑树

#### 红黑树的性质

> 红黑树的定义：
>
> 红黑树是一种二叉搜索树，但是每个节点上增加一个存储位置代表节点的颜色，可能是red/black,红黑树里面最长的的路径最多是最短路径的2倍，接近于平衡
>

> 红黑树的性质：
>
> 1.每个节点不是红色就是黑色
>
> 2.根节点是黑色
>
> 3.如果一个节点是红色的，那么它的两个孩子节点是黑色的(树中没有连续的红色节点)
>
> 4.对于每个节点，从该节点到其后代节点的简单路径上，均包含相同数目的黑色节点(每一条路径上具有相同数量的黑色节点)
>
> 5.每个叶子节点都是黑色的(此处叶子节点为NULL节点)



> 如何保证最长路径是最短路径的2倍：
>
> 最短路径全部由黑色节点构成：
>
> 最长路径：一黑一红，红色结点的数量和黑色节点的数量相等
>
> 假设黑色节点有N个，每条路径上有logN个黑色节点
>
> 最短路径：log(N)
>
> 最长路径长度：2*log(N)
>

> ps:正常的红黑树中，不一定会有全黑的最短路径和一黑一红的最长路径
>
>  AVLTree：高度控制平衡，严格平衡，每颗子树左右高度差不超过1
>
> 红黑树/RedBlackTree:通过颜色互斥来控制平衡，近似平衡，最长路径不超过最短路径的二倍
>





#### 红黑树的插入

```cpp
//红黑树的性质：
//1.红黑树是一颗二叉搜索树，它的每个节点具有两种颜色，红和黑
//2.红黑树中父亲节点必须时黑色节点
//3.红黑树每条路径上具有相同数量的黑色节点
//4.红黑树中红色节点不能连续
//5.红黑树中，nullptr节点颜色为黑

//PS:没有迭代器的红黑树，只实现了简单的插入功能

#include<iostream>
using namespace std;
enum Color
{

	RED,
	BLACK,
};
template<class K,class V>
struct RbTreeNode
{
	RbTreeNode<K, V>* _left;
	RbTreeNode<K, V>* _right;
	RbTreeNode<K, V>* _parent;
	Color _col;
	pair<K, V>_kv;
	

	RbTreeNode(const pair<K,V>&kv):
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_col(RED),
		_kv(kv)
	{

	}
};

template<class K,class V>
class RbTree
{
	typedef RbTreeNode<K, V> Node;
public:
	RbTree() :_root(nullptr)
	{

	}

	//拷贝构造与赋值运算符重载


	//插入
	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = Color::BLACK;
			return make_pair(_root, true);
		}

		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(cur, false);
			}
		}

		Node* newnode = new Node(kv);
		if (kv.first > parent->_kv.first)
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
				if (uncle != nullptr&&uncle->_col==RED)
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
		if (BLACK != _root->_col)
		{
			cout<<"违反红黑树的性质:根节点必须为黑色" << endl;
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
		cout << root->_kv.first << ":" << root->_kv.second << endl;
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




	Node* _root;

};


int main01()
{
	RbTree<int, int>r;
	//int arr[]{ 16,3,7,11,9,26,18,15,15 };
	int arr[]{ 4,2,6,1,3,5,7,16,14 };
	for (auto e : arr)
	{
		r.Insert(make_pair(e, e));
	}
	r.Inorder();
	r.Is_RbTree();
	return 0;
}
```

>   1.parent的颜色是黑色，不需要调整，插入完成
>
>  2.parent的颜色是红色，违反了规则3，需要进行处理(关键看叔叔)
>        a.cur为红，parent为红，grandfather为黑，uncle存在且为红，处理方案：
>         把父亲和叔叔变黑，祖父变红，保持一棵树黑色节点不变
>         继续往上处理
>
> ​	   b.cur为红，parent为红，uncle不存在/为黑(直线单旋)
>
> ​      c.cur为红，p为红，g为黑，u不存在/u为黑(折线双旋)
>

> 具象图二：
>
> ![image-20211112200545630](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211112200545630.png)
>

满足情况1，进行处理

![image-20211112200918034](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211112200918034.png)

继续往上处理：

![image-20211112201020298](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211112201020298.png)

![image-20211112201040416](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211112201040416.png)

![image-20211112201100528](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211112201100528.png)

p存在且为黑时停止，或者p不存在(把根变黑)



b.



![image-20211112204953398](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211112204953398.png)

右单旋+p变黑，g变红

c.cur为红，p为红，g为黑，u不存在/u为黑

![image-20211112210754840](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211112210754840.png)

#### 红黑树的验证

> 红黑树的验证：
>
> 1.中序遍历比有序
>
> 2.按照红黑树的性质进行查找
>
> a.根节点必须是黑色
>
> b.没有连续的红色节点
>
> c.每条路径上的黑色节点的数量必须是相等的
>

```cpp
bool Is_RbTree()
{
    if(_root==nullptr)
    {
        return true;
    }
    if(_root->_col!=BLACK)
    {
        return false;
    }
    Node*cur=_root;
    size_t blackCount=0;
    while(cur)
    {
        if(cur->_col==BLACK)
        {
            blackCount++;
        }
        cur=cur->_left;
    }
    size_t k=0;
    return _Is_RbTree(_root,k,blackCount);
}

bool _Is_RbTree(Node*root,size_t k,const size_t &blackCount)
{
    if(root==nullptr)
    {
        if(k!=blackCount)
        {
            cout<<"黑色节点不相等"<<endl;
            return false;
        }
        return true;
    }
    
    if(root->_col==RED&&root->_parent->_col==RED)
    {
        cout<<"存在连续的红色节点"<<endl;
       	return false;
    }
    if(root->_col==BLACK)
    {
        k++;
    }
    
    
    
    
    return _Is_RbTree(root->_left,k,blackCount)&&_Is_RbTree(root->_right,k,blackCount);
}

```

#### 项目地址

[The-C-PLus-PLus-Language/2.C++初阶/test_11_13_Rb_Tree模拟实现 at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/2.C%2B%2B初阶/test_11_13_Rb_Tree模拟实现)



### 带有iterator的红黑树

本项目实现了红黑树的简单迭代器分装，实现了红黑树迭代器前置++/–，后置++/–，*/->功能，实现了红黑树的拷贝构造功能，析构函数，赋值用算符重载

#### iterator实现

```cpp
template<class T, class Ref, class Ptr>
struct _RbTreeIterator
{
	typedef RbTreeNode<T> Node;
	typedef typename _RbTreeIterator<T, Ref, Ptr> Self;

	Node* _node;

	

	_RbTreeIterator(Node* node) :_node(node)
	{

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


};

```

#### 红黑树中实现

##### begin,end迭代器实现

```cpp
	//重定义迭代器名称
	typedef typename _RbTreeIterator<T, T&, T*> iterator;

	//开始迭代器
	//找到最左边的元素即为红黑树的开始迭代器
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

```

##### 构造函数

```cpp
RbTree(Node*root=nullptr) :_root(root)
	{

	}
```

ps:红黑树的节点外界拿不到，象征性的给一个节点代表，如果非要进行根据节点进行拷贝的话就必须是深拷贝了

##### 拷贝构造函数

```cpp
	RbTree(RbTree<K, T, KeyOfT>& Rb_Tree)
	{
		_root = copy(Rb_Tree._root,nullptr);
	}
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
```

##### 赋值运算符重载

```cpp
	//赋值运算符重载
	RbTree& operator=(RbTree<K, T, KeyOfT>& Rb_Tree)
	{
		if (this != &Rb_Tree)
		{
			this->_root = copy(Rb_Tree._root,nullptr);
		}
		return *this;
	}
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
```

##### 析构函数

```cpp
	~RbTree()
	{
		Destory(_root);
		//cout << "~RbTree()" << endl;
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

```

##### 插入+4种旋转

```cpp

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
	Node* _root;

};
```

##### 仿函数KeyOfT

```cpp
//这样我们只需要简单改变仿函数就可以改变比较方式，从而实现map,set
template<class K,class T>
struct KeyOfT
{
	K operator()(const T &kv)
	{
		return kv.first;
	}
};
```

##### 红黑树验证

```cpp

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
```

演示效果

```cpp

int main()
{
	//定义红黑树
	RbTree<int, pair<const int, int>, KeyOfT<int,pair<const int,int>>>m;
	//int arr[]{16,3,7,11,9,26,18,14,15};
	int arr[]{ 4,2,6,1,3,5,15,7,16,14};
	for (auto e : arr)
	{
		m.Insert(make_pair(e, e));

	}

	cout << endl;
	RbTree<int, pair<const int, int>, KeyOfT<int, pair<const int, int>>>s;
	s = m;//赋值运算符重载
	RbTree<int, pair<const int, int>, KeyOfT<int, pair<const int, int>>>::iterator it = s.begin();//迭代器遍历
	while (it != s.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;
	cout << s.Is_RbTree() << endl;//红黑树的验证
}
```

![image-20211120110112576](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211120110112576.png)

#### 项目地址

[The-C-PLus-PLus-Language/2.C++初阶/test_11_15_Rb_Tree_iterator版本 at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/2.C%2B%2B初阶/test_11_15_Rb_Tree_iterator版本)

## map与set的封装以及iterator

本项目主要实现利用红黑树封装map,set，实现map,set的正向迭代器，反向迭代器，实现对map,set上的简单插入，以及对map中operator[]的重载

### 对Rb_Tree进行改造

对原始Rb_Tree改造主要分为以下几个方面

#### 1.RbTreeNode数据类型改变

```cpp
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
```

将节点类型改为T,如果我们传过来的是pair<K,V>，那么节点就是一个K，V类型的map结构，如果传过来的单纯是一个T结构那么就是一个set结构

树中的改变

```cpp

template<class K, class T,class KeyOfT>
//将所有的数据类型都改为了T,K知识为了方便标识第一个元素，方便查找，KeyOfT为仿函数，主要是为了方便取出T中的key,方便进行比较
```

例如map中KeyOfT的定义：

```cpp
template<class K, class V>
struct KeyOfT
		{
			K operator()(const pair<const K, V>& key)
			{
				return key.first;
			}
		};
```

set中的KeyOfT

```cpp
template<class K>
struct KeyOfT
		{
			K operator()(const K& key)
			{
				return key;
			}
		};
```



#### 2.正向迭代器的封装

map/set中的迭代器与list迭代器相似，是一个类，类里面包含一个节点的指针，我们对这个指针进行++， - -操作

```
//下面这个正向迭代器我们实现了operator*,operator->,operator++/operator++(int),operator--/operator--(int)原算符重载
template<class T, class Ref, class Ptr>
struct _RbTreeIterator
{
	typedef RbTreeNode<T> Node;
	typedef typename _RbTreeIterator<T, Ref, Ptr> Self;
	typedef Ref Ref;
	typedef Ptr Ptr;
	Node* _node;

	

	_RbTreeIterator(Node* node) :_node(node)
	{

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


};
```

红黑树中的变化

```cpp
typedef typename _RbTreeIterator<T, T&, T*> iterator;

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
		return iterator(nullptr);
	}
```

#### 3.反向迭代器的封装

所谓的反向迭代器不过就是在一个类里面封装一个正向迭代器，然后进行与之相反的操作，但是注意它的返回值Ptr,Ref,比较难获得，我们需要它的返回值和正向迭代器一样，所以要获得正向迭代器的Ptr和Self,所以我们在_RbTreeIterator里面重定义Ptr,Ref，这样我们就能在反向迭代器中拿到Ptr,Ref了

```cpp
//反向迭代器里面封装正向迭代器
template<class Iterator>
struct Reverse_Iterator
{
//重新定义反向迭代器的名字
	typedef Reverse_Iterator<Iterator> Self;
//定义返回值，非常重要！
	typedef typename Iterator::Ptr Ptr;
	typedef typename Iterator::Ref Ref;


	Reverse_Iterator(Iterator it):
		_it(it)
	{}
//重载operator*
	Ref operator*()
	{
		return _it.operator*();
	}
//重载operator->
	Ptr operator->()
	{
		return _it.operator->();
	}


//重载前置++运算符
	Self& operator++()
	{
		_it.operator--();
		return *this;
	}
//重载前置--运算符
	Self& operator--()
	{
		_it.operator++();
		return *this;
	}
//重载operator!=运算符
	bool operator!=(const Self& s)
	{
		return _it!=s._it;
	}
//重载operator==运算符
	bool operator==(const Self& s)
	{
		return _it==s._it;
	}

	Iterator _it;
}
```

改变这一步对Rb_Tree的改变

```cpp
typedef typename Reverse_Iterator<iterator> reverse_iterator;

	reverse_iterator rbegin()
	{
		Node* right = _root;
		while (right && right->_right)
		{
			right = right->_right;
		}
		return	reverse_iterator(right);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(nullptr);
	}
```

#### 4.对于insert返回值的返回值

改变insert的返回值，其返回值变成迭代器类型，方便map对operator[]进行重载

```cpp
pair<iterator,bool>Insert(const T&data)
{
	return make_pair(iterator(cur),bool);
}
```



### map的封装

#### Map.h

```cpp
//对于map的封装
#pragma once
#include"Rb_Tree.h"
namespace world
{
	template<class K, class V>
	class map
	{
        //定义仿函数比较器
		struct KeyOfT
		{
			K operator()(const pair<const K, V>& key)
			{
				return key.first;
			}
		};
	public:
        //定义正向迭代器
		typedef typename RbTree<K, pair<const K, V>, KeyOfT>::iterator iterator;
        //定义反向迭代器
		typedef typename RbTree<K, pair<const K, V>, KeyOfT>::reverse_iterator reverse_iterator;
        
        //定义rbegin,rend
		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.rend();
		}

        
        //定义begin，end
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
		
        //插入元素
		pair<iterator,bool> insert(const pair<const K,V>&key)
		{
			return _t.Insert(key);
			
		}

        //operator[]重载
		V& operator[](const K&key)
		{
			pair<iterator,bool> ret =insert(make_pair(key,V()));
			return ret.first->second;
		}
				
        
        //判断它是不是一个map
		bool Is_Map()
		{
			return _t.Is_RbTree();
		}

		//一般不用这个
		void inorder()
		{
			_t.Inorder();
		}

	private:
        //里面封装了一棵红黑树
		RbTree<K, pair<const K, V>,KeyOfT>_t;
	};
}
```

#### Test_Map

简单测试自定义map的插入，正向迭代器以及反向迭代器

```cpp
#include"Set.h"
#include"Map.h"
#include<string.h>
int main()
{
	world::map<int, int>m;
	int arr[]{4,2,6,1,3,5,15,7,16,14};
	for (auto e : arr)
	{
		m.insert(make_pair(e, e));
	}
	cout<<m.Is_Map()<<endl;

	world::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << (*it).second << endl;
		++it;
	}
	world::map<int, int>::reverse_iterator rit = m.rbegin();
	while (rit != m.rend())
	{
		cout << (*rit).first << ":" << (*rit).second<< endl;
		++rit;
	}
}
```

![image-20211120115357546](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211120115357546.png)

测试自定义map的operator[]重载是否合理

```cpp
#include"Map.h"
#include<string.h>
int main()
{
	//world::map<int, int>m;
	//int arr[]{4,2,6,1,3,5,15,7,16,14};
	//for (auto e : arr)
	//{
	//	m.insert(make_pair(e, e));
	//}
	//cout<<m.Is_Map()<<endl;

	//world::map<int, int>::iterator it = m.begin();
	//while (it != m.end())
	//{
	//	cout << (*it).first << ":" << (*it).second << endl;
	//	++it;
	//}
	//world::map<int, int>::reverse_iterator rit = m.rbegin();
	//while (rit != m.rend())
	//{
	//	cout << (*rit).first << ":" << (*rit).second<< endl;
	//	++rit;
	//}


	//operator[]的测试
	world::map<string, string>m;
	m["left"] = "左边";
	m["left"] += ",剩余";
	m["right"] = "右边";
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}
```

![image-20211120115614201](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211120115614201.png)

### set的封装

本项目主要实现对红黑树进行分装使之称为set结构，实现对set的插入，遍历，正向迭代器和反向迭代器的实现

#### Set.h

```cpp
#pragma once
#include"Rb_Tree.h"
namespace hello
{
	template<class K>
	class set
	{
        //自定义比较器：取出T中的key元素
		struct KeyOfT
		{
			K operator()(const K& key)
			{
				return key;
			}
		};
	public:
        //封装RbTree里面的迭代器称为自己的正向迭代器
		typedef typename RbTree<K, const K, KeyOfT>::iterator iterator;
        //封装反向迭代器
		typedef typename RbTree<K, const K, KeyOfT>::reverse_iterator reverse_iterator;
        
        //rbegin,rend
		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.rend();
		}
		
        //begin,end
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
	
        //插入元素
		bool insert(const K&key)
		{
			_t.Insert(key);
			return true;
		}

        //判断底层是否为红黑树
		bool Is_Set()
		{
			
			return _t.Is_RbTree();
		}

		void inorder()
		{
			_t.Inorder();
		}

	private:
        //里面分装一个红黑树
		RbTree<K, const K,KeyOfT>_t;
	};
}
```

#### Test_Set

实现对自定义Set的测试，主要实现对自定义set的插入，正向遍历以及反向遍历

```cpp
#include"Set.h"
int main()
{
	hello::set<int>s;
	int arr[]{4,2,6,1,3,5,15,7,16,14};
	for (auto e : arr)
	{
		s.insert(e);
	}
	cout<<s.Is_Set()<<endl;
	cout << endl;
	//s.inorder();
	hello::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	hello::set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << (*rit) << " ";
		++rit;
	}
	cout << endl;
}
```

![image-20211120121104124](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211120121104124.png)



### 项目地址

[The-C-PLus-PLus-Language/2.C++初阶/test_11_15_map与set的模拟实现及iterator实现 at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/2.C%2B%2B初阶/test_11_15_map与set的模拟实现及iterator实现)

