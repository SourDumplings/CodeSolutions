/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * @Date: 2019-03-19 17:54:29
 * 
 * 想象一下，肯定是谷值处买，然后峰值处卖，这样最赚钱
 * 
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        int maxProfit = 0, n = prices.size();
        int peak = prices[0], valley = prices[0];
        int i = 0;
        while (i < n - 1)
        {
            while (i < n - 1 && prices[i + 1] <= prices[i])
                ++i;
            valley = prices[i];
            while (i < n - 1 && prices[i + 1] >= prices[i])
                ++i;
            peak = prices[i];
            maxProfit += peak - valley;
        }
        return maxProfit;
    }
};