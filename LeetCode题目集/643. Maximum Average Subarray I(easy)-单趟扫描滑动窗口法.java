/*
 * @Autor: SourDumplings
 * @Date: 2019-10-11 18:26:49
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/maximum-average-subarray-i/
 * 
 * 维持一个大小为k的滑动窗口即可
 */

class Solution
{
    public double findMaxAverage(int[] nums, int k)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        int n = nums.length;
        int maxSum = sum;
        for (int i = k; i < n; i++)
        {
            sum -= nums[i - k] - nums[i];
            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
        return (double) maxSum / k;
    }
}