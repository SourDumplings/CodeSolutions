/*
 * @Author: SourDumplings
 * @Date: 2020-08-24 17:53:31
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 */

class Solution
{
    public boolean search(int[] nums, int target)
    {
        int l = nums.length;
        for (int i = 0; i < l; i++)
        {
            if (nums[i] == target)
            {
                return true;
            }
        }
        return false;
    }
}