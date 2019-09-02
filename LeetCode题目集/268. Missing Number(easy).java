/*
 * @Author: SourDumplings
 * @Date: 2019-09-02 21:06:31
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/missing-number/
 * 
 * 方法就是把应该的和减去实际的序列和即可得到缺失的数
 */

class Solution
{
    public int missingNumber(int[] nums)
    {
        int n = nums.length;
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        return (0 + n) * (n + 1) / 2 - sum;
    }
}
