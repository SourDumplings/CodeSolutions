/*
 * @Autor: SourDumplings
 * @Date: 2019-09-26 17:10:24
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/hamming-distance/
 */

class Solution
{
    public int hammingDistance(int x, int y)
    {
        int r = x ^ y;
        int res = 0;
        for (int i = 0; i != 32; ++i)
        {
            if ((r & 1) == 1)
            {
                ++res;
            }
            r >>= 1;
        }
        return res;
    }
}