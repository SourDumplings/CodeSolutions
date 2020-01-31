/*
 * @Author: SourDumplings
 * @Date: 2019-10-24 10:28:18
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-search/
 * 
 * 此为优化版本的二分查找，每次只需要一次比较
 */

class Solution
{
    public int search(int[] nums, int target)
    {
        int lo = 0, hi = nums.length;
        while (lo < hi - 1)
        {
            int mi = (lo + hi) / 2;
            if (target < nums[mi])
            {
                hi = mi;
            }
            else
            {
                lo = mi;
            }
        }
        if (nums[lo] == target)
        {
            return lo;
        }
        else
        {
            return -1;
        }
    }
}