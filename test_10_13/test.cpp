#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>arr;
	arr.push_back(100);
	arr.push_back(300);
	arr.push_back(300);
	arr.push_back(300);
	arr.push_back(300);
	arr.push_back(500);
	vector<int>::iterator it = arr.begin();
	for (; it != arr.end(); it++)
	{
		if (*it == 300)
		{
			 arr.erase(it);
		}
	}
	for (it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << " " << endl;
	}
}