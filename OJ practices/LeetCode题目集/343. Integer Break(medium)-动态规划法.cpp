/*
 * @Author: SourDumplings
 * @Date: 2021-04-14 11:46:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/integer-break/
 * 
 * 对于每个正整数 x
 * dp[x] = max(dp[x - y] * y, (x - y) * y)，遍历 y
 * 
 * 参考：https://leetcode-cn.com/problems/integer-break/solution/zheng-shu-chai-fen-by-leetcode-solution/
 */

class Solution
{
public:
    int integerBreak(int n)
    {
        int dp[n + 1];
        fill(dp, dp + n + 1, 1);
        for (int x = 3; x <= n; ++x)
        {
            for (int y = 2; y < x; ++y)
            {
                int temp = max(dp[x - y] * y, (x - y) * y);
                dp[x] = max(dp[x], temp);
            }
        }
        return dp[n];
    }
};