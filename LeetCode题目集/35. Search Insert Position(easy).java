/**
 * @Date    : 2019-01-15 21:24:53
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/search-insert-position/
*/

class Solution
{
    public int searchInsert(int[] nums, int target)
    {
        int b = 0, e = nums.length;
        while (b < e)
        {
            int mi = (b + e) >> 1;
            if (target < nums[mi])
                e = mi;
            else
                b = mi + 1;
        }
        if (b == 0 || nums[b - 1] < target)
        {
            return b;
        }
        else
            return b - 1;
    }
}


