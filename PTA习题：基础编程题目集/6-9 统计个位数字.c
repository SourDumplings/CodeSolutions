#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit ( const int N, const int D )
{
    int count = 0;
    int n = N;

    if (n < 0)
        n *= -1;

    if (!n && !D)
        return 1;

    for (; n; n /= 10)
    {
        if (n % 10 == D)
            count++;
    }

    return count;

}
