#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    map<string, int>m;
    vector<string>v;
    int j = 0;
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            v.push_back(temp);
            temp = "";
        }
        else
        {
            temp += str[i];
        }
        if (i == str.size() - 2)
        {
            v.push_back(temp);
            break;
        }
    }


    for (auto s : v)
    {
        m[s]++;
    }
    auto it = m.begin();
    while (it != m.end())
    {
        string s = it->first;
        if (s.size() == 1)
        {

            if (s[0] >= 'A' && s[0] <= 'Z')
            {
                string s1 = s;
                s1[0] += 32;
                if (m[s] == m[s1])
                {
                    m[s1] += m[s];
                  //  m.erase(s);
                }
                else
                {
                    cout << s << ":" << m[s] << endl;
                }

            }
        }
        else
        {
            cout << it->first << ":" << it->second << endl;
        }
        ++it;
    }

    return 0;

}
