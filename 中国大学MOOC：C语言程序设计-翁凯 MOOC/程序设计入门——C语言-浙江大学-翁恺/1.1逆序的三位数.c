#include <stdio.h>

int main()
{
    int n, g, s, b;
    scanf("%d", &n);
    g = n % 10;
    b = n / 100;
    s = (n - b * 100) / 10;
    n = g * 100 + s * 10 + b;
    printf("%d\n", n);
    return 0;
}
