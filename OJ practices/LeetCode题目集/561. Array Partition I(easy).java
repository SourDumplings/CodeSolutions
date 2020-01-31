import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-05 09:20:06
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/array-partition-i/
 */

class Solution
{
    public int arrayPairSum(int[] nums)
    {
        Arrays.sort(nums);
        int l = nums.length;
        int res = 0;
        for (int i = 0; i < l; i += 2)
        {
            res += Math.min(nums[i], nums[i + 1]);
        }
        return res;
    }
}