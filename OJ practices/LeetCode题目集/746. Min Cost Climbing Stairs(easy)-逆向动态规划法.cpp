/*
 * @Autor: SourDumplings
 * @Date: 2019-11-01 07:47:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/min-cost-climbing-stairs/
 */

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        // c1代表从前一步走的成本，c2代表从前两步走的成本
        int c1 = 0, c2 = 0;
        int n = cost.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int c = cost[i] + min(c1, c2);
            c2 = c1;
            c1 = c;
        }
        return min(c1, c2);
    }
};