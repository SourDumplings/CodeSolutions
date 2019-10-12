import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2019-08-20 20:55:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/contains-duplicate/
 */

class Solution
{
    public boolean containsDuplicate(int[] nums)
    {
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return false;
    }
}