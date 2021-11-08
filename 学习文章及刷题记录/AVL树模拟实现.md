# AVL树的模拟实现

![image-20211105190719119](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211105190719119.png)

```cpp
#include<iostream>
#include<string.h>
using namespace std;
template <class K,vlass V>
struct AVLTreeNode
{   
    AVLTreeNode(const pair<K,V>&kv):
    _kv.first(kv.first),
    _kv.second(kv.second),
    _left(nullptr),
    _right(nullptr),
    _parent(nullptr),
    _bf(0)
    {
        
    }
    
    AVLTreeNode<K,V>*_left;
    AVLTreeNode<K,V>*_right;
    AVLTreeNode<K,V>*_parent;
    int _bf;//平衡因子
    
    pair<K,V>_kv;
};
template<class K,class V>
class AVLTree
{
    public:
    typedef AVLTreeNode<K,V> Node;
    AVLTree():
    _root(nullptr)
    {
        
    }
    
    //拷贝构造和赋值需要深拷贝
    
    void _Destoey(Node*root)
    {
        if(root==nullptr)
        {
            return;
        }
        _Dserory(root->left);
        _Destory(root->right);
     	delete root;
    }
    ~AVLTree()
    {
        _Destory(_root);
        _root=nullptr;
    }
    V&operator[](const K&key)
    {
        pair<Node*,bool>ret=Insert(make_pair(key,V());
        return ret.first->_kc.second;
    }
    
    
    pair<Node*,bool> Insert(const pair<K,V>&kv)
    {
        if(_root==nullptr)
        {
            _root=new Node(kv);
            return make_pair<_root,true>;
        }
        //找到存储位置，插入数据
        Node*parent=_root;
        Node*cur=_root;
        while(cur)
        {
            if(kv.first<cur->kv.first)
            {
                parent=cur;
                cur=cur->_left;
            }
            else if(kv.first>cur->kc.first)
            {
                parent=cur;
                cur=cur->_right;
            }
            else
            {
                return false;
            }
        }
        cur=new Node(kv);
        if(kc.fisrt>parent->kv.first)
        {
            parent->_right=cur;
            cur->_parent=parent;
        }
        else
        {
            parent->_left=cur;
            cur->_parent=parent;
        }
        
        //控制平衡
        
        //1.更新平衡因子：插入一个一节点，这个节点的祖先节点的平衡因子可能发生改变，平衡因子需要更新
        //倒着往上走
        //新增节点在paretn右边，paretn->bf++
        //新增节点在parent左边,parent->bf--
        //如果parent的平衡因子等于1or-1,继续往上跟新，说明parent所在子树的高度变了
        //如果parent的平衡因子等于0，停止跟新，说明两边平衡了
        //如果parent等于2or-2已经出现不平衡，需要旋转处理
        
        //1.更新平衡因子
        //2.不平衡则需要旋转
        while(parent!=nullptr)
        {
            if(parent->left==cur)
            {
                parent->_bf--;
            }
            else if(parent->right==cur)
            {
                parent->_bf++;
            }
            if(parent->_bf==0)
            {
                break;
            }
            else if(parent->_bf==1||parent->_bf==-1)
            {
                //继续往上更新
                cur=parent;
            	parent=parent->_parent;
            }
            else if(parent->_bf==2||parent->_bf==-2)
            {
                //parent所在的子树已经不平衡，旋转处理
                if(parent->_bf==-2)
                {
                    if(cur->_bf=-1)
                    {
                        //有单旋转
                        ROtateR(parent);
                    }
                   
                }
                else
                {
                    if(cur->_bf==-1)
                    {
                        
                    }
                }
                break;
            }
            else
            {
                //插入节点之前，树中的平衡因子bf出错了，需要检查其它逻辑
                //
                assert(false);
            }
           
        }
        
        return true;
        
    }
    void RotateR(Node*&parent)
    {
        Node*subL=parent->_left;
        Node*subLR=subL->_right;
        Node*Parent=parent->_parent;
        parent->_left=subLR;
        
        if(subLR!=nullptr)
        subLR->_parent=parent;
        
        
        subL-->_bf=paretn->-bf=0;
        if(Parent==nullptr)
        {
            subL->_parent=nullptr;
             _root=subL;
        }
        else
        {
            if(Parent->left==parent)
            {
                Parent->left=subL;
                subL->parent->Parent;
            }
            else
            {
                Parent->right=subL;
                subL->_parent=Parent;
            }
        }
          subL->_right=parent;
        parent->_parent=subL;
        
    }
    
    void RomateL(Node*&parent)
    {
        Node*grandparent=parent->_parent;
        Node*subR=parent->_right;
        Node*subRL=subR->_left;
        parent->_right=subRL;
        if(subRL!=nullptr)
            subRL->_parent=parent;
        subR->left=parent;
        parent->_parent=subR;
        subR->_bf=parent->_bf=0;
        if(grandparent==nullptr)
        {
            subR->_parent=nullptr;
            _root=subR;
        }
        else
        {
            if(grandparent->_left==parent)
            {
                grandparent->_left=subR;
                subR->_parent=grandparent;
                
            }
            else
            {
                grandparent->_right=subR;
                grandparent->parent=subR;
            }
        }
    }
    
    void RomateLR(Node*&parent)
    {
        Node*subL=parent->_left;
        Node*subLR=subL->_right;
        int bf=subLR->_bf;
        RomateL(parent->_left);
        RomateR(parent);
        if(bf==-1)
        {
            subL->_bf=0;
            parent->_bf=1;
            subLR->_bf=0;
        }
        else if(bf==1)
        {
            parent->_bf=0;
            subL->_bf=-1;
            subLR->_bf=0;
        }
        else if(bf==0)
        {
            parent->_bf=0;
            subL->_bf=0;
            subLR->_bf=0;
        }
        else
        {
            assert(false);
        }
    }
    
    
    void RomateRL(Node*&parent)
    {
        Node*subR=parent->_right;
        Node*subRL=subR->right;
        int _bf=subRL->_bf;
        RomateR(parent->_right);
  
        RomateL(parent);
        
        if(_bf==1)
        {
            subR->_bf=0;
            parent->_bf=-1;
            subRL->_bf=0;
        }
        else if(_bf==-1)
        {
            parent->_bf=0;
            subR->_bf=1;
            subRL->_bf=0;
        }
        else if(_bf==0)
        {
            parent->_bf=0;
            subR->_bf=0;
            subRL->_bf=0;
        }
        else
        {
            assert(false);
        }
    }
    
    
    
    Node*find(const K&key)
    {
     	Node*cur=_root;
        while(cur)
        {
            if(key<cur->_kc.first)
            {
                cur=cur->left;
            }
            else if(key>cur->_kv.first)
            {
                cur=cur->right;
            }
            else
            {
                return true;
            }
        }
        return nullptr;
    }
    
    bool Erase(const K&key)
    {
        
        return fasle;
    }
    
    void _Inorder(Node*root)
    {
        if(root==nullptr)
            return ;
        _Inorder(root->left);
        cout<<root->_kv.first<<":"<<root->_kv.second<<endl;
        _Inorder(root->right);
    }
    
    void Inorder()
    {
        _Inorder(_root);
    }
    
    int _Height(Node*root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        return max(_Height(root->left)+1,_Height(root->right)+1);
    }
    
    bool _IsBanlance(Node*root)
    {
     	if(root==nullptr)
            return true;
        int leftHeight=_Height(root->left);
        int rightHeight=_height(root->right);
        if(rightHeight-leftHeight!=root->_bf)
        {
            cout<<"平衡因子异常"<<root->_kv.first<<endl;
            return false;
        }
        return abs(rightHeight-leftHeight)<2&&_sBanlance(root->left)
            &&IsBanlance(root->_right);
    }
    
    bool IsAVLTree()
    {
        return _IsBanlance(_root);
    }
    
    private:
    Node*_root;
}
```

