/*
 * @Author: SourDumplings
 * @Date: 2019-07-21 21:28:44
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-bits/
 */

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        using unit32_t = unsigned int;
        unit32_t res = 0, numLo = 0, numHi = 0;
        for (unit32_t lo = 0, hi = 31; lo < hi; ++lo, --hi)
        {
            numLo = (1 << lo);
            numHi = (1 << hi);
            if (numLo & n)
            {
                res |= numHi;
            }
            if (numHi & n)
            {
                res |= numLo;
            }
        }
        return res;
    }
};