import java.util.Arrays;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-11 10:58:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/maximum-product-of-three-numbers/
 */

class Solution
{
    public int maximumProduct(int[] nums)
    {
        Arrays.sort(nums);
        int l = nums.length;
        return Math.max(nums[0] * nums[1] * nums[l - 1], nums[l - 1] * nums[l - 2] * nums[l - 3]);
    }
}