/*
 @Date    : 2017-11-12 20:40:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5804
 */

#include <stdio.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}

/* 你的代码将被嵌在这里 */

#include <math.h>
double fn(double x, int n)
{
    if (n == 1)
    {
        return x;
    }
    return pow(-1, n-1) * pow(x, n) + fn(x, n-1);
}
