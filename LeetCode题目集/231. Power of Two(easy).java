/*
 * @Author: SourDumplings
 * @Date: 2019-08-25 23:01:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/power-of-two/
 */

class Solution
{
    public boolean isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
}