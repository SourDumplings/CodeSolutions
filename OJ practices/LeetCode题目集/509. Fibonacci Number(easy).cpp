/*
 * @Autor: SourDumplings
 * @Date: 2019-09-29 07:59:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/fibonacci-number/
 */

class Solution
{
public:
    int fib(int N)
    {
        if (N == 0)
        {
            return 0;
        }

        int f[N + 1];
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= N; i++)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[N];
    }
};