/*
 * @Author: SourDumplings
 * @Date: 2021-03-18 10:37:06
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        int f0, f1, f2;
        // 初始条件
        f0 = -prices[0];
        f1 = f2 = 0;
        for (int i = 0; i < n; ++i)
        {
            int n0, n1, n2;
            n0 = max(f0, f2 - prices[i]);
            n1 = f0 + prices[i];
            n2 = max(f1, f2);
            
            f0 = n0;
            f1 = n1;
            f2 = n2;
        }
        return max(f1, f2);
    }
};