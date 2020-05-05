/*
 * @Author: SourDumplings
 * @Date: 2020-05-05 21:13:25
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/spiral-matrix-ii/
 */

class Solution
{
    public int[][] generateMatrix(int n)
    {
        int[][] res = new int[n][n];
        char direction = 'r';
        int num = 1;
        int[] limits = {0, n - 1, 0, n - 1};
        for (int i = 0; num <= n * n;)
        {
            for (int j = 0; num <= n * n;)
            {
                res[i][j] = num++;
                switch (direction)
                {
                case 'r':
                {
                    if (j == limits[3])
                    {
                        direction = 'd';
                        i++;
                        limits[0]++;
                    }
                    else
                    {
                        j++;
                    }
                    break;
                }
                case 'd':
                {
                    if (i == limits[1])
                    {
                        direction = 'l';
                        j--;
                        limits[3]--;
                    }
                    else
                    {
                        i++;
                    }
                    break;
                }
                case 'l':
                {
                    if (j == limits[2])
                    {
                        direction = 'u';
                        i--;
                        limits[1]--;
                    }
                    else
                    {
                        j--;
                    }
                    break;
                }
                case 'u':
                {
                    if (i == limits[0])
                    {
                        direction = 'r';
                        j++;
                        limits[2]++;
                    }
                    else
                    {
                        i--;
                    }
                    break;
                }
                }
            }
        }
        return res;
    }
}