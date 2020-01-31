/*
 * @Author: SourDumplings
 * @Date: 2019-10-09 13:31:19
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/range-addition-ii/
 */

class Solution
{
    public int maxCount(int m, int n, int[][] ops)
    {
        int minA = m;
        int minB = n;
        for (int[] p : ops)
        {
            int a = p[0];
            int b = p[1];
            if (a < minA)
            {
                minA = a;
            }
            if (b < minB)
            {
                minB = b;
            }
        }
        return minA * minB;
    }
}