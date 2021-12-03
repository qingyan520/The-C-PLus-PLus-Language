//#include<iostream>
//#include<string.h>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    //每三个字母三个字母进行映射
//    bool Is_true(string& temp, vector<int>arr, string& p)
//    {
//        for (int i = 0; i < temp.size(); i++)
//        {
//            arr[temp[i] - 97]++;
//        }
//
//        for (int i = 0; i < 26; i++)
//        {
//            if (arr[i] == 1)
//                return false;
//        }
//        for (int i = 0; i < p.size(); i++)
//        {
//            if (arr[p[i] - 97] != 2)
//                return false;
//        }
//        return true;
//    }
//    vector<int> findAnagrams(string s, string p) {
//        vector<int>arr(26, 0);
//        for (int i = 0; i < p.size(); i++)
//        {
//            arr[p[i] - 97]++;
//        }
//        string temp;
//        vector<int>ret;
//        int i = 0;
//        int j = 0;
//        while (i < s.size())
//        {
//            if (j + i < s.size() && j < p.size())
//            {
//                temp += s[i + j];
//                j++;
//            }
//            else if (j == p.size())
//            {
//                //cout<<temp<<endl;
//                if (Is_true(temp, arr, p))
//                {
//                    cout << temp << endl;
//                    cout << i << endl;
//                    ret.push_back(i);
//                }
//                i++;
//                j = 0;
//                temp = "";
//            }
//            if (j + i >= s.size())
//            {
//                break;
//            }
//
//        }
//        return ret;
//    }
//};
//int main()
//{
//    Solution s;
//   vector<int>arr= s.findAnagrams("cbaebabacd", "abc");
//   for (int i = 0; i < arr.size(); i++)
//   {
//       cout << arr[i] << " ";
//   }
//}



#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int startx,  starty;
int endx, endy;
struct pos
{
    int x;
    int y;
    int step;
};
int dir[4][2]{ {0,1},{1,0},{0,-1},{-1,0} };
int v[100][100]{ 0 };
int BST(vector<vector<int>>map)
{
    queue<pos>q;
    pos start{ startx,starty,0 };
    q.push(start);
    v[startx][starty] = 1;
    while (!q.empty())
    {
        pos front = q.front();
        q.pop();
        pos next;
        for (int i = 0; i < 4; i++)
        {
            next.x = front.x + dir[i][0];
            next.y = front.y + dir[i][1];
            next.step = front.step + 1;
            if (next.x == endx && next.y == endy)
            {
                return next.step;
            }
            if (next.x >= 0 && next.x < map.size() && next.y >= 0 && next.y < map[0].size() && map[next.x][next.y] == 1 && v[next.x][next.y] == 0)
            {
                q.push(next);
                v[next.x][next.y] = 1;
            }
        }
    }
    return 0;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>>map(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    cin >> startx >> starty >> endx >> endy;
    cout << BST(map) << endl;

}