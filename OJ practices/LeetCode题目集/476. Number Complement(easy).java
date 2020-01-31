/*
 * @Author: SourDumplings
 * @Date: 2019-09-27 13:45:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-complement/
 */

class Solution
{
    public int findComplement(int num)
    {
        int s = 1;
        int e = 0;
        for (int i = 0; i < 31; i++)
        {
            if ((num & s) != 0)
            {
                e = i;
            }
            s <<= 1;
        }
        int mask = (1 << (e + 1)) - 1;
        return num ^ mask;
    }
}