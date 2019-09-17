/*
 * @Autor: SourDumplings
 * @Date: 2019-09-17 13:14:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/sum-of-two-integers/
 * 
 * 对于任意两个二进制数a和b其和等于a ^ b + ((a & b) << 1)
 * a ^ b得到是没进位的部分，因为只有1和0亦或才是1，1和0相加也是1，而0和0相加本来就是0
 * a & b得到的是进位的部分，因为只有1和1加一起才会进位1，左移一位代表进位
 * 比如说1001 + 1011 = 10100
 * 1001 ^ 1011 = 10
 * 1001 & 1011 = 1001
 * 10100 = (1001 << 1) + 10
 */

class Solution
{
public:
    int getSum(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        else if (b == 0)
        {
            return a;
        }
        else
        {
            return getSum(a ^ b, ((unsigned)(a & b)) << 1);
        }
    }
};