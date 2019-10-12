#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber ( const int N )
{
    int i, square = 0;
    int j;
    int n0 = N, n;

    for (i = 0; i <= n0; i++)
    {
        if(i * i == n0)
        {
            square = 1;
            break;
        }
    }

    if (square)
    {
        while (1)
        {
            i = n0 % 10;
            n0 /= 10;
            if (!n0)
            {
                return 0;
            }
            for (n = n0; n; n /= 10)
            {
                j = n % 10;
                if (j == i)
                {
                    return 1;
                }
            }

        }
    }

    return 0;
}
