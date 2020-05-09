/*
 * @Author: SourDumplings
 * @Date: 2020-05-09 15:15:56
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/unique-paths/
 */

class Solution
{
    public int uniquePaths(int m, int n)
    {
        if (m == 1 && n == 1)
        {
            return 1;
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
            res[m - 1][n - 2] = 1;
        }
        if (m > 1)
        {
            res[m - 2][n - 1] = 1;
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
                        res[i][j] += res[i + 1][j];
                    }
                    if (j < n - 1)
                    {
                        res[i][j] += res[i][j + 1];
                    }
                }
            }
        }
        return res[0][0];
    }
}