#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        //定义一个下一位，作为进位
        int next = 0;
        int L1 = num1.size(), L2 = num2.size();
        int i = L1 - 1, j = L2 - 1;
        string s;
        int k = 0;
        while (i >= 0 || j >= 0)
        {
            int nums1 = 0;
            if (i >= 0)
            {
                nums1 = num1[i] - 48;
                i--;
            }
            int nums2 = 0;
            if (j >= 0)
            {
                nums2 = num2[j] - 48;
                j--;
            }
            int num = nums1 + nums2 + next;
            if (num > 10)
            {
                num -= 10;
                next = 1;
            }
            s += num + 48;
            k++;
            cout << s << endl;
        }
        return s;
    }
};

int main()
{
    Solution().addStrings("11", "123");
}