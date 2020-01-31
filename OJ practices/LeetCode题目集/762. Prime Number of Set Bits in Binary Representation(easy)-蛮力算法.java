import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2019-11-06 19:52:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
 * 
 * 注意到2 ^ 20 = 1048576 > 10 ^ 6，因此对于素数的判断完全可以穷举20以内的素数即可
 */

class Solution
{
    private List<Integer> primes = new ArrayList<>(Arrays.asList(new Integer[]
    { 2, 3, 5, 7, 11, 13, 17, 19 }));

    public int countPrimeSetBits(int L, int R)
    {
        int res = 0;
        for (int i = L; i <= R; i++)
        {
            if (primes.contains(Integer.bitCount(i)))
            {
                ++res;
            }
        }
        return res;
    }
}