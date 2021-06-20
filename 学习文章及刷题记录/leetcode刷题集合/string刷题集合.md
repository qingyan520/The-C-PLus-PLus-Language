# string刷题集合

## 简单题

### 1.验证回文字符串

#### [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/)

> 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

> **说明：**本题中，我们将空字符串定义为有效的回文串。
>
> ```cpp
> 示例 1:
> 输入: "A man, a plan, a canal: Panama"
> 输出: true
> 
> 示例 2:
> 输入: "race a car"
> 输出: false
> ```

> 本题思路比较清楚，对于大多数人来说上来就是直接双指针开干，也不看题目，这就导致下面的问题：

![image-20210608111759959](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608111759959.png)

> 本题主要要注意审题：
>
> 1.忽略字母的大小写
>
> 2.忽略标点符号及空格
>
> 3.只考虑字母和数字字符

> 故本题第一步是将字符串进行转化，将上面的字符串转化为只含有数字字符和同是大写或者小写字母的字符，这样我们才能够利用左右指针进行判断

```cpp
class Solution {
public:
  //经典双指针问题:定义左右指针，两边开始遍历，如果两者不相等返回false，相等返回true;
  
  bool isPalindrome(string s) {

​    //1.定义一个新的自负床，存储不是逗号的元素
​    string str;

​    //2.首先同一将大写字母转换为小写字母并且将字母与数字赋值个这个新字符串
​    for(int i=0;i<s.size();i++)
​    {
​      if(s[i]>=65&&s[i]<=90)
​      {
​        s[i]+=32;
​      }
​      //将所有的小写字母赋值给新字符串
​      if((s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57))
       {
​        str+=s[i];
​      }
​    }

​    //3.左右双指针循环遍历
​    int left=0,right=str.size()-1;
​    while(left<right)
​    {
​      if(str[left]!=str[right])
​      {
​        return false;
​      }
​      left++;
​      right--;
​    }
​    return true;
  }
};
```

![image-20210608112706401](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608112706401.png)

解法二：不构建新的字符串，直接在旧的字符串基础上进行改进，判断每一位为数字和字母的是否为回文字符串

```cpp
class Solution {
public:

  //首先定义一个函数判断是否为数字或者字母
  bool IsLetter(char c)
  {
​    if((c>=48&&c<=57)||(c>=65&&c<=90)||(c>=97&&c<=122))
​    {
​      return true;
​    }
​    return false;
  }

  bool isPalindrome(string s) {
​    int left=0,right=s.size()-1;
​    for(int i=0;i<s.size();i++)
​    {
​      if(s[i]>=65&&s[i]<=90)
​      {
​        s[i]+=32;
​      }
​    }
​    while(left<right)
​    {
    //找到两边都是字母或者数字的为进行比较，看是否为回文字符串
​      while(left<right&&!(IsLetter(s[left])))
​      {
​        left++;
​      }
​      while(left<right&&!(IsLetter(s[right])))
​      {
​        right--;
​      }
​      if(s[left]==s[right])
​      {
​        left++;
​       --right;
​      }
​      else
​      {
​        return false;
​      }
​    }
​    return true;
  }
};
```

### 2.字符串中的唯一字符

#### [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

> 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

```cpp
示例：
s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
```

> **提示：**你可以假定该字符串只包含小写字母。

> 本题思路：
>
> 1.双指针循环遍历，找到那个只出现了一次的字符，时间复杂度O(N*N)
>
> 2.采用哈希映射，将小写字母映射到大小为26的数组当中，例如a映射映射到arr[0],b映射到arr[1]，统计每一个位子上数字出现的次数，第二次遍历找到那个只出现过一次的字符串，时间复杂度O(N)

```cpp
class Solution {

public:

//本题最简单的思路：循环遍历看这个字符串出现了几次，但是时间复杂度为O(N*N)

//所以换一种思路：

//采用计数排序的思想，映射

  int firstUniqChar(string s) {
	//建立数组，映射26个小写字母
​    int arr[26]={0};
​    for(int i=0;i<s.size();i++)
​    {
    	//注意小写字母范围为97~112，减去97刚好使a映射到arr[0],这个位置上，依次类推
​      	arr[s[i]-97]++;
​    }
	//第二次遍历寻找找到那个只出现了一次的字母
​    for(int i=0;i<s.size();i++)
​    {
​      if(arr[s[i]-97]==1)
​      {
​        return i;
​      }
​    }
      //找不到返回-1
​    return -1;
  }
};
```

