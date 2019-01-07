/*
 @Date    : 2018-01-05 11:03:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
期末考试2
 */

#include <stdio.h>

int gcd(int a, int b)
{
    int r;
    do
    {
        r = a % b;
        a = b;
        b = r;
    } while (b);
    return a;
}

int main(int argc, char const *argv[])
{
    int n1, d1, n2, d2;
    scanf("%d/%d %d/%d", &n1, &d1, &n2, &d2);
    long long value1, value2;
    int g1 = gcd(n1, d1);
    int g2 = gcd(n2, d2);
    value1 = (n1/g1) * (d2/g2);
    value2 = (n2/g2) * (d1/g1);
    if (value1 < value2)
        printf("%d/%d < %d/%d\n", n1, d1, n2, d2);
    else if (value1 == value2)
        printf("%d/%d = %d/%d\n", n1, d1, n2, d2);
    else
        printf("%d/%d > %d/%d\n", n1, d1, n2, d2);
    return 0;
}
