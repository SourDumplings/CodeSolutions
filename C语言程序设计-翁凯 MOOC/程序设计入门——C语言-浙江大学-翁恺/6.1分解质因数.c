#include <stdio.h>

int IsPrime(int n)
{
    int i;
    if (n == 2)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return 0;
    }
    for (i = 3; i < n/2; i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    int i;
    scanf("%d", &n);
    printf("%d=", n);
    while (!IsPrime(n))
    {
        for (i = 2; i < n; i++)
        {
            if (IsPrime(i) && n % i == 0)
            {
                printf("%dx", i);
                break;
            }
        }
        n /= i;
    }
    printf("%d\n", n);
    return 0;
}
