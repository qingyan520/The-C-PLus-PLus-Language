# 红黑树(Rb_Tree)



```cpp
#include<iostream>
using namespace std;
int main()
{
    
}
```



红黑树的定义：

红黑树是一种二叉搜索树，但是每个节点上增加一个存储位置代表节点的颜色，可能是red/black,红黑树里面最长的的路径最多是最短路径的2倍，接近于平衡

红黑树的性质：

1.每个节点不是红色就是黑色

2.根节点是黑色

3.如果一个节点是红色的，那么它的两个孩子节点是黑色的(树中没有连续的红色节点)

4.对于每个节点，从该节点到其后代节点的简单路径上，均包含相同数目的黑色节点(每一条路径上具有相同数量的黑色节点)

5.每个叶子节点都是黑色的(此处叶子节点为NULL节点)



如何保证最长路径是最短路径的2倍：

最短路径全部由黑色节点构成：

最长路径：一黑一红，红色结点的数量和黑色节点的数量相等

假设黑色节点有N个，每条路径上有logN个黑色节点

最短路径：log(N)

最长路径长度：2*log(N)

ps:正常的红黑树中，不一定会有全黑的最短路径和一黑一红的最长路径





```cpp
#include<iostream>
using namespace std;
enum Colour
{
    REA,
    BLACK,
}
template<class K,class V>
struct RBTreeNode
{
    RBTreeNode<K,V>*_left;
    RBTreeNode<K，V>*_right;
    RBTreeNode<K,V>*_parent;
    pair<K,V>_kv;
    Colour _col;
    
    RBTreeNode(const pair<K,V>&kv):
    _left(nullptr),
    _right(nullptr),
    _parent(nullptr),
    _col(RED),
    _kv(kv)
    {}
};
template<class K,class V>
struct _TreeIterator
{
    typedef RBTreeNode<K,V>Node;
    Node*node;
    _TreeIterator(Node*_node):
    node(_node)
    {
        
    }
    
}
template<class K,class V>
class RBTree
{
    typedef RBTReeNode<K,V> Node;
    
    public:
    RBTree():
    _root(nullptr)
    {
        
    }
    Node*Find(const K&key)
    {
        Node*cur=_root;
        while(cur)
        {
            if(cur->_kv.first>key)
            {
                cur=cur->_left;
            }
            else if(cur->_kc.first<key)
            {
                cur=cur->_right;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }
    
    void Destory(Node*root)
    {
        if(root==nullptr)
            return ;
        Destory(root->_left);
        Destory(root->_right);
        delete root;
    }
    
    ~RBTree()
    {
        Destory(_root);
        _root=nullptr;
    }
    
    //拷贝构造operator=
    
    
    pair<Node*,bool> Insert(const pair<K,V>&kv)
    {
        if(_root==nullptr)
        {
            _root=new Node(kv);
            _root->col=BLACK;
            return make_pair<_root,true>;
        }
        
        Node*cur=_root;
        Node*parent=nullptr;
        while(cur)
        {
            if(cur->_kv.first<kv.first)
            {
                parent=cur;
                cur=cur->_right;
            }
            else if*cur->_KV.first>kv.first
            {
                parent=cur;
                cur=cur->_left;
            }
            else
            {
                return make_pair(cur,flase);
            }
         }
        Node*newNode=new Node(kv)
        newnode->_col=RED;
        if(paret->_kv.first<kv.first)
        {
            parent->_right=newnode;
            newnode->_parent=parent;
        }
        else
        {
            parent->left=newnode;
            newnode->_parent=parent;
        }
        cur=newnode;
        //插入新节点的颜色黑的好还是红的好？
        //新插入红色节点，因为红色节点破环规则3，影响不大
        //插入黑色节点，一定破环规则四，并且破环其它路径，影响面大
        //1.parent的颜色是黑色，不需要调整，插入完成
        //2.parent的颜色是红色，违反了规则3，需要进行处理(关键看叔叔)
        //a.cur为红，parent为红，grandfather为黑，uncle存在且为红，处理方案：
        //把父亲和叔叔变黑，祖父变红，保持一棵树黑色节点不变
        //继续往上处理
      
        //b.
        
        //如果父亲存在且颜色为红色则需要处理
        while(parent&&parent->_col==RED)
        {
            //关键看叔叔
            Node*grandfather=parent->_parent;
            if(parent==grandfather->_left)
            {
                Node*uncle=grandfather->_right;
                //情况一：叔叔存在且为红
                if(uncle!=nullptr&&uncle->_col==RED)
                {
                    parent->_col=BLACK;
                    uncle->_col=BLACK:
                    grandfather->_col=RED;
                    //继续往上处理
                    cur=grandfather;
                }
                else
                {
                    //情况2+情况3：
                    //uncle不存在或者uncle存在且为黑
                    if(cur==parent->_left)//情况2：单旋
                    {
                        RotateR(grandfather);
                        grandfather->_col=RED;
                        parent->_col=BLACK;
                    }
                    else//情况3：双旋
                    {
                        RotateL(parent);
                        RotateR(grandparent);
                        cur->_col=BLACK:
                        grandfather->_col=RED;
                       
                    }
                    break;
                }
            }
            else
            {
                
            }
        }
        
        _root->_col=BLACK;
        return make_pair(newnode,true);
    }
    
    
    private:
    Node*_root;
}
```

  1.parent的颜色是黑色，不需要调整，插入完成

 2.parent的颜色是红色，违反了规则3，需要进行处理(关键看叔叔)
       a.cur为红，parent为红，grandfather为黑，uncle存在且为红，处理方案：
        把父亲和叔叔变黑，祖父变红，保持一棵树黑色节点不变
        继续往上处理

​	   b.cur为红，parent为红，uncle不存在/为黑(直线单旋)

​      c.cur为红，p为红，g为黑，u不存在/u为黑(折线双旋)

具象图二：

![image-20211112200545630](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20211112200545630.png)

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

