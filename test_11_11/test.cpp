#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        vector<int>ret(len, 0);
        int i = 0;
        int j = 0;
        while (i < len && j < len)
        {
            if (arr[i] % 2 == 0)
            {
                ret[j] = arr[i];
                j += 2;
            }
            i++;
        }
        i = 0;
        j = 1;
        while (i < len && j < len)
        {
            if (arr[i] % 2 == 1)
            {
                ret[j] = arr[i];
                j += 2;
            }
            i++;
        }
        i = 0;
        for (; i < len; i++)
        {
            arr[i] = ret[i];
        }



    }
};

int main()
{
    vector<int>arr{ 1,2,3,4 ,5,6,7,8,9};
    Solution s;
    s.oddInOddEvenInEven(arr, 9);
    for (auto e : arr)
    {
        cout << e << " ";
    }
}