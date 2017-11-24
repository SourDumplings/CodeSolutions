#include <stdio.h>

// 这个判断素数的方法很妙
int IsPrime(int n)
{
    int i;
    if (n == 2)
    {
        return 1;
    }
    for (i = 3; i <= n/3; i += 2)
    {
        if (!(n % i))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int M, N;
    int i;
    int count = 0;
    int count_o = 0;
    scanf("%d %d", &M, &N);

    for (i = 2;; i++)
    {
        if (i != 2 && !(i % 2))
        {
            continue;
        }
        if (IsPrime(i))
        {
            count++;
            if (count > N)
            {
                return 0;
            }
            else if (count >= M)
            {
                printf("%d", i);
                count_o++;
                if (!(count_o % 10) || (count == N))
                {
                    putchar('\n');
                }
                else if (count_o % 10 && count <= N - 1)
                {
                    putchar(' ');
                }
            }
        }
    }

    return 0;
}
