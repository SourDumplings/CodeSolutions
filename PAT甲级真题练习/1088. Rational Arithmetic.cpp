/*
 @Date    : 2018-02-17 10:51:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1088
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void simplify(long long &n, long long &d)
{
    if (n && d)
    {
        long long gcd;
        long long r;
        long long tempn = max(n, d), tempd = min(n, d);
        while (tempd)
        {
            r = tempn % tempd;
            tempn = tempd;
            tempd = r;
        }
        gcd = tempn;
        n /= gcd;
        d /= gcd;
    }
    return;
}

void output_num(long long n, long long d)
{
    if (d == 0)
        printf("Inf");
    else if (n == 0)
        printf("0");
    else
    {
        bool neg = false;
        if (n * d < 0)
        {
            printf("(-");
            neg = true;
        }
        if (n < 0)
            n = -n;
        if (d < 0)
            d = -d;
        long long i = n / d;
        if (i)
        {
            printf("%lld", i);
            n -= i * d;
            if (n)
                putchar(' ');
        }
        if (n)
            printf("%lld", n);
        if (d > 1)
            printf("/%lld", d);
        if (neg)
            putchar(')');
    }
    return;
}

void output(long long n1, long long d1, long long n2, long long d2, char c,
    long long n, long long d)
{
    output_num(n1, d1);
    printf(" %c ", c);
    output_num(n2, d2);
    printf(" = ");
    output_num(n, d);
    putchar('\n');
    return;
}

void my_sum(long long n1, long long d1, long long n2, long long d2)
{
    long long n = n1 * d2 + n2 * d1;
    long long d = d1 * d2;
    simplify(n, d);
    output(n1, d1, n2, d2, '+', n, d);
    return;
}

void my_sub(long long n1, long long d1, long long n2, long long d2)
{
    long long n = n1 * d2 - n2 * d1;
    long long d = d1 * d2;
    simplify(n, d);
    output(n1, d1, n2, d2, '-', n, d);
    return;
}

void my_mult(long long n1, long long d1, long long n2, long long d2)
{
    long long n = n1 * n2;
    long long d = d1 * d2;
    simplify(n, d);
    output(n1, d1, n2, d2, '*', n, d);
    return;
}

void my_div(long long n1, long long d1, long long n2, long long d2)
{
    if (n2)
    {
        long long n = n1 * d2;
        long long d = d1 * n2;
        simplify(n, d);
        output(n1, d1, n2, d2, '/', n, d);
    }
    else
        output(n1, d1, n2, d2, '/', 1, 0);
    return;
}

int main(int argc, char const *argv[])
{
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    simplify(a1, b1);
    simplify(a2, b2);
    my_sum(a1, b1, a2, b2);
    my_sub(a1, b1, a2, b2);
    my_mult(a1, b1, a2, b2);
    my_div(a1, b1, a2, b2);
    return 0;
}
