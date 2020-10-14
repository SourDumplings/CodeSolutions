/*
 * @Author: SourDumplings
 * @Date: 2020-10-14 19:35:51
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/single-number-ii/
 * 
 * a ^ a = 0, 0 ^ a = a
 * seenOnce 只保留出现一次的数字，不保留出现三次的数字
 * 例如数字2：
 * 出现一次时：
 * seenOnce = ~seenTwice & (seenOnce ^ 2) = 0xFFFFFFFF & 2 = 2
 * seenTwice = ~seenOnce & (seenTwice ^ 2) = ~2 & 2 = 0
 * 出现两次时：
 * seenOnce = ~seenTwice & (seenOnce ^ 2) = 0xFFFFFFFF & (2 ^ 2) = 0xFFFFFFFF & 0 = 0
 * seenTwice = ~seenOnce & (seenTwice ^ 2) = 0xFFFFFFFF & (0 ^ 2) = 0xFFFFFFFF & 2 = 2
 * 出现三次时：
 * seenOnce = ~seenTwice & (seenOnce ^ 2) = ~2 & (0 ^ 2) = ~2 & 2 = 0
 * seenTwice = ~seenOnce & (seenTwice ^ 2) = 0xFFFFFFFF & (2 ^ 2) = 0 
 */

class Solution
{
    public int singleNumber(int[] nums)
    {
        int seenOnce = 0, seenTwice = 0;

        for (int num : nums)
        {
            seenOnce = ~seenTwice & (seenOnce ^ num);
            seenTwice = ~seenOnce & (seenTwice ^ num);
        }

        return seenOnce;
    }
}