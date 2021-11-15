//����������ʣ�
//1.�������һ�Ŷ���������������ÿ���ڵ����������ɫ����ͺ�
//2.������и��׽ڵ����ʱ��ɫ�ڵ�
//3.�����ÿ��·���Ͼ�����ͬ�����ĺ�ɫ�ڵ�
//4.������к�ɫ�ڵ㲻������
//5.������У�nullptr�ڵ���ɫΪ��
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

	//���������븳ֵ���������


	//����
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
		if (BLACK != _root->_col)
		{
			cout<<"Υ�������������:���ڵ����Ϊ��ɫ" << endl;
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
		cout << root->_kv.first << ":" << root->_kv.second << endl;
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