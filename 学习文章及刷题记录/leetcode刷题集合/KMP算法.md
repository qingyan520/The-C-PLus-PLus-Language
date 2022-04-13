KMP算法

字符串匹配算法

例如：查找子串

利用匹配失败后的信息，尽量减少模式串与主串之间的匹配次数以达到快速匹配的目的，具体实现是通过一个next函数实现的，函数本身包含了模式串的局部匹配信息

kmp算法事件复杂度O(m+n)

```
aabaabaaf
aabaaf
```

 

前缀：包含首字母但不包含为字母的所有子字符串

```
a
aa
aab
aaba
aabaa
```

后缀：只包含尾字母不包首字母的所有子字符串

```
f
af
aaf
baaf
abaaf
```

最长相等前缀和后缀的长度

```
aabaaf   |
a      0 | 前
aa     1 | 缀
aab    0 | 表
aaba   1 |
aabaa  2 |
aabaaf 0 |
```

```
a a b a a b a a f
a a b a a f
0 1 0 1 2 0
找到f处发现不相等了，找到最长相等前后缀，然后子字符串下标挪到下表为2的地方
即b的位置，然后往后匹配

```

```
a a b a a b a a f
a a b a a f
0 1 0 1 2 0
next的数组:

```

```cpp
//KMP伪代码：
//i:指向后缀末尾位置
//j:指向前缀末尾位置
void getNext(vector<int>&next,char*s)
{
	j=0;
    next[0]=0;
    for(i=1;i<s.size();i++)
    {
           while(  j>0&& s[i]!=s[j]
                 j=next[j-1];
          if(s[i]==s[j])
           {
               j++;
               next[i]=j;
               
           }
    }
}
//初始化next数组及函数里的变量，处理前后缀不相同的情况
//处理前后缀相同的情况
//next
```

```cpp
//KMP算法的具体实现
#include<vector>
using namespace std;
namespace hello
{
	void getNext(vector<int>& next, const string& s)
	{
		int j = 0;
		next[0] = 0;
		for (int i = 1; i < s.size(); i++)//注意i从1开始
		{
			while (j > 0 && s[i] != s[j])//前后缀不相同了
			{
				j = next[j-1];//向前回退
			}
			if (s[i] == s[j])//找到相同的前后缀
			{
				j++;
			}
			next[i] = j;//将j(前缀的长度)赋给next[i]
		}
	}
	int strstr(string haystack, string needle)
	{
		if (needle.size() == 0)
			return 0;
		int n = needle.size();
		vector<int>next(n);
		getNext(next, needle);
		int j = 0;//因为next数组里记录的其实位置为-1
		for (int i = 0; i < haystack.size(); i++)//注意下标从0开始
		{
			while (j >0 && haystack[i] != needle[j])//不匹配
			{
				j = next[j-1];//j寻找之前匹配的位置
			}
			if (haystack[i] == needle[j])//匹配，i，j同时后移
			{
				j++;
			}
			if (j == needle.size())//出现了字串的位置
			{
				return (i - needle.size() + 1);
			}
		}
		//未找到，返回-1
		return -1;


	}
}
int main()
{
	cout<<hello::strstr("hello", "llo");
	return 0;
}
```

