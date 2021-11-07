AVL树

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

AVL树的四种旋转

当新插入的节点位于左子树的左侧时，进行右单旋

![image-20211106171625424](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211106171625424.png)





平衡因子的更新

![image-20211107101352580](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211107101352580.png)









![image-20211107101421717](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211107101421717.png)



![image-20211107102257083](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211107102257083.png)

