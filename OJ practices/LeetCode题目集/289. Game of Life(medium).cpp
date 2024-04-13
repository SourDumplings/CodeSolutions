/**
 * @file 289. Game of Life(medium).cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 使用额外的状态记录原本是活着变成死了的，以及原本是死的变成活的
 * 以此空间复杂度为 O(1)
 * https://leetcode.cn/problems/game-of-life/solutions/179750/sheng-ming-you-xi-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isLiveNext(board, i, j, m, n))
                {
                    board[i][j] = (board[i][j] == 1 ? 1 : 2);
                }
                else
                {
                    board[i][j] = (board[i][j] == 0 ? 0 : 3);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1 || board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
                else
                {
                    board[i][j] = 0;
                }

            }

        }

    }

private:
    bool isLiveNext(const vector<vector<int>> &board, int r, int c, int m, int n) const
    {
        int liveNeighborNum = 0;
        if (0 < r)
        {
            liveNeighborNum += getLiveNeighborNumForOneRow(board, r - 1, c, m, n);
            liveNeighborNum += (board[r - 1][c] % 2 > 0 ? 1 : 0);
        }
        liveNeighborNum += getLiveNeighborNumForOneRow(board, r, c, m, n);
        if (liveNeighborNum <= 3 && r < m - 1)
        {
            liveNeighborNum += getLiveNeighborNumForOneRow(board, r + 1, c, m, n);
            liveNeighborNum += (board[r + 1][c] % 2 > 0 ? 1 : 0);
        }
        return (board[r][c] == 1 && (liveNeighborNum == 2 || liveNeighborNum == 3))
            || (board[r][c] == 0 && liveNeighborNum == 3);
    }

    int getLiveNeighborNumForOneRow(const vector<vector<int>> &board, int r, int c, int m, int n) const
    {
        int liveNeighborNum = 0;
        if (0 < c)
        {
            liveNeighborNum += (board[r][c - 1] % 2 > 0 ? 1 : 0);
        }
        if (c < n - 1)
        {
            liveNeighborNum += (board[r][c + 1] % 2 > 0 ? 1 : 0);
        }
        return liveNeighborNum;
    }
};