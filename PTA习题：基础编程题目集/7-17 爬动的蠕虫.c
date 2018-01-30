#include <stdio.h>

int main()
{
    int N, U, D, t = 0;
    int d = 0;

    scanf("%d %d %d", &N, &U, &D);

    while(1)
    {
        d += U;
        t += 1;
        if (d >= N)
        {
            break;
        }
        else
        {
            d -= D;
            t += 1;
        }
    }

    printf("%d\n", t);

    return 0;
}
