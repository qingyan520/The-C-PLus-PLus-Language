//二维数组的应用
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<vector<int>>ret;
//	ret.resize(5);
//	for (int i = 0; i < 5; i++)
//	{
//		ret[i].resize(i + 1);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		ret[i][0] = 1;
//		ret[i][ret[i].size() - 1]=1;
//	}
//
//	return 0;
//}
//
//for (int i = 0; i < v.size(); i++)
//{
//	cout << v[i] << endl;
//}


//#include<iostream>
//using namespace std;
//#include<vector>
//int main()
//{
//	vector<int>v(10, 1);
//	//vector<int>::iterator it = v.begin();
//	//while (it != v.end())
//	//{
//	//	cout << *it << endl;
//	//	it++;
//	//}
//	for (auto e :v)
//	{
//		cout << e << endl;
//	}
//}

//vector的迭代器失效问题
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int>v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	vector<int>::iterator it = find(v.begin(), v.end(), 3);
//	v.insert(it, 30);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//删除3
//	v.erase(it);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it=v.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}