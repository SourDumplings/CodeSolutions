/*
 @Date    : 2017-11-29 17:46:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1015
 */

#include <stdio.h>
#include <math.h>

int GetReverseValue(int N, int D)
{
    int d_n[100];
    int i;
    for (i = 0; N; i++)
    {
        d_n[i] = N % D;
        // printf("$$d_n[%d] = %d$$\n", i, d_n[i]);
        N /= D;
    }
    int temp = 1;
    int result = 0;
    for (i -= 1; i >= 0; i--)
    {
        result += d_n[i] * temp;
        temp *= D;
    }
    return result;
}

int IsPrime(int N)
{
    if (N == 2)
    {
        return 1;
    }
    else if (N % 2 == 0 || N == 0 || N == 1)
    {
        return 0;
    }
    else
    {
        int i;
        for (i = 3; i <= sqrt(N); i += 2)
        {
            if (N % i == 0)
            {
                // printf("%d is a composite number, it has factor %d.\n", N, i);
                return 0;
            }
        }
        // printf("%d is a prime number.\n", N);
        return 1;
    }
}

int main()
{
    int N, D;
    int flag;
    while (1)
    {
        scanf("%d", &N);
        if (N < 0)
        {
            break;
        }
        else
        {
            scanf("%d", &D);
            flag = IsPrime(N);
            if (flag)
            {
                N = GetReverseValue(N, D);
                // printf("$$Its reverse value is %d.$$\n", N);
                flag = IsPrime(N);
            }
            if (flag)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}

