#include <stdio.h>
#include <math.h>

int main()
{
    int N, X, Y, flag = 0;

    scanf("%d", &N);

    for (X = 1; X < sqrt(N); X++)
    {
        for (Y = X; Y < sqrt(N); Y++)
        {
            if (X * X + Y * Y == N)
            {
                printf("%d %d\n", X, Y);
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
