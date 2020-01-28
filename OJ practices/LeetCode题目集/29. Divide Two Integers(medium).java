/*
 * @Autor: SourDumplings
 * @Date: 2020-01-28 20:56:10
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/divide-two-integers/
 * 
 * 基本思想就是从被除数中去减去除数的倍数，然后商加上被减数是除数的几倍
 * 直到被除数小于除数
 * 由于题目要求不能用乘法，故借助位运算的来实现倍增
 */

class Solution
{
    public int divide(int dividend, int divisor)
    {
        long a = (long) dividend;
        long b = (long) divisor;

        boolean isNeg = a * b < 0L;

        if (dividend == Integer.MIN_VALUE && divisor == -1)
        {
            return Integer.MAX_VALUE;
        }

        if (a < 0)
        {
            a *= -1;
        }
        if (b < 0)
        {
            b *= -1;
        }

        int res = 0;
        while (b <= a)
        {
            long t = b, p = 1;
            while ((t << 1) <= a)
            {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            a -= t;
        }
        return isNeg ? -res : res;
    }
}