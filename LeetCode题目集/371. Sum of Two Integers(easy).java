/*
 * @Autor: SourDumplings
 * @Date: 2019-09-17 13:33:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/sum-of-two-integers/
 */

class Solution
{
    public int getSum(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        else if (b == 0)
        {
            return a;
        }
        else
        {
            return getSum(a ^ b, (a & b) << 1);
        }
    }
}