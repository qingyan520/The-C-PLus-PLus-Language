#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 1,2,5,7,9 };
	int sum[5] = { 0 };
	sum[0] = arr[0];
	for (int i = 1; i < 5; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}
	return 0;
}