![image-20211105193612764](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211105193612764.png)

## AVL树的四种旋转

### 1.新节点插入较高左子树的左侧----左左：右单旋

![image-20211108141022895](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211108141022895.png)



```cpp
void RomateR(Node* parent)
	{
		//找到父亲节点
		Node* grandparent = parent->_parent;
		//找到左边的子节点
		Node* subL = parent->_left;

		//找到左边子节点的右节点
		Node* subLR = subL->_right;

		//让parent的左边子节点变成subLR
		parent->_left = subLR;
		if (subLR != nullptr)
		{
			subLR->_parent = parent;
		}
		//更新平衡因子
		subL->_bf = parent->_bf = 0;

		//让subL成为头节点或者局部父节点
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

		//让parent成为subL的子节点
		subL->_right = parent;
		parent->_parent = subL;
		
	}

```

### 2.新节点插入较高右子树的右侧----右右：左单旋

![image-20211108141313828](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211108141313828.png)



```cpp
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
```

### 3.节点插入到左子树的右侧：----左右：先左单旋再右单旋

![image-20211108141519349](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211108141519349.png)

将双旋变为单旋然后再旋转，即：先对30进行左单旋，然后再对90进行右单旋，旋转之后考虑平衡因子的更新

![image-20211108142437290](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211108142437290.png)



