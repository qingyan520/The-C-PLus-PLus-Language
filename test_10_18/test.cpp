#include <iostream>
#include<string.h>
using namespace std;

// ����silly��������ֵ�ж��
// ������a-�洢��ֵ���ַ����飬��'\0'���������Բ���Ҫ��һ���������ߺ��������ж೤
// ����ֵ����ֵ�����ĳ̶�
double silly(char a[]);

int main()
{
    char s[102];     // ����洢��ֵ������
    cin >> s;     // ���벻����λ������
    double sy = silly(s);     // ���㷸���ĳ̶�
    cout << sy << endl;     // ��������ĳ̶�
    return 0;
}

double silly(char a[])
{
    // ���ڴ���Ӵ��룬ʵ�ֺ���silly
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