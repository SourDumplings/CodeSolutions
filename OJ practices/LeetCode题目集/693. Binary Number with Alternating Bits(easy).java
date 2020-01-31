/*
 * @Author: SourDumplings
 * @Date: 2019-10-18 08:27:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-number-with-alternating-bits/
 */

class Solution
{
    public boolean hasAlternatingBits(int n)
    {
        int mask = 1 << 31;
        int count = 32;
        while ((mask & n) == 0)
        {
            mask >>>= 1;
            --count;
        }
        boolean last = false;
        while (count > 0)
        {
            if (last && (mask & n) != 0 || !last && (mask & n) == 0)
            {
                return false;
            }
            last = (mask & n) != 0;
            mask >>>= 1;
            --count;
        }
        return true;
    }
}