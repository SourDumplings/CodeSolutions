/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @Date: 2019-03-17 20:54:01
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            int money = prices[i];
            for (int j = i + 1; j < n; j++)
            {
                int profit = prices[j] > money ? prices[j] - money : 0;
                if (profit > max)
                {
                    max = profit;
                }
            }
        }
        return max;
    }
};