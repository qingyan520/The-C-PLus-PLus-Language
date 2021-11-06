AVL树

![image-20211105190719119](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211105190719119.png)

```cpp
#include<iostream>
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
    
    
    ~AVLTree()
    {
        
    }
    
    
    bool Insert(const pair<K,V>&kv)
    {
        if(_root==nullptr)
        {
            _root=new Node(kv);
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
    
    Node*find(const K&key)
    {
        
        return nullptr;
    }
    
    bool Erase(const K&key)
    {
        return fasle;
    }
    
    
    private:
    Node*_root;
}
```

![image-20211105193612764](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211105193612764.png)

AVL树的四种旋转

当新插入的节点位于左子树的左侧时，进行右单旋

![image-20211106171625424](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211106171625424.png)

