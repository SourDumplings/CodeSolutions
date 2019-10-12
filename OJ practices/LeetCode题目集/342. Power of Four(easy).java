/*
 * @Autor: SourDumplings
 * @Date: 2019-09-11 08:15:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/power-of-four/
 */

class Solution
{
    public boolean isPowerOfFour(int num)
    {
        return (Math.log(num) / Math.log(4)) % 1 == 0;
    }
}