/*
 * @Autor: SourDumplings
 * @Date: 2019-10-12 17:38:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/image-smoother/
 */

class Solution
{
    public int[][] imageSmoother(int[][] M)
    {
        int r = M.length;
        int c = M[0].length;
        int[][] res = new int[r][c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int count = 0, sum = 0;
                for (int nr = i - 1; nr <= i + 1; nr++)
                {
                    for (int nc = j - 1; nc <= j + 1; nc++)
                    {
                        if (0 <= nr && nr < r && 0 <= nc && nc < c)
                        {
                            sum += M[nr][nc];
                            ++count;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
}