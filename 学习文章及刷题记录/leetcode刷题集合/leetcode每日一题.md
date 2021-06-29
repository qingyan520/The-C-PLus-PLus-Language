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
>

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

