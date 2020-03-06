/*
 * @Author: SourDumplings
 * @Date: 2020-03-06 09:32:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/rotate-image/
 */

class Solution
{
    public void rotate(int[][] matrix)
    {
        int n = matrix.length;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
            }
        }
    }
}