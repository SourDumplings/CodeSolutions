/**
 * @Date    : 2019-02-17 22:05:57
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/climbing-stairs/
*/

class Solution
{
    public int climbStairs(int n)
    {
        int res = 0;
        if (n < 3)
        {
            res = n;
        }
        else
        {
            int first = 1, second = 2;
            for (int i = 3; i <= n; ++i)
            {
                res = first + second;
                first = second;
                second = res;
            }
        }
        return res;
    }
}
