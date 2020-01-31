import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-29 08:58:04
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-pivot-index/
 */

class Solution
{
    public int pivotIndex(int[] nums)
    {
        int sum = Arrays.stream(nums).sum();
        int preSum = 0;
        int l = nums.length;
        for (int i = 0; i < l; i++)
        {
            if (preSum == sum - preSum - nums[i])
            {
                return i;
            }
            preSum += nums[i];
        }
        return -1;
    }
}