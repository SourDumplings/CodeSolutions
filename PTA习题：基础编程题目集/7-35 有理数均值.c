#include <stdio.h>

void simplify(long long int *pa, long long int *pb)
{
    long long int m, n, temp;
    m = *pa;
    n = *pb;
    if (m < 0)
    {
        m = -m;
    }

    while (n > 0)
    {
        temp = m % n;
        m = n;
        n = temp;
    }

    *pa /= m;
    *pb /= m;

    return;
}

void sum(long long int ai, long long int bi, long long int *pn, long long int *pd)
{
    *pn = ai * *pd + bi * *pn;
    *pd *= bi;
    simplify(pn, pd);
    return;
}

int main()
{
    int N, i;
    long long int a[100], b[100];
    long long int numeritor = 0, denominator = 1;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%lld/%lld", &a[i], &b[i]);

        // 化简每个分式
        simplify(&a[i], &b[i]);

        // 求当前录入所有元素的和并化简
        sum(a[i], b[i], &numeritor, &denominator);
    }

    // 求均值并化简
    denominator *= N;
    simplify(&numeritor, &denominator);

    if (denominator != 1)
        printf("%lld/%lld\n", numeritor, denominator);
    else
        printf("%lld\n", numeritor);

    return 0;
}
