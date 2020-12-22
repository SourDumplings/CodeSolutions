/*
 * @Author: SourDumplings
 * @Date: 2020-12-22 08:51:10
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/number-of-islands/
 */

class Solution
{
private:
    int m, n;

    void mark(vector<vector<char>> &grid, int ci, int cj)
    {
        grid[ci][cj] = '*';

        if (ci > 0 && grid[ci - 1][cj] == '1')
        {
            mark(grid, ci - 1, cj);
        }
        if (cj > 0 && grid[ci][cj - 1] == '1')
        {
            mark(grid, ci, cj - 1);
        }
        if (ci < m - 1 && grid[ci + 1][cj] == '1')
        {
            mark(grid, ci + 1, cj);
        }
        if (cj < n - 1 && grid[ci][cj + 1] == '1')
        {
            mark(grid, ci, cj + 1);
        }

    }
public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        if (m == 0)
        {
            return 0;
        }
        n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    mark(grid, i, j);
                }
            }
        }
        return res;
    }
};
