/*
 * @Author: SourDumplings
 * @Date: 2021-04-14 12:01:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/integer-break/
 * 
 * 参考：https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/
 * 
 * 可以证明以下两个结论：
 * 1.有均值不等式可知，在拆分数字的个数一定时，n 拆分为相等数字 x 之和时乘积最大
 * 2.在 n 拆分为相等的数时，x 尽可能为 3 时乘积最大，3 最优，2 次之，1 最差，其他的不可能，例如 4 能拆成 2 + 2 乘积不变，5 可以拆成 2 + 3 等
 * 
 * 综合 1 和 2，考察 n 除以 3 的余数即可
 */

class Solution
{
public:
    int integerBreak(int n)
    {
        int res = 1;
        if (n == 3)
        {
            res = 2;
        }
        else if (n > 3)
        {
            int r = n % 3;
            switch (r)
            {
                case 0:
                {
                    res = pow(3, n / 3);
                    break;
                }
                case 1:
                {
                    // 需要将一个 1 + 3 转换为 2 + 2
                    res = pow(3, n / 3 - 1) * 4;
                    break;
                }
                case 2:
                {
                    res = pow(3, n / 3) * 2;
                }
            }
        }
        return res;
    }
};