//二分法查找数组中的最大值
#include<iostream>
using namespace std;
int Binary(int* arr, int n)
{
	int left = 0, right = n - 1;
	int ret = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid+1] > arr[mid])
		{
			ret =arr[mid+1];
			left = mid - 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ret;
}
int main()
{
	int arr[] = { 1,5,4,8,3,10,5,6,1 };
	printf("%d\n", Binary(arr, sizeof(arr) / sizeof(arr[0])));
	return 0;
}