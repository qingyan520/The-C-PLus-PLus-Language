#include<iostream>
#include<stack>
using namespace std;

template<class k>
struct BSTNode
{

	BSTNode(const k&_k):
		val(_k),
		left(nullptr),
		right(nullptr)
	{

	}

	k val;
	 BSTNode<k>* left;
	 BSTNode<k>* right;

};

template<class k>
class BST
{
	typedef BSTNode<k> Node;
public:
	BST() :
		root(nullptr)
	{

	}

	//�������캯��
	BST(const BST<k>& t)
	{
		root=copy(t.root);
	}

	//��ֵ���������
	BST& operator=(const BST<k>& t)
	{
		if (this != &t)
		{
			BST<k>s(t);
			swap(root, s.root);
		}
		return *this;
	}

	//��������
	~BST()
	{
		clear(root);
	}



	//�ǵݹ�汾ʵ��
	//1.����Ԫ��
	bool insert(const k& _val)
	{
		if (root == nullptr)
		{
			root = new Node(_val);
			return true;
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->val > _val)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (_val > cur->val)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(_val);
		if (_val > parent->val)
		{
			parent->right = cur;
		}
		else
		{
			parent->left=cur;
		}
		return true;
	}




	//2.����Ԫ��
	Node* find(const k& _val)
	{
		Node* cur = root;
		while (cur)
		{
			if (_val > cur->val)
			{
				cur = cur->right;
			}
			else if (_val < cur->val)
			{
				cur = cur->left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	//3.ɾ��Ԫ��
	bool erase(const k&_val)
	{
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (_val > cur->val)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (_val < cur->val)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				//ɾ���ֺü��������
				//1.���Һ��Ӷ�Ϊ��
				//2.ֻ���Һ���
				//3.ֻ������
				//4.���Һ��Ӷ���
				//���е�һ��������Բ���2����3��ȥ
				if (parent!=nullptr&&cur->left == nullptr)
				{
					if (parent->right == cur)
					{
						parent->right = cur->right;
					}
					else
					{
						parent->left = cur->right;
					}
					return true;
				}

				//�Һ���Ϊ�գ�ֻ������
				else if (parent!=nullptr&&cur->right == nullptr)
				{
					if (parent->left == cur)
					{
						parent->left = cur->left;
					}
					else
					{
						parent->right = cur->left;
					}
					return true;
				}


				//����˵�����ҽڵ㶼��
				//��ʱ���ҵ��������е���Сֵ(λ���������������)�����������е����ֵ(�����������Ҷ�)�����滻�ýڵ��ֵ��Ȼ��ɾ���ڵ�
				//�������ǲ���ѡȡ����������Сֵ�����滻��Ȼ��ɾ��
				else
				{
					Node* Min_Right = cur->right;
					Node* Min_parent = cur;
					while (Min_Right->left != nullptr)
					{
						Min_parent = Min_Right;
						Min_Right = Min_Right->left;
					}

					swap(cur->val, Min_Right->val);
					if (Min_parent->left == Min_Right)
					{
						Min_parent->left = Min_Right->right;
					}
					else
					{
						Min_parent->right = Min_Right->right;
					}
					delete Min_Right;
					Min_Right = nullptr;
					return true;
				}
			}
		}
		return false;
	}


	//4.��������ķǵݹ�汾
	//����ջ���������
	void inroder()
	{
		if (root == nullptr)
		{
			cout << endl;
			return;
		}
		stack<Node*>st;
		Node* cur =root;
		while (cur!=nullptr||!st.empty())
		{
			if (cur != nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur= st.top();
				st.pop();
				if (cur != nullptr)
				{
					cout << cur->val << " ";
					cur = cur->right;
				}
			}
		}
		cout << endl;
	}










	//����������д�ݹ��汾����ɾ���
	//1.�ݹ�汾����
	bool insert_R(const k& key)
	{
		return _insert_R(root, key);
	}

	//2.Find
	Node* find_R(const k& key)
	{
		return _find_R(root, key);
	}

	//3.ɾ��
	bool erase_R(const k& key)
	{
		return _erase_R(root, key);
	}


	//4.�������
	void inroder_R()
	{
		_Inroder(root);
		cout << endl;
	}


private:



	//1.�ݹ�汾
	//����
	bool _insert_R(Node*&_root,const k& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		if (key > _root->val)
		{
			return _insert_R(_root->right, key);
		}
		else if (key < _root->val)
		{
			return _insert_R(_root->left, key);
		}
		else
		{
			return false;
		}
	}

	//2.����
	Node* _find_R(Node* _root, const k& key)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}
		if (key> _root->val)
		{
			return _find_R(_root->right, key);
		}
		else if (key < _root->val)
		{
			return _find_R(_root->left, key);
		}
		else
		{
			return _root;
		}
	}


	//3.ɾ�����ݹ鷽������ɾ��
	bool _erase_R(Node*&_root, const k& key)
	{
		if (_root == nullptr)
		{
			return false;
		}
		if (key > _root->val)
		{
			return _erase_R(_root->right, key);
		}
		else if (key < _root->val)
		{
			return _erase_R(_root->left, key);
		}
		else
		{
			if (_root->left == nullptr)
			{
				Node* del = _root;
				_root = _root->right;
				delete del;
			}
			else if (_root->right == nullptr)
			{
				Node* del = _root;
				_root = _root->left;
			}
			else
			{
				Node* Min_Right = _root->right;
				while (Min_Right->left != nullptr)
				{
					Min_Right = Min_Right->left;
				}
				//�ٴε��õݹ麯��ɾ��Min_Right->val,Ȼ��ʹ�á���root->val=Min_Right->val
				k min_val = Min_Right->val;
				this->_erase_R(_root->right, min_val);
				_root->val = min_val;
			}
			return true;
		}
	}


	//4.�ݹ�����������
	void _Inroder(Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		_Inroder(_root->left);
		cout << _root->val << " ";
		_Inroder(_root->right);
	}

	//5.����������Ӻ���
	Node* copy(Node* _root)
	{
		if (_root == nullptr)
		{
			return nullptr;
		}
		Node* copyNode = new Node(_root->val);
		copyNode->left = copy(_root->left);
		copyNode->right = copy(_root->right);
		return copyNode;
	}

	//6.�����������Ӻ���
	void clear(Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		clear(_root->left);
		clear(_root->right);
		delete _root;
	}




	Node* root;

};

int main()
{
	BST<int>s;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : a)
	{
		s.insert_R(e);
	}
	s.inroder_R();
	//s.find_R(5);
	for (auto e : a)
	{
		s.erase_R(e);
		s.inroder();
	}

	//s.erase_R(0);
	//s.inroder_R();
	//s.erase_R(1);
	//s.inroder_R();
	//s.erase_R(2);
	//s.inroder_R();
	//s.erase_R(3);
	//s.inroder_R();
	//s.erase_R(4);
	//s.inroder_R();
	//s.erase_R(5);
	//s.inroder_R();
	//s.erase_R(6);
	//s.inroder_R();
	//s.erase_R(7);
	//s.inroder_R();
	//s.erase_R(8);
	//s.inroder();
	//s.erase(9);
	//s.inroder();
	BST<int>t(s);
	t.inroder();
	BST<int>w;
	w = s;
	s.inroder();
	return 0;
}