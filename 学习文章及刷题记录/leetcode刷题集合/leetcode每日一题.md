# leetcode每日一题

#### [6_21_401. 二进制手表](https://leetcode-cn.com/problems/binary-watch/)

> 二进制手表顶部有 4 个 LED 代表 **小时（0-11）**，底部的 6 个 LED 代表 **分钟（0-59）**。每个 LED 代表一个 0 或 1，最低位在右侧。

> - 例如，下面的二进制手表读取 `"3:25"` 。
>
> ![image-20210621140543674](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210621140543674.png)

> 给你一个整数 turnedOn ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
>
> 小时不会以零开头：

> 例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
> 分钟必须由两位数组成，可能会以零开头：

> 例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。

```cpp
示例 1：
输入：turnedOn = 1
输出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

示例 2：
输入：turnedOn = 9
输出：[]
```

> 本题中手表上一共有10个位置，亮灯代表在这个位置计数，而这个亮灯的位置也代表这一个位置二进制位为1，输入的数字就代表着二进制中1的个数，那么我们就要算出这个总共val个1可以表示多少个时间，但是这种比较难写，所以我们转化思路，我们循环遍历0~12小时，0~60分钟，找到每一个时刻二进制中1的个数，然后相加，如果等于val就追加到数组中，不相等就不要追加到数组中，到最终遍历完就找到所有可能的结果了

> 注意：
>
> 1.二进制位为1的个数统计：自己写一个或者用库函数：_builtin_popcount(val)
>
> 2.to_string(val)：将数字转化为字符串

```cpp
class Solution {
public:
  //设计一个函数求二进制中1的个数

  int count(int n)
  {
​    int count1=0;
​    while(n)
​    {
​      count1++;
​      n=n&(n-1);
​    }
​    return count1;
  }

  vector<string> readBinaryWatch(int turnedOn) {
  
​    //直接二进制枚举每个时刻的小时，分钟所能出现的可能的二进制位数，将时与分的二进制位数加起来如果和

​    //turnedOn（这个数字就代表二进制位的多少）相同，添加这个字符

​    vector<string>ret;
​    for(int h=0;h<12;h++)
​    {
​      for(int m=0;m<60;m++)
​      {
​        //比较二进制位
​        // if(count(h)+count(m)==turnedOn)
​        //_builtin_popcount(h)：系统提供的求一个数据中二进制位为1的个数
​        if(__builtin_popcount(h)+__builtin_popcount(m)==turnedOn)
​        {
​          //to_string可以将一个数字转化为string类型，注意分钟的书写
​          //判断m<10?，是的话"0"+to_string(m),不是的话直接to_string(m)
​          ret.push_back(to_string(h)+":"+(m<10? "0"+to_string(m):to_string(m)));
​        }
​      }
​    }
​    return ret;
​    //注意本题目时间复杂度位O(1)，不是O(N*N)，因为常数次就枚举完成了
​    //空间复杂度O(1)
  }
};
```

#### [6_22_剑指 Offer 38. 字符串的排列](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)

> 输入一个字符串，打印出该字符串中字符的所有排列。
>
> 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

```

示例:
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
```

> 回溯是一种暴力搜索算法，相当于n层for循环
>
> 1.确定循环终止条件
>
> 2.for循环
>
> 3.回溯

```cpp
class Solution {
public:
  vector<string>ret;
  void backtrack(string&s,string&str,vector<bool>used)
  {
​    //1.确定循环条件
​    if(str.size()==s.size())
​    {
​      ret.push_back(str);
​    }
​    //2.开始循环
​    for(int i=0;i<s.size();i++)
​    {
​      //2.1去除重复元素
​      if(i>0&&s[i]==s[i-1]&&used[i-1]==false)
​      continue;
​      //2.如果used[i]==false，说明该位置还没有字符，进入
​      if(used[i]==false)
​      {
​        used[i]=true;
​        str.push_back(s[i]);
​        //进入递归
​        backtrack(s,str,used);
​        //进入回溯过程
​        str.pop_back();
​        used[i]=false;
​      }
​    }
  }

  vector<string> permutation(string s) {
​    ret.clear();
   vector<bool>used(s.size(),false);
​    sort(s.begin(),s.end());
​    string str;
​    backtrack(s,str,used);
​    return ret;
  }
};
```

