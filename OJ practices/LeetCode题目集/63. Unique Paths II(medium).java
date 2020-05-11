/**
 * @Author: SourDumplings
 * @Date: 2020-05-11 10:48:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 
 */
 
class Solution
{
    public int uniquePathsWithObstacles(int[][] obstacleGrid)
    {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        if (m == 1 && n == 1 || obstacleGrid[0][0] == 1)
        {
            return obstacleGrid[0][0] == 1 ? 0 : 1;
        }
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = -1;
            }
        }
        res[m - 1][n - 1] = 0;
        if (n > 1)
        {
            res[m - 1][n - 2] = obstacleGrid[m - 1][n - 1] == 0 ? 1 : 0;
        }
        if (m > 1)
        {
            res[m - 2][n - 1] = obstacleGrid[m - 1][n - 1] == 0 ? 1 : 0;
        }
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (res[i][j] == -1)
                {
                    res[i][j] = 0;
                    if (i < m - 1)
                    {
                        res[i][j] += obstacleGrid[i + 1][j] == 0 ? res[i + 1][j] : 0;
                    }
                    if (j < n - 1)
                    {
                        res[i][j] += obstacleGrid[i][j + 1] == 0 ? res[i][j + 1] : 0;
                    }
                }
            }
        }
        return res[0][0];
    }
}