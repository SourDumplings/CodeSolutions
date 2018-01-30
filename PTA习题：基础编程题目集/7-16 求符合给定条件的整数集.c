#include <stdio.h>

int main()
{
    int A, i, j, k, count = 0;
    int A_sub[4];

    scanf("%d", &A);

    for (i = 0; i < 4; i++)
    {
        A_sub[i] = A + i;
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i != j)
            {
                for (k = 0; k < 4; k++)
                {
                    if (k != i && k != j)
                    {
                        printf("%d", A_sub[i] * 100 + A_sub[j] * 10 + A_sub[k]);
                        count++;
                        if (count % 6)
                        {
                            putchar(' ');
                        }
                        else
                            putchar('\n');
                    }

                }
            }
        }
    }

    return 0;
}
