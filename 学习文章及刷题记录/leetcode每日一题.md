# leetcode每日一题

#### [6_21_401. 二进制手表](https://leetcode-cn.com/problems/binary-watch/)

> 二进制手表顶部有 4 个 LED 代表 **小时（0-11）**，底部的 6 个 LED 代表 **分钟（0-59）**。每个 LED 代表一个 0 或 1，最低位在右侧。

> - 例如，下面的二进制手表读取 `"3:25"` 。
>
> ![image-20210621140543674](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210621140543674.png)

> 给你一个整数 turnedOn ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
>
> 小时不会以零开头：
>

> 例如，"01:00" 是无效的时间，正确的写法应该是 "1:00" 。
> 分钟必须由两位数组成，可能会以零开头：

> 例如，"10:2" 是无效的时间，正确的写法应该是 "10:02" 。
>

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

