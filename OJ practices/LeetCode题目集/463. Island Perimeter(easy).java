/*
 * @Author: SourDumplings
 * @Date: 2019-09-26 20:00:11
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/island-perimeter/
 */

class Solution
{
    public int islandPerimeter(int[][] grid)
    {
        int r = grid.length;
        if (r == 0)
        {
            return 0;
        }
        int res = 0;
        int c = grid[0].length;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }

                int count = 0;
                // left
                if (j > 0 && grid[i][j - 1] == 1)
                {
                    ++count;
                }
                // right
                if (j < c - 1 && grid[i][j + 1] == 1)
                {
                    ++count;
                }
                // up
                if (i > 0 && grid[i - 1][j] == 1)
                {
                    ++count;
                }
                // down
                if (i < r - 1 && grid[i + 1][j] == 1)
                {
                    ++count;
                }
                res += 4 - count;
            }
        }
        return res;
    }
}