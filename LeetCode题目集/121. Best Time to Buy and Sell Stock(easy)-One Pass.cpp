/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @Date: 2019-03-17 21:09:26
 * 
 * 这个方法真心神奇，这么维护两个变量都可以，是不是启示买股票的方法嘞？
 */

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (auto &i : prices)
        {
            if (i < minPrice)
            {
                minPrice = i;
            }
            else if (i - minPrice > maxProfit)
            {
                maxProfit = i - minPrice;
            }
        }
        return maxProfit;
    }
};