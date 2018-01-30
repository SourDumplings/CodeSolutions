#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    int n;
    n = x / 16 * 10 + (x - x / 16 * 16);
    printf("%d", n);

    return 0;
}
