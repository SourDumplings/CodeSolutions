/*
 * @Author: SourDumplings
 * @Date: 2019-07-31 18:03:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-of-1-bits/
 */

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        uint32_t mask = 1;
        int num = 32;
        while (num--)
        {
            if (n & mask)
            {
                ++res;
            }
            mask <<= 1;
        }
        return res;
    }
};