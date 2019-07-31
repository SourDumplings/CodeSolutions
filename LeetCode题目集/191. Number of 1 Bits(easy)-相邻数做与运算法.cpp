/*
 * @Author: SourDumplings
 * @Date: 2019-07-31 18:03:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-of-1-bits/
 * 
 * 对于数n，和n-1做与运算的话，会使得它的二进制表示中最低位的1变为0。因此统计做几次与运算它变为0即可。
 */

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n)
        {
            n &= (n - 1);
            ++res;
        }
        return res;
    }
};