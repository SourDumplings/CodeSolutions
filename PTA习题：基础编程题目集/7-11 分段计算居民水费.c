#include <stdio.h>

int main()
{
    float x, y;

    scanf("%f", &x);

    if (x <= 15)
    {
        y = 4 * x / 3;
    }
    else
    {
        y = 2.5 * x - 17.5;
    }

    printf("%.2f", y);

    return 0;
}
