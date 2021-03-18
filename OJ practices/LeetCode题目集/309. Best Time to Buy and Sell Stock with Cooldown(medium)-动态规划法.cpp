/*
 * @Author: SourDumplings
 * @Date: 2021-03-18 10:10:50
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 
我们目前持有一支股票，对应的「累计最大收益」记为 f[i][0]；
我们目前不持有任何股票，并且处于冷冻期中，对应的「累计最大收益」记为 f[i][1]；
我们目前不持有任何股票，并且不处于冷冻期中，对应的「累计最大收益」记为 f[i][2]。

这里的「处于冷冻期」指的是在第 ii 天结束之后的状态。
也就是说：如果第 ii 天结束之后处于冷冻期，那么第 i+1i+1 天无法买入股票

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
        int f[n][3];
        // 初始条件
        f[0][0] = -prices[0];
        f[0][1] = f[0][2] = 0;
        for (int i = 1; i < n; ++i)
        {
            // 持有股票的情况
            // 要么不操作继续持有，要么购买股票
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            
            // 不持有股票的冻结情况
            // 卖出了股票
            f[i][1] = f[i - 1][0] + prices[i];
            
            // 不持有股票的非冻结情况
            // 什么都没操作
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        // 最后一天持有股票是没有意义的
        return max(f[n - 1][1], f[n - 1][2]);
    }
};