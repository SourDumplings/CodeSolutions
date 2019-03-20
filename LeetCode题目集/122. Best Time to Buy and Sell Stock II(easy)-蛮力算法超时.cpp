/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * @Date: 2019-03-19 17:54:29
 * 

 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        return getMaxProfit(prices, 0);
    }

    int getMaxProfit(const vector<int> &prices, int s)
    {
        int n = prices.size();
        int res = 0, maxProfit = 0;
        for (int i = s; i < n; i++)
        {
            int profit = 0;

            for (int j = i + 1; j < n; j++)
            {

                if (prices[i] < prices[j])
                {
                    profit = prices[j] - prices[i] + getMaxProfit(prices, j + 1);
                }
                if (profit > maxProfit)
                {
                    maxProfit = profit;
                }
            }
            if (maxProfit > res)
            {
                res = maxProfit;
            }
        }
        return res;
    }
};