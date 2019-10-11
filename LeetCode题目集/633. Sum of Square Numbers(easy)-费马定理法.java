/*
 * @Autor: SourDumplings
 * @Date: 2019-10-11 14:09:46
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/sum-of-square-numbers/
 * 
 * 费马定理：
 * 任何一个可以表示成两个数完全平方和的形式的数，当且仅当每个（4k + 3）形式的素数因子出现偶数次
 */

class Solution
{
    public boolean judgeSquareSum(int c)
    {
        int r = (int) Math.sqrt(c);
        for (int i = 2; i <= r; i++)
        {
            if (c % i == 0)
            {
                int count = 0;
                while (c % i == 0)
                {
                    ++count;
                    c /= i;
                    // 这保证i一定是素因子
                }
                if (i % 4 == 3 && count % 2 == 1)
                {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
}
