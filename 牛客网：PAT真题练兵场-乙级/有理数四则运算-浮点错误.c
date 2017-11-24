/*
 @Date    : 2017-11-15 10:15:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.nowcoder.com/pat/6/problem/4060
 */

#include <stdio.h>
#include <math.h>

#define TOF 1E-15

long long gcd(int a, int b)
{
    // printf("$$a = %d b = %d\n$$", a, b);
    long long r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int IsInt(double n)
{
    return fabs((n - (int)n)) < TOF;
}

void ToInt(double *pa, double *pb)
{
    int i = 10;
    while (!IsInt(*pa) || !IsInt(*pb))
    {
        *pa *= i;
        *pb *= i;
        i *= 10;
    }
    return;
}

void OutPut(double a, double b)
{
    // printf("$$a = %f b = %f$$\n", a, b);
    if (fabs(a) < TOF)
    {
        printf("0");
        return;
    }
    if (a / b < 0)
    {
        printf("(-");
    }
    double num, del;
    num = a;
    del = b;
    long long k;
    k = num / del;
    if (!IsInt(num) || !IsInt(del))
    {
        ToInt(&num, &del);
        // printf("$$num = %f del = %f$$\n", num, del);
    }
    int c = gcd((long long)num, (long long)del);
    num -= del * k;
    num /= c;
    del /= c;
    if (k)
    {
        if (k < 0)
        {
            k *= -1;
        }
        printf("%lld", k);
    }
    if (fabs(num) > TOF)
    {
        if (num < 0)
        {
            num *= -1;
        }
        if (del < 0)
        {
            del *= -1;
        }
        if (k)
        {
            putchar(' ');
        }
        printf("%lld/%lld", (long long)num, (long long)del);
    }
    if (a / b < 0)
    {
        putchar(')');
    }
    return;
}

int main()
{
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    double a, b;
    // 和
    OutPut(a1, b1);
    printf(" + ");
    OutPut(a2, b2);
    b = b1 * b2;
    a = a1 * b2 + b1 * a2;
    printf(" = ");
    OutPut(a, b);
    putchar('\n');
    // 差
    OutPut(a1, b1);
    printf(" - ");
    OutPut(a2, b2);
    b = b1 * b2;
    a = a1 * b2 - a2 * b1;
    printf(" = ");
    OutPut(a, b);
    putchar('\n');
    // 积
    OutPut(a1, b1);
    printf(" * ");
    OutPut(a2, b2);
    a = a1 * a2;
    b = b1 * b2;
    printf(" = ");
    OutPut(a, b);
    putchar('\n');
    // 商
    OutPut(a1, b1);
    printf(" / ");
    OutPut(a2, b2);
    printf(" = ");
    if (!a2)
    {
        printf("Inf");
    }
    else
    {
        a = (double)a1 / a2;
        b = (double)b1 / b2;
        // printf("$$a = %f b = %f$$", a, b);
        OutPut(a, b);
    }
    putchar('\n');
    // printf("%f\n", 1.0/0.0); // 会输出inf
    return 0;
}
