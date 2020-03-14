/*
 * @Author: SourDumplings
 * @Date: 2020-03-14 23:31:49
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/single-number/
 * 
 * 将所有的数两两异或起来即可
 */

class Solution
{
    public int singleNumber(int[] nums)
    {
        int a = 0;
        for (int i : nums)
        {
            a ^= i;
        }
        return a;
    }
}