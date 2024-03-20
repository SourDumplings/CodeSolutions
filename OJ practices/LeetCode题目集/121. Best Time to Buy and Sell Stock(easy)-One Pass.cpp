/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * @Date: 2019-03-17 21:09:26
 * 
 * 该方法即记住之前遇到的最低价和当前价比较即可
 * 复杂度：时间 O(n) 空间 O(1)
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/136684/121-mai-mai-gu-piao-de-zui-jia-shi-ji-by-leetcode-/?envType=study-plan-v2&envId=top-interview-150
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