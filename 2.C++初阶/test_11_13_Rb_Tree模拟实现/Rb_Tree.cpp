//红黑树的性质：
//1.红黑树是一颗二叉搜索树，它的每个节点具有两种颜色，红和黑
//2.红黑树中父亲节点必须时黑色节点
//3.红黑树每条路径上具有相同数量的黑色节点
//4.红黑树中红色节点不能连续
//5.红黑树中，nullptr节点颜色为黑
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


int main()
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
}