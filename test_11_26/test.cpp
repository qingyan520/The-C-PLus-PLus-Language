// write your code here cpp
// write your code here cpp
//后缀表达式计算方法：
//遇到数字就入栈，遇到运算符就取出栈顶的两个元素进行运算
#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    //逆波兰表达式(后缀表达式)计算方法：遇到数字就入栈，遇到运算符就进行运算，运算完成后将结果再次返回到栈中，到最后返回栈顶元素即可

    void GetNumber(stack<int>& st, int& left, int& right)
    {
        right = st.top();
        st.pop();
        left = st.top();
        st.pop();
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        //auto自动变量遍历每一个数组内容赋值到str中去
        for (auto& str : tokens)
        {
            int left, right;
            //str.back():返回末尾最后一位字符，用于判断它是什么符号
            //遇到数字就入栈，遇到运算符就将栈顶两个元素拿出来进行运算，然后将运算结果继续入栈
            switch (str.back())
            {
            case '+':
                GetNumber(st, left, right);
                st.push(left + right);

                break;
            case '-':
                GetNumber(st, left, right);
                st.push(left - right);
                break;
            case '*':
                GetNumber(st, left, right);
                st.push(left * right);
                break;
            case '/':
                GetNumber(st, left, right);
                st.push(left / right);
                break;
            default:
                st.push(stoi(str));
            }
        }
        //返回栈顶元素即为最终所求
        return st.top();

    }
};
int main()
{
    int n;
    while (cin >> n)
    {
    //    stack<int>s;
        vector<string>v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ret = Solution().evalRPN(v);
        cout << ret << endl;
    }
}