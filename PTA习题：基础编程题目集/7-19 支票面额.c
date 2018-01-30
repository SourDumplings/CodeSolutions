#include <stdio.h>

int main()
{
    int n, y, f, flag = 0;

    scanf("%d", &n);
    for (y = 0; y < 100; y++)
    {
        for (f = 0; f < 100; f++)
        {
            if (y == 0 && f == 0)
            {
                continue;
            }
            if (98 * f - n - 199 * y == 0)
            {
                printf("%d.%d\n", y, f);
                flag = 1;
            }
        }
    }

    if (!flag)
    {
        printf("No Solution\n");
    }

    return 0;
}
