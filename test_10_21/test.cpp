#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        //判断竖的情况
        int flag1 = 0;
        for (int j = 0; j < board[0].size(); j++)
        {
            int i = 1;
            for (; i < board.size(); i++)
            {
                if (board[i][j] != board[i - 1][j])
                {
                    break;
                }
            }
            if (i == board.size() && board[i-1][j] == 1 && board[i-1][j] == board[i -2][j])
            {
                flag1 = 1;
                break;
            }
        }

        //判断横的是否有相等的
        int flag2 = 0;
        for (int i = 0; i < board.size(); i++)
        {
            int j = 1;
            for (; j < board[0].size(); j++)
            {
                if (board[i][j] != board[i][j - 1])
                {
                    break;
                }
            }
            if (j == board[0].size() && board[i][j-1] == 1 && board[i][j-1] == board[i][j - 2])
            {
                flag2 = 1;
                break;
            }
        }


        //判断正斜是否相等
        int flag3 = 0;
        int i = 1;
        for (; i < board.size(); i++)
        {
            if (board[i][i] != board[i - 1][i - 1])
            {
                break;
            }
        }
        if (i == board.size()  && board[i-1][i-1] == board[i - 2][i - 2] && board[i-1][i-1] == 1)
        {
            flag3 = 1;
        }

        //判断反斜是否相等
        int flag4 = 0;
        int j = board.size() - 1;
        for (; j >= 1; i--)
        {
            if (board[j][j] != board[j - 1][j - 1])
            {
                break;
            }
        }
        if (j == 1 && board[j][j] == board[j - 1][j - 1] && board[j][j] == 1)
        {
            flag4 = 1;
        }
        if (flag1 || flag2 || flag3 || flag4)
        {
            return true;
        }
        return false;
    }
};


int main()
{
    vector<vector<int>>ret = { {0,0,1},{1,-1,-1},{1,-1,0} };
    bool ans = Board().checkWon(ret);
    cout << ans << endl;
}