#include<iostream>
using namespace std;
void encrypt(char info[]);
int main()
{
    // ÇëÔÚ´ËÌí¼ÓÄãµÄ´úÂë
   /********** Begin ********/
    char str[7] = "\0";
    gets_s(str);
   /********** End **********/
    encrypt(str);
   // cout << str << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << str[i];
    }
    //cout << end;
}
void encrypt(char info[])
{
    // ÇëÔÚ´ËÌí¼ÓÄãµÄ´úÂë
   /********** Begin ********/
    for (int i = 0; i < 6; i++)
    {
        if (info[i] == 'w')
        {
            info[i] = 'a';
        }
        else if (info[i] == 'x')
        {
            info[i] = 'b';
        }
        else if (info[i] == 'y')
        {
            info[i] = 'c';
        }
        else if (info[i] == 'z')
        {
            info[i] = 'd';
        }
        else if (info[i] == 'W')
        {
            info[i] = 'A';
        }
        else if (info[i] == 'X')
        {
            info[i] = 'B';
        }
        else if (info[i] == 'Y')
        {
            info[i] = 'C';
        }
        else if (info[i] == 'Z')
        {
            info[i] = 'D';
        }
        else if(info[i]!='\0')
        {
            info[i] += 4;
        }
    }
   /********** End **********/
}

