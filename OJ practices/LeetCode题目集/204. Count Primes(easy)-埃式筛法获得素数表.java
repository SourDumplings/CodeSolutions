/*
 * @Author: SourDumplings
 * @Date: 2019-08-17 15:11:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/count-primes/
 */

class Solution
{
    public int countPrimes(int n)
    {
        if (n == 3)
        {
            return 1;
        }
        else if (n < 3)
        {
            return 0;
        }

        boolean[] isPrime = new boolean[n];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < n; i += 2)
        {
            isPrime[i] = false;
        }
        int res = 1;
        for (int i = 3; i * i < n; i += 2)
        {
            if (isPrime[i])
            {
                for (int j = i + i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i])
            {
                ++res;
            }
        }
        return res;
    }
}
