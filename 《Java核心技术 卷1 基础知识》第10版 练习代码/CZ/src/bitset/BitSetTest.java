package bitset;

import java.util.BitSet;

/**
 * This program runs the Sieve of Erathostenes benchmark.
 * It computes all primes up to 2000000.
 *
 * @author CHANG Zheng
 * @title: BitSetTest
 * @projectName 《Java核心技术 卷1 基础知识》第10版 练习代码
 * @description: TODO
 * @date 2019/10/1116:12
 */
public class BitSetTest
{
    public static void main(String[] args)
    {
        int n = 2000000;
        long start = System.currentTimeMillis();
        BitSet b = new BitSet(n + 1);
        int count = 0;
        int i;
        for (i = 2; i <= n; i++)
        {
            b.set(i);
        }
        i = 2;
        while (i * i <= n)
        {
            if (b.get(i))
            {
                int k = 2 * i;
                while (k <= n)
                {
                    b.clear(k);
                    k += i;
                }
            }
            ++i;
        }
        i = 2;
        while (i <= n)
        {
            if (b.get(i))
            {
                ++count;
            }
            ++i;
        }
        long end = System.currentTimeMillis();
        System.out.println(count + " primes");
        System.out.println((end - start) + " milliseconds");
    }
}
