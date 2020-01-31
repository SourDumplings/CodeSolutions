/*
 * @Author: SourDumplings
 * @Date: 2019-10-18 07:56:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-number-with-alternating-bits/
 * 
 * 注意对于int右移是用符号位补齐
 */

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        unsigned mask = 1 << 31;
        int count = 32;
        while ((mask & n) == 0)
        {
            mask >>= 1;
            --count;
        }
        bool last = false;
        while (count > 0)
        {
            if (last && (mask & n) != 0 || !last && (mask & n) == 0)
            {
                return false;
            }
            last = (mask & n) != 0;
            mask >>= 1;
            --count;
        }
        return true;
    }
};