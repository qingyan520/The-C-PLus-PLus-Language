#include"unordered_Map.h"
#include"unordered_Set.h"
int main()
{
	/*unordered_map<string, int>map;
	string s[]{ "苹果","西瓜","苹果", "西瓜", "苹果", "苹果","苹果","玉米","小麦" };
	for (auto e : s)
	{
		HashTableNode<pair<const string,int>>* ret = map.Find(e);
		if (ret == nullptr)
		{
			map.Insert(make_pair(e, 1));
		}
		else
		{
			ret->_data.second++;
		}
	}*/


	//unordered_set<int>us;
	//int arr[]{ 1,5,4,3,2,1,0 ,100,900,212,31};
	//for (auto e : arr)
	//{
	//	us.Insert(e);
	//}

	//unordered_set<int>::iterator it = us.begin();
	//while (it != us.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}


	//unordered_map<string, int>um;
	//string s[]{ "苹果","西瓜","苹果", "西瓜", "苹果", "苹果","苹果","玉米","小麦" };
	//for (auto e : s)
	//{
	//	um[e]++;
	//}
	//auto it = um.begin();
	//while (it != um.end())
	//{
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}

	unordered_map<string, string>um;
	um["left"] = "左边";
	um["left"] += ",剩余";
	um["right"] = "右边";
	um["string"] = "字符串";
	unordered_map<string, string>::iterator it = um.begin();
	while (it != um.end())
	{
		cout << (*it).first << ":" << it->second << endl;
		++it;
	}


}