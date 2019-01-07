#include <stdio.h>

int IsPrime(int num)
{
    int i;
    if (num > 2 && !(num % 2))
    {
        return 0;
    }
    for (i = 3; i < num; i++)
    {
        if (!(num % i))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int i, n, m;
    int sum = 0;
    int count = 0;
    scanf("%d %d", &n, &m);
    for (i = 2; count < m; i++)
    {
        if (IsPrime(i))
        {
            count++;
            if (count >= n)
            {
                sum += i;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
