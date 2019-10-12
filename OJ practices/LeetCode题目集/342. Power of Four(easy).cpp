/*
 * @Autor: SourDumplings
 * @Date: 2019-09-11 08:10:46
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/power-of-four/
 */

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        double d = log(num) / log(4);
        return fabs(d - (int)d) < 1e-5;
    }
};