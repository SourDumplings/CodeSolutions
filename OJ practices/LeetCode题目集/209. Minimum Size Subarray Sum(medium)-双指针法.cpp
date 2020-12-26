/*
 * @Author: SourDumplings
 * @Date: 2020-12-26 11:17:21
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
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int res = INT32_MAX;
        int left = 0, right = 0;
        int sum = 0;
        while (right < n)
        {
            sum += nums[right];
            while (sum >= s)
            {
                if (right - left + 1 < res)
                {
                    res = right - left + 1;
                }
                sum -= nums[left++];
            }
            ++right;
        }
        return res == INT32_MAX ? 0 : res;
    }
};