#### [6_23_剑指 Offer 15. 二进制中1的个数](https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/)

> 请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

```cpp
示例 1：
输入：00000000000000000000000000001011

输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。

示例 2：
输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。

示例 3：
输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
```

```cpp
class Solution {
public:

  int hammingWeight(uint32_t n) {
​    int count=0;
​    while(n)
​    {
​      count++;
​      n=n&(n-1);
​    }
​    return count;
  }
};
```

#### [6_29_168. Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)

> 给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。

> 例如：
>
> A -> 1
> B -> 2
> C -> 3
> ...
> Z -> 26
> AA -> 27
> AB -> 28 
> ...

```cpp
示例 1：
输入：columnNumber = 1
输出："A"

示例 2：
输入：columnNumber = 28
输出："AB"

示例 3：
输入：columnNumber = 701
输出："ZY"

示例 4：
输入：columnNumber = 2147483647
输出："FXSHRXW"
```

> 这里首先要直到excel表格的编号是26进制，而且A~Z的assic的范围为65~90，中间相差25
>
> 26进制余数的范围应该为0~25，所以每次操作前先将这个数字--

```cpp
class Solution {
public:

 

  string convertToTitle(int columnNumber) {
​    string ret;
​    //题目本质：将一个数字转化为26进制数字，首先最容易想到的就是直接相除取余
​    //那么我们取得第一个余数所对应的字母就是最后一个字母
​    //当我们遍历完整个数字之后就是得到我们要找的字符串的逆序了，然会我们将其转置一下，就得到了正确的答案
​    //但是这里我们还要注意一下，这个取余的过程，
​    //26进制是1~26，那么%26对应的余数就应该位于0~25之间，所以我们将所有的数都减1，比如26，26-1=25%26=25


​    while(columnNumber)
​    {
​      ret+=(columnNumber-1)%26+'A'; 
​      columnNumber-=(columnNumber-1)%26;
​      columnNumber/=26;
​    }
​    reverse(ret.begin(),ret.end());
​    return ret;
  }
};
```

#### [7_2_1833. 雪糕的最大数量](https://leetcode-cn.com/problems/maximum-ice-cream-bars/)

> 夏日炎炎，小男孩 Tony 想买一些雪糕消消暑。
>
> 商店中新到 n 支雪糕，用长度为 n 的数组 costs 表示雪糕的定价，其中 costs[i] 表示第 i 支雪糕的现金价格。Tony 一共有 coins 现金可以用于消费，他想要买尽可能多的雪糕。
>
> 给你价格数组 costs 和现金量 coins ，请你计算并返回 Tony 用 coins 现金能够买到的雪糕的 最大数量 。
>
> 注意：Tony 可以按任意顺序购买雪糕。

```
示例 1：
输入：costs = [1,3,2,4,1], coins = 7
输出：4
解释：Tony 可以买下标为 0、1、2、4 的雪糕，总价为 1 + 3 + 2 + 1 = 7

示例 2：
输入：costs = [10,6,8,7,7,8], coins = 5
输出：0
解释：Tony 没有足够的钱买任何一支雪糕。

示例 3：
输入：costs = [1,6,3,1,2,5], coins = 20
输出：6
解释：Tony 可以买下所有的雪糕，总价为 1 + 6 + 3 + 1 + 2 + 5 = 18 。
```

> 一看题目以为是金典的背包问题，但是看示例就知道，本题与购买雪糕的数量无关，只与购买的种类有关，因此转化为求最多可以买多少种类的雪糕，我们先将价钱顺序排个序，然后从前往后加，看到第几个到coins，就知道需要最大购买雪糕的数量

```cpp
class Solution {
public:

  int maxIceCream(vector<int>& costs, int coins) {
​    sort(costs.begin(),costs.end());
​    int count=0;
​    for(int i=0;i<costs.size();i++)
​    {
​      if(coins-costs[i]>=0)
​      {
​        coins-=costs[i];
​        count++;
​      }
​    }
​    return count;
  }
};
```

