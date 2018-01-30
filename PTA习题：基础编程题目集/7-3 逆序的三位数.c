#include <stdio.h>

int main()
{
    int b, s, g, num, result;

    scanf("%d", &num);

    b = num / 100;
    s = (num % 100) / 10;
    g = num % 10;

    result = g * 100 + s * 10 + b * 1;

    printf("%d", result);

    return 0;
}
