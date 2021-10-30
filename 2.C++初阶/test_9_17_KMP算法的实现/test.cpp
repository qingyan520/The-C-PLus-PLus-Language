#include<iostream>
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