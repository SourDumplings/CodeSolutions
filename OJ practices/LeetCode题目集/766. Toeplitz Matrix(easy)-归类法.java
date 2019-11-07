import java.util.Arrays;

/*
 * @Autor: SourDumplings
 * @Date: 2019-11-07 09:43:04
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/toeplitz-matrix/
 * 
 * 对于左上到右下的斜线上的元素有一个特点就是行序号和列序号的差值是相同的
 * 故可以按照此归类
 */

class Solution
{
    public boolean isToeplitzMatrix(int[][] matrix)
    {
        int[] num = new int[50];
        Arrays.fill(num, -1);
        int lr = matrix.length;
        int lc = matrix[0].length;
        for (int i = 0; i < lr; i++)
        {
            for (int j = 0; j < lc; j++)
            {
                int n = matrix[i][j];
                int d = i - j + 21;
                if (num[d] == -1)
                {
                    num[d] = n;
                }
                else if (num[d] != n)
                {
                    return false;
                }
            }
        }
        return true;
    }
}