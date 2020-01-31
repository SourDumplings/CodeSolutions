/*
 * @Author: SourDumplings
 * @Date: 2019-09-24 15:31:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/third-maximum-number/
 */

class Solution
{
    public int thirdMax(int[] nums)
    {
        int f = Integer.MIN_VALUE;
        int s = Integer.MIN_VALUE;
        int t = Integer.MIN_VALUE;
        for (int i : nums)
        {
            if (i > f)
            {
                f = i;
            }
        }
        for (int i : nums)
        {
            if (i > s && i < f)
            {
                s = i;
            }
        }
        boolean hasT = false;
        for (int i : nums)
        {
            if (i >= t && i < s)
            {
                hasT = true;
                t = i;
            }
        }
        return hasT ? t : f;
    }
}
