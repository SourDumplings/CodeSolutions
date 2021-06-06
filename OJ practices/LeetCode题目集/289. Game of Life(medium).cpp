/*
 * @Author: SourDumplings
 * @Date: 2021-06-06 08:38:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/game-of-life/
 */

class Solution
{
private:
    pair<int, int> cal_live_dead_neighbor(const vector<vector<int>> &board,
                                          int m,
                                          int n,
                                          int i,
                                          int j)
    {
        pair<int, int> res;
        for (int k = i - 1; k < i + 2; ++k)
        {
            if (k >= 0 && k < m)
            {
                for (int l = j - 1; l < j + 2; ++l)
                {
                    if (!(k == i && l == j) && l >= 0 && l < n)
                    {
                        (board[k][l] == 0 || board[k][l] == -2) ? ++res.second : ++res.first;
                    }
                }
            }
        }
        return res;
    }
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        if (m == 0)
        {
            return;
        }
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                const pair<int, int>
                    lDNum = cal_live_dead_neighbor(board, m, n, i, j);
                if (board[i][j])
                {
                    if (lDNum.first < 2 || lDNum.first > 3)
                    {
                        board[i][j] = -1;
                    }
                }
                else
                {
                    if (lDNum.first == 3)
                    {
                        board[i][j] = -2;
                    }
                }
            }
        }
        for (int k = 0; k < m; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                if (board[k][i] == -1)
                {
                    board[k][i] = 0;
                }
                else if (board[k][i] == -2)
                {
                    board[k][i] = 1;
                }
            }
        }
    }
};