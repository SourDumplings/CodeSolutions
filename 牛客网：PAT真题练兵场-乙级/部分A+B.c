#include <stdio.h>

int main()
{
    long long A, B;
    int dA, dB;
    int i;
    int pa[11] = {0}, pb[11] = {0};
    int na = 0, nb = 0;

    scanf("%lld %d %lld %d", &A, &dA, &B, &dB);

    while (A)
    {
        if (A % 10 == dA)
        {
            pa[na++] = dA;
        }
        A /= 10;
    }
    while (B)
    {
        if (B % 10 == dB)
        {
            pb[nb++] = dB;
        }
        B /= 10;
    }

    for (i = 0; i < na; i++)
    {
        A = A * 10 + pa[i];
    }
    for (i = 0; i < nb; i++)
    {
        B = B * 10 + pb[i];
    }

    printf("%lld\n", A+B);

    return 0;
}
