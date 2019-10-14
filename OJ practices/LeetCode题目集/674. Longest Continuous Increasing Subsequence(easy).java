/*
 * @Autor: SourDumplings
 * @Date: 2019-10-14 08:02:51
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 */

class Solution
{
    public int findLengthOfLCIS(int[] nums)
    {
        int n = nums.length;
        if (n == 0)
        {
            return 0;
        }
        int res = 0, count = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                if (count > res)
                {
                    res = count;
                }
                count = 1;
            }
            else
            {
                ++count;
            }
        }
        if (count > res)
        {
            res = count;
        }
        return res;
    }
}
