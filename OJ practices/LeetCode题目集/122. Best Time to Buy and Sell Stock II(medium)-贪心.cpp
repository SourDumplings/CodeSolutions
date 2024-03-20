/**
 * @file 122. Best Time to Buy and Sell Stock II(medium)-贪心.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 找到股票买卖的最大获利
 * @version 1.0.0
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 
 * 贪心算法：只考虑长度为 1 的区间即可
 * 对于一个大区间的最大获利，等于将其划分成长度 1 的小区间之后各个小区间最大获利之和
 * 因此我们只需要考虑能获利的最小区间将获利加起来即可
 * 即一支股票连续增长 n 天，第一天买第 n 天卖与第一天买第二天卖，第二天买第三天卖，
 * 直到第 n - 1 天买，第 n 天卖所获利完全一样
 * 
 * 复杂度：时间 O(n) 空间 O(1)
 * 
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solutions/476791/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode-s/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            if (prices[i - 1] < prices[i])
            {
                res += prices[i] - prices[i - 1];
            }
        }
        
        return res;
    }
};