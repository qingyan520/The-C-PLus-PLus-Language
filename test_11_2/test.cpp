#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int ret = 0;
	vector<vector<int>>dp(str1.size(), vector<int>(str2.size(), 0));
	for (int i = 0; i < str1.size(); i++)
	{
		for (int j = 0; j < str2.size(); j++)
		{
			if (i == 0 && str1[i] == str2[j])
			{
				dp[i][j] = 1;
			}
			else if (j == 0 && str1[i] == str2[j])
			{
				dp[i][j] = 1;
			}
			else if (j > 0 && i > 0 && str1[i] == str2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			ret = max(ret, dp[i][j]);

		}

	}
	cout << ret << endl;
	return 0;
}