import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-05 21:51:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/move-zeroes/
 */

class Solution
{
    public void moveZeroes(int[] nums)
    {
        int n = nums.length;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        Arrays.fill(nums, j, n, 0);
    }
}