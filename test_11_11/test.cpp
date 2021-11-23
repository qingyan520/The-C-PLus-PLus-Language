#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     *  ����λ�϶�����������ż��λ�϶���ż��
     *  ���룺����arr�����ȴ���2
     *  len��arr�ĳ���
     *  ��arr����������λ�϶�����������ż��λ�϶���ż��
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