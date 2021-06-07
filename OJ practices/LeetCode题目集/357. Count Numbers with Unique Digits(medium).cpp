/*
 * @Author: SourDumplings
 * @Date: 2021-06-07 18:29:37
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/count-numbers-with-unique-digits/
 */

class Solution
{
private:
    int f[10];

    int A(int k, int n)
    {
        return fact(n) / fact(n - k);
    }

    int fact(int n)
    {
        if (f[n] != -1)
        {
            return f[n];
        }
        else
        {
            return n * fact(n - 1);
        }
    }
public:
    int countNumbersWithUniqueDigits(int n)
    {
        int res = 1;
        fill(f, f + 10, -1);
        f[0] = f[1] = 1;
        for (int i = 1; i <= n; ++i)
        {
            int thisRes = 9 * A(i - 1, 9);
            res += thisRes;
        }
        return res;
    }
};