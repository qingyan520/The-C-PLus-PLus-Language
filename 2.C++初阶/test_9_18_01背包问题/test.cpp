//01�������������Ķ�̬�滮���⣺
//��һ�����������װm��Ʒ����ֵΪvalue[i]����Ʒ����Ϊweight[i],���װ����ʹ����չ������ֵ
//����ת����
//dp[i][j]:��������Ϊj��[0,i]����Ʒ��ѡ���ֵ������Ʒ
//���ڵ�i����Ʒ�������������ѡ�벻ѡ
//ѡ���i����Ʒ��dp[i][j]=max(dp[i-1][j],dp[i][d-weight[i]]+value[i])
//��ѡ��i����Ʒ��dp[i][j]=dp[i-1][j]
//���ڵ�i����Ʒ��ѡ�벻ѡ����Ҫȡ����i��weight[i]�Ĺ�ϵ
//j>weight[i]:dp[i][j]=max(dp[i-1][j],dp[i][d-weight[i]]+value[i])
//j<wieght[i]:dp[i][j]=dp[i-1][j]
//��ʼ�����⣺
//1.dp����Ĺ�����vector<vector<int>>dp(weight.size()+1,vector<int>(bagweight+1,0))
//2.dp����ĳ�ʼ���������ʼ��
//for(int j=bagweight;j>=0;j--)
//   dp[0][j]=dp[0][j-weight[0]]+value[0];
//3.������Ʒ�������ȱ����ĸ������ԣ������������ȱ�����Ʒ���ڱ�������
//��ʼʱ��һ���Ѿ���ʼ���ˣ�������i=1,j=0;
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
//	//��ʼ������
	//for (int j = bagweight; j >= weight[0]; j--)
	//{
	//	dp[0][j] = dp[0][j - weight[0]] + value[0];
	//}
//	//˫���������
//	//�ȱ�����Ʒ���ڱ�������
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


//һά��������ʵ��01��������
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