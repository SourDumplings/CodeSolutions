#include <stdio.h>

int main()
{
    int numerator, denominator;
    int i;

    scanf("%d/%d", &numerator, &denominator);

    for (i = numerator; i > 1; i--)
    {
        if (!(numerator % i) && !(denominator % i))
        {
            numerator /= i;
            denominator /= i;
        }
    }

    printf("%d/%d\n", numerator, denominator);
    return 0;
}
