#include <iostream>
#include<string.h>
using namespace std;

// 函数silly：计算数值有多二
// 参数：a-存储数值的字符数组，以'\0'结束，所以不需要另一个参数告诉函数数组有多长
// 返回值：数值犯二的程度
double silly(char a[]);

int main()
{
    char s[102];     // 定义存储数值的数组
    cin >> s;     // 输入不超过位的整数
    double sy = silly(s);     // 计算犯二的程度
    cout << sy << endl;     // 输出犯二的程度
    return 0;
}

double silly(char a[])
{
    // 请在此添加代码，实现函数silly
    /********** Begin *********/
    double flag1 = 1.0;
    double flag2 = 1.0;
    size_t n = strlen(a);
    int m = n;
    int i = 0;
    if (a[0] == '-')
    {
        flag1 = 1.5;
        if ((a[n-1]-48)%2==0)
        {
            flag2 = 2.0;
        }
        m--;
        i++;
    }
    int count = 0;
    for (; i < n; i++)
    {
        if (a[i] == '2')
        {
            count++;
        }
    }
    double x = (double)m;
    double s= ((double)count / x) * flag1 * flag2;
    return s;


    /********** End **********/
}