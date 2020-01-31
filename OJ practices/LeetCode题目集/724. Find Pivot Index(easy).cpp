/*
 * @Author: SourDumplings
 * @Date: 2019-10-29 08:54:40
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-pivot-index/
 */

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int preSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (preSum == sum - nums[i] - preSum)
            {
                return i;
            }
            preSum += nums[i];
        }
        return -1;
    }
};