![image-20210608125728465](https://raw.githubusercontent.com/qingyan520/Cloud_img/master/img/image-20210608125728465.png)

#### 牛客网：找出字符串中第一个只出现一次的字符

[找出字符串中第一个只出现一次的字符_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&&tqId=21282&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking)

> 描述
>
> 找出字符串中第一个只出现一次的字符
>
> 输入描述：
>
> 输入几个非空字符串
>
> 输出描述：
>
> 输出第一个只出现一次的字符，如果不存在输出-1

```cpp
输入：
asdfasdfo
aabb
    
输出：
 o
-1   
```

解法一：利用string提供的函数find和rfind进行查找，将每个字符从前往后，从后往前两端开始遍历，看两者的下标是否相等，要是相等就打印，不相等就到最后打印-1；

```cpp
#include <iostream>
#include <string>

int main()
    {
    using namespace std;
    string str;
    while(cin>>str)
        {
       	 unsigned int i;
        for (i=0;i<str.size();i++)
       {
            //利用find和rfind分别从左右两端开始遍历，如果这个字符在左右liang
            //端遍历的位置都相等，那么说明该字符位置唯一
​        if(str.find(str[i])==str.rfind(str[i]))
​        {
​            cout<<str[i]<<endl;
​        		break;
​        }
​    }
​    if(i==str.size())
​        cout<<"-1";
}
return 0;
}
```

#### [剑指 Offer 50. 第一个只出现一次的字符](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/)

在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

```cpp
示例:
s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
```

> 本题思路1：基本与上面的题目思路一样，利用哈希映射，两遍遍历，第一遍将所有小写字母映射到数组中，第二遍遍历找到只出现一次的字母返回，时间复杂度O(N)

> 思路2：遍历字符串，头开始遍历，找到每一个字符，然后分别从前往后走，从后往前找，看找到下标的位置是否一样，位置要是一样就说明该字母是唯一的

```cpp
//解法一：利用哈希映射解题
class Solution {
public:

  char firstUniqChar(string s) {
​    //1.利用哈希映射
​    int arr[26]={0};
​    for(int i=0;i<s.size();i++)
​    {
​      arr[s[i]-97]++;
​    }
​    for(int i=0;i<s.size();i++)
​    {
​      if(arr[s[i]-97]==1)
​      {
​        return s[i];
​      }
​    }
​    return ' ';
  }
};
```

```cpp
//解法二：使用内置函数find从前往后找这个字符的下标，使用rfind从后往前找这个数字的下标，看这两个下标是否相等
class Solution {
public:

  char firstUniqChar(string s) {
​    for(int i=0;i<s.size();i++)
​    {
    //find,从前往后找字符;rfind，，从后往前找字符
​      if(s.find(s[i])==s.rfind(s[i]))
​      {
​        return s[i];
​      }
​    }
​    return ' ';
  }
};
```



### 3.字符串的翻转

#### [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/)

> 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
>
> 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
>
> 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

```cpp
示例 1：

输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：

输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]

来源：力扣（LeetCode）
```

> 本题思路非常简单，入门级算法之一，定义左右指针，交换左右顺序即可

```cpp
class Solution {
public:
  void Swap(char&a,char&b)
  {
​    char temp=a;
​    a=b;
​    b=temp;
  }

  void reverseString(vector<char>& s) {
	 int left=0;
​    int right=s.size()-1;
​    while(left<right)
​    {
​      Swap(s[left],s[right]);
​      left++;
​      right--;
​    }
  }
};
```

#### [917. 仅仅反转字母](https://leetcode-cn.com/problems/reverse-only-letters/)

给定一个字符串 `S`，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

```cpp
示例 1：
输入："ab-cd"
输出："dc-ba"
    
示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"
示例 3：
    
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"
```

这道题可以说是上面那道反转字符串的的变形：这道题的意思是让我们找到左右两边是字母的元素进行交换，还是一道简单题，我们只要像快排那样左右两边找到字母后交换就好

```cpp
class Solution {
public:
  //定义一个函数判断是否为字母
  bool IsLetter(char c)
  {
​    if((c>=65&&c<=90)||
​    (c>=97&&c<=122))
​    {
​      return true;
​    }
​    return false;
  }

  string reverseOnlyLetters(string s) {
​    int left=0,right=s.size()-1;
​    while(left<right)
​    {
​      //采取快排是的思想，不是字母的话向前加加，直到找到字母
​      while(left<right&&!(IsLetter(s[left])))
​      {
​        left++;
​      }
​     while(left<right&&!(IsLetter(s[right])))
​      {
​        right--;
​      }
		//使用系统内置交换函数swap进行交换
​      swap(s[left],s[right]);
		//交换之后++left,--right
​      left++;
​      right--;
​    }
​    return s;
  }
};
```

#### [541. 反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/)

> 给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。

> 如果剩余字符少于 k 个，则将剩余字符全部反转。
> 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

```cpp
示例:
输入: s = "abcdefg", k = 2
输出: "bacdfeg"
```

> 本题思路：

```cpp
class Solution {
public:

  string reverseStr(string s, int k) {
​    //直接暴力反转
    //每2k个元素为一组，然后在这一组里面反转前k项
    //如果剩余元素少于k个则直接进行反转
    //如果剩余元素小于2k或者等于k个，反转前k项其余元素保持不变
    //换句话来时，每次我们让i+=2*k，保证每次初始位置都位于2k的倍数上，然后每次判断i+k的大小
    //如果i+k的大小小于等于s.size(),那么就说明剩余元素刚好够前k个元素进行反转
    //如果大于size,说明后，说明元素不够了，直接进行反转
​    for(int i=0;i<s.size();i+=(2*k)){
​    if(i+k<=s.size())
​    {
​      reverse(s.begin()+i,s.begin()+i+k);
​      continue;
​    }
​    reverse(s.begin()+i,s.begin()+s.size());
  }
  return s;
  }
};
```

#### [557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

> 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

```cpp
示例：
输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
```

> 本题思路比较清楚，以空格为界限进行反转，只要找到空格的位置，然后按照空格的位置进行反转就行

```cpp
class Solution {
public:

  //反转字符串
  void _reverse(string&s,int begin,int end)
  {
​    while(begin<end)
​    {
​      swap(s[begin],s[end]);
​      begin++;
​      end--;
​    }
  }

  string reverseWords(string s) {
​    //定义一个位置记录空格的位置
​    int begin=0;
​    for(int i=0;i<s.size();i++)
​    {
​      //每次找到空格后开始进行反转
​      if(s[i]==' ')
​      {
​        _reverse(s,begin,i-1);
​        //反转之后更新空格的位置
​        begin=i+1;
​      }
​    }
​    //反转最后一个空格到结尾的位置
​    _reverse(s,begin,s.size()-1);
​    return s;
  }
};
```

### 4.计算最后一个单词的长度

#### [字符串最后一个单词的长度_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking)

> 计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。
>
> 输入描述：
>
> 输入一行，代表要计算的字符串，非空，长度小于5000。
>
> 输出描述：
>
> 输出一个整数，表示输入字符串最后一个单词的长度。

```cpp
示例1
输入：
hello nowcoder

输出：
8

说明：
最后一个单词为nowcoder，长度为8
```

> 思路：从后往前找空格，找到空格，那么字符串长度减去空格所在位置再减1就是最后一个单词的长度，如果单词长度遍历完了都没有找到空格那么说明该单词是整句话，直接返回字符串的长度

> 注意：本题是传统的写一个完整程序，因此要注意输入问题，在C/C++中scanf/cin在输入字符串时遇到空格都会停止，因此在C语言中输入字符串推荐用gets,C++中输入字符串推荐用getline(cin,str)进行输入

```cpp
//1.注意输入，如果输入有空格的话要用getline(cin,str)进行输入
//2.从后往前找空格的位置，然后相减
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int i=str.size()-1;
    for(;i>=0;i--)
    {
        if(str[i]==' ')
        {
            break;
        }
    }
    if(i!=-1)
    {
       cout<<str.size()-i-1<<endl;
    }
    else
    {
        cout<<str.size();
    }
    return 0;
}
```

### 6.判断是否为子序列

#### [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/)

> 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
>
> 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

```cpp
示例 1：
输入：s = "abc", t = "ahbgdc"
输出：true

示例 2：
输入：s = "axc", t = "ahbgdc"
输出：false
```

![image-20210618123907827](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210618123907827.png)

本题是经典的双指针做法，定义两个指针，分别指向s,t的首元素位置，如果s[i]==t[j],那么i++,此时再做匹配，看t中是否也有s[i],找最后判断i是否等于s.size()即可

```cpp
class Solution {
public:

  bool isSubsequence(string s, string t) {
​    int s_size=s.size();
​    int t_size=t.size();
​    int i=0;
​    int j=0;
​    while(i<s_size&&j<t_size)
​    {
​      if(s[i]==t[j])
​      {
​        i++;
​      }
​      j++;
​    }
​    return i==s_size;
  }
};
```

### 7.str函数模拟实现

#### [28. 实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)

> 实现 strStr() 函数。
>
> 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

```cpp
示例 1：
输入：haystack = "hello", needle = "ll"
输出：2
    
示例 2：
输入：haystack = "aaaaa", needle = "bba"
输出：-1
    
示例 3：
输入：haystack = "", needle = ""
输出：0
```

```cpp
//经典的双指针问题，定义两个指针，一个指针指向haystack,另一个指针指向needle
//当haystack[i]==needle[i]时候，接着往后走
//具体看代码
int strStr(char * haystack, char * needle){
    int haystackSize=strlen(haystack);
    int needleSize=strlen(needle);
    if(needleSize==0&&haystackSize==0)
    {
        return 0;
    }
    if(haystackSize!=0&&needleSize==0)
    {
        return 0;
    }
    int i=0;
    int j=0;
    while(i<haystackSize&&j<needleSize)
    {
        int temp=i;
        while(i<haystackSize&&j<needleSize&&haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        if(j==needleSize)
        {
            return temp;
        }
        else
        {
            i=temp+1;
            j=0;
        }
    }
    return -1;

}
```

### 8.重新排列字符串

#### [1528. 重新排列字符串](https://leetcode-cn.com/problems/shuffle-string/)

> 给你一个字符串 s 和一个 长度相同 的整数数组 indices 。
>
> 请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。
>
> 返回重新排列后的字符串。
>
> 示例 1：

![image-20210619134308512](C:\Users\史金伟\AppData\Roaming\Typora\typora-user-images\image-20210619134308512.png)

```cpp
输入：s = "codeleet", indices = [4,5,6,7,0,2,1,3]
输出："leetcode"
解释：如图所示，"codeleet" 重新排列后变为 "leetcode" 。

示例 2：
输入：s = "abc", indices = [0,1,2]
输出："abc"
解释：重新排列后，每个字符都还留在原来的位置上。

示例 3：
输入：s = "aiohn", indices = [3,1,4,2,0]
输出："nihao"

示例 4：
输入：s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
输出："arigatou"

示例 5：
输入：s = "art", indices = [1,0,2]
输出："rat"
```

> 本题是将s中的s[i]挪到s[indices[i]]位置上去，那么只要我们重新创建一个字符串，然后让str[indices[i]]=s[i]就可以了

```cpp
class Solution {

public:

  string restoreString(string s, vector<int>& indices) {
​    //有点像哈希映射
​    string str;
​    str.resize(s.size());
​    for(int i=0;i<indices.size();i++)
​    {
​      str[indices[i]]=s[i];
​    }
​    return str;
  }
};
```

> 时间复杂度：O(N)O(N)，其中 NN 为字符串 ss 的长度。我们只需对字符串 ss 执行一次线性扫描即可。
>
> 空间复杂度：O(1)O(1) 或 O(N)O(N)。除开辟的存储答案的字符串外，我们只需要常数空间存放若干变量。如果使用的语言不允许对字符串进行修改，我们还需要 O(N)O(N) 的空间临时存储答案。

### 9.字符串中的最大奇数

#### [5788. 字符串中的最大奇数](https://leetcode-cn.com/problems/largest-odd-number-in-string/)

> 给你一个字符串 num ，表示一个大整数。请你在字符串 num 的所有 非空子字符串 中找出 值最大的奇数 ，并以字符串形式返回。如果不存在奇数，则返回一个空字符串 "" 。
>
> 子字符串 是字符串中的一个连续的字符序列。
>

```cpp
示例 1：
输入：num = "52"
输出："5"
解释：非空子字符串仅有 "5"、"2" 和 "52" 。"5" 是其中唯一的奇数。
    
示例 2：
输入：num = "4206"
输出：""
解释：在 "4206" 中不存在奇数。
    
示例 3：
输入：num = "35427"
输出："35427"
```

> 思路：本题初看比较难，但是仔细分析还是非常简单的，只要我们从后往前遍历，找到第一个奇数，然后从首位置到这个位置所有字符串即为最大连续奇数字符串

```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        //首先排除特殊情况,要是string为空或者string中的每一位都是偶数，那么就返回空字符串
        if(num.size()==0)
            return "";
        int flag1=0;
        for(int i=0;i<num.size();i++)
        {
            if((num[i]-48)%2==0)
                flag1++;
        }
        if(flag1==num.size())
        {
            return "";
        }
        //从后往前找，找到第一个位置为奇数的位置j，从[0,j]这个为位置构成的所有字符串就是我们要求的最大字符串
        int j=num.size()-1;
        while((num[j]-48)%2==0)
        {
            j--;
        }
        int i=0;
        string s;
        for(int i=0;i<=j;i++)
        {
            s+=num[i];
        }
        return s;
    }
};
```

## 中等题

### 1.将字符串转化为整数

#### 题霸：将字符串转化为整数

[把字符串转换成整数_牛客题霸_牛客网 (nowcoder.com)](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking)

> 描述：
>
> 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
>
> 输入描述：
>
> 输入一个字符串,包括数字字母符号,可以为空
>
> 返回值描述：
>
> 如果是合法的数值表达则返回该数字，否则返回0

```cpp
示例1
输入：
"+2147483647"
输出：
2147483647
    
示例2：
输入：
"1a33"
返回值：
0
```

> 思路：
>
> 1.首先考虑特殊情况，如果输入的字符串不是一个合法的字符字符字符串，如果不是直接返回0
>
> 2.如果是合法的数值字符串，那么就考虑将数值字符串转化为数值

代码如下：

```cpp
class Solution {
public:
  int StrToInt(string str) {
    //1.判断是否为空串，是空串直接返回0
    if(str.empty())
    {
      return 0;
    } 

//2.判断输入的字符串是否合法
for(int i=0;i<str.size();i++)
{
  //开头第一个字母是'+'或者'-'是合法的，进入下一层循环
  if(str[0]=='+'||str[0]=='-')
  {
    continue;
  }
  //如果str[i]不是数值字符串就返回0
  if(str[i]<48||str[i]>57)
  {
    return 0;
  }
}

//3.字符串转化，将合法的字符串转化为数值
	long long int sum=0;
    long long int flag=1;
    int n=str.size();
    for(int i=n-1;i>=0;i--)
    {
       int j=48;
       for(;j<=57;j++ )
       {
            if(str[i]==j)
            {
                sum+=(j-48)*flag;
                flag*=10;
                break;
            }
      }
    }
    //如果是负数就返回相反数
    if(str[0]=='-')
    {
      	return (-1)*sum;
    }
    return sum;
   }
};
```

### 2.字符串相加

#### [415. 字符串相加](https://leetcode-cn.com/problems/add-strings/)

> 给定两个字符串形式的非负整数 `num1` 和`num2` ，计算它们的和

> 提示：
>
> num1 和num2 的长度都小于 5100
> num1 和num2 都只包含数字 0-9
> num1 和num2 都不包含任何前导零
> 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式

> 本题我们只需要对两个大整数模拟「竖式加法」的过程。竖式加法就是我们平常学习生活中常用的对两个整数相加的方法，回想一下我们在纸上对两个整数相加的操作，是不是如下图将相同数位对齐，从低到高逐位相加，如果当前位和超过 1010，则向高位进一位？因此我们只要将这个过程用代码写出来即可。
>
> 具体实现也不复杂，我们定义两个指针 ii 和 jj 分别指向 num1和num2  的末尾，即最低位，同时定义一个变量 \textit{add}add 维护当前是否有进位，然后从末尾到开头逐位相加即可。你可能会想两个数字位数不同怎么处理，这里我们统一在指针当前下标处于负数的时候返回 00，等价于对位数较短的数字进行了补零操作，这样就可以除去两个数字位数不同情况的处理，具体可以看下面的代码。

```cpp
class Solution {
public:

  string addStrings(string num1, string num2) {
​    //定义一个下一位，作为进位
​    int next=0;
      //求出两个字符串的长度
​    int L1=num1.size(),L2=num2.size();
      //找出两个字符串最后一个下标
​    int i=L1-1,j=L2-1;
​    string s;
​    while(i>=0||j>=0)
​    {
    //定义一个nums1记录num1中最后一个字符
​      int nums1=0;
    //如果num1的小标i>=0，那么就可以找到最后一个元素
​      if(i>=0)
​      {
​        nums1=num1[i]-48;
​        i--;
​      }
    //定义一个nums2记录num2中的最后一个元素
​      int nums2=0;
​      if(j>=0)
​      {
​        nums2=num2[j]-48;
​        j--;
​      }
    //nums1+nums2+进位即为新的字符串的最后一位
​      int num=nums1+nums2+next;
    //如果最后一位大于等于10，则这一位要-10，然后向后进一位，即把进位变成1
​      if(num>=10)
​      {
​        num-=10;
​        next=1;
​      }
    //如果不进位就把进位变为0
​      else
​      {
​        next=0;
​      }
    //让字符串追加
​      s+=num+48;
​    }
      //如果最后一位向前进1，则最后一位要加1
​    if(next==1)
​    {
​      s+='1';
​    }
      //反转字符串，即为所求
​    reverse(s.begin(),s.end());
​    return s;
  }
};
```

