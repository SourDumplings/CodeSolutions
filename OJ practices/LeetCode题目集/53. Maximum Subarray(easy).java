/**
 * @Date    : 2019-01-17 18:01:55
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/maximum-subarray/
*/

class Solution
{
    public int maxSubArray(int[] nums)
    {
        int thisSum = 0, maxSum = 0;
        boolean isFirst = true;
        int n = nums.length;
        for (int i = 0; i != n; ++i)
        {
            if (isFirst)
            {
                thisSum = maxSum = nums[0];
                isFirst = false;
            }
            else
            {
                if (maxSum < 0 && nums[i] > maxSum)
                {
                    maxSum = thisSum = nums[i];
                }
                else if (nums[i] + thisSum < 0 && maxSum >= 0)
                {
                    thisSum = 0;
                }
                else
                {
                    thisSum += nums[i];
                    if (thisSum > maxSum)
                    {
                        maxSum = thisSum;
                    }
                }
            }
        }
        return maxSum;
    }
}

