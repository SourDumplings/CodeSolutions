/*
 * @Author: SourDumplings
 * @Date: 2019-11-01 08:16:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/min-cost-climbing-stairs/
 */

class Solution
{
    public int minCostClimbingStairs(int[] cost)
    {
        // c1代表从前一步走的成本，c2代表从前两步走的成本
        int c1 = 0, c2 = 0;
        int l = cost.length;
        for (int i = 0; i < l; i++)
        {
            int c = cost[i] + Math.min(c1, c2);
            c2 = c1;
            c1 = c;
        }
        return Math.min(c1, c2);
    }
}