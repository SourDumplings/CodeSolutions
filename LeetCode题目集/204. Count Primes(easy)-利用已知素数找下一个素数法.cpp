/*
 * @Author: SourDumplings
 * @Date: 2019-08-17 14:20:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/count-primes/
 * 
 * 注意判断素数，除数的平方大于被除数就没必要再增大除数了
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

        vector<int> primes;
        primes.push_back(2);
        primes.push_back(3);
        while (primes.back() < n)
        {
            get_next_prime(primes);
        }
        return primes.size() - 1;
    }

    void get_next_prime(vector<int> &primes)
    {
        int start = primes.back();
        for (int i = start + 2;; i += 2)
        {
            bool isPrime = true;
            for (auto it = primes.begin() + 1; it != primes.end(); ++it)
            {
                int j = *it;
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
                if (j * j > i)
                {
                    break;
                }
            }
            if (isPrime)
            {
                primes.push_back(i);
                break;
            }
        }
    }
};
