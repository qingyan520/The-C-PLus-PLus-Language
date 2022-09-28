### B树及其应用

B树结构：一棵M阶的B树，是一颗平衡的M路平衡搜索树，可以是空树或者满足一下性质

```
根节点至少存在两个孩子
每个非根节点至少又M/2(上取整)个孩子，至多有M个孩子
每个非根节点至少又M/2-1(上取整)个关键字，至多有M-1个关键字，并且升序排列
key[i]和ke[i+1]之间的孩子节点的值介于key[i]，key[i+1]之间
所有的叶子节点都在同一层
```

总结：

根结节点：关键字数量[1,M-1],孩子数量[2,M]

非根节点：关键字数量[M/2-1,M-1]，孩子数量[M/2,M]

每个节点中，孩子数量比关键字数量多一个

```cpp
template<class K,class V,class M>
struct BTreeNode
{
    //空间上多给一个空间，方便插入之后进行分裂
    pair<K,V>_kvs[M];
    BTreeNode<K,V,M>*_subs[M+1];
    BTreeNode<K,V,M>*_parent;
	size _kvSize;
    
    BTreeNode():
    _kvSize(0),
    _parent(nullptr)
    {
        for(int i=0;i<M+1;i++)
        {
            _subs[i]=nullptr'
        }
    }
};

19063218
template<class K,class V,class M>
class BTree
{
  	typedef BTreeNode<K,V,M>Node;
    public:
    
    
    //第i个key的左孩子是subs[i]
    //第i个key的右孩子是subs[i+1]
    pair<Node*,int> Find(const K&key)
    {
        Node*cur=_root;
        while(cur)
        {
            size_t i=0;
            while(i<cur->_kvSize)
            {
                if(cur->_kvs[i].first<key)
                {
                    ++i;
                }
                else if(cir->_kvs[i].firrst>key)
                {
                    break;
                }
                else
                {
                    return make_pair(cur,1);
                }
                cur=cur->_subs[i];
            }
        }
        return make_pair(parent,-1);
        
        
    }
    bool Insert(const pair<K,V>&key)
    {
        if(root==nullotr)
        {
            _root=new Node;
            _root->_kvs[0]=kv;
            _root->_kvSize=1;
            return true;
        }
        
        pair<Node*,int>ret=Find(kv.first);
        //已经有了，不能插入(如果当前容许插入就是)
        if(ret.second>=0)
        {
            return false;
        }
        
        Node*cur=ret.first;
        InsertKV(cur,kv);
        if(cur->_kvSize<M)
        {
            return true;
        }
        else //满了，需要分裂
        {
            //分裂出一个兄弟节点
            Node*newnode=new node;
            
            //1.拷贝走右半区间一般给分裂的兄弟节点
            int mid=M/2;
            int j=0;
            for(int i=mid+1;i<M;++i)
            {
                newnode->_kvs[j++]=cur->_kvs[i];
                 newnode->_kvSize++;
                //
            }
            
            K newkey=cur->_kvs[mid];
            cur->_kvSize=cur->_kvSize-newnode->_kvSize-1;
            
            //1.如果cur没有父亲，那么cur就是根，产生新的根
            //2.如果cur有父亲，那么就要转换成往cur的父亲中插入一个key和一个孩子newnode
            if(cur->_parent==nullptr)
            {
                _root=new Node;
                _root->_kvs[0]=newkey;
                _root->_subs[0]=cur;
                _root->_subs[1]=newnode;
                _root->_kvSize=1;
                return true;
            }
            else
            {
                
            }
        }
        
        
    }
    
    
    private:
    
    Node*_root=nullptr;
    
    
};

```

为什么分裂时，要提中位数插入到父亲呢？

因为分裂增加了一个兄弟节点，对于父亲而言，多了一个孩子，还多了一个关键字，这样才能保持孩子的数量比关键字数量多一个

多层数据之后，插入一定是往叶子插入，因为这样才不会严重破环结构

B树增删查改的时间复杂度：log M(N)

