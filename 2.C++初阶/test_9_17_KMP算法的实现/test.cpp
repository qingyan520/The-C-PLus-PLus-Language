#include<iostream>
#include<vector>
using namespace std;
namespace hello
{
	void getNext(vector<int>& next, const string& s)
	{
		int j = 0;
		next[0] = 0;
		for (int i = 1; i < s.size(); i++)//ע��i��1��ʼ
		{
			while (j > 0 && s[i] != s[j])//ǰ��׺����ͬ��
			{
				j = next[j-1];//��ǰ����
			}
			if (s[i] == s[j])//�ҵ���ͬ��ǰ��׺
			{
				j++;
			}
			next[i] = j;//��j(ǰ׺�ĳ���)����next[i]
		}
	}
	int strstr(string haystack, string needle)
	{
		if (needle.size() == 0)
			return 0;
		int n = needle.size();
		vector<int>next(n);
		getNext(next, needle);
		int j = 0;//��Ϊnext�������¼����ʵλ��Ϊ-1
		for (int i = 0; i < haystack.size(); i++)//ע���±��0��ʼ
		{
			while (j >0 && haystack[i] != needle[j])//��ƥ��
			{
				j = next[j-1];//jѰ��֮ǰƥ���λ��
			}
			if (haystack[i] == needle[j])//ƥ�䣬i��jͬʱ����
			{
				j++;
			}
			if (j == needle.size())//�������ִ���λ��
			{
				return (i - needle.size() + 1);
			}
		}
		//δ�ҵ�������-1
		return -1;


	}
}
int main()
{
	cout<<hello::strstr("hello", "llo");
	return 0;
}