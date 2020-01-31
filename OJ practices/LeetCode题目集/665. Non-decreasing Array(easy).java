/*
 * @Author: SourDumplings
 * @Date: 2019-10-13 09:08:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/non-decreasing-array/
 */

class Solution
{
    public boolean checkPossibility(int[] nums)
    {
        boolean flag = true;
        int n = nums.length;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                if (flag)
                {
                    flag = false;
                    if (i == 0 || nums[i - 1] <= nums[i + 1])
                    {
                        nums[i] = nums[i + 1];
                    }
                    else
                    {
                        nums[i + 1] = nums[i];
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
}