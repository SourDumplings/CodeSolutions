/*
 * @Author: SourDumplings
 * @Date: 2021-03-18 10:49:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        int minPrice = __INT32_MAX__;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > res)
            {
                res = prices[i] - minPrice;
            }
        }
        return res;
    }
};