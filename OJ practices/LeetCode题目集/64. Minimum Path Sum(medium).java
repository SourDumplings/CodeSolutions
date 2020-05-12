/**
 * @Author: SourDumplings
 * @Date: 2020-05-12 19:14:50
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 
 */

class Solution
{
    public int minPathSum(int[][] grid)
    {
        int m = grid.length;
        int n = grid[0].length;
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = -1;
            }
        }
        res[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (res[i][j] == -1)
                {
                    int road1 = Integer.MAX_VALUE, road2 = Integer.MAX_VALUE;
                    if (i < m - 1)
                    {
                        road1 = res[i + 1][j] + grid[i][j];
                    }
                    if (j < n - 1)
                    {
                        road2 = res[i][j + 1] + grid[i][j];
                    }
                    res[i][j] = Math.min(road1, road2);
                }
            }
        }
        return res[0][0];
    }
}