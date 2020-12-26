/*
 * @Author: SourDumplings
 * @Date: 2020-12-26 10:46:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * 
 * 时间复杂度 O(nlogn)
 * 空间复杂度 O(n)
 */

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int res = INT32_MAX;
        int sum[n];
        fill(sum, sum + n, 0);
        sum[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int i = 0; i < n; ++i)
        {
            int b = i, e = n;
            while (b < e)
            {
                int m = (b + e) / 2;
                int thisSum;
                if (i == 0)
                {
                    thisSum = sum[m];
                }
                else
                {
                    thisSum = sum[m] - sum[i - 1];
                }
                if (thisSum < s)
                {
                    b = m + 1;
                }
                else if (thisSum >= s)
                {
                    if (m - i + 1 < res)
                    {
                        res = m - i + 1;
                    }
                    if (thisSum == s)
                    {
                        break;
                    }
                    e = m;
                }
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};