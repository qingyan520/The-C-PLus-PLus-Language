#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        vector<int>dp;

        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];

    }
};
int main()
{
    Solution a;
    cout<<a.fib(2);
	return 0;
}