####  [7_9_面试题 17.10. 主要元素](https://leetcode-cn.com/problems/find-majority-element-lcci/)                                                  

> 数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。若没有，返回 -1 。请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。

```cpp
示例 1：
输入：[1,2,5,9,5,9,5,5,5]
输出：5

示例 2：
输入：[3,2]
输出：-1

示例 3：
输入：[2,2,1,1,1,2,2]
输出：2
```

> 方法一：暴力双重循环统计每个数字出现的次数，判断是否超出一半,当然，这样时间复杂度为O(N*N),超时

```cpp
//遍历数组，统计每一个数组的个数，另外准备一个used[i]数组用来统计该数是否被使用
class Solution {

public:

  int majorityElement(vector<int>& nums) {
​    vector<bool>used(nums.size(),false);
​    int n=nums.size()/2;
​    for(int i=0;i<nums.size();i++)
​    {
​      used[i]=true;
​      int flag=1;
​      for(int j=0;j<nums.size();j++)
​      {
​        if(i!=j&&nums[i]==nums[j]&&used[j]==false)
​        {
​          used[j]=true;
​          flag++;
​        }
​      }
​      if(flag>n)
​      return nums[i];
​    }
​    return -1;
  }
};
```

> 方法二：先排序，如果是主要元素它的长度超过数组长度的一半，那么中间元素必定是主要元素，则我们只要先排序，再查找中间元素的个数就可以判断是否为中间元素了

```cpp
//主要元素是指数组中出现超过一半的元素，将数组进行排序之后，这个主要元素一定会跨越左右两个区域，则中间元素一定为主要元素
//将数组排序，找出中间元素，然后从前往后遍历找这个中间元素的个数，如果中间元素的个数大于元素个数的一半，那么就存在主要元素
//否则，就不存在主要元素

class Solution {
public:

  int majorityElement(vector<int>& nums) {
​    sort(nums.begin(),nums.end());
​    int a=nums[nums.size()/2];
​    int flag=0;
​    for(int i=0;i<nums.size();i++)
​    {
​      if(nums[i]==a)
​      {
​        flag++;
​      }
​    }
​    if(flag>nums.size()/2)
​    return a;
​    return -1;
  }
};
```

#### [7_11_274. H 指数](https://leetcode-cn.com/problems/h-index/)

> 给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。
>
> h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。且其余的 N - h 篇论文每篇被引用次数 不超过 h 次。
>
> 例如：某人的 h 指数是 20，这表示他已发表的论文中，每篇被引用了至少 20 次的论文总共有 20 篇。

```cpp
示例：
输入：citations = [3,0,6,1,5]
输出：3 

解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 3, 0, 6, 1, 5 次。
     由于研究者有 3 篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3。
提示：如果 h 有多种可能的值，h 指数是其中最大的那个
```

这道题目纯粹考阅读理解能力

```cpp
class Solution {
public:

  int hIndex(vector<int>& citations) {
​    sort(citations.begin(),citations.end());
​    for(int i=0;i<citations.size();i++)
​    {
​      int h=citations.size()-i;
​      if(citations[i]>=h)
​      return h
​    }
​    return 0;
  }
};
```

#### [7_12_275. H 指数 II](https://leetcode-cn.com/problems/h-index-ii/)

> 给定一位研究者论文被引用次数的数组（被引用次数是非负整数），数组已经按照 升序排列 。编写一个方法，计算出研究者的 h 指数。
>
> h 指数的定义: “h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。（其余的 N - h 篇论文每篇被引用次数不多于 h 次。)
>

```cpp
示例:
输入: citations = [0,1,3,5,6]
输出: 3 
解释: 给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
     由于研究者有 3 篇论文每篇至少被引用了 3 次，其余两篇论文每篇被引用不多于 3 次，所以她的 h 指数是 3。
说明:
如果 h 有多有种可能的值 ，h 指数是其中最大的那个。
```

```cpp
class Solution {
public:

  int hIndex(vector<int>& citations) {
    for(int i=0;i<citations.size();i++)
    {
      int h=citations.size()-i;
      if(citations[i]>=h)
      return h
    }
    return 0;
  }
};
```

