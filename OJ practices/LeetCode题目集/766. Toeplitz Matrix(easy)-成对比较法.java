/*
 * @Author: SourDumplings
 * @Date: 2019-11-07 09:56:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/toeplitz-matrix/
 * 
 * 对于每个元素都和它左上的元素进行比较
 */

class Solution
{
    public boolean isToeplitzMatrix(int[][] matrix)
    {
        int lr = matrix.length;
        int lc = matrix[0].length;
        for (int i = 0; i < lr; i++)
        {
            for (int j = 0; j < lc; j++)
            {
                if (i > 0 && j > 0 && matrix[i - 1][j - 1] != matrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
}