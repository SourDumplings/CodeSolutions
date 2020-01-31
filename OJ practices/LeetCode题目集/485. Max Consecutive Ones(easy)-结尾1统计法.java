/*
 * @Author: SourDumplings
 * @Date: 2019-09-27 14:59:45
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/max-consecutive-ones/
 */

class Solution
{
    public int findMaxConsecutiveOnes(int[] nums)
    {
        int res = 0;
        int leftMost = -1;
        boolean isOnes = false;
        int l = nums.length;
        for (int i = 0; i < l; i++)
        {
            if (nums[i] == 1)
            {
                if (!isOnes)
                {
                    isOnes = true;
                    leftMost = i;
                }
                if (i < l - 1 && nums[i + 1] == 0 || i == l - 1 && nums[i] == 1)
                {
                    if (i - leftMost + 1 > res)
                    {
                        res = i - leftMost + 1;
                    }
                }
            }
            else
            {
                isOnes = false;
            }
        }
        return res;
    }
}