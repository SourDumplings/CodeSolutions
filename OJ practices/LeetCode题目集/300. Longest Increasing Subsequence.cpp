/*
 * @Author: SourDumplings
 * @Date: 2021-01-23 12:49:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n];
        int res = 1;
        fill(dp, dp + n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};