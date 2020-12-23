/*
 * @Author: SourDumplings
 * @Date: 2020-12-23 08:50:08
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
 * 
 * 对所有数字执行按位与运算的结果是所有对应二进制字符串的公共前缀再用零补上后面的剩余位
 * 比如两个数 12 和 14
 * 12               0 0 0 0 1 1 0 0
 * 13               0 0 0 0 1 1 0 1
 * 14               0 0 0 0 1 1 1 0
 * 结果             0 0 0 0 1 1 0 0
 * 12 和 14 的公用前缀数字是 1 1，可以发现其也是所有数的公用前缀，数值是 0 0 0 0 1 1 0 0，
 * m 和 n 的公用前缀就是 [m, n] 上所有数的公用前缀，也就是结果
 * 将 m 和 n 先右移直到二者相等，再左移相同的位数即可得到该结果
 * 
 */

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int shiftNum = 0;
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            ++shiftNum;
        }
        for (int i = 0; i < shiftNum; ++i)
        {
            m <<= 1;
        }
        return m;
    }
};