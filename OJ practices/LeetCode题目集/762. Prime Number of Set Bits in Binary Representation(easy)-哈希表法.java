import java.util.Arrays;

/*
 * @Autor: SourDumplings
 * @Date: 2019-11-06 20:11:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
 */

class Solution
{
    private int primes[] = new int[]
    { 2, 3, 5, 7, 11, 13, 17, 19 };

    public int countPrimeSetBits(int L, int R)
    {
        boolean[] isPrime = new boolean[20];
        Arrays.fill(isPrime, false);
        for (int i : primes)
        {
            isPrime[i] = true;
        }
        int res = 0;
        for (int i = L; i <= R; i++)
        {
            if (isPrime[Integer.bitCount(i)])
            {
                ++res;
            }
        }
        return res;
    }
}