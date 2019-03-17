/**
 * @Date    : 2019-01-10 16:34:43
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution
{
    public int removeDuplicates(int[] nums)
    {
        if (nums.length == 0)
        {
            return 0;
        }
        int lastNum = nums[0];
        int k = 1;
        for (int i = 1; i < nums.length; ++i)
        {
            if (nums[i] != lastNum)
            {
                lastNum = nums[k++] = nums[i];
            }
        }
        return k;
    }
}