```cpp
	void RomateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		//先左旋，再右旋
		RomateL(parent->_left);
		RomateR(parent);

		//更新平衡因子
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
```

### 4.新节点插入较高右子树的左侧----右左：先有单旋再左单旋

![image-20211108142750122](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211108142750122.png)

```cpp
	void RomateRL(Node* parent)
	{
		//先右旋，再左旋
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RomateR(parent->_right);

		RomateL(parent);

		//最关键的就是平衡因子的更新
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
```

> 总结：
>
> 假如以parent为根的子树不平衡，即parent的平衡因子为2或者-2，分以下情况进行考虑
>
> 1.parent的平衡因子为-2，说明parent的左子树高，parent的左子树为subL,
>
> 当subL的平衡因子为-1时，执行右单旋
>
> 当subL的平衡因子为1时，执行左右双旋
>
> 2.parent的平衡因子为2时，说明parent的右子树高，parent的右子树为subR
>
> 当subR的平衡因子为1时，执行左单旋
>
> 当subL的平衡因子为-1时，执行右左双旋

## AVL树的验证

> AVL树是在二叉搜索树的基础上加入了平衡性的限制，因此要验证AVL树，可以分两步：
>
> 1.中序遍历得到一个有序序列

```cpp
	void Inorder()
	{
		_Inorder(_root);
	}
	
		void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second <<" "<<root->_bf << endl;
		_Inorder(root->_right);
	}

```

> 2.验证其为平衡树：
>
> 每个节点的右左子树的高度差的绝对值不超过1
>
> 节点的平衡因子是否计算正确

```cpp

	bool Is_Banlance()
	{
		return _Is_Banlance(_root);
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
			cout << "平衡因子发生异常" << "right_height-left_height=" << right_height - left_height << "   " << "root->key=" << root->_kv.first<<"  " << "root->_bf=" << root->_bf << endl;
			return false;
		}

		return (right_height - left_height) == root->_bf &&
			_Is_Banlance(root->_left) &&
			_Is_Banlance(root->_right);

	}
```

3.验证用例

```cpp
常规场景：
{16，3，7，11，9，26，18，14，15}
```

```cpp
特殊场景：
{4，2，6，1，3，5，15，7，16，14}
```

![image-20211108144027946](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211108144027946.png)

演示效果：

![image-20211108151651637](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211108151651637.png)



![image-20211108151745994](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211108151745994.png)

## AVL树的删除

> 1.先找的要删除值所在的节点
>
> 2.按照搜索树的规则进行删除，左为空，右为空，左右都为空
>
> 3.更新平衡因子，和插入是反着的
>
> 1.删除parent的左，parent->bf++
>
> 2.删除parent的右，parent->bf--
>
> a.更新后parent->bf==0,说明我原来是1或者-1，把高的那边删除掉了，高度变了，继续往上更新
>
> b.更新后parent->bf==1||更新后parent->bf==-1，说明原来是0，现在删除一个，parent的高度不变，不影响上一层，停止更新
>
> c.更新后parent->bf==2或者-2不平衡旋转

## 项目地址：

[The-C-PLus-PLus-Language/2.C++初阶/test_11_6_AVL树的模拟实现 at master · qingyan520/The-C-PLus-PLus-Language (github.com)](https://github.com/qingyan520/The-C-PLus-PLus-Language/tree/master/2.C%2B%2B初阶/test_11_6_AVL树的模拟实现)

