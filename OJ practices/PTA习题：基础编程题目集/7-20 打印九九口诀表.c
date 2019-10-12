#include <stdio.h>

int main()
{
    int N, i, j;

    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (i * j >= 10)
            {
                printf("%d*%d=%d  ", j, i, i * j);
            }
            else
            {
                printf("%d*%d=%d   ", j, i, i * j);
            }
        }
        putchar('\n');
    }
    return 0;
}
