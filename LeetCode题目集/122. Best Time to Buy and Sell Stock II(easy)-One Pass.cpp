/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * @Date: 2019-03-19 17:54:29
 * 
 * 就是一点一点往峰值上爬，只要股价涨了就卖，积小胜为大胜
 * 
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < prices[i + 1])
            {
                maxProfit += prices[i + 1] - prices[i];
            }
        }

        return maxProfit;
    }
};