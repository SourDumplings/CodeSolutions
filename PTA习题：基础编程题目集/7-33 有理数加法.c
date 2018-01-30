#include <stdio.h>

int main()
{
    int a1, a2, b1, b2;
    int denominator;
    int numeritor;
    int i;
    int min;

    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);

    denominator = b1 * b2;
    numeritor = a1 * b2 + a2 * b1;

    min = denominator > numeritor ? numeritor:denominator;

    for (i = min; i >= 2; i--)
    {
        if (!(denominator % i) && !(numeritor % i))
        {
            denominator /= i;
            numeritor /= i;
        }
    }

    if (denominator == 1)
    {
        printf("%d\n", numeritor);
    }
    else
    {
        printf("%d/%d\n", numeritor, denominator);
    }


    return 0;
}
