#include <stdio.h>

int FindGcd(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, d;
    scanf("%d/%d", &n, &d);
    int gcd = FindGcd(n, d);
    printf("%d/%d\n", n/gcd, d/gcd);
    return 0;
}
