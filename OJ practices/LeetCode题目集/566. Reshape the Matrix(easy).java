/*
 * @Author: SourDumplings
 * @Date: 2019-10-05 17:10:56
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reshape-the-matrix/
 */

class Solution
{
    private int ir = 0;
    private int ic = 0;

    public int[][] matrixReshape(int[][] nums, int r, int c)
    {
        int nr = nums.length;
        if (nr == 0)
        {
            return nums;
        }
        int nc = nums[0].length;
        if (nr * nc != r * c)
        {
            return nums;
        }
        int[][] res = new int[r][c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                res[i][j] = getNext(nums, nc);
            }
        }
        return res;
    }

    private int getNext(int[][] nums, int nc)
    {
        if (ic == nc)
        {
            ++ir;
            ic = 0;
        }
        return nums[ir][ic++];
    }
}