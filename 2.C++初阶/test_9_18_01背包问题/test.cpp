//01背包问题是最经典的动态规划问题：
//即一个背包最多能装m物品，价值为value[i]的物品重量为weight[i],如何装才能使背包展现最大价值
//问题转化：
//dp[i][j]:背包容量为j在[0,i]件物品中选择价值最大的物品
//对于第i件物品，有两种情况，选与不选
//选择第i件物品：dp[i][j]=max(dp[i-1][j],dp[i][d-weight[i]]+value[i])
//不选第i件物品：dp[i][j]=dp[i-1][j]
//对于第i件物品的选与不选，主要取决于i与weight[i]的关系
//j>weight[i]:dp[i][j]=max(dp[i-1][j],dp[i][d-weight[i]]+value[i])
//j<wieght[i]:dp[i][j]=dp[i-1][j]
//初始化问题：
//1.dp数组的构建：vector<vector<int>>dp(weight.size()+1,vector<int>(bagweight+1,0))
//2.dp数组的初始化：倒叙初始化
//for(int j=bagweight;j>=0;j--)
//   dp[0][j]=dp[0][j-weight[0]]+value[0];
//3.遍历物品，不论先便利哪个都可以，在这里我们先遍历物品，在遍历背包
//初始时第一行已经初始化了，所以让i=1,j=0;
//for(int i=1;i<weight.size();i++)
//{
//		
//#include<iostream>
//using namespace std;
//#include<vector>
//void test()
//{
//	vector<int>weight = { 1,3,4 };
//	vector<int>value = { 15,20,30 };
//	int bagweight = 4;
//	vector<vector<int>>dp(weight.size()+1 , vector<int>(bagweight + 1, 0));
//	//初始化背包
	//for (int j = bagweight; j >= weight[0]; j--)
	//{
	//	dp[0][j] = dp[0][j - weight[0]] + value[0];
	//}
//	//双层遍历背包
//	//先便利物品，在遍历背包
	/*for (int i = 1; i<weight.size(); i++)
	{
		for (int j = 0; j <= bagweight; j++)
		{
			if (j < weight[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
		}*/
//	}
//	cout << dp[weight.size() - 1][bagweight] << endl;
//}
//int main()
//{
//
//	test();
//	return 0;
//}


//一维滚动数组实现01背包问题
#include<iostream>
#include<vector>
; using namespace std;
void test()
{
	vector<int>weight = { 1,3,4 };
	vector<int>value = { 15,20,30 };
	int bagweight = 4;
	vector<int>dp(bagweight + 1, 0);
	for (int i = 0; i<weight.size(); i++)
	{
		for (int j = bagweight; j >= weight[i]; j--)
		{

			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	cout << dp[bagweight] << endl;
}
int main()
{
	test();
	return 0;
}