# BST以及BST的KV模型

## BST

### 1.BST的概念

BST(Binary Search Tree):二叉搜索树，它是一棵具有以下性质的树：

若它的左子树 不为空，则左子树上所有节点的值都小于根节点的值

若它的右子树不为空，则右子树上所有结点的值都大于根结点的值

它的左右子树也分别是二叉搜索树

如下图所示：

![image-20211024100347031](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211024100347031.png)

### 2.BST的模拟实现

BST的操作我们主要从它的增删查，遍历，拷贝构造函数，析构函数，赋值运算符重载来学习

1.节点的定义

```cpp
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
```

#### 1.插入元素：

##### 非递归版本

```
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
```

##### 递归版本：

```cpp
	bool insert_R(const k& key)
	{
		return _insert_R(root, key);
	}
	
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
```

#### 2.查找

##### 非递归版本：

```cpp
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
```

##### 递归版本：

```cpp
//2.Find
	Node* find_R(const k& key)
	{
		return _find_R(root, key);
	}
//2.查找
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


```

#### 3.中序遍历:

##### 非递归版本：

```cpp
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
```

##### 递归版本：

```cpp
//4.中序遍历
	void inroder_R()
	{
		_Inroder(root);
		cout << endl;
	}
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

```

#### 4.删除

##### 非递归版本：

```cpp
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
				//删除分好几种情况：
				//1.左右孩子都为空
				//2.只有右孩子
				//3.只有左孩子
				//4.左右孩子都有
				//其中第一种情况可以并到2或者3中去
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

				//右孩子为空，只有左孩子
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


				//否则，说明左右节点都有
				//这时候找到右子树中的最小值(位于右子树的最左端)或者左子树中的最大值(左子树的最右端)进行替换该节点的值，然后删除节点
				//这里我们采用选取右子树的最小值进行替换，然后删除
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
```

##### 递归版本：

```cpp
//3.删除
	bool erase_R(const k& key)
	{
		return _erase_R(root, key);
	}
//3.删除：递归方法进行删除
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
				//再次调用递归函数删掉Min_Right->val,然后使得——root->val=Min_Right->val
				k min_val = Min_Right->val;
				this->_erase_R(_root->right, min_val);
				_root->val = min_val;
			}
			return true;
		}
	}
```

#### 5.拷贝构造函数

```cpp
//拷贝构造函数
	BST(const BST<k>& t)
	{
		root=copy(t.root);
	}
	//5.拷贝构造的子函数
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
```

#### 6.赋值运算符重载

```cpp
	BST& operator=(const BST<k>& t)
	{
		if (this != &t)
		{
			BST<k>s(t);
			swap(root, s.root);
		}
		return *this;
	}
```

#### 7.析构函数

```cpp
	//析构函数
	~BST()
	{
		clear(root);
	}
	//6.析构函数的子函数
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
```

### 3.完整测试代码

[The-C-PLus-PLus-Language/2.C++初阶/test_10_17_BST的模拟实现 at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/2.C%2B%2B初阶/test_10_17_BST的模拟实现)

## BST的KV模型：

BST的KV模型是BST的一种变形，这里面它的节点值现在由key和value组成，通过key值来寻找到value值，其模拟实现方式基本和BST的实现方式是一致的，就是数据里面多了个value

下面给出最基础的节点值定义和插入，至于删除和上面的一样：

```cpp
#include<iostream>
#include<string.h>
using namespace std;

//BST的<K,V>模型：即此时树的节点保存有数据key,value,根key确定value
template<class K,class V>
struct BST_Node
{
	BST_Node(K _k = K(), V _value = V()) :
		key(_k),
		value(_value),
		left(nullptr),
		right(nullptr)
	{

	}
	K key;
	V value;
	struct BST_Node* left;
	struct BST_Node* right;
};

template<class K,class V>
class BST
{
	typedef BST_Node<K, V> Node;
public:
	BST() :
		root(nullptr)
	{

	}

	bool insert(const K& key, const V& value)
	{
		if (root == nullptr)
		{
			root = new Node(key, value);
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key > cur->key)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (key < cur->key)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (key > parent->key)
		{
			parent->right = cur;
		}
		else
		{
			parent->left = cur;
		}
	}

	void inorder()
	{
		_InOrder(root);
	}

	Node* find(const K& key)
	{
		Node* cur = root;
		while (cur)
		{
			if (key > cur->key)
			{
				cur = cur->right;
			}
			else if (key < cur->key)
			{
				cur = cur->left;
			}
			else
			{
				break;
			}
		}
		return cur;
	}






	~BST()
	{
		delete root;
		root = nullptr;
	}
private:
	void _InOrder(Node* _root)
	{
		if (_root == nullptr)
		{
			return;
		}
		_InOrder(_root->left);
		cout << "key:" << _root->key << "value:" << _root->value << endl;
		_InOrder(_root->right);
	}
	Node* root;
};

int main()
{
	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
	BST<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.find(str);
		if (ret == NULL)
		{
			countTree.insert(str, 1);
		}
		else
		{
			ret->value++;
		}
	}
	countTree.inorder();
	return 0;
}
```

完整测试代码：

[The-C-PLus-PLus-Language/2.C++初阶/test_10_22_BST的KV模型 at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/2.C%2B%2B初阶/test_10_22_BST的KV模型)

