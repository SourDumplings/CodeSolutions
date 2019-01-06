/**
 * @Date    : 2018-04-06 13:52:54
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * 求斐波那契数
*/

import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int N = cin.nextInt();
        System.out.println(fib(N));
    }
    public static long fib(int N)
    {
        if (N == 0 || N == 1)
        {
            return 1;
        }
        else
        {
            long[] res = new long[N+1];
            res[0] = res[1] = 1;
            for (int i = 2; i != N + 1; ++i)
            {
                res[i] = res[i-1] + res[i-2];
            }
            return res[N];
        }
    }
}


