/*
 * @Author: SourDumplings
 * @Date: 2020-12-26 10:26:44
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * 
 * 时间复杂度 O(n^2)
 * 空间复杂度 O(1)
 */

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        int res = INT32_MAX;
        for (int i = 0; i < n; ++i)
        {
            int thisSum = 0;
            for (int j = i; j < n; ++j)
            {
                thisSum += nums[j];
                if (thisSum >= s)
                {
                    if (j - i + 1 < res)
                    {
                        res = j - i + 1;
                    }
                    break;
                }
            }
        }
        if (res == INT32_MAX)
        {
            res = 0;
        }
        return res;
    }
};