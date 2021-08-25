# 剑指offer刷题集合

### day1 栈与队列   

###### [剑指 Offer 09. 用两个栈实现队列 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

> 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
>

```cpp
示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]


示例 2：
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```

> 思路：用栈来实现队列，这里只要求实现插入与删除头部元素(同时显示头部元素)，这里我们定义两个栈s1,s2,每次在s1中插入元素，要删除的时候我们将s1中的元素导入s2中，就能实现

```cpp
class CQueue {
public:
//队列：先进先出
//栈：先进出

    stack<int>q1;
    stack<int>q2;
    CQueue() {

    }
    
    void appendTail(int value) {
        q1.push(value);

    }
    
    int deleteHead() {
    //如果q1是空的直接返回-1
        if(q1.empty())
        return -1;
        //我们一一将q1中的元素导入q2中去，这时q1就变为空，q2的顺序与原来q1的顺序相反，我们拿出q2的top元素即为我们要删除
        //的队列的头部元素，我们标记一下这个元素，然后pop删除这个元素，我们再将q2中的元素重新导入q1中
        while(!q1.empty())
        {
            q2.push(q1.top());
            q1.pop();
        }
        int ret=q2.top();
        q2.pop();
        while(!q2.empty())
        {
            q1.push(q2.top());
            q2.pop();
        }
        return ret;

    }
};
```

###### [剑指 Offer 30. 包含min函数的栈 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)

> 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
>

```cpp
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
```

> 定义两个栈，让每一个数字都有其对应的最小值

```cpp
class MinStack {
public:

//设置两个栈，一个栈作为正常栈，另外一个栈用来存储最小值，让每一个数都有其对应的最小值

  /** initialize your data structure here. */

 	 stack<int>s1;
​    stack<int>s2;

  MinStack() {
​    s2.push(INT_MAX);
  }

  

  void push(int x) {
​    s1.push(x);
​    s2.push(::min(s2.top(),x));
  }

  

  void pop() {
​    s1.pop();
​    s2.pop();
  }

  

  int top() {
​    return s1.top();
  }

  
    
  int min() {
​    return s2.top();
  }

};
```

