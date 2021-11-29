#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void test()
{
	vector<int>weight = { 1,3,4 };
	vector<int>value = { 15,20,30 };
	int bagweight = 4;
	vector<vector<int>>dp(value.size(), vector<int>(bagweight + 1, 0));
	for (int j = 0; j <= bagweight; j++)
	{
		if (j >= weight[0])
		{
			dp[0][j] = value[0];
		}
	}
	for (int i = 1; i <value.size(); i++)
	{
		for (int j = 1; j <= bagweight ; j++)
		{
			if (j < weight[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - weight[i]] + value[i], dp[i - 1][j]);
			}
		}
	}
	cout << dp[value.size()-1][bagweight] << endl;
}
int main()
{
	test();
	return 0;
}