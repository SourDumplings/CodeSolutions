/*
 * @Author: SourDumplings
 * @Date: 2024-04-05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 * 
 * 时间复杂度 O(n)
 * 空间复杂度 O(1)
 * 
 * 参考：https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode-solutio/
 */

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int res = __INT32_MAX__;
        int l = 0, r = 0;
        int sum = 0;
        while (r < n)
        {
            sum += nums[r];
            if (sum < target)
            {
                ++r;
                continue;
            }

            while (target <= sum - nums[l])
            {
                sum -= nums[l];
                ++l;
            }
            
            if (r - l + 1 < res)
            {
                res = r - l + 1;
                if (res == 1)
                {
                    break;
                }
            }
            ++r;
        }
        if (res == __INT32_MAX__)
        {
            res = 0;
        }
        
        return res;
    }
};