/*
 * @Author: SourDumplings
 * @Date: 2019-08-17 14:20:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/count-primes/
 * 
 * 利用埃式筛法，将合数都覆盖掉便得到素数表
 */

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 3)
        {
            return 1;
        }
        else if (n < 3)
        {
            return 0;
        }

        bool isPrime[n];
        fill(isPrime, isPrime + n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 4; i < n; i += 2)
        {
            isPrime[i] = false;
        }

        for (int i = 3; i * i < n; i += 2)
        {
            if (isPrime[i])
            {
                for (int j = 2; j * i < n; ++j)
                {
                    isPrime[i * j] = false;
                }
            }
        }
        return count(isPrime, isPrime + n, true);
    }
};
