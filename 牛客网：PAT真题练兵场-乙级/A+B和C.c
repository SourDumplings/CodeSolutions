#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    long long a[10], b[10], c[10];
    int i;

    for (i = 0; i < T; i++)
    {
        scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
    }

    for (i = 0; i < T; i++)
    {
        printf("Case #%d: ", i+1);
        if (a[i] + b[i] > c[i])
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }

    return 0;
}
