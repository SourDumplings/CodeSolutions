/**
 * @file 209. Minimum Size Subarray Sum(medium)-二分查找-用 lower_bound.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-05
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/minimum-size-subarray-sum/solutions/305704/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode-solutio/?envType=study-plan-v2&envId=top-interview-150
 * 
 * 复杂度：时间 O(nlogn)
 * 空间 O(n)
 */

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int sum[n];
        sum[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            sum[i] = sum[i - 1] + nums[i];
        }

        int res = __INT32_MAX__;
        for (int i = 0; i < n; ++i)
        {
            if (target <= nums[i])
            {
                res = 1;
                break;
            }
            
            int targetSum = target + sum[i] - nums[i];
            auto it = lower_bound(sum + i + 1, sum + n, targetSum);
            if (it - sum < n
                && it - sum - i + 1 < res
            )
            {
                res = it - sum - i + 1;
            }
        }
        if (res == __INT32_MAX__)
        {
            res = 0;
        }
        
        return res;
    }
};