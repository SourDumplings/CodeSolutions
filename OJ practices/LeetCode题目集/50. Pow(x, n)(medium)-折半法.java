/*
 * @Author: SourDumplings
 * @Date: 2020-03-08 12:09:17
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/powx-n/
 */

class Solution
{
    public double myPow(double x, int n)
    {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2)
        {
            if (i % 2 != 0)
            {
                res *= x;
            }
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
}